#include "config.hpp"

using namespace suanzi;

void suanzi::to_json(json &j, const UserConfig &c) {
  SAVE_JSON_TO(j, "blacklist_policy", c.blacklist_policy);
  SAVE_JSON_TO(j, "liveness_policy", c.liveness_policy);
  SAVE_JSON_TO(j, "detect_level", c.detect_level);
  SAVE_JSON_TO(j, "extract_level", c.extract_level);
  SAVE_JSON_TO(j, "liveness_level", c.liveness_level);
  SAVE_JSON_TO(j, "duplication_interval", c.duplication_interval);
}

void suanzi::from_json(const json &j, UserConfig &c) {
  LOAD_JSON_TO(j, "blacklist_policy", c.blacklist_policy);
  LOAD_JSON_TO(j, "liveness_policy", c.liveness_policy);
  LOAD_JSON_TO(j, "detect_level", c.detect_level);
  LOAD_JSON_TO(j, "extract_level", c.extract_level);
  LOAD_JSON_TO(j, "liveness_level", c.liveness_level);
  LOAD_JSON_TO(j, "duplication_interval", c.duplication_interval);
}

void suanzi::to_json(json &j, const AppConfig &c) {
  SAVE_JSON_TO(j, "recognize_tip_top_percent", c.recognize_tip_top_percent);
  SAVE_JSON_TO(j, "server_port", c.server_port);
  SAVE_JSON_TO(j, "server_host", c.server_host);
  SAVE_JSON_TO(j, "image_store_path", c.image_store_path);
  SAVE_JSON_TO(j, "person_service_base_url", c.person_service_base_url);
  SAVE_JSON_TO(j, "enable_anti_spoofing", c.enable_anti_spoofing);
  SAVE_JSON_TO(j, "show_infrared_window", c.show_infrared_window);
  SAVE_JSON_TO(j, "device_face_x", c.device_face_x);
  SAVE_JSON_TO(j, "device_face_y", c.device_face_y);
  SAVE_JSON_TO(j, "device_face_height", c.device_face_height);
  SAVE_JSON_TO(j, "device_face_width", c.device_face_width);
  SAVE_JSON_TO(j, "temperature_distance", c.temperature_distance);
  SAVE_JSON_TO(j, "device_body_start_angle", c.device_body_start_angle);
  SAVE_JSON_TO(j, "device_body_open_angle", c.device_body_open_angle);
  SAVE_JSON_TO(j, "disabled_temperature", c.disabled_temperature);
  SAVE_JSON_TO(j, "infraraed_faces_store_path", c.infraraed_faces_store_path);
  SAVE_JSON_TO(j, "show_isp_hist_window", c.show_isp_hist_window);
}

void suanzi::from_json(const json &j, AppConfig &c) {
  LOAD_JSON_TO(j, "recognize_tip_top_percent", c.recognize_tip_top_percent);
  LOAD_JSON_TO(j, "server_port", c.server_port);
  LOAD_JSON_TO(j, "server_host", c.server_host);
  LOAD_JSON_TO(j, "image_store_path", c.image_store_path);
  LOAD_JSON_TO(j, "person_service_base_url", c.person_service_base_url);
  LOAD_JSON_TO(j, "enable_anti_spoofing", c.enable_anti_spoofing);
  LOAD_JSON_TO(j, "show_infrared_window", c.show_infrared_window);
  LOAD_JSON_TO(j, "device_face_x", c.device_face_x);
  LOAD_JSON_TO(j, "device_face_y", c.device_face_y);
  LOAD_JSON_TO(j, "device_face_height", c.device_face_height);
  LOAD_JSON_TO(j, "device_face_width", c.device_face_width);
  LOAD_JSON_TO(j, "temperature_distance", c.temperature_distance);
  LOAD_JSON_TO(j, "device_body_start_angle", c.device_body_start_angle);
  LOAD_JSON_TO(j, "device_body_open_angle", c.device_body_open_angle);
  LOAD_JSON_TO(j, "disabled_temperature", c.disabled_temperature);
  LOAD_JSON_TO(j, "infraraed_faces_store_path", c.infraraed_faces_store_path);
  LOAD_JSON_TO(j, "show_isp_hist_window", c.show_isp_hist_window);
}

