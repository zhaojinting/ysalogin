#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include <QScreen>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include "systemtray.h"
#include "httputil.h"
#include "mainwindow.h"
#include "locklogin.h"
#include "database.h"
#include "reminderthread.h"
#include "traymenu.h"

namespace Ui {
class OrderDialog;


}

class OrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDialog(QWidget *parent = 0);
    ~OrderDialog();
    bool initOrder();
    bool isOrder=false;
    SystemTray* systemTray;
    ReminderThread reminderThread;





private slots:
    void on_pushButton_clicked();
    //初始化数据

    void initTableWidget(const QJsonObject& itemsArray, bool adjustTableSize);

    /**
     * 上机操作
     */
    void operate(QString token,QString type,QString orderId,QString endTime);
signals:
    void haveAccess();

private:
    Ui::OrderDialog *ui;
    HttpUtil *httpUtil;
    Message message;






};

#endif // ORDERDIALOG_H
