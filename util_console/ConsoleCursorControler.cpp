#include "ConsoleCursorControler.hpp"


#if IS_WINDOWS
#include <windows.h>   // WinApi header

void  CCC::win_show_cur(const bool show) {
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(H, &cci);
	cci.bVisible = show; // show/hide cursor
	SetConsoleCursorInfo(H, &cci);
}

#endif

void CCC::getCurPos(short& x, short& y)
{
#if IS_WINDOWS
	POINT p;
	if (GetCursorPos(&p))
	{
		x = p.x;
		y = p.y;
	}
#else
	printf("\033[6n");  /* This escape sequence !writes! the current
						  coordinates to the terminal.
						  We then have to read it from there, see [4,5].
						  Needs <termios.h>,<unistd.h> and some others */
	scanf("\033[%d;%dR", &x, &y);
#endif
}

void CCC::addCurPos(short& x, short& y)
{
}

void CCC::resetCurPos()
{
	setCurPos(0, 0);
}

void CCC::setCurPos(const short x, const short y)
{
#if IS_WINDOWS
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
#else
	printf("%c[%d;%df", 0x1B, y, x);
#endif
}



void CCC::hideCursor(bool hide)
{
	if (hide) {
#if IS_WINDOWS
		win_show_cur(false);
#else
		printf("\e[?25l");
#endif
	}
	else {
		showCusor();
	}
}

void CCC::showCusor(const bool show)
{
	if (show) {
#if IS_WINDOWS
		win_show_cur(true);
#else
		printf("\e[?25h");
#endif
	}
	else {
		hideCursor();
	}
}
