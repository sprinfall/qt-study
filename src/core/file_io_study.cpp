#include <QFile>

#include "common/utility.h"

void TestReadFile() {
  // The QIODevice::Text flag passed to open() tells Qt to convert Windows-style
  // line terminators ("\r\n") into C++-style terminators ("\n").
  QFile file(GetStudyDataFile("remember.txt"));
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }

  std::cout << "size: " << file.size() << std::endl;

  // Read file line by line.
  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    qStdOut() << line;
  }

  // Or read all at once.
//  QByteArray all = file.readAll();
}

void TestReadFile_TextStream() {
  QFile file(GetStudyDataFile("remember.txt"));
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }

  QTextStream in(&file);
  // Set codec by setCodec() or use system default locale.

  // Read file line by line.
  while (!in.atEnd()) {
    // QTextStream takes care of converting the 8-bit data stored on disk into
    // a 16-bit Unicode QString.
    QString line = in.readLine();
    qStdOut() << line << "\n";
  }
}

void TestReadFile_BinaryMode() {
  QFile file(GetStudyDataFile("remember.txt"));

  // No QIODevice::Text flag.
  if (!file.open(QIODevice::ReadOnly)) {
    return;
  }

  std::cout << "size: " << file.size() << std::endl;

  QByteArray all = file.readAll();
  qStdOut() << all;
}

int main(int argc, char *argv[]) {
  std::cout << "QT_STUDY_DATA_DIR: " << GetStudyDataDir() << std::endl;

  //TestReadFile();
  //TestReadFile_TextStream();
  TestReadFile_BinaryMode();

  return 0;
}
