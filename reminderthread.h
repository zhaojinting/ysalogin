#ifndef REMINDERTHREAD_H
#define REMINDERTHREAD_H

#include <QThread>
#include <QDateTime>
#include <QDebug>

class ReminderThread : public QThread
{
    Q_OBJECT

public:
    explicit ReminderThread(QObject *parent = nullptr);

    void setTargetTime(const QDateTime &targetTime);

signals:
    void reminderTriggered();

protected:
    void run() override;

private:
    QDateTime calculateNextReminderTime() const;

    QDateTime m_targetTime;
};

#endif // REMINDERTHREAD_H
