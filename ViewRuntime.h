// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				G�re l'affichage de la simulation. La "vue" du mod�le MVC est ici divis�e
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
	// Enum qui associe les actions possible pendant la simulation � leurs entr�es au clavier.
	enum class keyBinding_ec : char {
		Exit_Runtime = 27,	// escape character
		Cycle_Solution_Display = 32,  // spacebar character
		None = 0, // utilis� pour "vider" mInputKey
		_count_
	};

	// Enum des diff�rentes options d'affichage. On peut d�cider de ne pas afficher de forme (none), d'afficher 
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

	// Lecture des entr�es au clavier.
	void readInput();

	// Effectue les actions correspondantes aux entr�es au clavier de l'usager.
	void doAction();

	// Parcourt les diff�rentes options d'affichage des solutions
	void cycleSolutionDisplay();

	// Demande l'affichage � l'�cran des solutions selon le type choisi par l'usager (mSolutionDisplay)
	void drawAsSolutionDisplaySelected(); // Pas de "const" car clearScreen est appel�

public:
	// Constructeur qui initialize le canvas (mCanvas) avec les param�tres de la console et mBlankImage avec un buffer vide (pour la m�thode clearScreen()).
	ViewRuntime();
	~ViewRuntime() = default;

	// Mutateur de la variable mShapeOptimizer qui est utilis�e pour que les entr�es au cliavier puisse modifier les 
	// variables des param�tres (sortie de la simulation et type d'affichage des solutions) qui sont dans la classe ShapeOptimizer.
	void setShapeOptimizer(ShapeOptimizer * shapeOptimizer);

	// Configuration des param�tres de la console. Afin de r�duire la tailel des pixels pour permettre un meilleur affichage des
	// formes g�om�triques la console doit �tre redimensionn�e.
	void setupWindow();

	// M�thode appel�e par l'observateur (mShapeObserver) lorsqu'une nouvelle g�n�ration des populations est compl�t�es. Demande le 
	// rafraichissement de l'�cran et une lecture des entr�es au clavier.
	void update();

	// Acesseur de la variable mCanvas.
	Canvas const & canvas() const;

	// Efface l'�cran.
	void clearScreen();

	// Accesseur de la variable mSolutionDisplay qui repr�sente le type d'affichage des solutions 
	// demand� par l'usager.
	solutionDisplay_ec const & solutionDisplay() const;

};

#endif // VIEW_RUNTIME_H
