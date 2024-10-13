#include "message.h"

/**
 * 专业处理消息
*/
Message::Message()
{

}

Message::~Message()
{

}

void Message::about(const QString& text, QWidget *parent)
{
    messageCenter(QStringFromLocalOrUtf8("关于我们"),QMessageBox::Warning,text,parent);
}

void Message::alert(const QString& text)
{
    messageCenter(QStringFromLocalOrUtf8("提示"),QMessageBox::Warning,text);
}

void Message::alert(QWidget *parent, const QString &text)
{
    QMessageBox::warning(parent, QStringFromLocalOrUtf8("提示"), text, QStringFromLocalOrUtf8("取消"));
}

int Message::confirm(const QString& text, QWidget *parent)
{
    return messageCenter(QStringFromLocalOrUtf8("确认"),QMessageBox::Question,text,parent);
}

int Message::messageCenter(const QString& title,QMessageBox::Icon icon,const QString& text, QWidget *parent)
{
    QMessageBox messageBox;
    QApplication::setQuitOnLastWindowClosed(false);
    messageBox.setWindowTitle(title);
    messageBox.setIcon(icon);
    messageBox.setText(text);
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setButtonText(QMessageBox::Yes, QStringFromLocalOrUtf8("确定"));
    messageBox.setButtonText(QMessageBox::No, QStringFromLocalOrUtf8("取消"));

    // 获取屏幕的几何信息
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    // 计算弹窗的中心位置
    int x = (screenWidth - messageBox.width()) / 2;
    int y = (screenHeight - messageBox.height()) / 2;

    int result = messageBox.exec();
    // 设置弹窗的位置
    messageBox.move(x, y);
    return result;
}
