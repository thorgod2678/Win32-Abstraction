#pragma once


#include <Windows.h>

struct WNDSTYLE
{
	   // WNDCLASS rc;
	LPCWSTR clname;
		DWORD exstyle;
		DWORD style;
		
		//rgb color ints need to change in future
		int cr;
		int cg;
		int cb;
		//rgb color ints need to change in future


};

struct WIDSTYLE {


};

struct INFO {
	int x;
	int y;
	int h;
	int w;

};


