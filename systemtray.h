#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QObject>
#include <QSystemTrayIcon>

#include "mainwindow.h"
#include "ui_mainwindow.h"
class MainWindow;   // 前置声明

#include "message.h"
#include "traymenu.h"
#include "systemtrayglobal.h"

class SystemTray : public QObject
{
    Q_OBJECT
public:
    explicit SystemTray(Ui::MainWindow * ui);
    ~SystemTray();

    Ui::MainWindow* exUI;
private:
    Message message;
    QSystemTrayIcon *m_sysTrayIcon; // 托盘图标对象

private slots:
    /**
     * @brief on_systemTrayActivated 托盘图标响应槽函数
     * @param reason 响应操作（支持单击，双击，右键，滚轮按下等）
     */
    void onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason);

signals:

public slots:
    /**
     * 初始化管理员的菜单项
    */
    void setAdmin();
    /**
     * 初始化预约用户的菜单项
    */
   void setUser();
    /**
     * 释放托盘
    */
   void onRelease();
   /**
    * @brief showMessage
    * @param message
    * 托盘气泡，必须在m_sysTrayIcon->show();后调用
    */
   void showMessage(QString message);

   void setHaveAccess();
};

#endif // SYSTEMTRAY_H
