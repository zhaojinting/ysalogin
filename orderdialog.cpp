#include "orderdialog.h"
#include "ui_orderdialog.h"

OrderDialog::OrderDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::OrderDialog)

{
    ui->setupUi(this);
    // 将窗口永远置于上层可见 不会被遮盖
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    // 阻塞除当前窗口之外的所有窗口
    setWindowModality(Qt::ApplicationModal);

    setWindowIcon(QIcon(":/res/images/1024.png"));

    // 去掉问号，只保留关闭
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    // 设置窗口标题
    setWindowTitle(QString::fromLocal8Bit("我的订单"));

    // 使窗口在屏幕中心显示
    QScreen *mScreen = QGuiApplication::screens().first();
    this->move((mScreen->geometry().width() - this->width()) / 2, (mScreen->geometry().height() - this->height()) / 2);


    // 创建QTableWidget
    ui->tableWidget->setColumnCount(8);

    // 设置垂直表头模式为隐藏
    ui->tableWidget->verticalHeader()->setVisible(false);


    QStringList headerLabels;
    // 设置表格的列标题
    headerLabels << QString::fromLocal8Bit("订单号") << QString::fromLocal8Bit("用户名") << QString::fromLocal8Bit("所在部门") << QString::fromLocal8Bit("课题名称") << QString::fromLocal8Bit("开始时间") << QString::fromLocal8Bit("结束时间")<< QString::fromLocal8Bit("上机类型") << QString::fromLocal8Bit("操作");
    // 设置一些表格样式
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:#548AD5;border:none};height:38px");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setFixedHeight(30);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
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

    TrayMenu* trayMenu=new TrayMenu(this);
    //trayMenu->haveAccess();
    httpUtil=new HttpUtil();


}

OrderDialog::~OrderDialog()
{
    delete ui;
}

void OrderDialog::on_pushButton_clicked()
{
    accept();

}

bool OrderDialog::initOrder(){
    //账号登录URL
    QString url=Settings::getServers()+"/getOrder";
    QString token=Settings::getToken();

    QMap<QString, QString> parameters;
    parameters["token"]=token;
    if(token.isEmpty()){
        ui->tableWidget->clearContents();  // 清除表格内的数据，但保留表头
        ui->tableWidget->setRowCount(1);  // 设置行数为1
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromLocal8Bit("数据异常，缺少token"));
        ui->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单

    }else{
        httpUtil->get(url, parameters,
                [=](int code, QString msg, QJsonObject result) {
            if(code==1){
                qDebug()<<"***********************************"<<msg;
                initTableWidget(result,true);

            }else{
                ui->tableWidget->clearContents();  // 清除表格内的数据，但保留表头
                ui->tableWidget->setRowCount(1);  // 设置行数为1
                QTableWidgetItem* item = new QTableWidgetItem(QString::fromLocal8Bit("数据异常"));
                ui->tableWidget->setItem(0, 0, item);  // 将"暂无数据"放置在第一行第一列的单元格中
            }

        });

    }
    return isOrder;
}

