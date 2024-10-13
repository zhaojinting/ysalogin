#include "protecttaskmgr.h"

#include"QDebug.h"

ProtectTaskmgr::ProtectTaskmgr()
{

}

void ProtectTaskmgr::run()
{
    DWORD processId = 0;
    while (!m_quit) {
        processId = getTaskmgrProcessId();
        if (processId != (DWORD)(-1)) {
            qDebug() << QString("processId = %1").arg(processId);
            killProcess(processId);
            m_quit = false;
            sleep(1);
        }
    }
}

DWORD ProtectTaskmgr::getTaskmgrProcessId()
{
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 processEntry = {0};
    processEntry.dwSize = sizeof(PROCESSENTRY32);
    BOOL bRet = Process32First(hProcessSnap, &processEntry);
    while (bRet)
    {
        if (!lstrcmpW(L"Taskmgr.exe", processEntry.szExeFile)||!lstrcmpW(L"taskmgr.exe", processEntry.szExeFile))
        {
            CloseHandle(hProcessSnap);
            return processEntry.th32ProcessID;
        }
        bRet = Process32Next(hProcessSnap, &processEntry);
    }
    CloseHandle(hProcessSnap);
    return (-1);
}

void ProtectTaskmgr::killProcess(DWORD processId)
{
    HANDLE hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,processId);
    TerminateProcess(hProcess,0);
    CloseHandle(hProcess);
}

