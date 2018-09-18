// Study the key events of Qt Widget.

#include <QApplication>

#include "my_window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MyWindow window;
  window.show();

  return app.exec();
}
