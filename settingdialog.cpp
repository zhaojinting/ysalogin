#include "settingdialog.h"
#include "ui_settingdialog.h"


#include <QGuiApplication>
#include <QScreen>




SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog),protectTaskmgr(new ProtectTaskmgr(this))
{

    ui->setupUi(this);

    // 注册 HWND 类型
    static int hwndMetaTypeId = qRegisterMetaType<HWND>("HWND");
    // 将窗口永远置于上层可见 不会被遮盖
	setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
	// 阻塞除当前窗口之外的所有窗口
	setWindowModality(Qt::ApplicationModal);
	// 去掉问号，只保留关闭
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	// 设置窗口标题
    setWindowTitle(QStringFromLocalOrUtf8("系统设置"));
    setWindowIcon(QIcon(":/res/images/1024.png"));
	// 设置窗口大小
	// resize(500,500);
	// 使窗口在屏幕中心显示
	QScreen *mScreen = QGuiApplication::screens().first();
	this->move((mScreen->geometry().width() - this->width()) / 2, (mScreen->geometry().height() - this->height()) / 2);

    // 默认值


    ui->radioButton1->setChecked(true);
    ui->urlEdit->setText("https://");
    ui->radioButton2->setEnabled(false);

    ui->radioButton2->setVisible(false);
    ui->ipEdit->setVisible(false);

    ui->serverToolButton->setStyleSheet("color: blue;");

    ui->instrumentToolButton->setCheckable(true);
    ui->otherToolButton->setCheckable(true);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QStringFromLocalOrUtf8("取消"));


    // 创建QTableWidget
    ui->tableWidget->setColumnCount(4);

    // 设置垂直表头模式为隐藏
    ui->tableWidget->verticalHeader()->setVisible(false);


    //初始化进程列表


    QStringList headerLabels;
    headerLabels << " " << QStringFromLocalOrUtf8("仪器名称") << QStringFromLocalOrUtf8("仪器编号") << QStringFromLocalOrUtf8("所属单位");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    // 设置一些表格样式
    ui->tableWidget->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#548AD5;border:none};height:38px");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setFixedHeight(30);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    //初始化设备列表信息；
    QTableWidgetItem* item = new QTableWidgetItem(QStringFromLocalOrUtf8("暂无数据"));
    ui->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单元格中
    //设置最后一列平铺整个空间
    ui->tableWidget->resizeColumnsToContents();
    int totalWidth = ui->tableWidget->verticalHeader()->width();
    for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
        totalWidth += ui->tableWidget->columnWidth(column);
    }

    int availableWidth = ui->tableWidget->viewport()->width() - totalWidth;
    if (availableWidth > 0) {
        ui->tableWidget->setColumnWidth(ui->tableWidget->columnCount() - 1, ui->tableWidget->columnWidth(ui->tableWidget->columnCount() - 1) + availableWidth);
    }

    step = 0;

    ui->pushButton->setVisible(false);
    //connect(ui->serverToolButton, &QPushButton::clicked, this, &SettingDialog::onServerToolButtonClicked);
    //connect(ui->instrumentToolButton, &QPushButton::clicked, this, &SettingDialog::onInstrumentToolButtonClicked);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingDialog::onButtonBoxClicked);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    //connect(ui->searchMachine, &QPushButton::clicked, this, &SettingDialog::onSearchMachineClicked);

    //connect(ui->testButton, &QPushButton::clicked, this, &SettingDialog::onButtonTestClicked);
    httpUtil=new HttpUtil();
    //初始化已经配置的数据
    initData();
}

SettingDialog::~SettingDialog()
{
    delete ui;
    delete protectTaskmgr;

}

void SettingDialog::onServerToolButtonClicked()
{

}

