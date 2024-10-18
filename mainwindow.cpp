#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

#include <QMessageBox>
#include <QCloseEvent>

#include <QDebug>

#include "message.h"
#include <QScreen>

// 保护键盘
//#include "keypress.h"

#include "settingdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化自适应
    initResize();
    //登录界面
    lockLogin = new LockLogin(ui, this);
    //初始化配置文件
    initSettins();
    // 移除焦点
    setFocus();
    //系统托盘
    //systemTray = new SystemTray(ui);
    //菜单设置管理员为管理|员工
//    systemTray->setUser();

//    KeyPress *k= new KeyPress();
//    k->regHotKey(true);

}

MainWindow::~MainWindow()
{
    systemTray->onRelease();
    delete ui;
    delete lockLogin;
}

// 显示窗体
void MainWindow::showWindow()
{
    showNormal();
    raise();
    activateWindow();
}


// 窗口关闭时询问是否退出
void MainWindow::closeEvent(QCloseEvent *event)
{
    int result=message.confirm(QStringFromLocalOrUtf8("确定要退出本程序吗？"),this);

    if (result==QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::initResize() {
    QList<QScreen*> screen = QGuiApplication::screens();

    if(screen.size()>=1)
    {
        ui->frame->move((screen[0]->geometry().width()-ui->frame->width())/2,(screen[0]->geometry().height()-ui->frame->height())/2);
        ui->label_5->move((screen[0]->geometry().width()-ui->label_5->width())/2,(screen[0]->geometry().height()-100));
    }
}

// 当分辨率发生变化，触发该事件
void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << QStringFromLocalOrUtf8("分辨率发生变化啦！");
    initResize();
}

void MainWindow::initSettins() {
    //初始化数据库
    Database *d = new Database();
    //设置数据库全局变量
    Database::setDatabase(d);

    //判断数据库是否存在，不存在则创建
    if(!d->isDbExistAndCreated()) {
        qDebug() << QStringFromLocalOrUtf8("配置文件失败并自动创建，在此可以弹出配置窗口");
        confirmSettins();
    } else {
        //d->clearConfig();
        //如果存在是初始化参数
        s.initConfig();
        qDebug() << QString("qDebug output:%1").arg(s.getServers());
        if(s.getServers().isEmpty() || s.getInstrumentId().isEmpty()) {
            qDebug() << QStringFromLocalOrUtf8("没有获取到配置，在此可以弹出配置窗口");
            confirmSettins();
        } else {
            //初始化界面数据
            lockLogin->initWindowData();
        }
    }
}

void MainWindow::handleDialogAccept() {
    //配置窗口确认后，更新配置
    s.initConfig();
    //刷新界面数据
    lockLogin->initWindowData();
}

void MainWindow::confirmSettins()
{
    SettingDialog *sd = new SettingDialog(this);
    connect(sd, &QDialog::accepted, this, &MainWindow::handleDialogAccept);

    int result=message.confirm(QString::QStringFromLocalOrUtf8("软件尚未完成配置，请点击【确定】进入配置界面！"),this);
    if (result==QMessageBox::Yes)
    {
        sd->show();
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->page || watched == ui->page_2)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent *>(event);
            if (ke->key() == Qt::Key_Return || ke->key() == Qt::Key_Enter)
            {
                // 如果当前在Page1
                if (ui->stackedWidget->currentIndex() == 0 && watched == ui->page)
                {
                    // 触发Button1的点击事件
                    qDebug()<<"触发Button1的点击事件";
                    emit ui->loginButton->clicked();
                    return true;
                }
                // 如果当前在Page2
                else if (ui->stackedWidget->currentIndex() == 1 && watched == ui->page_2)
                {
                    // 触发Button2的点击事件
                    qDebug()<<"触发Button2的点击事件";
                    emit ui->dynamicLoginButton->clicked();
                    return true;
                }
            }
        }
    }
    return false;
}
