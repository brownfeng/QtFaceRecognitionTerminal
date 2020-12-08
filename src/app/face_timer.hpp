#ifndef FACE_TIMER_HPP
#define FACE_TIMER_HPP

#include <chrono>

#include <QObject>
#include <QThread>
#include <QTimer>

#include "detection_data.hpp"
#include "pingpang_buffer.hpp"
#include "quface_common.hpp"

namespace suanzi {
class FaceTimer : QThread {
  Q_OBJECT
 public:
  static FaceTimer *get_instance();

 private slots:
  void rx_detect_result(bool valid_detect);
  void screen_saver_timeout();
  void white_led_timeout();
  void delay_close_white_led();

 signals:
  void tx_display_screen_saver(bool visible);
  void tx_white_led_timeout();

 private:
  FaceTimer(QObject *parent = nullptr);
  ~FaceTimer();
  void display_screen_saver(bool visible);
  void run() override;

  int disappear_counter_;
  int disappear_duration_;
  std::chrono::steady_clock::time_point disappear_begin_;

  QTimer *screen_saver_timer_;
  QTimer *white_led_timer_;
  bool bclose_white_led_;

  const int MAX_WHITE_LED_TIMEOUT = 5;
};

}  // namespace suanzi

#endif
