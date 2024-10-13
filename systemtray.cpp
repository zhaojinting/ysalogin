#include "systemtray.h"

/**
 * 系统托盘实现类
*/
SystemTray::SystemTray(Ui::MainWindow * ui):
    exUI(ui)
{
    // 创建托盘图标对象
    m_sysTrayIcon = new QSystemTrayIcon(this);
    //存储到公共变量中，方便其它地方调用
    SystemTrayGlobal::setSystemTrayIcon(m_sysTrayIcon);
    // 设置托盘图标
    m_sysTrayIcon->setIcon(QIcon(":/res/images/1024.png"));

    // 设置悬浮提示文本
    m_sysTrayIcon->setToolTip(QStringFromLocalOrUtf8("仪器猫"));


}

SystemTray::~SystemTray()
{
    // 释放指针对象
    delete m_sysTrayIcon;
}

void SystemTray::setAdmin() {
    TrayMenu *trayMenu = new TrayMenu();
    trayMenu->setAdmin();
    // 设置系统托盘的上下文菜单
    m_sysTrayIcon->setContextMenu(trayMenu);
    // 显示托盘图标
    m_sysTrayIcon->show();
}

void SystemTray::setUser() {
    TrayMenu *trayMenu = new TrayMenu();
    trayMenu->setUser();
    // 设置系统托盘的上下文菜单
    m_sysTrayIcon->setContextMenu(trayMenu);
    // 显示托盘图标
    m_sysTrayIcon->show();
}

void SystemTray::setHaveAccess() {
    TrayMenu *trayMenu = new TrayMenu();
    trayMenu->haveAccess();
}

void SystemTray::onRelease(){
    // 释放指针对象
    delete m_sysTrayIcon;
}

void SystemTray::onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    //! 根据reason对象响应对应操作
    //! 需要对应的操作在对应模块中添加即可
    switch (reason)
    {
    case QSystemTrayIcon::Unknown: //未知原因
    {
        
        break;
    }
    case QSystemTrayIcon::Context: //系统托盘的上下文菜单请求
    {
        
        break;
    }
    case QSystemTrayIcon::DoubleClick: //双击系统托盘
    {
        
        break;
    }
    case QSystemTrayIcon::Trigger: //单击系统托盘
    {
        
        break;
    }
    case QSystemTrayIcon::MiddleClick: //鼠标中键点击系统托盘
    {
        
        break;
    }
    default:
        break;
    }
}

void SystemTray::showMessage(QString message) {
    m_sysTrayIcon->showMessage(QStringFromLocalOrUtf8("温馨提示"), message, QSystemTrayIcon::Information, 800);
}
