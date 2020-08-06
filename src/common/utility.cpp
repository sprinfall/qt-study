#include "utility.h"

#include <QColor>
#include <QWidget>

QTextStream& qStdOut() {
  static QTextStream ts(stdout);
  return ts;
}

namespace utility {

void SetBackgroundColor(QWidget* widget, const QColor& color) {
  QPalette pal = widget->palette();
  pal.setColor(QPalette::Background, color);
  widget->setAutoFillBackground(true);
  widget->setPalette(pal);
}

}  // namespace utility