void suanzi::to_json(json &j, const QufaceConfig &c) {
  SAVE_JSON_TO(j, "product_key", c.product_key);
  SAVE_JSON_TO(j, "device_name", c.device_name);
  SAVE_JSON_TO(j, "device_secret", c.device_secret);
  SAVE_JSON_TO(j, "client_id", c.client_id);
  SAVE_JSON_TO(j, "db_name", c.db_name);
  SAVE_JSON_TO(j, "model_file_path", c.model_file_path);
  SAVE_JSON_TO(j, "license_filename", c.license_filename);
}

void suanzi::from_json(const json &j, QufaceConfig &c) {
  LOAD_JSON_TO(j, "product_key", c.product_key);
  LOAD_JSON_TO(j, "device_name", c.device_name);
  LOAD_JSON_TO(j, "device_secret", c.device_secret);
  LOAD_JSON_TO(j, "client_id", c.client_id);
  LOAD_JSON_TO(j, "db_name", c.db_name);
  LOAD_JSON_TO(j, "model_file_path", c.model_file_path);
  LOAD_JSON_TO(j, "license_filename", c.license_filename);
}

void suanzi::to_json(json &j, const CameraConfig &c) {
  SAVE_JSON_TO(j, "index", c.index);
  SAVE_JSON_TO(j, "rotate", c.rotate);
  SAVE_JSON_TO(j, "flip", c.flip);
  SAVE_JSON_TO(j, "pipe", c.pipe);
  SAVE_JSON_TO(j, "isp", c.isp);
}

void suanzi::from_json(const json &j, CameraConfig &c) {
  LOAD_JSON_TO(j, "index", c.index);
  LOAD_JSON_TO(j, "rotate", c.rotate);
  LOAD_JSON_TO(j, "flip", c.flip);
  LOAD_JSON_TO(j, "pipe", c.pipe);
  LOAD_JSON_TO(j, "isp", c.isp);
}

void suanzi::to_json(json &j, const DetectConfig &c) {
  SAVE_JSON_TO(j, "threshold", c.threshold);
  SAVE_JSON_TO(j, "min_face_size", c.min_face_size);
  SAVE_JSON_TO(j, "max_yaw", c.max_yaw);
  SAVE_JSON_TO(j, "min_yaw", c.min_yaw);
  SAVE_JSON_TO(j, "max_pitch", c.max_pitch);
  SAVE_JSON_TO(j, "min_pitch", c.min_pitch);
  SAVE_JSON_TO(j, "max_roll", c.max_roll);
  SAVE_JSON_TO(j, "min_roll", c.min_roll);
  SAVE_JSON_TO(j, "min_tracking_iou", c.min_tracking_iou);
  SAVE_JSON_TO(j, "min_tracking_number", c.min_tracking_number);
}

void suanzi::from_json(const json &j, DetectConfig &c) {
  LOAD_JSON_TO(j, "threshold", c.threshold);
  LOAD_JSON_TO(j, "min_face_size", c.min_face_size);
  LOAD_JSON_TO(j, "max_yaw", c.max_yaw);
  LOAD_JSON_TO(j, "min_yaw", c.min_yaw);
  LOAD_JSON_TO(j, "max_pitch", c.max_pitch);
  LOAD_JSON_TO(j, "min_pitch", c.min_pitch);
  LOAD_JSON_TO(j, "max_roll", c.max_roll);
  LOAD_JSON_TO(j, "min_roll", c.min_roll);
  LOAD_JSON_TO(j, "min_tracking_iou", c.min_tracking_iou);
  LOAD_JSON_TO(j, "min_tracking_number", c.min_tracking_number);
}

