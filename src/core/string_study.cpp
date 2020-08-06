#include <QtGlobal>  // For Q_ASSERT
#include <QDebug>
#include <QMatrix4x4>

#include "common/utility.h"

int main() {

  float mt[4][4] = { { 1.0, 0.0, 0.0, 0.0 },
                      { 0.0, 1.0, 0.0, 0.0 },
                      { 0.0, 0.0, 1.0, 0.0 },
                      { -1, -1, -1, 1.0 } };
  qDebug() << mt[3][0];
  qDebug() << mt[3][1];
  qDebug() << mt[3][2];
  qDebug() << mt[3][3];

  QMatrix4x4 matrix;
  matrix.setRow(3, QVector4D(1, 1, 1, 0));
  qDebug() << matrix;

  QString hello = "Hello, World!";
  //std::cout << hello << std::endl;
  qInfo() << hello;

  // NOTE: Q_ASSERT is just like C assert(), only effective in debug build.

  Q_ASSERT(!hello.isEmpty());

  Q_ASSERT(hello.size() == hello.length());
  Q_ASSERT(hello.size() == hello.count());
  Q_ASSERT(hello.size() == 13);

  // Find

  // QString doesn't have any find() methods as std::string does.
  Q_ASSERT(hello.indexOf("World", 0, Qt::CaseSensitive) == 7);

  // indexOf() returns -1 on failure.
  Q_ASSERT(hello.indexOf("wORLD", 0, Qt::CaseSensitive) == -1);

  // Ignore case.
  Q_ASSERT(hello.indexOf("wORLD", 0, Qt::CaseInsensitive) == 7);

  // Find last of


  // Find by regex
  // TODO

  // Substr

  // QString has no substr(), instead it provides mid(), left() and right().

  // Just clone the whole string.
  Q_ASSERT(hello.mid(0/*, -1*/) == hello);

  // The 2nd parameter is the number of chars instead of the index.
  // This is consistent with std::string.
  Q_ASSERT(hello.mid(7, 5) == "World");

  return 0;
}
