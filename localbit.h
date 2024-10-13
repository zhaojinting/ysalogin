#ifndef MACRO_H
#define MACRO_H

#ifdef Q_OS_WIN
    #include <windows.h>
    #define QStringFromLocalOrUtf8(str) QString::fromUtf8(str)
#else
    #define QStringFromLocalOrUtf8(str) QString::fromLocal8Bit(str)
#endif

#endif // MACRO_H
