#pragma once
#ifndef VIEW_PARAMETERS_H
#define VIEW_PARAMETERS_H

#include <string>
#include <console.h>
#include "ShapeOptimizer.h"

class ViewParameters
{
public:
	ViewParameters();
	~ViewParameters() = default;
	void readInput();
	void clearScreen();

private:
	static std::string sTxtTitle;
	static std::string sFontStyle;
	static std::string sMenuTitle;
	static std::string sActualObstacleCount;
	static std::string sChangeObstacleCountQuestion;
	static std::string sObstacleCountQuestion;
	static std::string sObstaclesPositionQuestion;
	static std::string sPopulationSizeQuestion;
	static std::string sElitismSizeQuestion;
	static std::string sPopulationCountQuestion;
	static std::string sMaximumGenerationCountQuestion;
	static std::string sChosenShapeQuestion;
	int consoleWidth{ 150 };
	int consoleHeight{ 30 };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 16 };
	windows_console::font::ratio_type mRunningFontRatio{ 0.5 };
	size_t mPopulationSize;
	size_t mObstacleCount;
	size_t mElitismSize;
	size_t mConcurrentPopulationCount;
	size_t MaximumGenerationCount;
	std::string chosenShape;


	void setupWindow();
	void displayMenu();
};

#endif // VIEW_PARAMETERS_H
