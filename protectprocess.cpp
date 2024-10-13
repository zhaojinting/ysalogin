#include "protectprocess.h"

char exepath[MAX_PATH];

/**
 * 进程保护
*/
ProtectProcess::ProtectProcess() {
    
}

ProtectProcess::~ProtectProcess() {

}

DWORD ProtectProcess::run() {
    setlocale(LC_ALL, "chs");

    DWORD pid = getTargetProcessId();
    if (pid == 0)
    {
        //printf("getTargetProcessId error code is %d\n", GetLastError());
        qDebug() << QString("getTargetProcessId error code is %1").arg(GetLastError());
        return 0;
    }
    return codeInject(pid);
}

DWORD WINAPI threadProc(LPVOID param)
{
    thread_param* tparam = (thread_param*)param;
    HMODULE hd = tparam->loadFunc(tparam->data[0]);//data的第一个参数是kernel32.dll
    lpWaitForSingleObject wfso = (lpWaitForSingleObject)tparam->GetPFunc(hd, tparam->data[2]);
    lpWinExec we = (lpWinExec)tparam->GetPFunc(hd, tparam->data[3]);
    lpOpenProcess op = (lpOpenProcess)tparam->GetPFunc(hd, tparam->data[4]);
    DWORD pid = tparam->PID;
    HANDLE hProcess = op(PROCESS_ALL_ACCESS, 0, pid);
    wfso(hProcess, INFINITE);
    we(tparam->data[1], SW_SHOW);
    return 0;
}

DWORD ProtectProcess::codeInject(DWORD pid)
{
    qDebug() << QString("pid code is %1").arg(pid);
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
    if (hProcess == 0 || hProcess == INVALID_HANDLE_VALUE)
    {
        qDebug() << QString("OpenProcess error code is %1").arg(GetLastError());
        return 0;
    }
    thread_param param = { 0 };
    param.loadFunc = (lpLoadLibraryA)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    param.GetPFunc = (lpGetProcAddress)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetProcAddress");
    memcpy(&param.data[0], "kernel32.dll", 13);
    GetModuleFileNameA(0, exepath, MAX_PATH);
    memcpy(&param.data[1], exepath, strlen(exepath) + 1);
    memcpy(&param.data[2], "WaitForSingleObject", 20);
    memcpy(&param.data[3], "WinExec", 8);
    memcpy(&param.data[4], "OpenProcess", 12);
    param.PID = GetCurrentProcessId();
    //DWORD codesize = (DWORD)codeInject - (DWORD)threadProc; //计算线程函数的代码大小
    LPVOID database = VirtualAllocEx(hProcess, 0, sizeof(thread_param), MEM_COMMIT, PAGE_READWRITE);
    SIZE_T written;
    HANDLE hThread;
    if (database == 0)
    {
        CloseHandle(hProcess);
        qDebug() << QString("CloseHandle1 error code is %1").arg(GetLastError());
        return 0;
    }
    WriteProcessMemory(hProcess, database, &param, sizeof(thread_param), &written);
    LPVOID codebase = VirtualAllocEx(hProcess, 0, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (codebase == 0)
    {
        VirtualFreeEx(hProcess, database, sizeof(thread_param), MEM_FREE);
        CloseHandle(hProcess);
        qDebug() << QString("CloseHandle2 error code is %1").arg(GetLastError());
        return 0;
    }
    WriteProcessMemory(hProcess, codebase, (LPCVOID)threadProc, 0x1000, &written);

    // 创建远程线程
    if ((hThread = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)codebase, database, 0, 0)) != 0)
    {
        VirtualFreeEx(hProcess, database, sizeof(thread_param), MEM_FREE);
        VirtualFreeEx(hProcess, codebase, 0x1000, MEM_FREE);
        CloseHandle(hThread);
        CloseHandle(hProcess);
        return 1;
    } else {
        qDebug() << QString("CreateRemoteThread error code is %1").arg(GetLastError());
    }
    VirtualFreeEx(hProcess, database, sizeof(thread_param), MEM_FREE);
    VirtualFreeEx(hProcess, codebase, 0x1000, MEM_FREE);
    CloseHandle(hProcess);
    return 0;
}

DWORD ProtectProcess::getTargetProcessId()
{
    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    DWORD result = Process32FirstW(snap, &pe32);
    if (result == 0)
    {
        return 0;
    }
    do
    {
        if (lstrcmpW(pe32.szExeFile, L"explorer.exe") == 0)
        {
            CloseHandle(snap);
            return pe32.th32ProcessID;
        }
    } while (Process32NextW(snap, &pe32));
    CloseHandle(snap);
    return 0;
}

QString ProtectProcess::getApplicationName()
{
    return QCoreApplication::applicationName() + ".exe";
}

QString ProtectProcess::getApplicationFilePath()
{
    return QCoreApplication::applicationFilePath();
}

QString ProtectProcess::getApplicationDllPath()
{
    return QCoreApplication::applicationDirPath() + "/Protect.dll";
}

qint64 ProtectProcess::getApplicationPid() {
    return QCoreApplication::applicationPid();
}
