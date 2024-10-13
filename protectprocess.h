#ifndef PROTECTPROCESS_H
#define PROTECTPROCESS_H

//#include <QThread>
#include <QString>
#include <QCoreApplication>
#include <QDebug>

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <TlHelp32.h>
#include <locale.h>

//声明需要用到的函数
typedef HMODULE(WINAPI* lpLoadLibraryA)(char* filename);
typedef FARPROC(WINAPI* lpGetProcAddress)(HMODULE hModule, char* funcName);
typedef UINT(
    WINAPI*
    lpWinExec)(
        IN LPCSTR lpCmdLine,
        IN UINT uCmdShow
        );

typedef DWORD(
    WINAPI*
    lpWaitForSingleObject)(
        IN HANDLE hHandle,
        IN DWORD dwMilliseconds
        );


typedef HANDLE(
    WINAPI*
    lpOpenProcess)(
        IN DWORD dwDesiredAccess,
        IN BOOL bInheritHandle,
        IN DWORD dwProcessId
        );


typedef struct _thread_param
{
    lpLoadLibraryA loadFunc;
    lpGetProcAddress GetPFunc;
    DWORD PID;//被保护的进程的进程id
    //char mutex[8];//保证只被注入一次
    //保存所有参数
    //在被注入进程中需要调用的函数:LoadLibrary,GetProcAddress,WaitForSimpleObject,WinExec
    //因此需要参数:被保护的进程路径,kernel32.dll ,WaitForSingleObject,WinExec,
    //OpenProcess(这3个作为GetProcAddress的参数) 共5个参数
    char data[5][100];
}thread_param;

class ProtectProcess
{
public:
    ProtectProcess();
    ~ProtectProcess();

    DWORD run();
private:
    //DWORD WINAPI threadProc(LPVOID param);
    /**
     * 远程注入
    */
    DWORD codeInject(DWORD pid);
    /**
     * 获取对象explorer.exe的pid
    */
    DWORD getTargetProcessId();
    /**
     * 获取当前进程exe名称
    */
    QString getApplicationName();
    /**
     * 获取当前进程路径
    */
    QString getApplicationFilePath();
    /**
     * 获取进程保护dll
    */
    QString getApplicationDllPath();
    /**
     * 获取当前进程id
    */
    qint64 getApplicationPid();
};

#endif // PROTECTPROCESS_H
