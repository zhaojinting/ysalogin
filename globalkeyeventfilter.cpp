#include "globalkeyeventfilter.h"
#include <QDebug>

GlobalKeyEventFilter* GlobalKeyEventFilter::m_instance = nullptr;

GlobalKeyEventFilter::GlobalKeyEventFilter(QObject* parent)
    : QObject(parent),m_isCardInput(false)
{
    m_intervalTimerId =0;

}

GlobalKeyEventFilter* GlobalKeyEventFilter::instance()
{
    if (!m_instance) {
        m_instance = new GlobalKeyEventFilter();
    }
    return m_instance;
}

GlobalKeyEventFilter::~GlobalKeyEventFilter()
{
    m_instance = nullptr;
}

bool GlobalKeyEventFilter::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            if (m_isCardInput && !m_inputBuffer.isEmpty()) {
                qDebug() << "Card Data:" << m_inputBuffer;

                // 提取刷卡输入的卡号部分
                QString cardNumber = m_inputBuffer.mid(m_cardInputStartPosition, m_cardInputLength);
                qDebug() << "Card Number:" << cardNumber;

                if (!cardNumber.isEmpty()) {
                    // 在这里触发信号或执行相关操作，传递卡号参数
                    emit inputBufferUpdated(cardNumber);
                }

                m_inputBuffer.clear();
                m_isCardInput = false;
                stopIntervalTimer();
            }
        } else {
            QString text = keyEvent->text();
            if (!text.isEmpty() && text.at(0).isDigit()) {
                if (!m_isCardInput) {
                    qDebug() << "Time start" ;

                    startIntervalTimer();
                    m_inputBuffer.clear();
                    m_isCardInput = true;
                    m_cardInputStartPosition = m_inputBuffer.length();  // 记录刷卡输入的起始位置
                }
                m_inputBuffer.append(text);
            }
        }
        m_lastKeyPressTime = QTime::currentTime(); // 记录最后一次按键的时间
    } else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            m_lastKeyPressTime = QTime(); // 重置最后一次按键的时间
            stopIntervalTimer();
        }
    } else if (event->type() == QEvent::FocusOut) {
        // 处理焦点丢失的情况，例如切换到其他窗口
        clearInputBuffer();
        stopIntervalTimer();
        m_lastKeyPressTime = QTime(); // 重置最后一次按键的时间
    } else if (event->type() == QEvent::MouseMove || event->type() == QEvent::MouseButtonPress) {
        // 处理鼠标移动和按钮按下的情况，以防止误判为刷卡输入
        m_lastKeyPressTime = QTime::currentTime(); // 更新最后一次按键的时间
    } else if (event->type() == QEvent::Timer) {
        QTimerEvent* timerEvent = static_cast<QTimerEvent*>(event);
        if (timerEvent->timerId() == m_intervalTimerId) {
            QTime currentTime = QTime::currentTime();
            int elapsed = m_lastKeyPressTime.msecsTo(currentTime);
            if (elapsed >= m_cardInputInterval) {
                if (m_isCardInput && !m_inputBuffer.isEmpty()) {
                    clearInputBuffer();
                    stopIntervalTimer();
                }
            }
        }
    }

    return QObject::eventFilter(obj, event);
}
void GlobalKeyEventFilter::startIntervalTimer()
{
    if (m_intervalTimerId == 0) {
        m_intervalTimerId = startTimer(m_cardInputInterval);
    }
}

void GlobalKeyEventFilter::stopIntervalTimer()
{
    if (m_intervalTimerId != 0) {
        killTimer(m_intervalTimerId);
        m_intervalTimerId = 0;
    }
}

void GlobalKeyEventFilter::clearInputBuffer()
{
    m_inputBuffer.clear();
    m_isCardInput = false;
    m_lastKeyPressTime = QTime(); // 重置最后一次按键的时间
}
