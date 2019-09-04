#include "main_window.h"

#include <QtWidgets>

#include "arrow_pad.h"

MainWindow::MainWindow() {
  arrow_pad_ = new ArrowPad;
  setCentralWidget(arrow_pad_);

  exit_action_ = new QAction(tr("E&xit"), this);
  exit_action_->setShortcuts(QKeySequence::Quit);

  //connect(exit_action_, SIGNAL(triggered()), this, SLOT(close()));
  connect(exit_action_, &QAction::triggered, this, &MainWindow::close);

  file_menu_ = menuBar()->addMenu(tr("&File"));
  file_menu_->addAction(exit_action_);
}
