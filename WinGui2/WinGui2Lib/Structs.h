#pragma once
#include <Windows.h>

typedef struct Window;
typedef void (*Handler)(UINT msg, UINT wp, UINT lp, Window* win);

typedef struct STYLE {
    int color[3];               // RGB color values
    int exstyle;                // Extended window styles
    int style;                  // Window styles
    const wchar_t* clname;      // Class name
    BOOL defpaint;
};

typedef struct Window {

    int h;                      // Height of the window
    int b;                      // Width of the window
    int x;                      // X position of the window
    int y;                      // Y position of the window
    const wchar_t* title;               // Title of the window
    STYLE style;                // Window style
    Handler handler;            // Pointer to the message handler
    HWND parent;                // Handle to the parent window
    HWND self;
};

typedef struct Control {

    int h;
    int b;
    int x;
    int y;
    const wchar_t* title;
    HWND parent;
    const wchar_t* type;
    HWND self;
    int id;

};

#define DefStyle {{255,255,255},0,WS_OVERLAPPED,L"Window1",1}
#define PTR(x) x*
#define ADDR(x) &x
#define VAL(x) *x

#pragma region controls

#define BUTTON         L"Button"      //Button
#define EDIT           L"Edit"        // Edit control (textbox)
#define STATIC         L"Static"      // Static control (label)
#define LISTBOX        L"ListBox"     // List box control
#define COMBOBOX       L"ComboBox"    // Combo box control
#define SCROLLBAR      L"ScrollBar"   // Scroll bar control
#define PROGRESSBAR    L"msctls_progress32" // Progress bar control
#define TRACKBAR       L"msctls_trackbar32" // Trackbar (slider) control
#define UPDOWN         L"msctls_updown32"   // Up-down (spinner) control
#define TOOLBAR        L"ToolbarWindow32"   // Toolbar control
#define STATUSBAR      L"msctls_statusbar32" // Status bar control
#define TABCONTROL     L"SysTabControl32"   // Tab control
#define TREEVIEW       L"SysTreeView32"     // Tree view control
#define LISTVIEW       L"SysListView32"     // List view control
#define RICHEDIT       L"RichEdit20A"       // Rich edit control (multiline edit box)
#define RICHEDITW      L"RichEdit20W"       // Rich edit control (Unicode version)
#define DATETIMEPICKER L"SysDateTimePick32" // Date and time picker control
#define MONTHCALENDAR  L"SysMonthCal32"     // Month calendar control
#define HOTKEY         L"msctls_hotkey32"   // Hotkey control
#define ANIMATE        L"SysAnimate32"      // Animate control
#define REBAR          L"ReBarWindow32"     // Rebar control (toolbars can be placed inside it)
#define IPADDRESS      L"SysIPAddress32"    // IP Address control
#define HEADER         L"SysHeader32"       // Header control (used in list views)
#define TOOLTIPS       L"tooltips_class32"  // Tooltips control
#define TRACKBAR       L"msctls_trackbar32" // Trackbar (slider)
#define BUTTON_SPLIT   L"msctls_spliterbar32" // Splitter control
#define SPINNER        L"msctls_updown32"   // Spin control (up-down)
#define PAGER          L"SysPager"          // Pager control (used for scrolling)

#pragma endregion

