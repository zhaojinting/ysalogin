#ifndef GLOBALKEYEVENTFILTER_H
#define GLOBALKEYEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QTime>
class GlobalKeyEventFilter : public QObject
{
    Q_OBJECT

public:
    static GlobalKeyEventFilter* instance();
    ~GlobalKeyEventFilter();
signals:
    void inputBufferUpdated(const QString& inputBuffer);



protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    static GlobalKeyEventFilter* m_instance;
    GlobalKeyEventFilter(QObject* parent = nullptr);
    QString extractCardNumber(const QString& input);
    void startIntervalTimer();
    void clearInputBuffer();
    void stopIntervalTimer();

    QString m_inputBuffer;
    bool m_isCardInput;
    bool m_isCardInputInProgress; // 新增标志位
    QTime m_lastKeyPressTime; // 记录最后一次按键的时间
    int m_intervalTimerId; // 定时器ID
    int m_cardInputInterval=300; // 刷卡输入的时间间隔阈值
    int m_cardInputLength=20;
    int m_cardInputStartPosition;
};

#endif // GLOBALKEYEVENTFILTER_H
