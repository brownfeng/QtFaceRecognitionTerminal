#include "detect_task.hpp"

#include <QRect>
#include <QThread>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

#include "quface/common.hpp"
#include "quface/face.hpp"

using namespace suanzi;

DetectTask::DetectTask(FaceDetectorPtr detector, QThread *thread,
                       QObject *parent)
    : face_detector_(detector) {
  b_tx_ok_ = true;
  b_data_ready_ = false;
  recognize_data1_ = nullptr;
  recognize_data2_ = nullptr;
  pingpang_buffer_ = nullptr;

  if (thread == nullptr) {
    static QThread new_thread;
    moveToThread(&new_thread);
    new_thread.start();
  } else {
    moveToThread(thread);
    thread->start();
  }
}

DetectTask::~DetectTask() {
  if (recognize_data1_ != nullptr) delete recognize_data1_;
  if (recognize_data2_ != nullptr) delete recognize_data2_;
  if (pingpang_buffer_ != nullptr) delete pingpang_buffer_;
}

void DetectTask::copy_buffer(ImagePackage *pang, DetectionRatio &bgr_detection,
                             DetectionRatio &nir_detection) {
  if (pingpang_buffer_ == nullptr) {
    recognize_data1_ =
        new RecognizeData({(SZ_UINT32)pang->img_bgr_large->width,
                           (SZ_UINT32)pang->img_bgr_large->height},
                          {(SZ_UINT32)pang->img_bgr_small->width,
                           (SZ_UINT32)pang->img_bgr_small->height},
                          {(SZ_UINT32)pang->img_nir_large->width,
                           (SZ_UINT32)pang->img_nir_large->height},
                          {(SZ_UINT32)pang->img_nir_small->width,
                           (SZ_UINT32)pang->img_nir_small->height});
    recognize_data2_ =
        new RecognizeData({(SZ_UINT32)pang->img_bgr_large->width,
                           (SZ_UINT32)pang->img_bgr_large->height},
                          {(SZ_UINT32)pang->img_bgr_small->width,
                           (SZ_UINT32)pang->img_bgr_small->height},
                          {(SZ_UINT32)pang->img_nir_large->width,
                           (SZ_UINT32)pang->img_nir_large->height},
                          {(SZ_UINT32)pang->img_nir_small->width,
                           (SZ_UINT32)pang->img_nir_small->height});
    pingpang_buffer_ =
        new PingPangBuffer<RecognizeData>(recognize_data1_, recognize_data2_);
  }
  RecognizeData *ping = pingpang_buffer_->get_ping();
  pang->copy_to(*ping);
  ping->bgr_detection = bgr_detection;
  ping->nir_detection = nir_detection;
}

void DetectTask::rx_frame(PingPangBuffer<ImagePackage> *buffer) {
  auto cfg = Config::get_detect();

  // SZ_LOG_DEBUG("rx_frame");
  ImagePackage *pang = buffer->get_pang();
  SZ_RETCODE ret;

  // 256x256  7ms
  std::vector<suanzi::FaceDetection> bgr_detections;
  ret = face_detector_->detect(
      (const SVP_IMAGE_S *)pang->img_bgr_small->pImplData, bgr_detections,
      cfg.threshold, cfg.min_face_size);
  if (ret != SZ_RETCODE_OK) {
    SZ_LOG_ERROR("Detect bgr error ret={}", ret);
  }

  bool valid_face = true;

  int width;
  int height;
  DetectionRatio largest_bgr_face;
  DetectionRatio largest_nir_face;

  if (bgr_detections.size() > 0) {
    width = pang->img_bgr_small->width;
    height = pang->img_bgr_small->height;
    // SZ_LOG_DEBUG("bgr_detections w={},h={}", width, height);
    largest_bgr_face = select_face(bgr_detections, width, height);
    emit tx_bgr_display(largest_bgr_face);
  } else {
    valid_face = false;
    DetectionRatio no_face;
    no_face.b_valid = false;
    emit tx_bgr_display(no_face);
  }

  if (Config::is_liveness_enable()) {
    std::vector<suanzi::FaceDetection> nir_detections;
    ret = face_detector_->detect(
        (const SVP_IMAGE_S *)pang->img_nir_small->pImplData, nir_detections);
    if (ret != SZ_RETCODE_OK) {
      SZ_LOG_ERROR("Detect nir error ret={}", ret);
    }

    if (nir_detections.size() > 0) {
      width = pang->img_nir_small->width;
      height = pang->img_nir_small->height;
      // SZ_LOG_DEBUG("nir_detections w={},h={}", width, height);
      largest_nir_face = select_face(nir_detections, width, height);
      emit tx_nir_display(largest_nir_face);
    } else {
      valid_face = false;
      DetectionRatio no_face;
      no_face.b_valid = false;
      emit tx_nir_display(no_face);
    }
  }

  if (valid_face) {
    // SZ_LOG_DEBUG("bgr_detections x={},y={},w={},h={}", largest_bgr_face.x,
    //              largest_bgr_face.y, largest_bgr_face.width,
    //              largest_bgr_face.height);
    // SZ_LOG_DEBUG("nir_detections x={},y={},w={},h={}", largest_nir_face.x,
    //              largest_nir_face.y, largest_nir_face.width,
    //              largest_nir_face.height);
    // SZ_LOG_DEBUG("Faces bgr={}, nir={}", bgr_detections.size(),
    //              nir_detections.size());
    copy_buffer(pang, largest_bgr_face, largest_nir_face);
    if (b_tx_ok_) {
      b_tx_ok_ = false;
      b_data_ready_ = false;
      emit tx_frame(pingpang_buffer_);
    } else {
      b_data_ready_ = true;
    }
  } else {
    if (b_tx_ok_ && b_data_ready_) {
      b_tx_ok_ = false;
      b_data_ready_ = false;
      emit tx_frame(pingpang_buffer_);
    } else {
      emit tx_no_frame();
    }
  }
  buffer->switch_buffer();
  // SZ_LOG_DEBUG("tx_finish");
  emit tx_finish();
}

void DetectTask::rx_finish() { b_tx_ok_ = true; }

DetectionRatio DetectTask::select_face(
    std::vector<suanzi::FaceDetection> &detections, int width, int height) {
  int max_id = 0;
  float max_area = detections[0].bbox.width * detections[0].bbox.height;
  for (int i = 1; i < detections.size(); i++) {
    float area = detections[i].bbox.width * detections[i].bbox.height;
    if (area > max_area) {
      max_id = i;
      max_area = area;
    }
  }

  DetectionRatio detection;
  auto rect = detections[max_id].bbox;
  detection.x = rect.x * 1.0 / width;
  detection.y = rect.y * 1.0 / height;
  detection.width = rect.width * 1.0 / width;
  detection.height = rect.height * 0.8 / height;  // remove neck
#if 0
  if (isnan(detections[max_id].yaw) ||
      detections[max_id].yaw > config_->detect.max_yaw ||
      detections[max_id].yaw < config_->detect.min_yaw ||
      isnan(detections[max_id].pitch) ||
      detections[max_id].pitch > config_->detect.max_pitch ||
      detections[max_id].pitch < config_->detect.min_pitch)
    detection.b_valid = false;
  else
#endif
  detection.b_valid = true;
  for (int i = 0; i < 5; i++) {
    detection.landmark[i][0] = detections[max_id].landmarks.point[i].x / width;
    detection.landmark[i][1] = detections[max_id].landmarks.point[i].y / height;
  }

  return detection;
}