void SettingDialog::onInstrumentToolButtonClicked()
{
    if(Settings::getUrl().isEmpty()) {
        message.alert(this, QStringFromLocalOrUtf8("请先配置服务器"));
        return;
    }else{

    }
    ui->stackedWidget->setCurrentIndex(1);
    ui->instrumentToolButton->setStyleSheet("color: blue;");
    ui->serverToolButton->setStyleSheet("color: black;");


    ui->serverToolButton->setChecked(false);
    ui->otherToolButton->setChecked(false);


    //获取仪器默认选项
}

void SettingDialog::onButtonBoxClicked()
{
    QString url=ui->urlEdit->text();
    url=url+"/api/pc";
    QString ip=ui->ipEdit->text();
    QString tempserver;
    qDebug()<<"************************************************url="<<url;


    if(step==0){


        if(url.isEmpty() && ip.isEmpty()) {
            message.alert(this, QStringFromLocalOrUtf8("域名或IP地址不能够为空！"));
            return;
        }
        if(NetworkUtil::isDomainNameValid(url)==false) {
            message.alert(this, QStringFromLocalOrUtf8("无效域名！"));
            return;
        }
        bool islink = NetworkUtil::checkServer(ui->radioButton1->isChecked()?url:ip);
        if(!islink) {
            message.alert(this, QStringFromLocalOrUtf8("域名无法被请求，请检查URL设置"));
            return;
        }else{
            if(ui->radioButton1->isChecked())
            {
                server="url";
                tempserver=url;
            } else
            {
                server="ip";
                tempserver=ip;
            }

            // 域名有效则下一步；
            ui->stackedWidget->setCurrentIndex(1);
            ui->instrumentToolButton->setChecked(true);
            ui->serverToolButton->setChecked(false);
            ui->instrumentToolButton->setStyleSheet("color: blue;");
            ui->serverToolButton->setStyleSheet("color: black;");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
            ui->pushButton->setVisible(true);
            step = 1;
            //获取仪器
            getInstrumentList(tempserver);
        }


    } else if(step==1){
        // getInstrumentList(tempserver);
        int checkedId = buttonGroup->checkedId(); // 获取选中单选框的id
        qDebug()<<"checkedId"<<checkedId;

        QString instrumentId = map.value(checkedId);
        qDebug()<<"instrumentId"<<instrumentId;

        if(!instrumentId.isEmpty()) {

            if(checkedId==-1){
                qDebug()<<"请至少绑定一个仪器！";
                message.alert(this, QStringFromLocalOrUtf8("请至少绑定一个仪器！"));
                return;
            }else{
                QString mac=Settings::getMac();
                bool isBind=bindMachine(url,instrumentId,mac);
                if(isBind){
                    Database::getDatabase()->setConfig("url", url);
                    Database::getDatabase()->setConfig("ip", ip);
                    Database::getDatabase()->setConfig("server", server);
                    Database::getDatabase()->setConfig("mac", mac);
                    Database::getDatabase()->setConfig("instrumentId", instrumentId);

                    step=2;

                    ui->stackedWidget->setCurrentIndex(2);
                    ui->pushButton->setVisible(true);
                    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
                    ui->otherToolButton->setStyleSheet("color: blue;");
                    ui->instrumentToolButton->setStyleSheet("color: black;");

                    //message.alert(this, QStringFromLocalOrUtf8("初始化数据成功！"));
                    //accept();
                }else{
                    message.alert(this, QStringFromLocalOrUtf8("绑定设备失败！"));
                    ui->stackedWidget->setCurrentIndex(2);
                    ui->pushButton->setVisible(true);
                    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
                    ui->otherToolButton->setStyleSheet("color: blue;");
                    ui->instrumentToolButton->setStyleSheet("color: black;");
                    step=2;

                }


            }
        }

    }

    if (step == 2) {
            ui->stackedWidget->setCurrentIndex(2);
            ui->otherToolButton->setStyleSheet("color: blue;");
            ui->instrumentToolButton->setStyleSheet("color: black;");

            QString taskList=Database::getDatabase()->getConfig("taskList");
            ui->taskTextEdit->setPlainText(taskList);
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
            step = 3;
        } else if (step == 3) {
            QString taskList=ui->taskTextEdit->toPlainText().trimmed();
            qDebug() << "taskList="<<taskList;
            Database::getDatabase()->setConfig("taskList",taskList);
            accept(); // 关闭对话框
        }
}

