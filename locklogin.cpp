#include "locklogin.h"
#include <QSharedMemory>
/**
 * 登录控制界面
 *
*/
LockLogin::LockLogin(Ui::MainWindow * ui, QMainWindow* mainWindow):
    exUI(ui)
{
    m_mainWindow = mainWindow;
    Settings::setMainWindow(mainWindow);

    //更改鼠标形状
    exUI->qrCodeButton->setCursor(Qt::PointingHandCursor);
    exUI->loginButton->setCursor(Qt::PointingHandCursor);
    exUI->dynamicLoginButton->setCursor(Qt::PointingHandCursor);
    //默认隐藏二维码登录
    exUI->qcCodeFrame->hide();
    exUI->accountEdit->setFocus();
    //禁用二维码，不一定有网络
    exUI->qrCodeButton->setEnabled(false);

    //设置默认选项
    exUI->noticeButton->setChecked(true);
    exUI->accountLoginButton->setChecked(true);

    //公告管理
    exUI->noticeTitle->setText(QStringFromLocalOrUtf8("暂无公告"));
    exUI->contentNotice->setPlainText("");
    exUI->author->setText("");
    exUI->publishtime->setText("");

    //订单信息,清空列表
    exUI->tableWidget->setColumnCount(3);
    exUI->tableWidget->verticalHeader()->hide();
    // 设置列的调整模式为自动拉伸
    for (int i = 0; i < exUI->tableWidget->columnCount(); ++i) {
        exUI->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    }
    // 设置最后一列的调整模式为根据内容自动调整宽度
    exUI->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    // 设置行高自适应
    exUI->tableWidget->resizeRowsToContents();
    //设置tablewidget 的一些样式；
    exUI->tableWidget->setFrameStyle(QFrame::NoFrame);
    exUI->tableWidget->setShowGrid(false);
    exUI->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    exUI->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#548AD5;border:none};height:38px");
    exUI->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    exUI->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    exUI->tableWidget->horizontalHeader()->setFixedHeight(30);
    exUI->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    exUI->tableWidget->clearContents();  // 清除表格内的数据，但保留表头
    exUI->tableWidget->setRowCount(1);  // 设置行数为1
    QTableWidgetItem* item = new QTableWidgetItem(QStringFromLocalOrUtf8("暂无数据"));
    exUI->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单元格中

    exUI->ipLabel->setText("0.0.0.0");
    exUI->mcName->setText(QStringFromLocalOrUtf8("仪器名称：暂无"));
    exUI->mcNumber->setText(QStringFromLocalOrUtf8("仪器编号：暂无"));
    exUI->mcAdminIds->setText(QStringFromLocalOrUtf8("仪器管理员：暂无"));
    //*************************************************


    QMenu *menu = new QMenu;
    menu->setStyleSheet("color:rgb(255,255,255); background:rgba(255,255,255,20);");
    menu->setAttribute(Qt::WA_TranslucentBackground,true);
    menu->setAutoFillBackground(true);
    QAction *action_logout = new QAction(QStringFromLocalOrUtf8("注销"),this);
    QAction *action_reboot = new QAction(QStringFromLocalOrUtf8("重启"),this);
    QAction *action_suspend = new QAction(QStringFromLocalOrUtf8("待机"),this);
    //QAction *action_hibernate = new QAction("休眠",this);
    //QAction *action_lock = new QAction(QStringFromLocalOrUtf8("锁定"),this);
    menu->addAction(action_logout);
    menu->addAction(action_reboot);
    menu->addAction(action_suspend);
    //menu->addAction(action_hibernate);
    //menu->addAction(action_lock);
    exUI->pushButtonShutMenu->setMenu(menu);
    connect(action_logout,SIGNAL(triggered()),this,SLOT(logout()));
    connect(action_reboot,SIGNAL(triggered()),this,SLOT(reboot()));
    connect(action_suspend,SIGNAL(triggered()),this,SLOT(suspend()));
    //connect(action_hibernate,SIGNAL(triggered()),this,SLOT(hibernate()));
    //connect(action_lock,SIGNAL(triggered()),this,SLOT(lock()));

    QString sstyle = "QMenu { background:rgba(255,255,255,100); }"
                     "QMenu::item { background:rgba(255,255,255,100);}"
                     "QMenu::item:selected { background:rgba(255,255,255,100); }"
                     "QPushButton::menu-indicator { width:0px; }"
                     "QPushButton:focus { border:1px solid rgba(255,255,255,30); background-color:rgba(255,255,255,30); outline:none; }"
                     "QPushButton#pushButtonShutdown { border-image:url(:/res/images/shutdown.svg) }"
                     "QPushButton#pushButtonShutdown::hover { border-image:url(:/res/images/shutdown_hover.svg) }"
                     "QPushButton#pushButtonShutdown::focus { border-image:url(:/res/images/shutdown_hover.svg) }"
                     "QPushButton#pushButtonShutMenu { border-image:url(:/res/images/menu.svg) }"
                     "QPushButton#pushButtonShutMenu::hover { border-image:url(:/res/images/menu_hover.svg) }"
                     "QPushButton#pushButtonShutMenu::focus { border-image:url(:/res/images/menu_hover.svg) }"
                     "QLineEdit { background:rgba(255,255,255,10); border:5px solid rgba(255,255,255,10);}"
                     "QLineEdit::focus { background:rgba(255,255,255,255); }";
    m_mainWindow->setStyleSheet(sstyle);
    exUI->pushButtonShutdown->move(QApplication::desktop()->width() - 130, QApplication::desktop()->height() - 80);
    exUI->pushButtonShutMenu->move(exUI->pushButtonShutdown->x() + exUI->pushButtonShutdown->width()+10, exUI->pushButtonShutdown->y());
    //绑定事件
    setConnect();

    httpUtil=new HttpUtil();

    systemTray=new SystemTray(exUI);

}

