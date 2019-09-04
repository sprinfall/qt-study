// See: https://doc.qt.io/qt-5/signalsandslots.html

#include <iostream>

#include "counter.h"

int main() {
  Counter a;
  Counter b;

  // Connect using function pointers:
  QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

#if 0
  // Connect using SIGNAL and SLOT macros:
  QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
#endif

  a.setValue(12);
  std::cout << a.value() << ", " << b.value() << std::endl;
  // 12, 12

  b.setValue(48);
  std::cout << a.value() << ", " << b.value() << std::endl;
  // 12, 48

  return 0;
}