void suanzi::to_json(json &j, const ExtractConfig &c) {
  SAVE_JSON_TO(j, "history_size", c.history_size);
  SAVE_JSON_TO(j, "min_recognize_count", c.min_recognize_count);
  SAVE_JSON_TO(j, "min_recognize_score", c.min_recognize_score);
  SAVE_JSON_TO(j, "min_accumulate_score", c.min_accumulate_score);
  SAVE_JSON_TO(j, "max_lost_age", c.max_lost_age);
}

void suanzi::from_json(const json &j, ExtractConfig &c) {
  LOAD_JSON_TO(j, "history_size", c.history_size);
  LOAD_JSON_TO(j, "min_recognize_count", c.min_recognize_count);
  LOAD_JSON_TO(j, "min_recognize_score", c.min_recognize_score);
  LOAD_JSON_TO(j, "min_accumulate_score", c.min_accumulate_score);
  LOAD_JSON_TO(j, "max_lost_age", c.max_lost_age);
}

void suanzi::to_json(json &j, const LivenessConfig &c) {
  SAVE_JSON_TO(j, "history_size", c.history_size);
  SAVE_JSON_TO(j, "min_alive_count", c.min_alive_count);
  SAVE_JSON_TO(j, "continuous_max_lost_count", c.continuous_max_lost_count);
  SAVE_JSON_TO(j, "min_iou_between_bgr", c.min_iou_between_bgr);
  SAVE_JSON_TO(j, "min_width_ratio_between_bgr", c.min_width_ratio_between_bgr);
  SAVE_JSON_TO(j, "max_width_ratio_between_bgr", c.max_width_ratio_between_bgr);
  SAVE_JSON_TO(j, "min_height_ratio_between_bgr",
               c.min_height_ratio_between_bgr);
  SAVE_JSON_TO(j, "max_height_ratio_between_bgr",
               c.max_height_ratio_between_bgr);
}

void suanzi::from_json(const json &j, LivenessConfig &c) {
  LOAD_JSON_TO(j, "history_size", c.history_size);
  LOAD_JSON_TO(j, "min_alive_count", c.min_alive_count);
  LOAD_JSON_TO(j, "continuous_max_lost_count", c.continuous_max_lost_count);
  LOAD_JSON_TO(j, "min_iou_between_bgr", c.min_iou_between_bgr);
  LOAD_JSON_TO(j, "min_width_ratio_between_bgr", c.min_width_ratio_between_bgr);
  LOAD_JSON_TO(j, "max_width_ratio_between_bgr", c.max_width_ratio_between_bgr);
  LOAD_JSON_TO(j, "min_height_ratio_between_bgr",
               c.min_height_ratio_between_bgr);
  LOAD_JSON_TO(j, "max_height_ratio_between_bgr",
               c.max_height_ratio_between_bgr);
}

void suanzi::to_json(json &j, const ISPExposureConfig &c) {
  SAVE_JSON_TO(j, "hist_stat_adjust", c.hist_stat_adjust);
  SAVE_JSON_TO(j, "speed", c.speed);
  SAVE_JSON_TO(j, "black_speed_bias", c.black_speed_bias);
  SAVE_JSON_TO(j, "tolerance", c.tolerance);
  SAVE_JSON_TO(j, "compensation", c.compensation);
  SAVE_JSON_TO(j, "ev_bias", c.ev_bias);
  SAVE_JSON_TO(j, "ae_strategy_mode", c.ae_strategy_mode);
  SAVE_JSON_TO(j, "hist_ratio_slope", c.hist_ratio_slope);
  SAVE_JSON_TO(j, "max_hist_offset", c.max_hist_offset);
}

