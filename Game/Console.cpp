
#include "Console.h"

Console::Console() :
	Handle(0),
	bIsInitialized(false)
{
}

Console& Console::Instance()
{
	static Console Instance;
	return Instance;
}

void Console::Initialize()
{
	Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle(EConsole::Title);

	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.dwSize = 100;
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(Handle, &CursorInfo);

	CONSOLE_FONT_INFOEX FontInfo;
	ZeroMemory(&FontInfo, sizeof(FontInfo));
	FontInfo.cbSize = sizeof(FontInfo);
	GetCurrentConsoleFontEx(Handle, false, &FontInfo);

	FontInfo.dwFontSize.X = 18;
	FontInfo.dwFontSize.Y = 13;
	lstrcpyW(FontInfo.FaceName, EConsole::FontFace);
	SetCurrentConsoleFontEx(Handle, false, &FontInfo);

	bIsInitialized = true;
}

void Console::Clear(WORD ClearColor)
{
	if (!bIsInitialized)
	{
		exit(EXIT_FAILURE);
	}

	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
	GetConsoleScreenBufferInfo(Handle, &ScreenBufferInfo);

	DWORD ScreenBufferSize;
	ScreenBufferSize = ScreenBufferInfo.dwSize.X * ScreenBufferInfo.dwSize.Y;

	COORD CursorPosition = { 0, 0 };
	SetConsoleCursorPosition(Handle, CursorPosition);

	DWORD NumCharsWritten;
	FillConsoleOutputAttribute(Handle, ClearColor, ScreenBufferSize, CursorPosition, &NumCharsWritten);
	FillConsoleOutputCharacterA(Handle, EChar::Empty, ScreenBufferSize, CursorPosition, &NumCharsWritten);
}

void Console::Write(const std::string& Text, const WORD TextColor, int X, int Y)
{
	if (!bIsInitialized)
	{
		exit(EXIT_FAILURE);
	}

	COORD CursorPosition = { (short)X, (short)Y };
	SetConsoleCursorPosition(Handle, CursorPosition);
	SetConsoleTextAttribute(Handle, TextColor);

	DWORD NumCharsWritten;
	WriteConsoleA(Handle, Text.c_str(), Text.size(), &NumCharsWritten, 0);
}


