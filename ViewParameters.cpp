#include <iostream>
#include "ViewParameters.h"

std::string ViewParameters::sTxtTitle("B52 - Projet Final");
std::string ViewParameters::sFontStyle("Consolas");

std::string ViewParameters::sMenuTitle("Configuration des parametres de la simulation");
std::string ViewParameters::sActualObstacleCount("Le nombre d'obstacle actuel est de : ");
std::string ViewParameters::sChangeObstacleCountQuestion("Voulez-vous changer le nombre d'obstacle (O/N) ?");
std::string ViewParameters::sObstacleCountQuestion("Entrez le nombre d'obstacle désiré (min 0, max 250) : ");
std::string ViewParameters::sObstaclesPositionQuestion("Voulez-vous réinitialiser aléatoirement la position des obstacles?");

std::string ViewParameters::sElitismSizeQuestion("Entrez le ");
std::string ViewParameters::sPopulationCountQuestion;
std::string ViewParameters::sMaximumGenerationCountQuestion;
std::string ViewParameters::sChosenShapeQuestion;


ViewParameters::ViewParameters()
{
	using namespace windows_console;
	using namespace std;

	setupWindow();
	// mBlankImage est un buffer vide
	mBlankImage << fill;
	displayMenu();
}

void ViewParameters::setupWindow() {
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

void ViewParameters::clearScreen() {
	using namespace windows_console;
	csl << mBlankImage;
}

void ViewParameters::displayMenu() {
	std::cout << sMenuTitle;
	readInput();
}

void ViewParameters::readInput() {
	using namespace windows_console;
	console_events ce;
	while (true) {
		ce.read_events();
		while (ce.key_events_count()) {
			exit(0);
		}
	}
}

