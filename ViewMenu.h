// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				G�re l'affichage du menu principal ainsi que la configuration des
//							diff�rents param�tres du programme. La "vue" du mod�le MVC est ici divis�e
//							en deux partie, l'une pour le menu principale (ViewMenu) et l'autre pour 
//							la simulation (ViewRuntime). La conception est ainsi car la console doit 
//							�tre redimensionn�e entre les deux partie pour permettre l'affichage lisible
//							des caract�res 
//							
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer		

#pragma once
#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include <string>
#include <console.h>
#include "ShapeOptimizer.h"

class ShapeOptimizer;
class ViewMenu
{
public:
	ViewMenu();
	~ViewMenu() = default;
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);
	void run();

private:
	enum class keyBinding_ec : char {
		Quit = 27,	// escape character
		Start_Simulation = 32,  // spacebar character
		Lower_Obstacle_Count = 'Q',
		Raise_Obstacle_Count = 'W',
		Reset_Obstacle_Count = 'E',
		Set_Population_Count1 = '1',
		Set_Population_Count2 = '2',
		Set_Population_Count3 = '3',
		Set_Population_Count4 = '4',
		Cycle_Shape = 'A',
		None = 0, // utilis� pour "vider" mInputKey
		_count_
	};

	enum class availableShapes_ec : size_t {
		Rectangle,
		Circle,
		Triangle,
		_count_
	};

	enum class resetRequest_ec : bool {
		Oui = true,
		Non = false,
		_count_
	};

	static std::string sTxtTitle;
	static std::string sFontStyle;
	static std::string sMenuText;
	static std::string sConfigTitle;
	static std::string sChangeObstacleCount;
	static std::string sCurrentObstacleCount;
	static std::string sObstaclesPositionReset;
	static std::string sObstaclesResetRequested;
	static std::string sChangePopulationCount;
	static std::string sCurrentPopulationCount;
	static std::string sChangeShape;
	static std::string sCurrentShape;

	//static std::string sChangeElitismCount;
	//static std::string sCurrentElitismCount;
	//static std::string sChangeGenerationCount;
	//static std::string sCurrentGenerationCount;

	int mConsoleWidth{ 150 };
	int mConsoleHeight{ 30 };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 16 };
	windows_console::font::ratio_type mRunningFontRatio{ 0.5 };
	ShapeOptimizer * mShapeOptimizer;
	void obstacleCountChanged();
	bool mExitMenu{ false };
	keyBinding_ec mInputKey;

	void setupWindow();
	void displayMenu();
	void readInput();
	void clearScreen();
	void exitMenu();
};

#endif // VIEW_MENU_H