void LockLogin::onAccountLoginButtonClicked()
{
    exUI->stackedWidget->setCurrentIndex(0);
    exUI->accountLoginButton->setChecked(true);
    exUI->dynamicButton->setChecked(false);
}

void LockLogin::onPushButtonClicked()
{
    if(exUI->qcCodeFrame->isHidden()) {
        exUI->qcCodeFrame->show();
        exUI->label_6->setText(QStringFromLocalOrUtf8("切换账号登录"));

        exUI->accountEdit->clearFocus();
        exUI->dynamicEdit->setFocus();
        exUI->qrCodeButton->setStyleSheet("QPushButton {border-image: url(:/res/images/login.png)};");
        //QIcon icon(":/res/images/login.png");
        //exUI->qrCodeButton->setIcon(icon);
        //exUI->qrCodeButton->setIconSize(icon.availableSizes().first());

        //操作二维码
        QUrlQuery postData;
        postData.addQueryItem("number", Settings::getInstrumentId());
        postData.addQueryItem("mac", Settings::getMac());
        QString qrCodeurl=Settings::getServers()+"/getLoginQrcode";
        httpUtil->post(qrCodeurl, postData,
                       [=](int status,int code, QString msg, QJsonObject result) {
                if(code==1){
                    //获取返回参数中的data对象
                    QJsonValue data=result.value("data");
                    if(data.isObject()){
                        QJsonObject dataObject = data.toObject();
                        // 获取"data"对象中的具体字段值
                        QString imageUrl=dataObject.value("url").toString();
                        if(imageUrl.isEmpty()){
                            message.alert(m_mainWindow, QStringFromLocalOrUtf8("二维码加载异常，请联系管理员！"));

                        }else{

                            httpUtil->getImage(imageUrl,
                                          [=](int statusCode, int code,QByteArray result) {

                                qDebug()<< "图片加载成功" << statusCode << "code=" << code;
                                if(statusCode==200){
                                    QPixmap pixmap;
                                    pixmap.loadFromData(result);

                                    // 获取 Label 的大小
                                    QSize labelSize = exUI->qcCodeLabel->size();

                                    // 缩放图片以适应 Label 的大小
                                    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                                    // 设置缩放后的图片到 Label 控件
                                    exUI->qcCodeLabel->setPixmap(scaledPixmap);
                                    qDebug()<< "图片加载成功"  << qrCodeurl;


                                }else{
                                    qDebug()<< "图片加载失败";
                                }


                            });


                        }

                    }

                }else {


            }

        });
    } else {
        exUI->qcCodeFrame->hide();
        exUI->label_6->setText(QStringFromLocalOrUtf8("切换扫码登录"));

        exUI->dynamicEdit->clearFocus();
        exUI->accountEdit->setFocus();
        exUI->qrCodeButton->setStyleSheet("QPushButton {border-image: url(:/res/images/wxlogin.png)};");

        //QIcon icon(":/res/images/wxlogin.png");
        //exUI->qrCodeButton->setIcon(icon);
        //exUI->qrCodeButton->setIconSize(icon.availableSizes().first());
    }
}

