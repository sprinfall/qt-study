// Based on Qt Example \linguist\arrowpad.
// Modified to use CMake to handle the translations.
// See: https://doc.qt.io/qt-5/qtlinguist-arrowpad-example.html#
// See: https://doc.qt.io/qt-5/cmake-manual.html

#include <iostream>

#include <QDebug>
#include <QtWidgets>

#include "main_window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QString locale = QLocale::system().name();

  qDebug() << "system locale:" << locale;
  qDebug() << "app dir:" << qApp->applicationDirPath();

  QTranslator translator;
  translator.load(QString("arrow_pad_") + locale,
                  qApp->applicationDirPath() + QStringLiteral("/locale"));
  translator.load(QString("qt_") + locale,
                  qApp->applicationDirPath() + QStringLiteral("/locale"));
  app.installTranslator(&translator);

  MainWindow main_window;
  main_window.show();

  return app.exec();
}
