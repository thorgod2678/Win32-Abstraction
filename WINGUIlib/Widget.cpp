#include "Widget.h"

Widget::Widget(int posx, int posy, int Hh, int Ww, LPCWSTR name, HWND parent, Widget* wid) {
    
  
    
    hwnd = CreateWindowExW(
        0, L"Static", name, WS_CHILD | WS_VISIBLE, posx, posy, Hh, Ww,
        parent, NULL, GetModuleHandleW(nullptr), wid
    );

    if (hwnd) {
        SubclassWindow();  // Register subclass to handle messages
        ShowWindow(hwnd, SW_SHOWDEFAULT);

        posX = posx;
        posY = posy;
        h = Hh;
        w = Ww;
    }
}

void Widget::SubclassWindow() {
    // Store the original window procedure
    oldProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WidgetProc)));
    // Store this Widget instance in GWLP_USERDATA
    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}

LRESULT CALLBACK Widget::WidgetProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Widget* pWidget = reinterpret_cast<Widget*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    

    // Call the original window procedure
    return CallWindowProc(pWidget ? pWidget->oldProc : DefWindowProc, hwnd, msg, wParam, lParam);
}

INFO Widget::GetInfo() {
    // Implement this function as needed
    INFO info;
    info.h = h;
    info.x = posX;
    info.y = posY;
    info.w = w;
    return info;
}


