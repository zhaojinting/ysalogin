#include "keypress.h"
#pragma comment (lib, "User32.lib")

#include "protecttaskmgr.h"

KeyPress::KeyPress()
{

}

// 全局热键消息处理
LRESULT CALLBACK lowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKbs = (KBDLLHOOKSTRUCT*)lParam;
        if(
            (pKbs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL)& 0x8000 && GetAsyncKeyState(VK_SHIFT)&0x8000)|| //"Ctrl+Shift+Esc"
            (pKbs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) & 0x8000) || //"Ctrl+Esc"
            (pKbs->vkCode == VK_TAB && pKbs->flags & LLKHF_ALTDOWN )|| //"Alt+Tab"
            (pKbs->vkCode == VK_ESCAPE && pKbs->flags &LLKHF_ALTDOWN )|| //"Alt+Esc"
            (pKbs->vkCode == VK_LWIN || pKbs->vkCode == VK_RWIN )||	// "LWIN/RWIN"
            (pKbs->vkCode == VK_F4 && pKbs->flags & LLKHF_ALTDOWN )) //"Alt+F4"
        {
            return 1; // 阻止传递该消息
        }
        if((pKbs->vkCode == VK_DELETE && (GetKeyState(VK_CONTROL) & 0x8000) && (GetKeyState(VK_MENU) & 0x8000))) //"Ctrl+Alt+Delete"
        {
            ProtectTaskmgr *p =new ProtectTaskmgr();
            p->start();

            // 结束线程
//            p->wait();
//            delete p;
            return 1; // 阻止传递该消息
        }
    }
    return CallNextHookEx(0, nCode, wParam, lParam);
}

// 注册全局热键
void KeyPress::regHotKey(bool flag) {
    HHOOK hHook = NULL;
    // 注册全局热键
    if (flag)
    {
        // 安装钩子
        hHook = SetWindowsHookEx( WH_KEYBOARD_LL, lowLevelKeyboardProc, GetModuleHandle(NULL),0);
    }
    else
    {
        UnhookWindowsHookEx(hHook);
    }
}
