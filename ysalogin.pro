#-------------------------------------------------
#
# Project created by QtCreator 2024-03-30T11:10:26
#
#-------------------------------------------------
QT       += core gui network
QT       += sql
QT       += gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ysalogin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systemtray.cpp \
    traymenu.cpp \ 
    message.cpp \
    locklogin.cpp \
    settingdialog.cpp \
    protectprocess.cpp \
    systemtrayglobal.cpp \
    autostart.cpp \
    keypress.cpp \
    protecttaskmgr.cpp \
    httputil.cpp \
    database.cpp \
    settings.cpp \
    networkutil.cpp \
    orderdialog.cpp \
    confirmationialog.cpp \
    reminderthread.cpp \
    globalkeyeventfilter.cpp

HEADERS  += mainwindow.h \
    systemtray.h \
    traymenu.h \ 
    message.h \
    locklogin.h \
    settingdialog.h \
    protectprocess.h \
    systemtrayglobal.h \
    autostart.h \
    keypress.h \
    protecttaskmgr.h \
    httputil.h \
    database.h \
    settings.h \
    networkutil.h \
    orderdialog.h \
    confirmationialog.h \
    reminderthread.h \
    globalkeyeventfilter.h \
    localbit.h

FORMS    += mainwindow.ui \
    settingdialog.ui \
    orderdialog.ui \
    confirmationialog.ui

RESOURCES += \
    ysalogin.qrc

win32 {
    DESTDIR = $$PWD/../../bin/
    MOC_DIR = $$PWD/build_/moc
    RCC_DIR = $$PWD/build_/rcc
    OBJECTS_DIR = $$PWD/build_/obj
}

# import dll file
include($$PWD/../NConfig/NConfig_inc.pri)



