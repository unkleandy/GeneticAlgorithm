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

// Foward declaration
class ShapeOptimizer;

class ViewMenu
{
public:

	// Constructeur qui initialize mBlankImage avec un buffer vide (pour la m�thode clearScreen()).
	ViewMenu();
	~ViewMenu() = default;
	
	// Mutateur de la variable mShapeOptimizer qui est utilis�e pour que le menu principal puisse modifier les 
	// variables des param�tres (nb d'obstacles, nb de population, etc) qui sont dans la classe ShapeOptimizer.
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);

	// Boucle qui g�re les diff�rentes composantes du menu principal.
	void run();

private:

	// Enum qui associe les actions du menu principal � leurs entr�es au clavier.
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

	// Enum des diff�rentes formes qui peuvent �tre �valu�es par l'IA.
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

	// Des ajustements de param�tre qui peuvent (ou auraient pu) �ventuellement �tre ajout�s.
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

	// Configuration des param�tres de la console. Afin de permettre l'affichage de caract�res lisibles la console doit �tre 
	// redimensionn�e.
	void setupWindow();

	// Affichage du menu principal.
	void displayMenu() const;

	// Lecture des entr�es au clavier.
	void readInput();

	// Effectue les actions correspondantes aux entr�es au clavier de l'usager.
	void doAction();

	// Efface l'�cran.
	void clearScreen();

	// Change la variable "mExitMenu" � "true" pour permettre la sortie du menu principal.
	void exitMenu();
};

#endif // VIEW_MENU_H
