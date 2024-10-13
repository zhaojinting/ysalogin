#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMapIterator>
#include <QRadioButton>
#include <QTableWidget>
#include <QJsonArray>
#include <QMapIterator>
#include "message.h"
#include "database.h"
#include "networkutil.h"
#include "settings.h"
#include "httputil.h"
#include "networkutil.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SettingDialog *ui;
    Message message;
    HttpUtil *httpUtil;
    NetworkUtil *networkutil;
    QButtonGroup* buttonGroup; // 管理单选框的按钮组
    QMap<int, QString> map; // 用于关联按钮的id和隐藏值
    bool isSuccess=false;
    QString server;

    // 步骤
    int step =0;
private:
    //服务设置切换
    void onServerToolButtonClicked();
    //网络设置切换
    void onInstrumentToolButtonClicked();
    //确定按钮事情
    void onButtonBoxClicked();
    //测试链接
    void onButtonTestClicked();
    //初始化已经配置的数据
    void initData();
    //获取仪器列表
    void getInstrumentList(QString input);
    //获取仪器数据
    void initTableWidget(const QJsonArray& itemsArray, bool adjustTableSize);
    //绑定设备
    bool bindMachine(QString url,QString number,QString mac);
    //获取单选框默认值
    void initDefaultMachine();

};

#endif // SETTINGDIALOG_H
