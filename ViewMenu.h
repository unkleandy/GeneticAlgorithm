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
	void drawTest();
	void readInput();
	void clearScreen();

private:
	std::string const & mTxtTitle{"B52 - Projet Final"};
	std::string const& mFontStyle{ "Consolas" };
	// int const & mRunningFontSize{ 3 };
	// double const & mRunningFontRatio{ 1.0 };
	int consoleWidth{ 300 };
	int consoleHeight{ 200 };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	void setupWindow();
	windows_console::font::size_type mRunningFontSize{ 3 };
	windows_console::font::ratio_type mRunningFontRatio{ 1.0 };

};

#endif // VIEW_MENU_H
