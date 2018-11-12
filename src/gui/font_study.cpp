#include <QDebug>
#include <QFont>
#include <QFontDatabase>
#include <QFontInfo>
#include <QFontMetrics>
#include <QGuiApplication>

void TestFontCreation() {
  // Font families 可参见 QFont::StyleHint.

  QFont f1("SansSerif");
  qInfo() << f1.family();
  // "SansSerif"
  // 设置的是什么，返回就是什么

  qInfo() << QFontInfo(f1).family();
  // "MS Shell Dlg 2"
  // QFontInfo 返回实际的字体信息

  QFont f2("Monospace", 10, QFont::Bold);
  qInfo() << QFontInfo(f2).family();
  // "MS Shell Dlg 2"

  // 虽然参数叫 family，但是也可以传 facename
  // Qt 不像 wxWidgets，对字体没有 facename 这种说法
  QFont f3("Verdana", 10, QFont::Bold);
  qInfo() << QFontInfo(f3).family();
  // "Verdana"
  QFont f4("Consolas", 10, QFont::Bold);
  qInfo() << QFontInfo(f4).family();
  // "Consolas"
}

void TestFontDatabase() {
  QFontDatabase database;

  // 枚举系统里的字体

  for (const QString& family : database.families()) {
    qInfo() << family;  // 其实是 facename

    for (const QString& style : database.styles(family)) {
      QString sizes;
      for (int points : database.smoothSizes(family, style)) {
        sizes += QString::number(points) + ' ';
      }
      qInfo() << "  " << sizes.trimmed();
    }
  }
}

void TestFontMetrics() {
  QFont font("Consolas", 10);

  QFontMetrics metrics(font);

  // horizontalAdvance: Introduced in Qt 5.11.
  QString text = "How many pixels wide is this text?";
  qInfo() << "Text width in pixels:" << metrics.width(text);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
  qInfo() << "Text width in pixels (horizontalAdvance):"
          << metrics.horizontalAdvance(text);
#endif

  qInfo() << "Text height in pixels:" << metrics.height();
}

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  TestFontCreation();
  qInfo() << "\n";

  TestFontDatabase();
  qInfo() << "\n";

  TestFontMetrics();

  return app.exec();
}
