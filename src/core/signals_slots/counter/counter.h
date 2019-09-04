#ifndef COUNTER_H_
#define COUNTER_H_

#include <QObject>

class Counter : public QObject {
  Q_OBJECT

public:
  Counter() = default;

  int value() const { return value_; }

public slots:
  void setValue(int value);

signals:
  void valueChanged(int new_value);

private:
  int value_ = 0;
};

#endif  // COUNTER_H_
