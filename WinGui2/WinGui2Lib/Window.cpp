#pragma once
#include "Window.h"
#include "pch.h"
#include<Windows.h>
#include"Structs.h"

LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    Window* temp = reinterpret_cast<Window*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    if (temp) {

        if (msg == WM_DESTROY) {
            PostQuitMessage(2);
        }
        if (temp->style.defpaint == 1) {

            if (msg == WM_PAINT) {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(temp->self, &ps);

                // All painting occurs here, between BeginPaint and EndPaint.
                HBRUSH brush = CreateSolidBrush(RGB(temp->style.color[0], temp->style.color[1], temp->style.color[2]));
                FillRect(hdc, &ps.rcPaint, brush);

                EndPaint(temp->self, &ps);
            }
        }

        // Call the handler function if the window struct is valid
        temp->handler(msg, wParam, lParam,temp);
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

Window* createWindow(int h, int b, int x, int y, const wchar_t* title, STYLE style, Handler handler, HWND parent)
{
    WNDCLASS wc = { };
    wc.lpfnWndProc = wndproc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = style.clname;
    RegisterClass(&wc);

    // Dynamically allocate memory for the Window struct so it persists
    Window* win =  new Window{ h, b, x, y, title, style, handler, parent, NULL };
    HWND hwnd = CreateWindowExW(
        win->style.exstyle,
        win->style.clname,
        (LPCWSTR)win->title,
        win->style.style,
        win->x,
        win->y,
        win->b,
        win->h,
        win->parent,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    win->self = hwnd;
    SetWindowLongPtr(win->self, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(win));  // Store pointer to dynamically allocated Window

    return win;  // Return the dynamically allocated Window struct
}

void StartLoop() {
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

      
    }
}

void DefHandler(UINT msg, UINT wp, UINT lp, Window* win) {
    

}

Control* createControl(int id, const wchar_t* type, int h , int b , int x , int y, const wchar_t* title  , HWND parent  ) {

    Control* control = new  Control {h,b,x,y,title,parent,type,NULL,id};
    HWND temp = CreateWindowExW(0, control->type, control->title, WS_CHILD, control->x, control->y, control->b, control->b, control->parent, HMENU(control->id), 
                GetModuleHandleW(NULL), NULL);
    ShowWindow(temp, SW_SHOWDEFAULT);
    control->self = temp;
    return control;

}