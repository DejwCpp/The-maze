#include "settings.h"
#include <windows.h>

void Console::CursorVisibility(bool visible)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    
    cursorInfo.bVisible = visible;
    
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Console::AlignCenter(int consoleWidth, int consoleHeight)
{
	HWND consoleWindow = GetConsoleWindow();

    RECT consoleRect;
    GetWindowRect(consoleWindow, &consoleRect);

    int consoleWindowWidth = consoleRect.right - consoleRect.left;
    int consoleWindowHeight = consoleRect.bottom - consoleRect.top;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowLeft = (screenWidth - consoleWidth) / 2;
    int windowTop = (screenHeight - consoleHeight) / 2;

    MoveWindow(consoleWindow, windowLeft, windowTop, consoleWidth, consoleHeight, TRUE);
}

void Console::CharWidthLength(int charWidth, int charHeight)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &font);

    font.dwFontSize.X = charWidth;
    font.dwFontSize.Y = charHeight;
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;
    wcscpy(font.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(hConsole, FALSE, &font);

    SMALL_RECT srWindowRect;
    srWindowRect.Top = 0;
    srWindowRect.Left = 0;
    srWindowRect.Right = charWidth / 8 - 1;
    srWindowRect.Bottom = charHeight / 16 - 1;

    SetConsoleWindowInfo(hConsole, TRUE, &srWindowRect);
}

void Console::SetColor(std::string color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (color == "black") {
        SetConsoleTextAttribute(hConsole, 0);
    }
    else if (color == "blue") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    }
    else if (color == "green") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    }
    else if (color == "cyan") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else if (color == "red") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    }
    else if (color == "magenta") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    }
    else if (color == "yellow") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else if (color == "white") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}
