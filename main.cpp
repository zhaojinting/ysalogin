#include "mainwindow.h"
#include "reminderthread.h"
#include <QSharedMemory>
// #include <QApplication>
// #include <windows.h>

#include "protectprocess.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置统一的字体
    QFont font("微软雅黑", 10);
    a.setFont(font);

    // 打开进程互斥锁，即只能够运行一个软件
    HANDLE hMutex = CreateMutex(nullptr, TRUE, (LPCWSTR)qApp->applicationName().toStdWString().c_str());
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        QMessageBox::warning(nullptr, "Error", "An instance of the application is already running.");
        CloseHandle(hMutex);
        hMutex = NULL;
        return 1;
    }

    // 在此处写你的应用程序逻辑代码
    MainWindow w;
    w.show();
    //程序启动就全屏显示
    w.showFullScreen();
    // 去除状态栏
    w.setStatusBar(nullptr);
    // 去除菜单栏
    w.setMenuBar(nullptr);
    // 去除工具栏
    w.setToolTip(nullptr);
    a.exec();

     // 窗口置顶
     w.setWindowFlags( w.windowFlags() | Qt::WindowStaysOnTopHint);
     //完成后关闭互斥锁
     CloseHandle(hMutex);
     hMutex = NULL;

//    ProtectProcess *p = new ProtectProcess();
//    p->run();

     // 创建 WorkerThread 对象
}