void SettingDialog::onButtonTestClicked()
{
    QString url=ui->urlEdit->text();
    QString ip=ui->ipEdit->text();
    if(url.isEmpty() && ip.isEmpty()) {
        message.alert(this, QStringFromLocalOrUtf8("域名或IP地址不能够为空！"));
        return;
    }

    if(NetworkUtil::isDomainNameValid(url)==false) {
        message.alert(this, QStringFromLocalOrUtf8("无效域名！"));
        return;
    }

    bool islink = NetworkUtil::checkNetwork(ui->radioButton1->isChecked()?url:ip);
    if(islink==true) {
        message.alert(this, QStringFromLocalOrUtf8("连接成功！"));
    } else {
        message.alert(this, QStringFromLocalOrUtf8("连接失败！"));
    }
}

void SettingDialog::initData() {
    //读取配置文件，不要直接读数据库
    QString url = Settings::getUrl();
    QString ip = Settings::getIp();
    //获取mac
    QString mac=Settings::getMac();
    ui->urlEdit->setText(url);
    ui->ipEdit->setText(ip);
    //判断mac为空时，将mac存入配置文件
    if(mac.isEmpty()){
        QString tmpeMac=networkutil->getMac();
        Database::getDatabase()->setConfig("mac", tmpeMac);
        accept();
    }

}

void SettingDialog::getInstrumentList(QString input){
    qDebug() << "input=" << input;

    QString machineUrl = input + "/searchMachine";
    qDebug() << "machineUrl=" << machineUrl;
    QTableWidget* tableWidget = ui->tableWidget;
    QString keyword = ui->keyWord->text();
    QUrlQuery postData;
    postData.addQueryItem("keyword", keyword);
    postData.addQueryItem("page","1");
    postData.addQueryItem("pagesize","20");
    httpUtil->postAsyn(machineUrl, postData, [=](int status,int code, QString msg, QJsonObject result) {
        if (code == 1) {
            QJsonValue data = result.value("data");
            if (data.isObject()) {
                QJsonObject dataObject = data.toObject();
                QJsonArray itemsArray = dataObject["list"].toArray();
                initTableWidget(itemsArray,true);
                initDefaultMachine();



            }
        } else {
            ui->tableWidget->clearContents();  // 清除表格内的数据，但保留表头
            ui->tableWidget->setRowCount(1);  // 设置行数为1
            QTableWidgetItem* item = new QTableWidgetItem(QStringFromLocalOrUtf8("暂无数据"));
            ui->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单元格中
            // 调整表格大小以适应内容

        }
    });
}

