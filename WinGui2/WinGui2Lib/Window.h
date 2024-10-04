#pragma once
#include"Structs.h"

//LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void DefHandler(UINT msg, UINT wp, UINT lp, Window* win);
Window* createWindow(int h=800,int b=600,int x=0,int y=0,const wchar_t* title=L"Example", STYLE style=DefStyle, Handler handler=DefHandler, HWND parent=NULL);
void StartLoop();
Control* createControl(int id,const wchar_t* type ,int h=20, int b=100, int x=0, int y=0, const wchar_t* title=L"Example", HWND parent = NULL );
