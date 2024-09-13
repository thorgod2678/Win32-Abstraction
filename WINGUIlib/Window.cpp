#include "Window.h"
//#include "Structs.h"


Window::Window(LPCWSTR title, Window* x, WNDSTYLE style, int width, int hieght, int posx, int posy, HWND parent) {
    hInstance = GetModuleHandleW(nullptr);
     nCmdShow = SW_SHOWDEFAULT;
     
     WNDCLASS wc = { 0 };
     wc.lpfnWndProc = Window::WindowProc;
     wc.hInstance = hInstance;
     wc.lpszClassName = style.clname;

     RegisterClassW(&wc);
     stylecard = style;
     HWND hwnd = CreateWindowExW(
         style.exstyle,
         style.clname,
         title,
         style.style,
         posx, posy, width, hieght,
         parent,
         NULL,
         hInstance,
         x
     );

     ShowWindow(hwnd, nCmdShow);

     hww = hwnd;
    
   // Window::CreateWindowClass(L"WINDOW");
}



HWND Window::CreateExWindow(LPCWSTR title, Window* x, WNDSTYLE style,int width, int hieght , int posx , int posy,HWND parent ) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = Window::WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = style.clname;

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        style.exstyle,
        style.clname,
        title,
        style.style,
        posx, posy, width, hieght,
        parent,
        NULL,
        hInstance,
        x
    );

    ShowWindow(hwnd, nCmdShow);


    return hwnd;
}

void Window::hidewindow(HWND hw) {
    ShowWindow(hw, SW_HIDE);
}

void Window::shoWwindow(HWND hw) {
    ShowWindow(hw, nCmdShow);
}

void Window::StartLoop(HWND hw ) {
    MSG msg;
    
       while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    

     

    } 
}




  void Window::SetUserData(HWND hwnd, Window* pThis) {
      SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
  }

  Window* Window::GetUserData(HWND hwnd) {
      return reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
  }

  WNDSTYLE CreateWNDSTYLE(DWORD exst, DWORD st, int cr, int cg, int cb, LPCWSTR name)
  {
      WNDSTYLE x;
      x.exstyle = exst;
      x.style = st;
      x.cr = cr;
      x.cb = cb;
      x.cg = cg;

    


      return x;
  }
  HWND CreateWidManual(LPCWSTR clname, int x, int y, int h, int b, int id, LPCWSTR title = L"dfd", HWND parent = NULL) {


      HWND HW = CreateWindowExW(0, clname, title, WS_CHILD | WS_TABSTOP, x, y, b, h, parent, (HMENU)id, GetModuleHandleA(nullptr), NULL);
      return HW;


  }