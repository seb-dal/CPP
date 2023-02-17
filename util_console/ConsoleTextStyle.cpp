#include "ConsoleTextStyle.hpp"


#if IS_WINDOWS
#include <windows.h>   // WinApi header
#endif

CTS::Color CTS::current_text_color = CTS::White;
CTS::Color CTS::current_background_color = CTS::Black;
bool CTS::isTextColorBackgroundColorInversed = false;
bool CTS::inverseColorText = false;
bool CTS::inverseColorBackground = false;
bool CTS::isBold = false;
bool CTS::isUnderline = false;


CTS::Color CTS::inverseColor(CTS::Color c) {
	switch (c) {
	case Black:
		return White;
	case White:
		return Black;

	case Blue:
		return Yellow;
	case Yellow:
		return Blue;

	case Green:
		return Magenta;
	case Magenta:
		return Green;

	case Cyan:
		return Red;
	case Red:
		return Cyan;

	case Bright_White:
		return Gray;
	case Gray:
		return Bright_White;

	case Bright_Blue:
		return Bright_Yellow;
	case Bright_Yellow:
		return Bright_Blue;

	case Bright_Green:
		return Bright_Magenta;
	case Bright_Magenta:
		return Bright_Green;

	case Bright_Cyan:
		return Bright_Red;
	case Bright_Red:
		return Bright_Cyan;
	}
	return Gray;
}

void CTS::update() {
	CTS::Color text = (inverseColorText) ? inverseColor(current_text_color) : current_text_color;
	CTS::Color bg = (inverseColorBackground) ? inverseColor(current_background_color) : current_background_color;

	(isTextColorBackgroundColorInversed) ? setColorConsole(bg, text) : setColorConsole(text, bg);
}

void CTS::setColorConsole(CTS::Color text, CTS::Color background) {
#if IS_WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text + 16 * background);
#else
	std::cout << "\033["
		<< std::to_string(text) << ";"
		<< std::to_string(background + 10);
	std::cout << "m";
#endif
}

void CTS::setStyle(const bool bold, const bool underline, const bool inverseTextBackground, const bool inverseTextColor, const bool inverseBackgroundsColor, const CTS::Color text, const CTS::Color background) {
	// Style Not supported on Windows
#if !IS_WINDOWS
	setTextBold(bold);
	setTextUnderline(underline);
#endif

	if (inverseTextBackground)
		isTextColorBackgroundColorInversed = !(isTextColorBackgroundColorInversed);

	if (inverseTextColor)
		inverseColorText = !(inverseColorText);

	if (inverseBackgroundsColor)
		inverseColorBackground = !(inverseColorBackground);

	setColor(text, background);
}

void CTS::setTextBold(const bool bold) {
	//Bold Not supported on Windows
#if !IS_WINDOWS
	if (isBold != bold) {
		isBold = bold;
		std::cout << "\033[";
		std::cout << (isBold) ? std::to_string(Bold) : std::to_string(Bold_OFF);
		std::cout << "m";
	}
#endif
}

void CTS::setTextUnderline(bool underline) {
	//Underline Not supported on Windows
#if !IS_WINDOWS
	if (isUnderline != underline) {
		isUnderline = underline;
		std::cout << "\033[";
		std::cout << (isUnderline) ? std::to_string(Underline) : std::to_string(Underline_OFF);
		std::cout << "m";
	}
#endif
}

void CTS::setInverseColor(bool text, bool background) {
	if (text) {
		inverseColorText = !(inverseColorText);
	}
	if (background) {
		inverseColorBackground = !(inverseColorBackground);
	}
	if (text || background) {
		update();
	}
}

void CTS::setInverseTextBackground() {
	isTextColorBackgroundColorInversed = !(isTextColorBackgroundColorInversed);
	update();
}

void CTS::setColor(CTS::Color text, CTS::Color background) {
	current_text_color = text;
	current_background_color = background;
	update();
}

void CTS::reset() {
	isTextColorBackgroundColorInversed = false;
	inverseColorText = false;
	inverseColorBackground = false;
	isBold = false;
	isUnderline = false;
	current_text_color = White;
	current_background_color = Black;
#if IS_WINDOWS
	update();
#else
	std::cout << "\033[0m";
#endif
}
