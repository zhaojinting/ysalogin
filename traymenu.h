#ifndef TrayMenu_H
#define TrayMenu_H

#include <QMenu>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httputil.h"

#include "message.h"
class MainWindow;   // 前置声明
#include "systemtrayglobal.h"

class TrayMenu: public QMenu
{
    Q_OBJECT

public:
    explicit TrayMenu(QWidget *parent = 0);
    ~TrayMenu();

    /**
     * 初始化管理员的菜单项
    */
    void setAdmin();
    /**
     * 初始化预约用户的菜单项
    */
   void setUser();


   void haveAccess();
public slots:
   void onShowWindow();
   //void closeEvent(QCloseEvent *event);



private:
    /**
     * 无权限访问
     */
    void noAccess();
    /**
     * 无权限访问
     */
    void noAccessW();

    /**
     * 系统设置
    */
    void onSetting();
    /**
     * 上机下机
     */
    void on();
    void off();
    /**
     * 关于我们
    */
    void onAbout();
    /**
     * 关闭应用程序
    */
    void closeWindow();
    /**
     * @brief showMessage
     * @param message
     * 托盘气泡，必须在m_sysTrayIcon->show();后调用
     */
    void showMessage(QString message);
    /**
     * 下机函数
    */
    void getOff();


    void showWindow();

private:
    Message message;
    QAction *m_pSettingAction;
    QAction *m_pOnAction;
    QAction *m_pOffAction;
    QAction *m_pLockAction;
    QAction *m_pAboutAction;
    QAction *m_pQuitAction;
};

#endif // TrayMenu_H
