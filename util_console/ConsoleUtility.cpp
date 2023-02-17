#include "ConsoleUtility.hpp"

#if IS_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif IS_LINUX
#include <sys/ioctl.h>
#endif // Windows/Linux


void CU::getTerminalSize(short& width, short& height)
{
#if IS_WINDOWS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#elif IS_LINUX
	struct winsize w;
	ioctl(fileno(stdout), TIOCGWINSZ, &w);
	width = w.ws_col;
	height = w.ws_row;
#endif // Windows/Linux
}

void CU::clear_console()
{
#if IS_WINDOWS
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
#else
	system("clear");
#endif

}
