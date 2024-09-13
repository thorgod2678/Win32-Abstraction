#pragma



#include <Windows.h>
#include "Structs.h"


class Window
{
private:
    
    HINSTANCE hInstance;
    int nCmdShow;
    //int CreateWindowClass(LPCWSTR name);
    
  // static  WNDSTYLE dd;
    //COLORREF x = ;
   
   
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        Window* pThis = GetUserData(hwnd);
      
        if (pThis != NULL) {
            pThis->msg = uMsg;
            pThis->wp = wParam;
            pThis->lp = lParam;

          

            
        }


        if (uMsg == WM_NCCREATE) {
            
            
            CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
            pThis = reinterpret_cast<Window*>(pCreate->lpCreateParams);
            SetUserData(hwnd, pThis);

           

           

        }
        
        if (uMsg == WM_DESTROY) {
            pThis->isopen = false;

            PostQuitMessage(0);
            return 0;
        }
        

            if (uMsg == WM_PAINT) {

                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                RECT rect;
                GetClientRect(hwnd, &rect);
                HBRUSH brush = CreateSolidBrush(RGB(pThis->stylecard.cr, pThis->stylecard.cg, pThis->stylecard.cb));
                FillRect(hdc, &rect, brush);
                EndPaint(hwnd, &ps);

                return 0;
            }

            if (uMsg == WM_SIZE) {

            
                InvalidateRect(hwnd, nullptr, TRUE);
                return 0;
            }
       



        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
public:
    Window(LPCWSTR title, Window* x, WNDSTYLE style,int width = 800, int hieght = 600, int posx = 100, int posy = 100, HWND parent = NULL);
    
    
    HWND CreateExWindow( LPCWSTR title,Window* x, WNDSTYLE style,int width = 800, int hieght = 600, int posx = 100, int posy = 100,HWND parent = NULL);
    void hidewindow(HWND hw);
    void shoWwindow(HWND hw);
    void StartLoop(HWND hw);
    //int CreateWNDSTYLE(DWORD exst,DWORD st,int cr,int cg,int cb ,LPCWSTR name);
    
   
   static void SetUserData(HWND hwnd,Window* pThis);
  static  Window* GetUserData(HWND hwnd);

  bool isopen = true;
  WNDSTYLE stylecard;
  int msg;
  int wp;
  int lp;
  HWND hww;
};

HWND CreateWidManual(LPCWSTR clname, int x, int y, int h, int b, int id, LPCWSTR title, HWND parent);
WNDSTYLE CreateWNDSTYLE(DWORD exst, DWORD st, int cr, int cg, int cb, LPCWSTR name);
 // WINDOW_H
