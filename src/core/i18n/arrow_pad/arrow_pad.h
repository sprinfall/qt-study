#ifndef ARROW_PAD_H_
#define ARROW_PAD_H_

#include <QWidget>

class QPushButton;

class ArrowPad : public QWidget {
  Q_OBJECT

public:
  ArrowPad(QWidget* parent = nullptr);

private:
  QPushButton* up_button_;
  QPushButton* down_button_;
  QPushButton* left_button_;
  QPushButton* right_button_;
};

#endif  // ARROW_PAD_H_
