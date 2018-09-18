#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>

#include <QString>
#include <QTextStream>

// Print to stdout.
// Example: qStdOut() << "std out!";
QTextStream& qStdOut();

// Usage: std::cout << str;
inline std::ostream& operator<<(std::ostream& os, const QString& str) {
  return os << str.toStdString();
}

// Usage: std::wcout << str;
inline std::wostream& operator<<(std::wostream& os, const QString& str) {
  return os << str.toStdWString();
}

inline QString GetEnvString(const char* name) {
  return QString::fromLocal8Bit(qgetenv(name));
}

inline QString GetStudyDataDir() {
  return GetEnvString("QT_STUDY_DATA_DIR");
}

inline QString GetStudyDataFile(const QString& filename) {
  return GetStudyDataDir() + filename;
}

#endif  // UTILITY_H_
