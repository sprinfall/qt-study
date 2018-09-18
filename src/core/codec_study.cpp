#include <iostream>

#include <QList>
#include <QTextCodec>

#include "common/utility.h"

int main() {
  QList<int> mibs = QTextCodec::availableMibs();

  std::cout << "Available MIBs: " << mibs.size() << std::endl;
  // 60 (e.g.)

  for (int mib : mibs) {
    QTextCodec* codec = QTextCodec::codecForMib(mib);

    QString name = codec->name();// .toUpper();

    std::cout << name << std::endl;
  }

  // UTF-8
  // ISO-8859-1
  // ISO-8859-15
  // UTF-32LE
  // UTF-32BE
  // UTF-32
  // UTF-16LE
  // UTF-16BE
  // UTF-16
  // System
  // Big5-HKSCS
  // Big5

  return 0;
}
