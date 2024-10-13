#include "autostart.h"

/**
 * 自动启动
 */
AutoStart::AutoStart()
{

}

void AutoStart::setEnable()
{
    QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    auto application_name = QApplication::applicationName();
    auto path = settings->value(application_name).toString();
    QString appPath = QApplication::applicationFilePath();
    QString newPath = QDir::toNativeSeparators(appPath);
    if (path != newPath) {
        settings->setValue(application_name, newPath);
    }
    delete settings;
}
