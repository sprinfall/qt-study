#include "my_window.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "my_widget.h"

MyWindow::MyWindow() {
  setWindowTitle(tr("Key Event Study"));

  QWidget* central_widget = new QWidget();
  setCentralWidget(central_widget);

  MyWidget* my_widget = new MyWidget();

  log_text_edit_ = new QPlainTextEdit();

  clear_button_ = new QPushButton(tr("Clear logs"));

  QVBoxLayout* vlayout = new QVBoxLayout();

  vlayout->addWidget(my_widget, 1);
  vlayout->addWidget(log_text_edit_, 1);
  vlayout->addWidget(clear_button_, 0, Qt::AlignRight);

  central_widget->setLayout(vlayout);

  my_widget->set_log_text_edit(log_text_edit_);

  resize(800, 600);

  QObject::connect(clear_button_, &QPushButton::clicked,
                   this, &MyWindow::ClearLogs);
}

void MyWindow::ClearLogs() {
  log_text_edit_->clear();
}

