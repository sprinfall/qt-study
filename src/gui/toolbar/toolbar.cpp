#include "toolbar.h"

#include <QHBoxLayout>
#include <QPainter>

#include "common/utility.h"

// -----------------------------------------------------------------------------

ToolButton::ToolButton(QWidget* parent)
    : QAbstractButton(parent), state_(NORMAL), pressed_(false) {
}

void ToolButton::SetPixmap(const QPixmap& pixmap) {
  pixmap_ = pixmap;
  setFixedSize(pixmap_.size() + QSize(16, 16));
  update();
}

QSize ToolButton::sizeHint() const {
  return pixmap_.size() + QSize(16, 16);
}

void ToolButton::paintEvent(QPaintEvent* evt) {
  QPainter painter(this);

  // Anti-alias edges of primitives if possible.
  painter.setRenderHint(QPainter::RenderHint::Antialiasing);

  const QRect r = rect();

  {
    painter.save();

    QRect border_rect = r;

    if (state_ == NORMAL) {
      painter.setPen(QPen(QColor(155, 155, 155)));
      painter.setBrush(Qt::NoBrush);
    } else if (state_ == HOVERED) {
      painter.setPen(QPen(QColor(0, 162, 232)));
      painter.setBrush(QBrush(QColor(0, 162, 232)));
    }
    
    if (pressed_ || isChecked()) {
      painter.setPen(QPen(QColor(0, 162, 232)));
      painter.setBrush(QBrush(QColor(0, 140, 200)));
    }

    painter.drawRect(border_rect);

    painter.restore();
  }

  painter.drawPixmap(8, 8, pixmap_);
}

void ToolButton::enterEvent(QEvent* evt) {
  state_ = HOVERED;

  ori_cursor_ = cursor();
  setCursor(Qt::PointingHandCursor);

  update();
  QAbstractButton::enterEvent(evt);
}

void ToolButton::leaveEvent(QEvent* evt) {
  state_ = NORMAL;

  setCursor(ori_cursor_);

  update();
  QAbstractButton::leaveEvent(evt);
}

void ToolButton::mousePressEvent(QMouseEvent* evt) {
  pressed_ = true;
  update();
  QAbstractButton::mousePressEvent(evt);
}

void ToolButton::mouseReleaseEvent(QMouseEvent* evt) {
  pressed_ = false;
  update();
  QAbstractButton::mouseReleaseEvent(evt);
}

// -----------------------------------------------------------------------------

Toolbar::Toolbar(QWidget* parent)
  : QWidget(parent), button_size_(64, 64), margin_(10, 5) {
  utility::SetBackgroundColor(this, QColor(55, 55, 55));
  setMouseTracking(true);

  QHBoxLayout* hlayout = new QHBoxLayout();
  hlayout->setSpacing(3);
  hlayout->setMargin(10);
  setLayout(hlayout);
}

Toolbar::~Toolbar() {
}

QSize Toolbar::sizeHint() const {
  int w = buttons_.size() * button_size_.width() + margin_.width() * 2;
  int h = button_size_.height() + margin_.height() * 2;
  return QSize(w, h);
}

void Toolbar::AddButton(ToolButton* button) {
  buttons_.push_back(button);

  layout()->addWidget(button);
}

ToolButton* Toolbar::AddButton(const QPixmap& pixmap, bool checkable) {
  ToolButton* button = new ToolButton(this);
  button->SetPixmap(pixmap);
  button->setCheckable(checkable);
  AddButton(button);
  return button;
}
