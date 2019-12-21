#include <iostream>
#include "ViewMenu.h"

std::string ViewMenu::sTxtTitle( "B52 - Projet Final" );
std::string ViewMenu::sFontStyle( "Consolas" );

std::string ViewMenu::sMenuText(
R"-(
B52 - Laboratoire 3 - Algorithme genetique


Controles pendant la simulation :

 - [esc]	Termine la simulation et revient au menu
 - [espace]	Bascule l'affichage des solutions : aucune - toutes - la meilleure


Controles de ce menu : 

 - [esc]	Quitte l'application
 - [espace]	Demarre la simulation
)-");

std::string ViewMenu::sConfigTitle(				" Configuration des parametres de la simulation : ");
std::string ViewMenu::sChangeObstacleCount(		" - [q][w]\tNombre d'obstacles sur le canevas (-/+)");
std::string ViewMenu::sCurrentObstacleCount(	"   Nombre d'obstacle actuel : ");
std::string ViewMenu::sObstaclesPositionReset(	" - [e]\t\tReinitialiser la position des obstacles (des que le nombre d'obstacle est ajuste, cette option est automatiquement \"oui\" ");
std::string ViewMenu::sObstaclesResetRequested(			"   Reinitialisation actuellement requise : ");
std::string ViewMenu::sChangePopulationCount(	" - [1][2][3][4]\tNombre de populations concurrentes");
std::string ViewMenu::sCurrentPopulationCount(	"   Nombre de populations actuel : ");
std::string ViewMenu::sChangeShape(				" - [a]\t\tForme a optimiser (Cercle, Rectangle, Triangle)");
std::string ViewMenu::sCurrentShape(			"   Forme a optimiser actuelle : ");

//std::string ViewMenu::sChangeElitismCount(	" - [F3][F4]		Taille de l'elitisme (-/+)");
//std::string ViewMenu::sCurrentElitismCount(	"	Nombre d'elites actuel : ");
//std::string ViewMenu::sChangeGenerationCount(	" - [F7][F8]		Nombre maximum de generation (-/+)");
//std::string ViewMenu::sCurrentGenerationCount("	Nombre maximum de generation actuel : ");

ViewMenu::ViewMenu()
{
	using namespace windows_console;
	using namespace std;

	// mBlankImage est un buffer vide
	mBlankImage << fill;

}

void ViewMenu::setupWindow() {
	using namespace windows_console;
	csl << window::title(sTxtTitle);

	csl << window::fit(mConsoleWidth, mConsoleHeight, sFontStyle, mRunningFontSize, mRunningFontRatio)
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;
	csl >> mImage;
	csl >> mBlankImage;
}

void ViewMenu::setShapeOptimizer(ShapeOptimizer * shapeOptimizer) {
	mShapeOptimizer = shapeOptimizer;
}

void ViewMenu::run() {
	setupWindow();
	displayMenu();
	while (!mExitMenu) {
		readInput();
	}
	mExitMenu = false;
}

void ViewMenu::clearScreen() {
	using namespace windows_console;
	csl << mBlankImage;
}

void ViewMenu::displayMenu() {
	std::cout << sMenuText << std::endl << std::endl;
	std::cout << sConfigTitle << std::endl << std::endl;
	std::cout << sChangeObstacleCount << std::endl;
	std::cout << sCurrentObstacleCount << mShapeOptimizer->obstacleCount() << std::endl << std::endl;
	std::cout << sObstaclesPositionReset << std::endl;
	std::cout << sObstaclesResetRequested << mShapeOptimizer->resetRequestToString() << std::endl << std::endl;
	std::cout << sChangePopulationCount << std::endl;
	std::cout << sCurrentPopulationCount << mShapeOptimizer->populationCount() <<std::endl << std::endl;
	std::cout << sChangeShape << std::endl;
	std::cout << sCurrentShape << mShapeOptimizer->shapeToString() << std::endl << std::endl;
}

void ViewMenu::readInput() {
	using namespace windows_console;
	console_events ce;
	ce.read_events();
	if (ce.key_events_count()) { // Le if fonctionne aussi bien que le while
		mInputKey = (keyBinding_ec)toupper(ce.next_key_event().ascii_value());
		switch (mInputKey) {
		case keyBinding_ec::Lower_Obstacle_Count:
			mShapeOptimizer->lowerObstacleCount();
			break;
		case keyBinding_ec::Raise_Obstacle_Count:
			mShapeOptimizer->raiseObstacleCount();
			break;
		case keyBinding_ec::Reset_Obstacle_Count:
			mShapeOptimizer->cycleObstacleResetRequested();
			break;
		case keyBinding_ec::Set_Population_Count1:
		case keyBinding_ec::Set_Population_Count2:
		case keyBinding_ec::Set_Population_Count3:
		case keyBinding_ec::Set_Population_Count4:
			mShapeOptimizer->setPopulationCount((size_t)((char)mInputKey - '0')); // '1' = 49 dont - 48 va donner 1 en int ('2'=50, '3'=51, etc)
			break;
		case keyBinding_ec::Cycle_Shape:
			mShapeOptimizer->cycleShape();
			break;
		case keyBinding_ec::Quit:
			mShapeOptimizer->setQuitProgram(true); // Pas de break: on veut sortir du menu lorsqu'on quit.
		case keyBinding_ec::Start_Simulation:
			exitMenu();
			break;
		}
		mInputKey = keyBinding_ec::None;
		clearScreen();
		if (mShapeOptimizer->obstacleCountChanged()) {
			mShapeOptimizer->setObstacleResetRequested(true);
		}
		if (!mExitMenu) {
			displayMenu();
		}
	}
}


void ViewMenu::exitMenu() {
	mExitMenu = true;
}



