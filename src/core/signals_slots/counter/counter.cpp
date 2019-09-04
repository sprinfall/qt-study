#include <iostream>

#include "counter.h"

void Counter::setValue(int value) {
  if (value != value_) {
    value_ = value;

    // sender() returns a pointer to the object that sent the signal.

    emit valueChanged(value);
  }
}