void LockLogin::onDynamicButtonClicked()
{
    exUI->stackedWidget->setCurrentIndex(1);
    exUI->accountLoginButton->setChecked(false);
    exUI->dynamicButton->setChecked(true);
}

void LockLogin::onNoticeButtonClicked()
{
    exUI->stackedWidget_2->setCurrentIndex(0);
    exUI->noticeButton->setChecked(true);
    exUI->makehButton->setChecked(false);
}

void LockLogin::onMakehButtonClicked()
{
   exUI->stackedWidget_2->setCurrentIndex(1);
   exUI->noticeButton->setChecked(false);
   exUI->makehButton->setChecked(true);
}

void LockLogin::onShutdownClicked()
{
//    int result=message.confirm(QStringFromLocalOrUtf8("点击【确定】将关闭电脑，您确定要进行关机操作吗？"));
//    if (result==QMessageBox::Yes) {
//        QProcess::startDetached("shutdown", QStringList() << "/s" << "/t" << "0");
//    }
    QApplication* app;
    app->exit(0);
}

void LockLogin::setConnect() {
    //账号登录界面切换
    connect(exUI->accountLoginButton, &QPushButton::clicked, this, &LockLogin::onAccountLoginButtonClicked);

    //动态密码登录界面切换
    connect(exUI->dynamicButton, &QPushButton::clicked, this, &LockLogin::onDynamicButtonClicked);
    //二维码登录界面切换
    connect(exUI->qrCodeButton, &QPushButton::clicked, this, &LockLogin::onPushButtonClicked);

    //公告界面切换
    connect(exUI->noticeButton, &QPushButton::clicked, this, &LockLogin::onNoticeButtonClicked);
    //预约界面切换
    connect(exUI->makehButton, &QPushButton::clicked, this, &LockLogin::onMakehButtonClicked);

    //绑定账号密码登录按钮时间事件
     connect(exUI->loginButton, &QPushButton::clicked, this, &LockLogin::on_loginButton_clicked);
     //绑定动态密码登录按钮事件
     connect(exUI->dynamicLoginButton, &QPushButton::clicked, this, &LockLogin::on_dynamicLoginButton_clicked);

    //关机事件
    connect(exUI->pushButtonShutdown, &QPushButton::clicked, this, &LockLogin::on_pushButtonShutdown_clicked);



    exUI->page->installEventFilter(m_mainWindow);
    exUI->page_2->installEventFilter(m_mainWindow);
}

