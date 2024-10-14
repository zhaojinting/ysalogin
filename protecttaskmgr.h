#ifndef PROTECTTASKMGR_H
#define PROTECTTASKMGR_H


#include <QObject>
#include <QThread>
#include <QStringList>
#include <QList>

#include <windows.h>
#include <TlHelp32.h>

// 用于存储窗口信息的结构体
struct WindowInfo {
    HWND hwnd;
    QString title;
};

class ProtectTaskmgr : public QThread
{
    Q_OBJECT
public:
    explicit ProtectTaskmgr();
    void run();
    //返回桌面应用列表
    QList<WindowInfo> getWindowHandleList();
    //按列表名干死他
    void killProcessByList(QStringList items);
private:
    //获取task进程Id
    DWORD getTaskmgrProcessId();
    //按进程杀死
    void killProcess(DWORD processId);
private:
    bool m_quit = false;
};

#endif // PROTECTTASKMGR_H
