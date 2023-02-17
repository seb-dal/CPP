//
// Created by Dalverny on 24/09/2022.
//

#ifndef _CONSOLE_CURSOR_CONTROLER_HPP
#define _CONSOLE_CURSOR_CONTROLER_HPP

#include "OS.h"

class CCC {
#if IS_WINDOWS
	static void win_show_cur(const bool show);
#endif



public:

	static void resetCurPos();
	static void getCurPos(short& x, short& y);
	static void addCurPos(short& x, short& y);
	static void setCurPos(const short x, const short y);

	static void hideCursor(const bool hide = true);
	static void showCusor(const bool show = true);
};

#endif
