#include <windows.h>
#include "C:\Users\PULAK\source\repos\Cpp\WinGui2\WinGui2Lib\Window.h"  // Your window management header
void myWindowHandler(UINT msg, UINT wp, UINT lp,Window* win) {
    if (msg == WM_COMMAND) {
        if (wp == 1) {
            MessageBox(NULL, L"dd", L"dd", MB_ICONERROR);
        }
    }
}

int  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main()
{
    STYLE style = { {100,100,100},0,WS_OVERLAPPEDWINDOW,L"win1",1};
    STYLE style2 = { {100,200,200},0,WS_CHILD,L"win2",0 };
    Window* myWindow = createWindow(600, 800, 100, 100, L"dd", style, myWindowHandler, NULL);
    Window* myWindow2 = createWindow(100, 100, 100, 100, L"dd", style2, DefHandler, myWindow->self);
   // Control* control = createControl(1, L"Button", 20, 100, 50, 60, L"dd", myWindow->self);
    StartLoop();
    free(myWindow);
}
