#include "mainwindow.h"
#include "reminderthread.h"
#include <QSharedMemory>
// #include <QApplication>
// #include <windows.h>

#include "protectprocess.h"
#include "protecttaskmgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //进程保护
//    ProtectProcess *p = new ProtectProcess();
//    p->run();

    //其它桌面上其它应用
    ProtectTaskmgr *c = new ProtectTaskmgr();
    c->getWindowHandleList();

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
    w.setWindowIcon(QIcon(":/res/images/1024.png"));
    // 设置窗口标题
    w.setWindowTitle(QStringFromLocalOrUtf8("仪器猫"));
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
}
