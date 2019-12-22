// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Représente la boucle de gestion principale du programme. 	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger

#pragma once
#ifndef SHAPE_OPTIMIZER_H
#define SHAPE_OPTIMIZER_H

#include "GAEngine.h"
#include "Canvas.h"
#include "ShapeOptimizer.h"
#include "GAParameters.h"
#include "ViewMenu.h"
#include "ViewRuntime.h"
#include "EvolutionObserver.h"

// "Forward declaration"
class ViewMenu;
class ViewRuntime;

class ShapeOptimizer {

public:

	// Class interne qui appelle la mise à jour de l'affichage et la lecture des entrées au clavier. 
	class ShapeObserver : public EvolutionObserver {
	private: 
		// Nécessaire pour que le "update" de ShapeObserver puisse appeler le "update" de ShapeOptimizer.
		ShapeOptimizer & mShapeOptimizer;
	public:
		// Constructeur qui initialise mShapeOptimizer avec une référence de l'instance de ShapeOptimizer créée dans le "main" lors de la mise en
		// marche du programme.
		ShapeObserver(ShapeOptimizer & shapeOptimizer);
		~ShapeObserver() = default;

		//"update" est appelé lorsqu'une évolution est complétée pour mettre à jour l'affichage et faire la lecture des entrées au clavier
		// par l'entremise de la méthode "update" de ShapeOptimizer.
		void update(GAEngine const & engine) override;
	};

	// Constructeur qui initialize mViewMenu et mViewRuntime avec les instances qui ont été créées dans le "main" lors de la mise en marche du programme.
	// Initialize également mShapeObserver avec sa propre instance et mCanvas avec l'instace du canevas qui est dans viewRuntime.
	ShapeOptimizer(ViewMenu & viewMenu, ViewRuntime & viewRuntime);
	~ShapeOptimizer() = default;

	// Boucle principale du programme qui gère la mise en marche des différentes composantes.
	// Associe les sélections de l'usager dans le menu principal aux paramêtres de la simulation (mParameters).
	// Enregistre l'observateur dans l'engin GAEngine (mEngine). Cycle entre la vue du menu principale et la vue de 
	// la simulation.
	void run();

	// Met à jour l'affichage et appelle la lecture des entrées au clavier
	void update(GAEngine const & engine);

	// Dessine les formes géométriques (les solutions) de toutes les populations à l'écran.
	void drawPopulations(windows_console::image & anImage) const;

	// Dessine seulement les meilleures solutions trouvée par l'IA avec une couleur brillante pour chaque population.
	void drawOnlyBestSolutions(windows_console::image & anImage) const;

	// Augmente le nombre d'obstacle (mObstacleCount) affichés à l'écran par tranche de 10.
	void raiseObstacleCount();

	// Diminue le nombre d'obstacle (mObstacleCount) affichés à l'écran par tranche de 10.
	void lowerObstacleCount();

	// Vérifie si le nombre d'obstacke a été changé par l'usager depuis la mise en marche du menu principal.
	// Si c'est le cas mObstacleCountChanged est mis à "true". les obstacles doivent obligatoirement être repositionnés aléatoirement (mObstacleResetRequested
	// est bloqué à "true").
	bool checkIfObstacleCountChanged();

	// Accesseur de la variable qui est mise à "true" lorsque le nombre d'obstacle a été changé par l'usager (mObstacleCountChanged).
	bool obstacleCountChanged();

	// Change la variable "mObstacleResetRequested" à "true" si elle est "false" et vice versa.
	void cycleObstacleResetRequested();

	// Mutateur de la variable qui est mise à "true" lorsque le nombre d'obstacle a été changé par l'usager (mObstacleCountChanged).
	void setObstacleCountChanged(bool answer);

	// Mutateur de la variable qui est mise à "true" lorsqu'un repositionnement aléatoire des obstacles est demandé.
	void setObstacleResetRequested(bool answer);

	// Mutateur de la variable qui indique le nombre de population qui seront simultanément évaluée.
	void setPopulationCount(size_t newCount);

	// Permet de sélectionner la forme qui sera évaluée. 
	void cycleShape();

