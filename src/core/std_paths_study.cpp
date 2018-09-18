#include <QStandardPaths>
#include <QDebug>  // for qInfo()

// Suppose the user name is "adam".

// NOTE:
// For `DataLocation` and `AppDataLocation`, an extra AppName part will be
// appended if with QCoreApplication (or QApplication).

void TestStdPaths() {
  qInfo() << "Home:"
          << QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
  // Home: "/home/adam" (Linux)
  // Home: "C:/Users/adam" (Windows)

  qInfo() << "Data:"
          << QStandardPaths::writableLocation(QStandardPaths::DataLocation);
  // Data: "/home/adam/.local/share" (Linux)
  // Data: "C:/Users/19003883/AppData/Local" (Windows)

  qInfo() << "AppData:"
          << QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
  // "TODO" (Linux)
  // "C:/Users/adam/AppData/Roaming" (Windows)

  qInfo() << "Config:"
          << QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
  // Config: "/home/adam/.config" (Linux)
  // Config: "C:/Users/19003883/AppData/Local" (Windows)

  qInfo() << "Download (displayName):"
          << QStandardPaths::displayName(QStandardPaths::DownloadLocation);
  // Download (displayName): "Download" (Linux)
  // Download (displayName): "Download" (Windows)
}

int main(int argc, char *argv[]) {
  TestStdPaths();

  return 0;
}
