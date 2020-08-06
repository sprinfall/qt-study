#include <QApplication>
#include <QToolButton>

#include "common/utility.h"

#include "toolbar.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  Q_INIT_RESOURCE(toolbar);

  QPixmap tool_cut_pixmap{ ":/image/toolbar_cut.svg" };
  QPixmap tool_delete_pixmap{ ":/image/toolbar_delete.svg" };
  QPixmap tool_lock_pixmap{ ":/image/toolbar_lock.svg" };

  if (tool_cut_pixmap.isNull()) {
    return 1;
  }

  Toolbar toolbar;
  ToolButton* button = nullptr;

  toolbar.AddButton(tool_cut_pixmap, true);
  toolbar.AddButton(tool_delete_pixmap, false);
  toolbar.AddButton(tool_lock_pixmap, true);

  toolbar.show();

  //QWidget* widget = new QWidget;
  //ToolButton* tool_button = new QToolButton(widget);

  //ImageButton* image_button = new ImageButton(widget);
  //image_button->SetPixmap(tool_cut_pixmap);

  //widget->resize(300, 200);
  //widget->show();

  return app.exec();
}