	// Mutateur de la variable qui indique si l'arrêt du programme a été demandé par l'usager.
	void setQuitProgram(bool quit);

	// Mutateur de la variable qui indique si l'arrêt de la simulation a été demandé par l'usager.
	void setExitRuntime(bool answer);

	// Accesseur de la variable qui indique le nombre d'obstascle qui seront affiché à l'écran.
	size_t obstacleCount();

	// Accesseur de la variable qui indique le nombre d'obstacle qu'il y avait lors de la mise en marche du menu principal.
	// Utilisé pour vérifier si l'usager a demandé un changement de nombre d'obstacle.
	size_t startingObstacleCount();

	// Accesseur de la variable qui est mise à "true" lorsqu'un repositionnement aléatoire des obstacles est demandé.
	bool obstacleResetRequested();

	// Accesseur de la variable qui indique le nombre de population qui seront simultanément évaluée.
	size_t populationCount();

	// Accesseur de la variable qui indique si l'arrêt du programme a été demandé par l'usager.
	bool quitProgram();

	// Accesseur de la variable qui indique si l'arrêt de la simulation a été demandé par l'usager.
	bool exitRuntime();

	// Permet la traduction de l'état de la  variable booléenne "mObstacleResetRequested" en string pour être affichée à l'écran (true = "oui" et false = "non")
	std::string resetRequestToString();

	// Permet la traduction de l'état de la variable mCurrentShape en string afin que le nom de la forme sélectionnée soit affiché à l'écran.
	std::string shapeToString();

private:

	// Enum des différentes formes géométriques pouvant être évaluées.
	enum class availableShapes_ec : size_t {
		Rectangle,
		Circle,
		Losange,
		_count_
	};

	GAEngine mEngine;
	GAParameters mParameters;
	Canvas mCanvas;
	ViewMenu & mViewMenu;
	ViewRuntime & mViewRuntime;
	size_t mObstacleCount{ 20 };

	// Nombre d'obstacle lors de l'entré dans le menu. Si mObstacleCount change la réinitialisation du positionnement des obstacles est forcée.
	size_t mStartingObstacleCount{ 20 };
	bool mObstacleCountChanged{ false };
	bool mObstacleResetRequested{ false };
	size_t mPopulationCount{ 1 };
	ShapeObserver mShapeObserver;
	availableShapes_ec mCurrentShape{ availableShapes_ec::Circle };
	bool mQuitProgram{ false };
	bool mExitRuntime{ false };

	// Vecteur contenant les 2 intensité de luminosité possibles pour l'affichage des formes à l'écran. On utilise ce vecteur à l'aide d'un index lors de l'affichage des formes.
	std::vector<windows_console::brightness_type> const & mBrightnessTypes{ windows_console::brightness_type::bright,windows_console::brightness_type::dark };
	
	// Vecteur contenant les 4 couleurs possibles pour l'affichage des populations à l'écran. On utilise ce vecteur à l'aide d'un index lors de l'affichage des formes.
	// Lorsqu'on affiche la première population on sélectionne la première couleur et ainsi de suite.
	std::vector<windows_console::color_type> const & mColorTypes{ windows_console::color_type::red, windows_console::color_type::blue, windows_console::color_type::green,windows_console::color_type::yellow };
	
	// Associe la forme sélectionnée à sa solution dans les paramètres (GAParameters).
	void loadSolution();

	// Dessine la forme géométrique d'une solution à l'écran
	void drawOneSolution(int const & indexPopulation, int const & indexSolution, int const & indexBrightness, windows_console::image & anImage) const;

	// Dessine les formes géométriques (les solutions) d'une populations à l'écran.
	void drawOnePopulation(int const & indexPopulation, windows_console::image & anImage) const;

	// Dessine la meilleure solution d'une population trouvée par l'IA avec une couleur plus brillante. 
	void drawOneBestSolution(int const & indexPopulation, windows_console::image & anImage) const;

public:
	// Accesseur de la variable qui indique la forme sélectionnée par l'usager pour la simulation
	availableShapes_ec currentShape();


};



#endif // SHAPE_OPTIMIZER_H