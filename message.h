#ifndef MESSAGE_H
#define MESSAGE_H

#include <QApplication>
#include <QMessageBox>
#include <QDesktopWidget>
#include "localbit.h"

/**
 * 处理各种消息窗口
*/
class Message
{
public:
    Message();
    ~Message();

    /**
     * 关于我们
    */
    void about(const QString& text, QWidget *parent);
    /**
     * 弹窗提醒
    */
    void alert(const QString& text);
    void alert(QWidget *parent, const QString &text);
    /**
     * 确认提醒
    */
    int confirm(const QString& text, QWidget *parent);

private:
    /**
     * 消息居中弹窗
    */
    int messageCenter(const QString& title,QMessageBox::Icon icon,const QString& text, QWidget *parent=nullptr);
};

#endif // MESSAGE_H