void suanzi::from_json(const json &j, ISPExposureConfig &c) {
  LOAD_JSON_TO(j, "hist_stat_adjust", c.hist_stat_adjust);
  LOAD_JSON_TO(j, "speed", c.speed);
  LOAD_JSON_TO(j, "black_speed_bias", c.black_speed_bias);
  LOAD_JSON_TO(j, "tolerance", c.tolerance);
  LOAD_JSON_TO(j, "compensation", c.compensation);
  LOAD_JSON_TO(j, "ev_bias", c.ev_bias);
  LOAD_JSON_TO(j, "ae_strategy_mode", c.ae_strategy_mode);
  LOAD_JSON_TO(j, "hist_ratio_slope", c.hist_ratio_slope);
  LOAD_JSON_TO(j, "max_hist_offset", c.max_hist_offset);
}

void suanzi::to_json(json &j, const ISPStatConfig &c) {
  SAVE_JSON_TO(j, "roi_enable", c.roi_enable);
  SAVE_JSON_TO(j, "roi_margin", c.roi_margin);
  SAVE_JSON_TO(j, "roi_weight", c.roi_weight);
  SAVE_JSON_TO(j, "non_roi_weight", c.non_roi_weight);
  SAVE_JSON_TO(j, "crop_enable", c.crop_enable);
  SAVE_JSON_TO(j, "crop_margin", c.crop_margin);
}

void suanzi::from_json(const json &j, ISPStatConfig &c) {
  LOAD_JSON_TO(j, "roi_enable", c.roi_enable);
  LOAD_JSON_TO(j, "roi_margin", c.roi_margin);
  LOAD_JSON_TO(j, "roi_weight", c.roi_weight);
  LOAD_JSON_TO(j, "non_roi_weight", c.non_roi_weight);
  LOAD_JSON_TO(j, "crop_enable", c.crop_enable);
  LOAD_JSON_TO(j, "crop_margin", c.crop_margin);
}

void suanzi::to_json(json &j, const ISPGammaConfig &c) {
  SAVE_JSON_TO(j, "enable", c.enable);
  SAVE_JSON_TO(j, "curve_type", c.curve_type);
}

void suanzi::from_json(const json &j, ISPGammaConfig &c) {
  LOAD_JSON_TO(j, "enable", c.enable);
  LOAD_JSON_TO(j, "curve_type", c.curve_type);
}

void suanzi::to_json(json &j, const ISPWBConfig &c) {
  SAVE_JSON_TO(j, "op_type", c.op_type);
  SAVE_JSON_TO(j, "by_pass", c.by_pass);
}

void suanzi::from_json(const json &j, ISPWBConfig &c) {
  LOAD_JSON_TO(j, "op_type", c.op_type);
  LOAD_JSON_TO(j, "by_pass", c.by_pass);
}

void suanzi::to_json(json &j, const ISPSaturationConfig &c) {
  SAVE_JSON_TO(j, "op_type", c.op_type);
  SAVE_JSON_TO(j, "manual_saturation", c.manual_saturation);
}

void suanzi::from_json(const json &j, ISPSaturationConfig &c) {
  LOAD_JSON_TO(j, "op_type", c.op_type);
  LOAD_JSON_TO(j, "manual_saturation", c.manual_saturation);
}

void suanzi::to_json(json &j, const ISPHLCConfig &c) {
  SAVE_JSON_TO(j, "enable", c.enable);
  SAVE_JSON_TO(j, "luma_target", c.luma_target);
  SAVE_JSON_TO(j, "luma_threshold", c.luma_threshold);
}

void suanzi::from_json(const json &j, ISPHLCConfig &c) {
  LOAD_JSON_TO(j, "enable", c.enable);
  LOAD_JSON_TO(j, "luma_target", c.luma_target);
  LOAD_JSON_TO(j, "luma_threshold", c.luma_threshold);
}

void suanzi::to_json(json &j, const ISPDRCConfig &c) {
  SAVE_JSON_TO(j, "enable", c.enable);
  SAVE_JSON_TO(j, "op_type", c.op_type);
}

void suanzi::from_json(const json &j, ISPDRCConfig &c) {
  LOAD_JSON_TO(j, "enable", c.enable);
  LOAD_JSON_TO(j, "op_type", c.op_type);
}

