#include "Window.h"
#include <Widget.h>
#include"Button.h"
int main()
{
    
    WNDSTYLE x = CreateWNDSTYLE(0, WS_OVERLAPPEDWINDOW,0,0,0,L"dd");
    Window win = Window(L"Window 2", &win,x, 800, 600, 148, 100);
   // CreateWNDSTYLE(0, WS_OVERLAPPEDWINDOW, 0, 255, 0, L"WindowClass2"); // Black color

   // HWND window = win.createwindow(L"Window 2", &win, 800, 600, 148, 100);

    //Button but = Button(40, 40, 40, 200, L"gg", win.hww, &but);
   // Widget vbut = Widget(80, 80, 40, 200, L"gg", win.hww, &vbut);
   // CreateWidManual(L"Button",12,12,50,80,34,L"ff",NULL);

    while (win.isopen) {
        win.StartLoop(win.hww);
       // if (but.Rclick) {
        //    MessageBox(NULL, L"ff", L"gg", MB_ABORTRETRYIGNORE);
      //  }

    }
    return 0;
}

