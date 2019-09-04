// See: https://doc.qt.io/qt-5/metaobjects.html#

#include <cassert>
#include <string>

#include <QApplication>
#include <QtWidgets>

#include "common/utility.h"

int main(int argc, char* argv[]) {
  QApplication app{ argc, argv };  // Needed for using QWidget.

  QObject* object = new QWidget;

  auto widget = qobject_cast<QWidget*>(object);
  assert(widget != nullptr);

  auto label = qobject_cast<QLabel*>(object);
  assert(label == nullptr);

  // inherits() is just like IsA().
  assert(object->inherits("QWidget"));
  assert(widget->inherits("QObject"));
  assert(widget->inherits("QWidget"));
  assert(!widget->inherits("QLabel"));

  const QMetaObject* meta_object = object->metaObject();
  assert(std::string(meta_object->className()) == "QWidget");

  std::cout << QObject::tr("hello") << std::endl;
  // hello

  delete object;

  return 0;
}