void SettingDialog::initTableWidget(const QJsonArray& itemsArray, bool adjustTableSize) {

    QTableWidget* tableWidget = ui->tableWidget;

    // 设置行数和列数
    tableWidget->setRowCount(itemsArray.size());
    tableWidget->setColumnCount(4);


    // 创建QButtonGroup用于管理单选框
    buttonGroup = new QButtonGroup(tableWidget);
    for (int i = 0; i < itemsArray.size(); ++i) {
        QJsonObject itemObject = itemsArray[i].toObject();
        QString name = itemObject["name"].toString();
        QString number = itemObject["number"].toString();
        QString orgName = itemObject["org_name"].toString();
        QString adminIds = itemObject["admin_ids_text"].toString();

        QTableWidgetItem* nameItem = new QTableWidgetItem(name);
        QTableWidgetItem* orgNameItem = new QTableWidgetItem(orgName);
        QTableWidgetItem* adminIdsItem = new QTableWidgetItem(number);
        QRadioButton* radioButton = new QRadioButton();
        // 添加单选框到单元格
        tableWidget->setCellWidget(i, 0, radioButton);

        // 添加其他字段到对应的单元格
        tableWidget->setItem(i, 1, nameItem);
        tableWidget->setItem(i, 2, adminIdsItem);
        tableWidget->setItem(i, 3, orgNameItem);

        // 将单选框添加到按钮组
        map.insert(i, number);

        buttonGroup->addButton(radioButton, i);
    }

    // 处理单选框的选中状态
    QObject::connect(buttonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [tableWidget](int id) {
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            QWidget* widget = tableWidget->cellWidget(row, 0);
            QRadioButton* radioButton = qobject_cast<QRadioButton*>(widget);
            radioButton->setChecked(row == id);
        }
    });

    if(adjustTableSize){
        // 调整表格大小以适应内容
        tableWidget->resizeColumnsToContents();

        int totalWidth = tableWidget->verticalHeader()->width();
        for (int column = 0; column < tableWidget->columnCount(); ++column) {
            totalWidth += tableWidget->columnWidth(column);
        }

        int availableWidth = tableWidget->viewport()->width() - totalWidth;
        if (availableWidth > 0) {
            tableWidget->setColumnWidth(tableWidget->columnCount() - 1, tableWidget->columnWidth(tableWidget->columnCount() - 1) + availableWidth);
        }
    }

    tableWidget->resizeRowsToContents();
}

//绑定设备
bool SettingDialog::bindMachine(QString url,QString number,QString mac){
    QString bindMachineUrl=url+"/bindMachine";
    QUrlQuery postData;
    postData.addQueryItem("number", number);
    postData.addQueryItem("mac", mac);
    if(number.isEmpty() || mac.isEmpty()){
        message.alert(this, QStringFromLocalOrUtf8("绑定设备失败，获取信息异常"));
    }else{
        httpUtil->post(bindMachineUrl, postData,
                       [=](int status,int code, QString msg, QJsonObject result) {
            if (code==1) {

                isSuccess=true;

            }

        });

    }
    return isSuccess;

}
void SettingDialog::initDefaultMachine(){
    QString instrumentId=Settings::getInstrumentId();
    qDebug()<< "instrumentId="<< instrumentId;
    if(!instrumentId.isEmpty()){
        int defaultCheckedId = -1;
        QMapIterator<int, QString> i(map);
        qDebug()<< "map="<< map;
        while (i.hasNext()) {
            i.next();
            if(i.value() == instrumentId)
                defaultCheckedId = i.key();
        }
        // 如果找到对应的单选框，进行默认选中设置
        if(defaultCheckedId != -1) {
            QRadioButton *defaultCheckedButton = qobject_cast<QRadioButton*>(buttonGroup->button(defaultCheckedId));
            if(defaultCheckedButton != nullptr) {
                defaultCheckedButton->setChecked(true);
            }
        }
    }

}


void SettingDialog::on_pushButton_clicked()
{
    qDebug() << "step===="<<step;
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QStringFromLocalOrUtf8("下一步"));
    if(step==1){
        ui->stackedWidget->setCurrentIndex(0);
        ui->pushButton->setVisible(false);
        ui->serverToolButton->setStyleSheet("color: blue;");
        ui->instrumentToolButton->setStyleSheet("color: black;");

        step=0;
    }else{
        step=1;
        ui->pushButton->setVisible(true);
        ui->stackedWidget->setCurrentIndex(1);
        ui->instrumentToolButton->setStyleSheet("color: blue;");
        ui->otherToolButton->setStyleSheet("color: black;");

    }
//    ui->serverToolButton->setChecked(true);
//    ui->instrumentToolButton->setChecked(false);


}

void SettingDialog::on_searchMachine_clicked()
{
    qDebug() << "**********************";

    QString url=ui->urlEdit->text();
    url=url+"/api/pc";
    getInstrumentList(url);
}
