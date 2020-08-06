#include <QApplication>

#include "opengl/triangle/main_window.h"

int main(int argc, char** argv) {
  // Enable automatic scaling based on the pixel density of the monitor
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

  renderer::MainWindow main_window;
  main_window.show();

  return app.exec();
}
