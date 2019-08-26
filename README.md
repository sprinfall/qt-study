## 安装配置

### Using Qt5 with CMake

官方文档：http://doc.qt.io/qt-5/cmake-manual.html

为了让 CMake 能够找到 Qt，在 CMake 里添加变量 `CMAKE_PREFIX_PATH`，比如：

```
CMAKE_PREFIX_PATH = C:\Qt\5.10.1\msvc2013_64
```

注意：必须具体到特定的版本，仅指定安装根目录（`C:\Qt`）是不够的。

注意：`CMAKE_PREFIX_PATH` 可以指定多个目录，以分号分隔。但是 `CMAKE_PREFIX_PATH` 的类型需为 `FILEPATH` 而非 `STRING`。可以指定多个目录是你的程序可能还要寻找其他程序库，比如 VTK，这时候你应该把 VTK 的安装目录也加进来。

### Qt DLLs

大家用的基本上都是动态库版的 Qt，你的程序需要找到 Qt 的 DLL，比如一个最简单 QtWidgets 程序就需要三个 DLL：

* Qt5Widgets.dll （Debug 版为 Qt5Widgetsd.dll，下同）
* Qt5Gui.dll
* Qt5Core.dll

最直接的方法就是添加 Qt 的 `bin` 目录（比如 `D:\Qt\5.10.1\msvc2015_64\bin`）到 `PATH` 环境变量。然后，必须重启 Windows 才能生效。当然，也可以把需要的 DLLs 拷贝到你的 EXE 所在目录，但那样太麻烦了。在开发过程中，添加 `PATH` 环境变量就足够了。

### AUTOMOC

用 CMake 作为 Qt 项目的构建系统时，经常要加上以下两句：

```cmake
# Find includes in corresponding build directories.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
```

现在，假如有下面一个类的定义，声明了 `Q_OBJECT`，希望被 `moc` 程序处理，那么，`MyWidget` 的声明**必须位于头文件**，否则 `moc` 处理过程会报错！

```cpp
class MyWidget : public QWidget {
  Q_OBJECT

public:
  MyWidget(QWidget* parent = nullptr) : QWidget(parent) {
    setWindowTitle(tr("My Widget"));
  }
};
```

因为我写的是一个例子程序，本想简单起见，全部代码放在同一个源文件里，结果就遇到了这种诡异的事情。

## 核心

### Console Output

```cpp
#include <QTextStream>

// Print to stdout.
// Example: qStdOut() << "std out!";
QTextStream& qStdOut() {
  static QTextStream ts(stdout);
  return ts;
}
```

参考：https://stackoverflow.com/a/3886128

### OS Macros

E.g.,

```cpp
#include <QtGlobal>

#ifdef Q_OS_WIN32
```

Or:

```cpp
#if defined (Q_OS_WIN32) || defined (Q_OS_MACOS)
```

### 编译时检查 Qt 版本

比如 `QFontMetrics` 在 5.11 新引入的 `horizontalAdvance()`:

```cpp
#if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
  qInfo() << metrics.horizontalAdvance(text);
#endif
```

### 访问环境变量 Access Environment Variables

http://doc.qt.io/qt-5/qtglobal.html#qgetenv

```cpp
QByteArray qgetenv(const char *varName)

bool qputenv(const char *varName, const QByteArray &value)
```

需要包含头文件 `<QtGlobal>`。

### 系统标准路径 System Standard Paths

http://doc.qt.io/qt-5/qstandardpaths.html

Qt 提供了类 `QStandardPaths`，类似于 wxWidgets 的 `wxStandardPaths`。

### Qt 资源系统 Resource System

https://doc.qt.io/qt-5/resources.html


## GUI & Widgets

### Screen Rectangle

```cpp
QRect screenGeometry = QApplication::desktop()->screenGeometry(this);
```

### Child Window Rectangle

对子窗口来说，`geometry()` 返回的是相对于父窗口的坐标，通过 `mapFromParent()` 转换后，左上点才为 `(0, 0)`。

而 `rect()` 返回的才是正常的 rectangle。

```cpp
const QRect& rect = geometry();
QPoint tl = mapFromParent(rect.topLeft());
```

### 设置控件背景色 Set Widget Background Color

https://wiki.qt.io/How_to_Change_the_Background_Color_of_QWidget

```cpp
MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent), log_text_edit_(nullptr) {
  // Set background.
  QPalette pal = palette();
  pal.setColor(QPalette::Background, Qt::GlobalColor::red);
  setAutoFillBackground(true);
  setPalette(pal);
}
```

### 显示消息框 Show Message Box

```cpp
int reply = QMessageBox::question(
                this,
                tr("Test"),
                tr("Are you OK with it?"),
                QMessageBox::Yes | QMessageBox::No);

if (reply == QMessageBox::Yes) {
    qDebug() << "Yes was clicked.";
} else if (reply == QMessageBox::No) {
    qDebug() << "No was clicked.";
} else {
    qDebug() << "Canceled.";
}
```