void suanzi::to_json(json &j, const ISPConfig &c) {
  SAVE_JSON_TO(j, "stat", c.stat);
  SAVE_JSON_TO(j, "exposure", c.exposure);
  SAVE_JSON_TO(j, "wb", c.wb);
  SAVE_JSON_TO(j, "saturation", c.saturation);
  SAVE_JSON_TO(j, "gamma", c.gamma);
  SAVE_JSON_TO(j, "hlc", c.hlc);
  SAVE_JSON_TO(j, "drc", c.drc);
}

void suanzi::from_json(const json &j, ISPConfig &c) {
  LOAD_JSON_TO(j, "stat", c.stat);
  LOAD_JSON_TO(j, "exposure", c.exposure);
  LOAD_JSON_TO(j, "wb", c.wb);
  LOAD_JSON_TO(j, "saturation", c.saturation);
  LOAD_JSON_TO(j, "gamma", c.gamma);
  LOAD_JSON_TO(j, "hlc", c.hlc);
  LOAD_JSON_TO(j, "drc", c.drc);
}

void suanzi::to_json(json &j, const ISPGlobalConfig &c) {
  SAVE_JSON_TO(j, "adjust_window_size", c.adjust_window_size);
  SAVE_JSON_TO(j, "restore_size", c.restore_size);
}

void suanzi::from_json(const json &j, ISPGlobalConfig &c) {
  LOAD_JSON_TO(j, "adjust_window_size", c.adjust_window_size);
  LOAD_JSON_TO(j, "restore_size", c.restore_size);
}

void suanzi::from_json(const json &j, ConfigData &c) {
  LOAD_JSON_TO(j, "user", c.user);
  LOAD_JSON_TO(j, "app", c.app);
  LOAD_JSON_TO(j, "quface", c.quface);
  LOAD_JSON_TO(j, "isp", c.isp);

  if (j.contains("cameras")) {
    LOAD_JSON_TO(j.at("cameras"), "normal", c.normal);
    LOAD_JSON_TO(j.at("cameras"), "infrared", c.infrared);
  }

  if (j.contains("pro")) {
    LOAD_JSON_TO(j.at("pro"), "detect_levels", c.detect_levels_);
    LOAD_JSON_TO(j.at("pro"), "extract_levels", c.extract_levels_);
    LOAD_JSON_TO(j.at("pro"), "liveness_levels", c.liveness_levels_);
  }
}

void suanzi::to_json(json &j, const ConfigData &c) {
  SAVE_JSON_TO(j, "user", c.user);
  SAVE_JSON_TO(j, "app", c.app);
  SAVE_JSON_TO(j, "quface", c.quface);

  json cameras;
  SAVE_JSON_TO(cameras, "normal", c.normal);
  SAVE_JSON_TO(cameras, "infrared", c.infrared);
  SAVE_JSON_TO(j, "cameras", cameras);

  json pro;
  SAVE_JSON_TO(pro, "detect_levels", c.detect_levels_);
  SAVE_JSON_TO(pro, "extract_levels", c.extract_levels_);
  SAVE_JSON_TO(pro, "liveness_levels", c.liveness_levels_);
  SAVE_JSON_TO(j, "pro", pro);

  SAVE_JSON_TO(j, "isp", c.isp);
}

Config Config::instance_;

Config *Config::get_instance() { return &instance_; }

