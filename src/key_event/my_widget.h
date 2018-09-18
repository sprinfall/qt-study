#ifndef MY_WIDGET_H_
#define MY_WIDGET_H_

#include <QWidget>

class QPlainTextEdit;

class MyWidget : public QWidget {
  Q_OBJECT

public:
  MyWidget(QWidget* parent = nullptr);

  void set_log_text_edit(QPlainTextEdit* log_text_edit) {
    log_text_edit_ = log_text_edit;
  }

protected:
  void paintEvent(QPaintEvent* event) override;

  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;

private:
  QPlainTextEdit* log_text_edit_;
};

#endif  // MY_WIDGET_H_
