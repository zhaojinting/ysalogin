#ifndef SYSTEMTRAYGLOBAL_H
#define SYSTEMTRAYGLOBAL_H

#include <QSystemTrayIcon>

class SystemTrayGlobal
{
public:
    SystemTrayGlobal();

    static void setSystemTrayIcon(QSystemTrayIcon* sysTrayIcon);
    static QSystemTrayIcon* getSystemTrayIcon();
private:
       static QSystemTrayIcon *g_sysTrayIcon; // 托盘图标对象
};

#endif // SYSTEMTRAYGLOBAL_H