void Config::load_defaults(ConfigData &c) {
  c.app = {
      .recognize_tip_top_percent = 78,
      .server_port = 8010,
      .server_host = "127.0.0.1",
      .image_store_path = APP_DIR_PREFIX "/var/db/upload/",
      .person_service_base_url = "http://127.0.0.1",
      .enable_anti_spoofing = false,
      .show_infrared_window = false,
      .device_face_x = 0.289,
      .device_face_y = 0.18,
      .device_face_height = 0.35,
      .device_face_width = 0.48,
      .temperature_distance = 0.68,
      .device_body_start_angle = 2500,
      .device_body_open_angle = 180,
      .disabled_temperature = true,
      .infraraed_faces_store_path =
          APP_DIR_PREFIX "/var/face-terminal/ir-faces/",
      .show_isp_hist_window = false,
  };

  c.user = {
      .blacklist_policy = "alarm",
      .liveness_policy = "alarm",
      .detect_level = "medium",
      .extract_level = "medium",
      .liveness_level = "medium",
      .duplication_interval = 60,
  };

  c.quface = {
      .product_key = "",
      .device_name = "",
      .device_secret = "",
      .client_id = "face-service",
      .db_name = APP_DIR_PREFIX "/var/db/quface",
      .model_file_path = "facemodel.bin",
      .license_filename = "license.json",
  };

  c.isp = {
      .adjust_window_size = 10,
      .restore_size = 20,
  };

  c.normal = {
      .index = 1,
      .rotate = 0,
      .flip = 1,
      .pipe = 2,
      .isp =
          {
              .stat =
                  {
                      .roi_enable = true,
                      .roi_margin = 2,
                      .roi_weight = 2,
                      .non_roi_weight = 1,
                      .crop_enable = false,
                      .crop_margin = 25,
                  },
              .exposure =
                  {
                      .hist_stat_adjust = true,
                      .speed = 0x60,             // default: 0x40
                      .black_speed_bias = 0x90,  // default: 0x90
                      .tolerance = 0x2,          // default: 0x2
                      .compensation = 0x38,      // default: 0x38
                      .ev_bias = 0x600,          // default: 0x400
                      .ae_strategy_mode =
                          1,  // 0: HIGHLIGHT_PRIOR 1: LOWLIGHT_PRIOR
                      .hist_ratio_slope = 0xFFF,  // default: 0x80
                      .max_hist_offset = 0x6,     // default: 0x10
                  },
              .wb =
                  {
                      .by_pass = false,
                      .op_type = "auto",
                  },
              .saturation =
                  {
                      .op_type = "auto",
                      .manual_saturation = 0x64,
                  },
              .gamma =
                  {
                      .enable = true,
                      .curve_type = 0,
                  },
              .hlc =
                  {
                      .enable = false,
                      .luma_threshold = 240,
                      .luma_target = 10,
                  },
              .drc = {.enable = true, .op_type = "auto"},
          },
  };

  c.infrared = {
      .index = 0,
      .rotate = 0,
      .flip = 1,
      .pipe = 0,
      .isp =
          {
              .stat =
                  {
                      .roi_enable = true,
                      .roi_margin = 2,
                      .roi_weight = 2,
                      .non_roi_weight = 1,
                      .crop_enable = false,
                      .crop_margin = 25,
                  },
              .exposure =
                  {
                      .hist_stat_adjust = true,
                      .speed = 0x60,             // default: 0x40
                      .black_speed_bias = 0x90,  // default: 0x90
                      .tolerance = 0x2,          // default: 0x2
                      .compensation = 0x38,      // default: 0x38
                      .ev_bias = 0x600,          // default: 0x400
                      .ae_strategy_mode =
                          1,  // 0: HIGHLIGHT_PRIOR 1: LOWLIGHT_PRIOR
                      .hist_ratio_slope = 0xFFF,  // default: 0x80
                      .max_hist_offset = 0x6,     // default: 0x10
                  },
              .wb =
                  {
                      .by_pass = false,
                      .op_type = "manual",
                  },
              .saturation =
                  {
                      .op_type = "manual",
                      .manual_saturation = 0,
                  },
              .gamma =
                  {
                      .enable = true,
                      .curve_type = 0,
                  },
              .hlc =
                  {
                      .enable = false,
                      .luma_threshold = 240,
                      .luma_target = 10,
                  },
              .drc = {.enable = true, .op_type = "auto"},
          },
  };

  c.detect_levels_ = {
      .high = {.threshold = 0.4f,
               .min_face_size = 40,
               .max_yaw = 10,
               .min_yaw = -10,
               .max_pitch = 10,   // disable max pitch
               .min_pitch = -10,  // disable min pitch
               .min_roll = -10,
               .max_roll = 10,
               .min_tracking_iou = 0.9,
               .min_tracking_number = 3},
      .medium = {.threshold = 0.4f,
                 .min_face_size = 30,
                 .max_yaw = 15,
                 .min_yaw = -15,
                 .max_pitch = 15,   // disable max pitch
                 .min_pitch = -15,  // disable min pitch
                 .min_roll = -15,
                 .max_roll = 15,
                 .min_tracking_iou = 0.9,
                 .min_tracking_number = 3},
      .low = {.threshold = 0.4f,
              .min_face_size = 30,
              .max_yaw = 15,
              .min_yaw = -15,
              .max_pitch = 15,   // disable max pitch
              .min_pitch = -15,  // disable min pitch
              .min_roll = -15,
              .max_roll = 15,
              .min_tracking_iou = 0.85,
              .min_tracking_number = 2},
  };

  c.extract_levels_ = {
      .high =
          {
              .history_size = 2,
              .min_recognize_count = 2,
              .min_recognize_score = .8f,
              .min_accumulate_score = 1.6f,
              .max_lost_age = 20,
          },
      .medium =
          {
              .history_size = 1,
              .min_recognize_count = 1,
              .min_recognize_score = .8f,
              .min_accumulate_score = .8f,
              .max_lost_age = 20,
          },
      .low =
          {
              .history_size = 1,
              .min_recognize_count = 1,
              .min_recognize_score = .775f,
              .min_accumulate_score = .775f,
              .max_lost_age = 20,
          },
  };

  c.liveness_levels_ = {
      .high =
          {
              .history_size = 5,
              .min_alive_count = 2,
              .continuous_max_lost_count = 3,
              .min_iou_between_bgr = 0.1,
              .min_width_ratio_between_bgr = .5f,
              .max_width_ratio_between_bgr = 2.f,
              .min_height_ratio_between_bgr = .5f,
              .max_height_ratio_between_bgr = 2.f,
          },
      .medium =
          {
              .history_size = 3,
              .min_alive_count = 1,
              .continuous_max_lost_count = 3,
              .min_iou_between_bgr = 0.1,
              .min_width_ratio_between_bgr = .5f,
              .max_width_ratio_between_bgr = 2.f,
              .min_height_ratio_between_bgr = .5f,
              .max_height_ratio_between_bgr = 2.f,
          },
      .low =
          {
              .history_size = 5,
              .min_alive_count = 1,
              .continuous_max_lost_count = 2,
              .min_iou_between_bgr = 0.1,
              .min_width_ratio_between_bgr = .5f,
              .max_width_ratio_between_bgr = 2.f,
              .min_height_ratio_between_bgr = .5f,
              .max_height_ratio_between_bgr = 2.f,
          },
  };
}

