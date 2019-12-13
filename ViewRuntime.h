#pragma once
#ifndef VIEW_RUNTIME_H
#define VIEW_RUNTIME_H

#include <string>
#include <console.h>
#include "ShapeOptimizer.h"

class ViewRuntime
{
public:
	ViewRuntime();
	~ViewRuntime() = default;
	void drawTest();
	void readInput();
	void clearScreen();

private:
	std::string const & sTxtTitle{ "B52 - Projet Final" };
	std::string const& sFontStyle{ "Consolas" };
	int consoleWidth{ 300 };
	int consoleHeight{ 200 };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	void setupWindow();
	windows_console::font::size_type mRunningFontSize{ 3 };
	windows_console::font::ratio_type mRunningFontRatio{ 1.0 };

};

#endif // VIEW_RUNTIME_H
