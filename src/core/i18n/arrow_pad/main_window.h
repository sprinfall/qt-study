#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QMainWindow>

class QAction;
class QMenu;

class ArrowPad;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

private:
  ArrowPad* arrow_pad_;
  QMenu* file_menu_;
  QAction* exit_action_;
};

#endif  // MAIN_WINDOW_H_