SZ_RETCODE Config::load_from_file(const std::string &config_file,
                                  const std::string &config_override_file) {
  config_file_ = config_file;
  config_override_file_ = config_override_file;

  return reload();
}

SZ_RETCODE Config::read_config(json &cfg) {
  ConfigData cfg_data;
  load_defaults(cfg_data);
  json config(cfg_data);

  std::ifstream ifd(config_file_);
  if (!ifd.is_open()) {
    SZ_LOG_ERROR("Open {} failed, write defaults", config_file_);
  } else {
    SZ_LOG_INFO("Load config from {}", config_file_);
    json file_cfg;
    ifd >> file_cfg;
    config.merge_patch(file_cfg);
  }

  std::ofstream o(config_file_);
  if (!o.is_open()) {
    SZ_LOG_ERROR("Open {} for write failed", config_file_);
    return SZ_RETCODE_FAILED;
  }
  o << config.dump(2);
  cfg = config;

  SZ_LOG_INFO("Config updated to {}", config_file_);

  return SZ_RETCODE_OK;
}

SZ_RETCODE Config::read_override_config(json &cfg) {
  std::ifstream ifd(config_override_file_);
  if (!ifd.is_open()) {
    SZ_LOG_ERROR("Open {} failed", config_override_file_);
    return SZ_RETCODE_OK;
  }

  SZ_LOG_INFO("Override config from {}", config_override_file_);
  ifd >> cfg;
  return SZ_RETCODE_OK;
}

