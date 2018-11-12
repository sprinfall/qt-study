#ifndef PAINT_MY_WIDGET_H_
#define PAINT_MY_WIDGET_H_

#include <QWidget>

class MyWidget : public QWidget {
  Q_OBJECT

public:
  MyWidget(QWidget* parent = nullptr);

protected:
  void paintEvent(QPaintEvent* event) override;

private:
};

#endif  // PAINT_MY_WIDGET_H_
