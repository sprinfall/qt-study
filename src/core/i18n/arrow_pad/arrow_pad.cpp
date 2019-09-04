#include "arrow_pad.h"

#include <QtWidgets>

ArrowPad::ArrowPad(QWidget* parent) : QWidget(parent) {
  up_button_ = new QPushButton(tr("&Up"));
  down_button_ = new QPushButton(tr("&Down"));
  left_button_ = new QPushButton(tr("&Left"));
  right_button_ = new QPushButton(tr("&Right"));

  QGridLayout* layout = new QGridLayout;

  layout->addWidget(up_button_, 0, 1);
  layout->addWidget(left_button_, 1, 0);
  layout->addWidget(right_button_, 1, 2);
  layout->addWidget(down_button_, 2, 1);

  setLayout(layout);
}