SZ_RETCODE Config::reload() {
  {
    std::unique_lock<std::mutex> lock(cfg_mutex_);

    SZ_LOG_INFO("Load from files ...");
    try {
      json config;
      SZ_RETCODE ret = read_config(config);
      if (ret != SZ_RETCODE_OK) {
        return ret;
      }

      json config_patch;
      ret = read_override_config(config_patch);
      if (ret != SZ_RETCODE_OK) {
        return ret;
      }

      if (config_patch.is_array()) {
        config = config.patch(config_patch);
      }

      config.get_to(cfg_data_);
    } catch (std::exception &exc) {
      SZ_LOG_ERROR("Load error, will using defaults: {}", exc.what());
      return SZ_RETCODE_FAILED;
    }
  }

  dispatch("reload");

  return SZ_RETCODE_OK;
}

SZ_RETCODE Config::save_diff(const json &target_patch) {
  try {
    json source;
    SZ_RETCODE ret = read_config(source);
    if (ret != SZ_RETCODE_OK) {
      return ret;
    }

    json target = source;
    target.merge_patch(target_patch);

    std::ofstream o(config_override_file_);
    if (!o.is_open()) {
      SZ_LOG_WARN("Open {} failed, can't save", config_override_file_);
      return SZ_RETCODE_FAILED;
    }

    json diff = json::diff(source, target);

    o << diff.dump(2);
  } catch (std::exception &exc) {
    SZ_LOG_ERROR("Save diff error: {}", exc.what());
    return SZ_RETCODE_FAILED;
  }

  return SZ_RETCODE_OK;
}

SZ_RETCODE Config::reset() {
  SZ_LOG_INFO("Clear everything in {} ...", config_override_file_);
  std::ofstream o(config_override_file_);
  if (!o.is_open()) {
    SZ_LOG_WARN("Open {} failed, can't save", config_override_file_);
    return SZ_RETCODE_FAILED;
  }

  o << "{}";
  return reload();
}

const ConfigData &Config::get_all() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_;
}

const UserConfig &Config::get_user() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_.user;
}

const AppConfig &Config::get_app() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_.app;
}

const QufaceConfig &Config::get_quface() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_.quface;
}

const ISPGlobalConfig &Config::get_isp() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_.isp;
}

const CameraConfig &Config::get_camera(bool is_bgr) {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  if (is_bgr)
    return instance_.cfg_data_.normal;
  else
    return instance_.cfg_data_.infrared;
}

const CameraConfig &Config::get_camera(CameraType tp) {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  if (tp == CAMERA_BGR)
    return instance_.cfg_data_.normal;
  else
    return instance_.cfg_data_.infrared;
}

const DetectConfig &Config::get_detect() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  auto &i = instance_;
  return i.cfg_data_.detect_levels_.get(i.cfg_data_.user.detect_level);
}

const ExtractConfig &Config::get_extract() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  auto &i = instance_;
  return i.cfg_data_.extract_levels_.get(i.cfg_data_.user.extract_level);
}

const LivenessConfig &Config::get_liveness() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  auto &i = instance_;
  return i.cfg_data_.liveness_levels_.get(i.cfg_data_.user.liveness_level);
}

bool Config::enable_anti_spoofing() {
  std::unique_lock<std::mutex> lock(instance_.cfg_mutex_);
  return instance_.cfg_data_.app.enable_anti_spoofing;
}