void LockLogin::initWindowData()
{

    QString instrumentId = Settings::getInstrumentId();

    //初始化联网状态
    bool islink = NetworkUtil::checkNetwork(Settings::getServers());
    if(islink==true) {
        QString ip=getIp();
        exUI->qrCodeButton->setEnabled(true);
        exUI->netWork->setText(QStringFromLocalOrUtf8("■ 在线"));
        exUI->netWork->setStyleSheet("font-size: 8pt; color: rgb(112, 182, 3);");
        exUI->ipLabel->setText(ip);
        if(!instrumentId.isEmpty()) {
            // 一切准备就绪
            getInstrumentNotice(instrumentId);
            getInstrumentInfo(instrumentId);
            getInstrumentOrder(instrumentId);
        } else {
            message.alert(m_mainWindow, QStringFromLocalOrUtf8("参数异常"));
        }
    } else {
        //禁用二维码，没有网络图片显示不出来，影响用户体验
        exUI->qrCodeButton->setEnabled(false);
        exUI->netWork->setText(QStringFromLocalOrUtf8("离线"));
    }
    // 安装全局键盘事件过滤器
    GlobalKeyEventFilter* keyEventFilter = GlobalKeyEventFilter::instance();
    connect(keyEventFilter, &GlobalKeyEventFilter::inputBufferUpdated, this, &LockLogin::handleInputBufferUpdated);
    qApp->installEventFilter(keyEventFilter);



}
//槽函数
void LockLogin::handleInputBufferUpdated(const QString& inputBuffer)
{
    // 在这里处理更新的数据http://bk4.ilabeco.com/api/pc/loginByCard

    QString cardnum;
    QString loginUrl=Settings::getServers()+"/loginByCard";
    QString mac=Settings::getMac();
    QString number=Settings::getInstrumentId();
    for (int i = 0; i < inputBuffer.length(); i++) {
        if (i % 2 != 0) {
            cardnum += inputBuffer[i];
        }
    }
    QUrlQuery postData;
    postData.addQueryItem("cardnum", cardnum);
    postData.addQueryItem("number", number);
    postData.addQueryItem("mac", mac);
    httpUtil->post(loginUrl, postData,
                   [=](int status,int code, QString msg, QJsonObject result) {
        if(code==1){
            QJsonValue data=result.value("data");
            if(data.isObject()){
                QJsonObject dataObject = data.toObject();
                // 获取"data"对象中的具体字段值
                int isAdmin = dataObject.value("is_admin").toInt();
                QString token=dataObject.value("token").toString();
                Database::getDatabase()->setConfig("token", token);
                getOrderInfo(isAdmin);
            }

        }else {
            qDebug() << "Updated Input Buffer:" << cardnum;
            qDebug() << "Updated Input Buffer:++++" << mac;
            qDebug() << "Updated Input Buffer:+++++++" << number;
            message.alert(m_mainWindow, QStringFromLocalOrUtf8("刷卡登录失败，请联系管理员！"));

        }

    });

}


void LockLogin::getInstrumentNotice(QString number)
{
    QString url=Settings::getUrl()+"/mcNotice";
    QUrlQuery postData;
    postData.addQueryItem("number", number);
    //请求接口
    httpUtil->postAsyn(url, postData,
            [&](int status, int code, QString msg, QJsonObject result)
    {
        if(code==1){
            QJsonValue data=result.value("data");
            QJsonObject dataObject = data.toObject();
            QString title=dataObject.value("title").toString();
            QString content=dataObject.value("content").toString();
            QString publishtime=dataObject.value("publishtime").toString();
            QString author=dataObject.value("author").toString();
            //更新界面
            exUI->noticeTitle->setText(title);
            exUI->contentNotice->setPlainText(content);
            exUI->author->setText(author);
            exUI->publishtime->setText(publishtime);
        } else {
            exUI->noticeTitle->setText(QStringFromLocalOrUtf8("暂无公告"));
            exUI->contentNotice->setPlainText(QStringFromLocalOrUtf8("暂无公告"));
            exUI->publishtime->setText("");
            exUI->author->setText("");
        }
    });
}

