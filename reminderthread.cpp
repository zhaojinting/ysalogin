#include "ReminderThread.h"

ReminderThread::ReminderThread(QObject *parent)
    : QThread(parent)
{
    m_targetTime = QDateTime();
}

void ReminderThread::setTargetTime(const QDateTime &targetTime)
{
    m_targetTime = targetTime;
}

void ReminderThread::run()
{
    qDebug()<<"start thred";
    // 计算第一次提醒的时间点
    QDateTime firstReminderTime = m_targetTime.addSecs(15 * 60);

    // 计算当前时间和第一次提醒时间的时间差
    int delay = QDateTime::currentDateTime().secsTo(firstReminderTime);
    if (delay > 0) {
        // 如果时间差大于 0，则延时启动线程
        QThread::sleep(delay);
    }

    // 循环触发提醒
    while (true) {
        // 发送提醒信号
        emit reminderTriggered();

        // 等待 15 分钟
        QThread::sleep(15 * 60);
    }
}

QDateTime ReminderThread::calculateNextReminderTime() const
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    if (currentDateTime >= m_targetTime) {
        return QDateTime(currentDateTime.date().addDays(1), m_targetTime.time().addSecs(-15 * 60));
    } else {
        return QDateTime(m_targetTime.date(), m_targetTime.time().addSecs(-15 * 60));
    }
}
