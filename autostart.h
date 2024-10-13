#ifndef AUTOSTART_H
#define AUTOSTART_H

#include <QApplication>
#include <QSettings>
#include <QDir>

class AutoStart
{
public:
    AutoStart();
    /**
     * 开机自动启动
     */
    void setEnable();
};

#endif // AUTOSTART_H
