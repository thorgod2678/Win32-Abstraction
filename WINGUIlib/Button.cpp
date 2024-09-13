#include "Button.h"


Button::Button(int posx, int posy, int Hh, int Ww, LPCWSTR name, HWND parent, Button* wid) : Widget(posX, posY, h, w, name, parent, wid) {



    hwnd = CreateWindowExW(
        0, L"Button", name, WS_CHILD | WS_VISIBLE, posx, posy, Hh, Ww,
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

void Button::SubclassWindow() {
    oldProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(ButtonProc)));
    // Store this Widget instance in GWLP_USERDATA
    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}


LRESULT CALLBACK Button::ButtonProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Widget* pWidget = reinterpret_cast<Widget*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (pWidget) {

        if (msg == WM_LBUTTONDOWN) {
            pWidget->Lclick = true;
        }
        if (msg == WM_LBUTTONUP) {
            pWidget->Lclick = false;
        }
        if (msg == WM_RBUTTONDOWN) {
            pWidget->Rclick = true;
        }
        if (msg == WM_RBUTTONUP) {
            pWidget->Rclick = false;
        }
        if (msg == WM_MBUTTONDOWN) {
            pWidget->Mclick = true;
        }
        if (msg == WM_MBUTTONUP) {
            pWidget->Mclick = false;
        }


        // Additional cases for other messages if needed

    }

    // Call the original window procedure
    return CallWindowProc(pWidget ? pWidget->oldProc : DefWindowProc, hwnd, msg, wParam, lParam);
}


