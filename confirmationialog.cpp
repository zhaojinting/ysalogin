#include "confirmationialog.h"
#include "ui_confirmationialog.h"

Confirmationialog::Confirmationialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirmationialog)
{
    ui->setupUi(this);

    // 将窗口永远置于上层可见 不会被遮盖
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    // 阻塞除当前窗口之外的所有窗口
    setWindowModality(Qt::ApplicationModal);
    // 去掉问号，只保留关闭
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    // 设置窗口标题
    setWindowTitle(QStringFromLocalOrUtf8("确认订单"));
}

Confirmationialog::~Confirmationialog()
{
    delete ui;
}
