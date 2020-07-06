#include "paint/my_widget.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QtMath>

#include "common/utility.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
  setFocusPolicy(Qt::StrongFocus);
}

void MyWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);

  const QRect& event_rect = event->rect();
  painter.fillRect(event_rect, Qt::white);

  // Anti-alias edges of primitives if possible.
  painter.setRenderHint(QPainter::RenderHint::Antialiasing);

  const QRect r = rect();

  // Draw a rectangle as border if have focus.
  if (hasFocus()) {
    painter.save();

    QRect border_rect = r;
    // Adjust -1 so that right and bottom borders could be visible.
    border_rect.adjust(0, 0, -1, -1);

    painter.setPen(QPen(Qt::red));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(border_rect);

    painter.restore();
  }

  painter.setPen(QPen(Qt::blue, 1, Qt::DotLine));
  painter.drawLine(r.topLeft(), r.bottomRight());
  painter.drawLine(r.bottomLeft(), r.topRight());

  painter.setPen(QPen(Qt::black));

  QFont f = font();
  f.setBold(true);
  f.setPointSize(12);
  painter.setFont(f);

  QFontMetrics fm(f);
  int y = fm.ascent();
  // NOTE: The y-position is used as the baseline of the font.
  painter.drawText(0, y, QStringLiteral("LeftTop"));

  painter.drawText(r, Qt::AlignCenter, QStringLiteral("Hello, Qt!"));

  painter.save();
  painter.translate(0, r.height() / 2 + fm.ascent() / 2);
  painter.drawText(0, 0, QStringLiteral("LeftMiddle"));
  painter.restore();

  painter.save();
  painter.translate(0, r.height() - fm.descent());
  painter.drawText(0, 0, QStringLiteral("LeftBottom"));
  painter.restore();

  painter.translate(r.width() / 2, r.height() / 2);
  //painter.rotate(qDegreesToRadians(45.0f));
  painter.drawEllipse(QRect(-100, -50, 200, 100));
}
