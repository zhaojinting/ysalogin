#ifndef LOCKLOGIN_H
#define LOCKLOGIN_H

#include <QObject>
#include <QProcess>
#include <QJsonArray>

#include <QStandardPaths>
#include <QDesktopWidget>
#include <QProcess>
#include <QPainter>
#include <QMenu>
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "message.h"
#include "settings.h"
#include "networkutil.h"
#include "httputil.h"
#include "orderdialog.h"
#include "globalkeyeventfilter.h"
class MainWindow;   // 前置声明

class LockLogin : public QObject
{
    Q_OBJECT
public:
    explicit LockLogin(Ui::MainWindow * ui,QMainWindow* mainWindow);
    Ui::MainWindow* exUI;
    QMainWindow *m_mainWindow;
    Message message;
    HttpUtil *httpUtil;
    SystemTray* systemTray;






public:
    /**
     * 初始化操作界面
     */
    void initWindowData();
private:
    /**
     * 账号登录界面切换
     */
    void onAccountLoginButtonClicked();
    /**
     * 动态密码登录界面切换
     */
    void onDynamicButtonClicked();
    /**
     * 二维码登录界面切换
     */
    void onPushButtonClicked();
    /**
     * 公告界面切换
     */
    void onNoticeButtonClicked();
    /**
     * 预约信息界面切换
     */
    void onMakehButtonClicked();
    /**
     * 关机按钮
     */
    void onShutdownClicked();
    /**
     * 绑定事件
     */
    void setConnect();
    /**
     * 获取仪器公告
     */
    void getInstrumentNotice(QString number);
    /**
     * 获取仪器基础信息
     */
    void getInstrumentInfo(QString number);
    /**
     * 获取仪器订单信息
     */
    void getInstrumentOrder(QString number);
    /**
     * 获取IP
     */
    QString getIp();
    /**
     * 登录按钮绑定事件
     */
    void on_loginButton_clicked();

    /**
     * 动态登录按钮绑定事件
     */
    void on_dynamicLoginButton_clicked();

    void getOrderInfo(int isAdmin);

    //void hibernate();
    //void lock();

private slots:

    void on_pushButtonShutdown_clicked();
    void logout();
    void reboot();
    void suspend();
    void handleInputBufferUpdated(const QString& inputBuffer);



};

#endif // LOCKLOGIN_H
