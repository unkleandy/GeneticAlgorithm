#pragma once
#ifndef VIEW_RUNTIME_H
#define VIEW_RUNTIME_H

#include <string>
#include <console.h>
#include "Canvas.h"
#include "ShapeOptimizer.h"

class ShapeOptimizer;
class ViewRuntime
{
public:
	ViewRuntime();
	~ViewRuntime() = default;
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);
	void run();


private:
	enum class keyBinding_ec : char {
		Exit_Runtime = 27,	// escape character
		Cycle_Solution_Display = 32,  // spacebar character
		None = 0, // utilisé pour "vider" mInputKey
		_count_
	};

	enum class solutionDisplay_ec : size_t {
		None = 0,
		All = 1,
		The_Best = 2,
		_count_
	};

	std::string const & sTxtTitle{ "B52 - Projet Final" };
	std::string const& sFontStyle{ "Consolas" };
	int consoleWidth{ 300 };
	int consoleHeight{ 200 };
	Canvas mCanvas;
	bool mExitRuntime{ false };
	bool mRandomizeObstacles{ true };
	keyBinding_ec mInputKey;
	solutionDisplay_ec mSolutionDisplay;
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 3 };
	windows_console::font::ratio_type mRunningFontRatio{ 1.0 };
	ShapeOptimizer * mShapeOptimizer;
	void setupWindow();
	void readInput();
	void clearScreen();
	void cycleSolutionDisplay();


};

#endif // VIEW_RUNTIME_H
