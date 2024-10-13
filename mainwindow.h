#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "localbit.h"

 // 系统托盘前置声明
#include "systemtray.h"
class SystemTray;

//系统配置文件
#include "database.h"
#include "settings.h"

#include "locklogin.h"
class LockLogin;



class LockLogin;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showWindow();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::MainWindow *ui;
    LockLogin* lockLogin;
    SystemTray* systemTray;
    Settings s;
    Message message;

private:
    void closeEvent(QCloseEvent *event);
    void initResize();
    void resizeEvent(QResizeEvent * event);
    /**
     * 初始化参数
     */
    void initSettins();
    void handleDialogAccept();
    /**
     * 是否需要配置
     */
    void confirmSettins();

};

#endif // MAINWINDOW_H
