#ifndef PROTECTTASKMGR_H
#define PROTECTTASKMGR_H


#include <QObject>
#include <QThread>

#include <windows.h>
#include <TlHelp32.h>

class ProtectTaskmgr : public QThread
{
    Q_OBJECT
public:
    explicit ProtectTaskmgr();
    void run();
private:
    DWORD getTaskmgrProcessId();
    void killProcess(DWORD processId);
private:
    bool m_quit = false;
};

#endif // PROTECTTASKMGR_H