void LockLogin::getInstrumentInfo(QString number)
{
    QString url=Settings::getUrl()+"/mcInfo";
    QUrlQuery postData;
    postData.addQueryItem("number", number);
    httpUtil->postAsyn(url, postData,
                    [&](int status, int code, QString msg, QJsonObject result)
    {
        if(code==1){
            QJsonValue data=result.value("data");
            QJsonObject dataObject = data.toObject();
            QString name=QStringFromLocalOrUtf8("仪器名称：");
            QString admin_ids=QStringFromLocalOrUtf8("仪器管理员：");
            QString number=QStringFromLocalOrUtf8("仪器编号：");
            name=name+dataObject.value("name").toString();
            admin_ids=admin_ids+dataObject.value("admin_ids").toString();
            number=number+dataObject.value("number").toString();
            //更新界面
            exUI->mcName->setText(name);
            exUI->mcNumber->setText(number);
            exUI->mcAdminIds->setText(admin_ids);
        }else{
            exUI->mcName->setText("");
            exUI->mcNumber->setText("");
            exUI->mcAdminIds->setText("");
        }
    });
}

void LockLogin::getInstrumentOrder(QString number)
{
    QString url=Settings::getUrl()+"/mcOrder";
    QUrlQuery postData;
    postData.addQueryItem("number", number);
    httpUtil->postAsyn(url, postData,
                    [&](int status, int code, QString msg, QJsonObject result)
    {
        if(code==1){
            // 获取 "data" 数组
            QJsonArray dataArray = result["data"].toArray();
            int rowCount = dataArray.size();
            qDebug() << "rowCount=" << rowCount;
            exUI->tableWidget->setRowCount(rowCount);
            // 循环遍历数据并设置到表格中
            for (int row = 0; row < rowCount; ++row) {
                QJsonObject dataObject = dataArray[row].toObject();

                // 获取数据项的值
                QString user = dataObject["user"].toString();
                QString time = dataObject["time"].toString();
                QString org_name = dataObject["org_name"].toString();
                QString tips = dataObject["tips"].toString();
                // 设置到对应的单元格
                exUI->tableWidget->setItem(row, 0, new QTableWidgetItem(user));
                exUI->tableWidget->setItem(row, 1, new QTableWidgetItem(org_name));
                exUI->tableWidget->setItem(row, 2, new QTableWidgetItem(time));
            }
        }else {
            exUI->tableWidget->clearContents();  // 清除表格内的数据，但保留表头
            exUI->tableWidget->setRowCount(1);  // 设置行数为1
            QTableWidgetItem* item = new QTableWidgetItem("暂无数据");
            exUI->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单元格中
        }
    });
}

//获取IP信息
QString LockLogin::getIp(){

    foreach (QHostAddress ptr , QNetworkInterface::allAddresses())
        {
            if(ptr.protocol() == QAbstractSocket::IPv4Protocol){// 获取ipv4地址
                if(!ptr.isLoopback()){  // 过滤本地回环127.0.0.1
                    qDebug() << "address: " <<ptr.toString()<< endl; // 在这里输出本地局域网ip
                    return ptr.toString();
                }
            }
        }

}
//账号登录按钮点击事件
void LockLogin::on_loginButton_clicked()
{
      //账号登录URL
      QString loginUrl=Settings::getServers()+"/loginbypw";
      QString account=exUI->accountEdit->text();
      QString password=exUI->passwordEdit->text();
      QUrlQuery postData;
      postData.addQueryItem("account", account);
      postData.addQueryItem("password", password);
      if(account.isEmpty() || password.isEmpty()){
           message.alert(m_mainWindow, QStringFromLocalOrUtf8("账号或密码不能为空！"));
           return;

      }else{
          httpUtil->post(loginUrl, postData,
                  [=](int status,int code, QString msg, QJsonObject result) {
              if(code==1){
                  //此处写登录之后的逻辑代码：如计时器等；
                  //获取返回参数中的data对象
                  QJsonValue data=result.value("data");
                  if(data.isObject()){


                      QJsonObject dataObject = data.toObject();
                      // 获取"data"对象中的具体字段值
                      int isAdmin = dataObject.value("is_admin").toInt();
                      QString token=dataObject.value("token").toString();
                      Database::getDatabase()->setConfig("token", token);
                      Database::getDatabase()->setUser(account,password);
                      getOrderInfo(isAdmin);


                  }

              }else{
                  //此处为本地登录代码，本地登录没有有可能，没办法请求订单，直接退出，进入托盘；
                  QString sysPassWord=Database::getDatabase()->getUser(account);
                  if(sysPassWord==password){
                      Database::getDatabase()->setConfig("isAdmin","admin");
                      Database::getDatabase()->setUser(account,password);
                      systemTray->setAdmin();
                      m_mainWindow->hide();


                  }else{
                      message.alert(m_mainWindow, QStringFromLocalOrUtf8("登录失败请联系管理员！"));

                  }
              }

          });

      }

}

