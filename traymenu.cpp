#include "TrayMenu.h"

#include "settingdialog.h"

TrayMenu::TrayMenu(QWidget *parent)
    : QMenu(parent)
{



}

TrayMenu::~TrayMenu()
{
}

void TrayMenu::setAdmin() {
    // 创建菜单项
    m_pSettingAction = new QAction(QIcon(":/res/images/setting"), QStringFromLocalOrUtf8("系统设置"), this);
    m_pOnAction = new QAction(QIcon(":/res/images/unlock"), QStringFromLocalOrUtf8("我要上机"), this);
    m_pOffAction = new QAction(QIcon(":/res/images/shutdown"), QStringFromLocalOrUtf8("我要下机"), this);
    m_pLockAction = new QAction(QIcon(":/res/images/lock"), QStringFromLocalOrUtf8("临时锁屏"), this);
    m_pAboutAction = new QAction(QIcon(":/res/images/about"), QStringFromLocalOrUtf8("关于我们"), this);
    m_pQuitAction = new QAction(QIcon(":/res/images/close"), QStringFromLocalOrUtf8("退出软件"), this);

    // 添加菜单项
    addAction(m_pSettingAction);
    addAction(m_pOnAction);
    addAction(m_pOffAction);
    addAction(m_pLockAction);
    addAction(m_pAboutAction);
    addAction(m_pQuitAction);

    // 连接操作信号
    connect(m_pSettingAction, &QAction::triggered, this, &TrayMenu::onSetting);
    connect(m_pOnAction, &QAction::triggered, this, &TrayMenu::on);
    connect(m_pOffAction, &QAction::triggered, this, &TrayMenu::off);
    connect(m_pLockAction, SIGNAL(triggered(bool)), this, SLOT(onShowWindow()));
    connect(m_pAboutAction, &QAction::triggered, this, &TrayMenu::onAbout);
    connect(m_pQuitAction, &QAction::triggered, this, &TrayMenu::closeWindow);
}

void TrayMenu::setUser() {
    // 创建菜单项
//    m_pOnAction = new QAction(QIcon(":/res/images/unlock"), QStringFromLocalOrUtf8("我要上机"), this);
    m_pOffAction = new QAction(QIcon(":/res/images/shutdown"), QStringFromLocalOrUtf8("我要下机"), this);
    m_pLockAction = new QAction(QIcon(":/res/images/lock"), QStringFromLocalOrUtf8("临时锁屏"), this);
    m_pAboutAction = new QAction(QIcon(":/res/images/about"), QStringFromLocalOrUtf8("关于我们"), this);

    // 添加菜单项
//    addAction(m_pOnAction);
    addAction(m_pOffAction);
    addAction(m_pLockAction);
    addAction(m_pAboutAction);
    // 连接操作信号
//    connect(m_pOnAction, &QAction::triggered, this, &TrayMenu::on);
    connect(m_pOffAction, &QAction::triggered, this, &TrayMenu::off);
    connect(m_pLockAction, SIGNAL(triggered(bool)), this, SLOT(showWindow()));
    connect(m_pAboutAction, &QAction::triggered, this, &TrayMenu::onAbout);
}

void TrayMenu::noAccess() {
    m_pOnAction->setDisabled(true);
    m_pOffAction->setDisabled(true);
}

void TrayMenu::noAccessW() {
    m_pOnAction->setDisabled(true);
    m_pOffAction->setDisabled(true);
    m_pQuitAction->setDisabled(true);
}

void TrayMenu::haveAccess() {
    m_pOnAction->setDisabled(false);
    m_pOffAction->setDisabled(false);
}

void TrayMenu::onSetting() {
    SettingDialog *settingDialog = new SettingDialog(this);
    settingDialog->show();
}

void TrayMenu::on() {
    OrderDialog *order=new OrderDialog();
    order->initOrder();
    order->show();
}

void TrayMenu::off() {
    Message message;
    int result=message.confirm(QStringFromLocalOrUtf8("确定要下机吗？"),this);

    if (result==QMessageBox::Yes)
    {
        getOff();
    }
}

void TrayMenu::onAbout() {
    message.about(QStringFromLocalOrUtf8("技术支持：广州仪速安电子科技有限公司"),this);
}

void TrayMenu::closeWindow() {
    QApplication* app;
    int result=message.confirm(QStringFromLocalOrUtf8("确定要退出本程序吗？"),this);

    if (result==QMessageBox::Yes) {
        app->exit(0);
    }
}

void TrayMenu::showMessage(QString message) {
    SystemTrayGlobal::getSystemTrayIcon()->showMessage(QStringFromLocalOrUtf8("温馨提示"), message, QSystemTrayIcon::Information, 800);
}
//下机操作
void TrayMenu::getOff(){
    QMap<QString, QString> parameters;
    QString isAdmin=Settings::getIsAdmin();
    qDebug()<< "type"<<isAdmin;

    if(isAdmin=="admin"){

        parameters["type"]="admin";
    }else{
        parameters["type"]=Settings::getType();

    }
    HttpUtil* httpUtil=new HttpUtil();
    QString orderUrl=Settings::getServers()+"/getOff";
    parameters["token"]=Settings::getToken();
    parameters["orderid"]=Settings::getOrderId();
    httpUtil->get(orderUrl, parameters,
                   [=]( int code, QString msg, QJsonObject result) {

        if (code==1) {

            showMessage(QStringFromLocalOrUtf8("下机成功"));
            m_pOffAction->setVisible(false);

        }else {
            showMessage(QStringFromLocalOrUtf8("下机失败"));

        }
    });


}

//临时锁屏函数；
void TrayMenu::onShowWindow()
{

    qDebug()<< "THIS is Test";
    //获取订单编号，存入临时订单号中；
    QString orderId=Settings::getOrderId();
    if(orderId.isEmpty()){
        showMessage(QStringFromLocalOrUtf8("获取订单失败，临时锁屏异常"));
       }else{
        Database::getDatabase()->setConfig("tempOrderId",orderId);
        this->close();
        Settings::getMainWindow()->show();
        qDebug()<< "THIS is Test"<< Settings::getTempOrderId();

    }


}

