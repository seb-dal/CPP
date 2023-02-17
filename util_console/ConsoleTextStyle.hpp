//
// Created by Dalverny on 28/04/2021.
//

#ifndef _CONSOLE_TEXT_STYLE_HPP
#define _CONSOLE_TEXT_STYLE_HPP

#include "OS.h"

/**
 * ConsoleTextStyle, Change the color and style of the text written after the change.
 *
 */
class CTS {
public:
	enum Color {
#if IS_WINDOWS
		Black = 0,
		Blue,
		Green,
		Cyan,
		Red,
		Magenta,
		Yellow,
		White,
		Gray,
		Bright_Blue,
		Bright_Green,
		Bright_Cyan,
		Bright_Red,
		Bright_Magenta,
		Bright_Yellow,
		Bright_White
#else
		Black = 30,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
		Gray = 90,
		Bright_Red,
		Bright_Green,
		Bright_Yellow,
		Bright_Blue,
		Bright_Magenta,
		Bright_Cyan,
		Bright_White
#endif
	};

	enum Style {
		Bold = 1,
		Underline = 4,
		Inverse = 7,
		Bold_OFF = 21,
		Underline_OFF = 24,
		Inverse_OFF = 27
	};

private:
	static CTS::Color current_text_color, current_background_color;
	static bool isTextColorBackgroundColorInversed, inverseColorText, inverseColorBackground, isBold, isUnderline;

	/**
	 * Inverse colors.
	 * @param c color
	 * @return inversed color of c
	 */
	static CTS::Color inverseColor(CTS::Color c);

	/**
	 * Update the style and colors that will be display.
	 */
	static void update();

	/**
	 * Apply the change of style and colors.
	 * @param text color of the text
	 * @param background color of the background
	 */
	static void setColorConsole(CTS::Color text, CTS::Color background);

public:

	/**
	 * Set the style of the text that will be written in the shell.
	 * @param bold text is bold (Doesnt work with Windows)
	 * @param underline text is underline (Doesnt work with Windows)
	 * @param inverseTextBackground inverse the color between the text and background
	 * @param inverseTextColor inverse the color of the text
	 * @param inverseBackgroundsColor inverse the color of the background
	 * @param text color of the text
	 * @param background color of the background
	 */
	static void setStyle(
		const bool bold, const bool underline,
		const bool inverseTextBackground,
		const bool inverseTextColor,
		const bool inverseBackgroundsColor,
		const CTS::Color text = White, const CTS::Color background = Black
	);

	/**
	 * Activate or deactivate the bold text.
	 * @param underline Activate or deactivate bold
	 */
	static void setTextBold(const bool bold);

	/**
	 * Activate or deactivate the underline text.
	 * @param underline Activate or deactivate underline
	 */
	static void setTextUnderline(bool underline);

	/**
	 * Inverse the color of the text and/or the background.
	 * @param text if true, inverse the text color
	 * @param background if true, inverse the background color
	 */
	static void setInverseColor(bool text = false, bool background = false);

	/**
	 * Inverse the color between the text and the background.
	 */
	static void setInverseTextBackground();

	/**
	 * Set the color for the text and/or the background.
	 * @param text color of the text
	 * @param background color of the background
	 */
	static void setColor(CTS::Color text = White, CTS::Color background = Black);

	/**
	 * Reset the styles and colors to there original values.
	 */
	static void reset();

};//END class CTS

#endif //HMAPLOAD_CONSOLETEXTSTYLE_HPP
