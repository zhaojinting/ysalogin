#include "systemtrayglobal.h"

/**
 * 该类主要用于管理托盘对象，把托盘对象设置为公共变量，方便托盘管理：如气泡、启禁用菜单。
 */
QSystemTrayIcon *SystemTrayGlobal::g_sysTrayIcon = 0;

SystemTrayGlobal::SystemTrayGlobal()
{

}

void SystemTrayGlobal::setSystemTrayIcon(QSystemTrayIcon* sysTrayIcon) {
    g_sysTrayIcon = sysTrayIcon;
}

QSystemTrayIcon* SystemTrayGlobal::getSystemTrayIcon() {
    return g_sysTrayIcon;
}