//动态密码登录方式的按钮触发事件
void LockLogin::on_dynamicLoginButton_clicked()
{



        QString loginUrl=Settings::getServers()+"/loginByCode";
        QString dynamicEdit=exUI->dynamicEdit->text();
        QUrlQuery postData;
        postData.addQueryItem("code", dynamicEdit);
        if(dynamicEdit.isEmpty()){

            message.alert(m_mainWindow, QStringFromLocalOrUtf8("请输入动态密码！"));
            return;

        }else{
            httpUtil->post(loginUrl, postData,
                    [=](int status,int code, QString msg, QJsonObject result) {
                if(code==1){
                    QJsonValue data=result.value("data");
                    if(data.isObject()){
                        QJsonObject dataObject = data.toObject();
                        // 获取"data"对象中的具体字段值
                        int isAdmin = dataObject.value("is_admin").toInt();
                        QString token=dataObject.value("token").toString();
                        Database::getDatabase()->setConfig("token", token);
                        getOrderInfo(isAdmin);
                    }

                }else {

                    message.alert(m_mainWindow, QStringFromLocalOrUtf8("登录失败，请联系管理员！"));

                }

            });

        }
}
void LockLogin::getOrderInfo(int isAdmin){
    //此处可能要加入是否为临时锁屏重新登录的；
    QString tempOrderId=Settings::getTempOrderId();
    qDebug()<<"******************isAdmin******"<<tempOrderId;

    //当为空时，代表是正式登录；
    if(tempOrderId.isEmpty()){
        //如果是管理员将用户名密码存入；
        if(isAdmin==1){
            qDebug()<<"******************isAdmin******"<<isAdmin;
            systemTray->setAdmin();
            //systemTray->setHaveAccess();
            Database::getDatabase()->setConfig("isAdmin","admin");
        }else{
            systemTray->setUser();
        }
        OrderDialog *order=new OrderDialog();
        bool isOrder=order->initOrder();
        qDebug()<< "isorder="<< isOrder;
        if(isOrder){
            order->show();

        }else{
            if(isAdmin==1){
                message.alert(m_mainWindow, QStringFromLocalOrUtf8("当前没有任何订单"));
                m_mainWindow->hide();
                TrayMenu *trayMenu = new TrayMenu();
                trayMenu->setAdmin();

            }else{
                message.alert(m_mainWindow, QStringFromLocalOrUtf8("当前没有任何订单"));
            }

        }
    }else{

        //有值的情况下，不显示选择订单界面.并且清空临时订单值；
        Database::getDatabase()->setConfig("tempOrderId","");
        Settings::getMainWindow()->hide();

    }

}

void LockLogin::on_pushButtonShutdown_clicked(){
    QProcess *process=new QProcess;

    process->start("shutdown -s -t 0");
    process->waitForFinished();

}

void LockLogin::logout()
{
    QProcess *process=new QProcess;

    process->start("shutdown -l");
    process->waitForFinished();

}

void LockLogin::reboot()
{
    QProcess *process=new QProcess;

    process->start("shutdown -r");
    process->waitForFinished();

}

void LockLogin::suspend()
{
    QProcess *process=new QProcess;

    process->start("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
    process->waitForFinished();


}



