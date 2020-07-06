#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <vector>

#include <QAbstractButton>
#include <QPixmap>
#include <QWidget>

// -----------------------------------------------------------------------------

class ToolButton : public QAbstractButton {
  Q_OBJECT

public:
  enum State {
    NORMAL = 0,
    HOVERED,
    CHECKED,
    DISABLED,
    STATES,
  };

  explicit ToolButton(QWidget* parent);

  void SetPixmap(const QPixmap& pixmap);

  QSize sizeHint() const override;

protected:
  void paintEvent(QPaintEvent* evt) override;
  void enterEvent(QEvent* evt) override;
  void leaveEvent(QEvent* evt) override;
  void mousePressEvent(QMouseEvent* evt) override;
  void mouseReleaseEvent(QMouseEvent* evt) override;

private:
  QPixmap pixmap_;
  State state_;
  bool pressed_;
  QCursor ori_cursor_;
};

// -----------------------------------------------------------------------------

class Toolbar : public QWidget {
  Q_OBJECT

public:
  explicit Toolbar(QWidget* parent = nullptr);

  ~Toolbar();

  QSize sizeHint() const override;

  void AddButton(ToolButton* button);

  ToolButton* AddButton(const QPixmap& pixmap, bool checkable);

signals:
  void clicked();

protected:

private:
  std::vector<ToolButton*> buttons_;

  QSize button_size_;
  QSize margin_;
};

#endif  // TOOLBAR_H_
