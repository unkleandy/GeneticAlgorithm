// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Gère l'affichage de la simulation. La "vue" du modèle MVC est ici divisée
//							en deux partie, l'une pour le menu principale (ViewMenu) et l'autre pour 
//							la simulation (ViewRuntime). La conception est ainsi car la console doit 
//							être redimensionnée entre les deux partie pour permettre l'affichage lisible
//							des caractères 
//							
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger

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
	void setupWindow();
	void update();
	Canvas const & canvas() const;
	void clearScreen();


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
	bool mRandomizeObstacles{ true };
	keyBinding_ec mInputKey;
	solutionDisplay_ec mSolutionDisplay;
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 3 };
	windows_console::font::ratio_type mRunningFontRatio{ 1.0 };
	ShapeOptimizer * mShapeOptimizer;
	void readInput();
	void cycleSolutionDisplay();


};

#endif // VIEW_RUNTIME_H
