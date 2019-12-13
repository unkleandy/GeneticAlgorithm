#pragma once
#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include <string>
#include <console.h>
#include "ShapeOptimizer.h"

class ViewMenu
{
public:
	ViewMenu();
	~ViewMenu() = default;
	void readInput();
	void clearScreen();

private:
	static std::string sTxtTitle;
	static std::string sFontStyle;
	static std::string sMenuText;
	int consoleWidth{ 150 };
	int consoleHeight{ 30 };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 16 };
	windows_console::font::ratio_type mRunningFontRatio{ 0.5 };

	void setupWindow();
	void displayMenu();
};

#endif // VIEW_MENU_H
