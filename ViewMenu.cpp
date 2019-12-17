#include <iostream>
#include "ViewMenu.h"

std::string ViewMenu::sTxtTitle( "B52 - Projet Final" );
std::string ViewMenu::sFontStyle( "Consolas" );

std::string ViewMenu::sMenuText(
R"-(
B52 - Laboratoire 3 - Algorithme genetique

Controle des parametres :
 - [1][2][3][4][5][6]				Nombre de populations concurrentes
 - [F1][F2]							Taille de la population (-/+)
 - [F3][F4]							Taille de l'elitisme (-/+)
 - [F5][F6]							Taux de mutation (-/+)
 - [F7][F8]							Nombre maximum de generation (-/+)
 - [F9][F10]						Nombre d'obstacles sur le canevas (-/+)
 - [F12]							Reinitialiser la position des obstacles

Forme a optimiser : 
 - [a][s][d]						Cercle, Rectangle, Triangle

Controle : 
 - [esc]							Quitte l'application
 - [espace]							Demarre la simulation

Controle pendant la simulation : 
 - [esc]							Termine la simulation et revient à la page parametres
 - [espace]							Bascule l'affichage des solutions : aucune - toutes - la meilleure

... appuyez sur une touche pour continuer vers la configuration des parametres


)-");


ViewMenu::ViewMenu()
{
	using namespace windows_console;
	using namespace std;

	setupWindow();
	// mBlankImage est un buffer vide
	mBlankImage << fill;
	displayMenu();
}

void ViewMenu::setupWindow() {
	using namespace windows_console;
	csl << window::title(sTxtTitle);

	csl << window::fit(consoleWidth, consoleHeight, sFontStyle, mRunningFontSize, mRunningFontRatio)
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;
	csl >> mImage;
	csl >> mBlankImage;
}

void ViewMenu::clearScreen() {
	using namespace windows_console;
	csl << mBlankImage;
}

void ViewMenu::displayMenu() {
	std::cout << sMenuText;
	readInput();
}

void ViewMenu::readInput() {
	using namespace windows_console;
	console_events ce;
	while (true) {
		ce.read_events();
		while (ce.key_events_count()) {
			exit(0);
		}
	}
}
