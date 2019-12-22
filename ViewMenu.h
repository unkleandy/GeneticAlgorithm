// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Gère l'affichage du menu principal ainsi que la configuration des
//							différents paramètres du programme. La "vue" du modèle MVC est ici divisée
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
#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include <string>
#include <console.h>
#include "ShapeOptimizer.h"

// Foward declaration
class ShapeOptimizer;

class ViewMenu
{
public:

	// Constructeur qui initialize mBlankImage avec un buffer vide (pour la méthode clearScreen()).
	ViewMenu();
	~ViewMenu() = default;
	
	// Mutateur de la variable mShapeOptimizer qui est utilisée pour que le menu principal puisse modifier les 
	// variables des paramètres (nb d'obstacles, nb de population, etc) qui sont dans la classe ShapeOptimizer.
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);

	// Boucle qui gère les différentes composantes du menu principal.
	void run();

private:

	// Enum qui associe les actions du menu principal à leurs entrées au clavier.
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
		None = 0, // utilisé pour "vider" mInputKey
		_count_
	};

	// Enum des différentes formes qui peuvent être évaluées par l'IA.
	enum class availableShapes_ec : size_t {
		Rectangle,
		Circle,
		Losange,
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

	// Des ajustements de paramètre qui peuvent (ou auraient pu) éventuellement être ajoutés.
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
	bool mExitMenu{ false };
	keyBinding_ec mInputKey{ keyBinding_ec::None };

	// Configuration des paramètres de la console. Afin de permettre l'affichage de caractères lisibles la console doit être 
	// redimensionnée.
	void setupWindow();

	// Affichage du menu principal.
	void displayMenu() const;

	// Lecture des entrées au clavier.
	void readInput();

	// Effectue les actions correspondantes aux entrées au clavier de l'usager.
	void doAction();

	// Efface l'écran.
	void clearScreen();

	// Change la variable "mExitMenu" à "true" pour permettre la sortie du menu principal.
	void exitMenu();
};

#endif // VIEW_MENU_H
