#pragma once
#include <Windows.h>
#include "Structs.h"
#include "Widget.h"

class Button : public Widget {
public:
    

      Button(int posX, int posY, int h, int w, LPCWSTR name, HWND parent, Button* wid);
      static LRESULT CALLBACK ButtonProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
      void SubclassWindow();


   

    

    
};
