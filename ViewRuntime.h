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

// Foward declaration
class ShapeOptimizer;

class ViewRuntime
{

private:
	// Enum qui associe les actions possible pendant la simulation à leurs entrées au clavier.
	enum class keyBinding_ec : char {
		Exit_Runtime = 27,	// escape character
		Cycle_Solution_Display = 32,  // spacebar character
		None = 0, // utilisé pour "vider" mInputKey
		_count_
	};

	// Enum des différentes options d'affichage. On peut décider de ne pas afficher de forme (none), d'afficher 
	// toutes les solutions (All) ou d'afficher seulement les meilleures solutions de chaque population.
	enum class solutionDisplay_ec : size_t {
		None = 0,
		All = 1,
		The_Best = 2,
		_count_
	};

	std::string const & sTxtTitle{ "B52 - Projet Final" };
	std::string const & sFontStyle{ "Consolas" };
	int const consoleWidth{ 300 };
	int const consoleHeight{ 200 };
	Canvas mCanvas;
	bool mRandomizeObstacles{ true };
	keyBinding_ec mInputKey{keyBinding_ec::None};
	solutionDisplay_ec mSolutionDisplay{ solutionDisplay_ec::All };
	windows_console::image mImage;
	windows_console::image mBlankImage;
	windows_console::font::size_type mRunningFontSize{ 3 };
	windows_console::font::ratio_type mRunningFontRatio{ 1.0 };
	ShapeOptimizer * mShapeOptimizer;

	// Lecture des entrées au clavier.
	void readInput();

	// Effectue les actions correspondantes aux entrées au clavier de l'usager.
	void doAction();

	// Parcourt les différentes options d'affichage des solutions
	void cycleSolutionDisplay();

	// Demande l'affichage à l'écran des solutions selon le type choisi par l'usager (mSolutionDisplay)
	void drawAsSolutionDisplaySelected(); // Pas de "const" car clearScreen est appelé

public:
	// Constructeur qui initialize le canvas (mCanvas) avec les paramètres de la console et mBlankImage avec un buffer vide (pour la méthode clearScreen()).
	ViewRuntime();
	~ViewRuntime() = default;

	// Mutateur de la variable mShapeOptimizer qui est utilisée pour que les entrées au cliavier puisse modifier les 
	// variables des paramètres (sortie de la simulation et type d'affichage des solutions) qui sont dans la classe ShapeOptimizer.
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);

	// Configuration des paramètres de la console. Afin de réduire la tailel des pixels pour permettre un meilleur affichage des
	// formes géométriques la console doit être redimensionnée.
	void setupWindow();

	// Méthode appelée par l'observateur (mShapeObserver) lorsqu'une nouvelle génération des populations est complétées. Demande le 
	// rafraichissement de l'écran et une lecture des entrées au clavier.
	void update();

	// Acesseur de la variable mCanvas.
	Canvas const & canvas() const;

	// Efface l'écran.
	void clearScreen();

	// Accesseur de la variable mSolutionDisplay qui représente le type d'affichage des solutions 
	// demandé par l'usager.
	solutionDisplay_ec const & solutionDisplay() const;

};

#endif // VIEW_RUNTIME_H
