#include "protecttaskmgr.h"

#include"QDebug.h"

// 回调函数，用于枚举窗口
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    // 获取窗口标题
    TCHAR title[256];
    GetWindowText(hwnd, title, sizeof(title) / sizeof(TCHAR));

    // 检查窗口是否可见且是顶级窗口
    if (IsWindowVisible(hwnd) && !IsIconic(hwnd) && title[0] != '\0' && QString::fromWCharArray(title) != "仪器猫") {
        // 将窗口信息添加到列表
        QList<WindowInfo>* windowList = reinterpret_cast<QList<WindowInfo>*>(lParam);
        windowList->append({ hwnd, QString::fromWCharArray(title) });
    }
    return TRUE; // 继续枚举
}

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

void ProtectTaskmgr::killProcessByList(QStringList items) {
    QList<WindowInfo> windows;
    // 枚举所有窗口
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&windows));

    // 输出找到的窗口信息
    for (const auto& window : windows) {
        // qDebug() << "窗口句柄:" << window.hwnd << ", 窗口标题:" << window.title;
        for(int i=0; i<items.length(); i++) {
            if(window.title==items.at(i)) {
                CloseWindow(window.hwnd);
            }
        }
    }
}

QList<WindowInfo> ProtectTaskmgr::getWindowHandleList() {
    QList<WindowInfo> windows;
    // 枚举所有窗口
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&windows));
    return windows;
}

