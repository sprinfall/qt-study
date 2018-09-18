#ifndef MY_WINDOW_H_
#define MY_WINDOW_H_

#include <QMainWindow>

class QPlainTextEdit;
class QPushButton;

class MyWindow : public QMainWindow {
  Q_OBJECT

public:
  MyWindow();

private:
  // Text edit for logging the events.
  QPlainTextEdit* log_text_edit_;

  // Button to clear the logs.
  QPushButton* clear_button_;
};

#endif  // MY_WINDOW_H_
