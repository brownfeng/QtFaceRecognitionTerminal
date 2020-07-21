#include <QMetaType>
#include <QtWidgets/QApplication>

#include "face_server.hpp"
#include "http_server.hpp"
#include "video_player.hpp"

using namespace suanzi;

int main(int argc, char* argv[]) {
  std::string cfg_file = "config.json";
  std::string cfg_override_file = "config.override.json";
  for (int i = 1; i < argc; i++) {
    auto arg = std::string(argv[i]);
    if (i < argc - 1) {
      if (arg == "-c" || arg == "--config") {
        i++;
        cfg_file = argv[i];
      } else if (arg == "-cc" || arg == "--override-config") {
        i++;
        cfg_override_file = argv[i];
      }
    }
  }

  auto config = suanzi::Config::get_instance();
  SZ_RETCODE ret = config->load_from_file(cfg_file, cfg_override_file);
  if (ret != SZ_RETCODE_OK) {
    return -1;
  }

  auto detector =
      std::make_shared<FaceDetector>(config->quface.model_file_path);
  auto extractor =
      std::make_shared<FaceExtractor>(config->quface.model_file_path);
  auto db = std::make_shared<FaceDatabase>(config->quface.db_name);

  auto face_service = std::make_shared<FaceService>(
      db, detector, extractor, config->app.image_store_path);
  auto face_server = std::make_shared<FaceServer>(face_service);
  auto http_server = std::make_shared<HTTPServer>(config);
  face_server->add_event_source(http_server);

  std::thread t([&]() {
    http_server->run(config->app.server_port, config->app.server_host);
  });
  t.detach();

  qRegisterMetaType<PersonData>("PersonData");
  qRegisterMetaType<DetectionRatio>("DetectionRatio");

  QApplication app(argc, argv);

  VideoPlayer player(db, detector, extractor);
  player.show();

  return app.exec();
}
