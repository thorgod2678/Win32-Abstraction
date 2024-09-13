#pragma once
#include <Windows.h>
#include "Structs.h"

class Widget {
public:
    int posX;
    int posY;
    int h;
    int w;

    bool Lclick;
    bool Rclick;
    bool Mclick;
    bool visible;
    
    HWND hwnd;  // Store the HWND of the button
    WNDPROC oldProc;



    static LRESULT CALLBACK WidgetProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

     void SubclassWindow();

     Widget(int posX, int posY, int h, int w, LPCWSTR name, HWND parent, Widget* wid);

    INFO GetInfo();

    //HWND CreateWidManual(LPCWSTR clname, int x, int y, int h, int b, int id, LPCWSTR title, HWND parent);
     // Store the original window procedure

    
};
