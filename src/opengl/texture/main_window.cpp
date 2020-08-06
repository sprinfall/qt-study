#include "opengl/triangle/main_window.h"

#include <QVBoxLayout>

#include "opengl/triangle/ogl_widget.h"

namespace renderer {

MainWindow::MainWindow() {
  setWindowTitle(tr("OpenGL - Triangle"));

  QWidget* central_widget = new QWidget{};
  setCentralWidget(central_widget);

  OglWidget* ogl_widget = new OglWidget{ central_widget };

  QHBoxLayout* hlayout = new QHBoxLayout{ central_widget };
  hlayout->addWidget(ogl_widget, 1);

  resize(800, 600);
}

}  // namespace renderer