void OrderDialog::initTableWidget(const QJsonObject& jsonData, bool adjustTableSize) {

    QTableWidget* tableWidget = ui->tableWidget;
    QJsonObject data = jsonData["data"].toObject();
    QJsonArray syOrderArray = data["sy_order"].toArray();
    QJsonArray sjOrderArray = data["sj_order"].toArray();
    int rowCount = syOrderArray.size() + sjOrderArray.size();
    int columnCount=8;
    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(columnCount);
    if(rowCount>0){
        isOrder=true;
        QString label = QString::fromLocal8Bit("您当前有 %1 个订单，是否需要上机？").arg(rowCount);
        ui->label_2->setText(label);
    }
    int row = 0;

        // 遍历sy_order数组
        for (const QJsonValue& syOrderValue : syOrderArray) {
            QJsonObject syOrder = syOrderValue.toObject();

            // 从syOrder对象中获取数据
            QString orderid = syOrder["orderid"].toString();
            QString username = syOrder["username"].toString();
            QString orgName = syOrder["org_name"].toString();
            QString classgroupName = syOrder["classgroup_name"].toString();
            QString startTime = syOrder["start_time"].toString();
            QString endTime = syOrder["end_time"].toString();

            // 在表格的相应位置插入数据
            tableWidget->setItem(row, 0, new QTableWidgetItem(orderid));
            tableWidget->setItem(row, 1, new QTableWidgetItem(username));
            tableWidget->setItem(row, 2, new QTableWidgetItem(orgName));
            tableWidget->setItem(row, 3, new QTableWidgetItem(classgroupName));
            tableWidget->setItem(row, 4, new QTableWidgetItem(startTime));
            tableWidget->setItem(row, 5, new QTableWidgetItem(endTime));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromLocal8Bit("送样订单")));

            // 创建并设置按钮
            QPushButton* button = new QPushButton(QString::fromLocal8Bit("上机"));
            button->setProperty("orderid", orderid); // 将orderid作为按钮的自定义属性
            button->setProperty("endTime",endTime);
            button->setStyleSheet("*{padding:5px;color: rgb(136, 136, 136);border-radius: 3px;background-color: rgb(255, 255, 255);border: 1px solid gray;}QPushButton:hover{color: rgb(0, 85, 255);border: 1px solid blue;}QPushButton::checked {background-color: blue;border: 1px solid blue;color: rgb(255, 255, 255);}");
            connect(button, &QPushButton::clicked, [=]() {
                QString clickedOrderid = button->property("orderid").toString();
                QString clickEndTime=button->property("endTime").toString();
                QString token=Settings::getToken();

                this->operate(token,"sy_order",clickedOrderid,clickEndTime);
                // 在这里处理按钮点击事件，使用clickedOrderid作为参数
                qDebug() << "按钮点击：" << clickedOrderid;

            });

            // 在表格的最后一列插入按钮
            tableWidget->setCellWidget(row, columnCount - 1, button);

            row++;
        }

        // 遍历sj_order数组
        for (const QJsonValue& sjOrderValue : sjOrderArray) {
            QJsonObject sjOrder = sjOrderValue.toObject();
            // 从syOrder对象中获取数据
            QString orderid = sjOrder["orderid"].toString();
            QString username = sjOrder["username"].toString();
            QString orgName = sjOrder["org_name"].toString();
            QString startTime = sjOrder["start_time"].toString();
            QString endTime = sjOrder["end_time"].toString();
            QString classgroupName = sjOrder["classgroup_name"].toString();


            // 在表格的相应位置插入数据
            tableWidget->setItem(row, 0, new QTableWidgetItem(orderid));
            tableWidget->setItem(row, 1, new QTableWidgetItem(username));
            tableWidget->setItem(row, 2, new QTableWidgetItem(orgName));
            tableWidget->setItem(row, 3, new QTableWidgetItem(classgroupName));
            tableWidget->setItem(row, 4, new QTableWidgetItem(startTime));
            tableWidget->setItem(row, 5, new QTableWidgetItem(endTime));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromLocal8Bit("上机订单")));


            // 创建并设置按钮
            QPushButton* button = new QPushButton(QString::fromLocal8Bit("上机"));
            button->setProperty("endTime",endTime);
            button->setProperty("orderid", orderid); // 将orderid作为按钮的自定义属性
            button->setStyleSheet("*{color: rgb(136, 136, 136);border-radius: 3px;background-color: rgb(255, 255, 255);border: 1px solid gray;}QPushButton:hover{color: rgb(0, 85, 255);border: 1px solid blue;}QPushButton::checked {background-color: blue;border: 1px solid blue;color: rgb(255, 255, 255);}");
            connect(button, &QPushButton::clicked, [=]() {
                QString clickedOrderid = button->property("orderid").toString();
                QString token=Settings::getToken();
                QString clickEndTime=button->property("endTime").toString();
                this->operate(token,"sy_order",clickedOrderid,clickEndTime);
                // 在这里处理按钮点击事件，使用clickedOrderid作为参数
                qDebug() << "按钮点击：" << clickedOrderid;
            });

            // 在表格的最后一列插入按钮
            ui->tableWidget->setCellWidget(row, columnCount - 1, button);

            row++;
        }



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


//上机操作
void OrderDialog::operate(QString token,QString type,QString orderId,QString endTime){
    QString operateUrl=Settings::getServers()+"/operate";
    QMap<QString, QString> parameters;
    parameters["token"]=token;
    parameters["type"]=type;
    parameters["orderid"]=orderId;
    //上机操作
    httpUtil->get(operateUrl,parameters, [=](int code, QString msg, QJsonObject result) {
        if (code==1) {
            qDebug()<< "YES";
            SystemTrayGlobal::getSystemTrayIcon()->showMessage(QString::fromLocal8Bit("温馨提示"), msg, QSystemTrayIcon::Information, 800);
            this->hide();

            //操作托盘结束
            Settings::getMainWindow()->hide();
            Database::getDatabase()->setConfig("orderId",orderId);
            Database::getDatabase()->setConfig("type",type);

            QDateTime targetTime = QDateTime::fromString(endTime, "yyyy-MM-dd hh:mm");
            reminderThread.setTargetTime(targetTime);

            QObject::connect(&reminderThread, &ReminderThread::reminderTriggered, []() {
                SystemTrayGlobal::getSystemTrayIcon()->showMessage(QString::fromLocal8Bit("温馨提示"), QString::fromLocal8Bit("您的订单已经超时！"), QSystemTrayIcon::Information, 800);
                qDebug() << "Reminder triggered!";
            });

            reminderThread.start();

        }
        else {
            message.alert(this, QString::fromLocal8Bit("上机机失败！参数异常"));
            this->hide();
        }});


}


