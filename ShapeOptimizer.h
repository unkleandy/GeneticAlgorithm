// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				Repr�sente la boucle de gestion principale du programme. 	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer

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

	// Class interne qui appelle la mise � jour de l'affichage et la lecture des entr�es au clavier. 
	class ShapeObserver : public EvolutionObserver {
	private: 
		// N�cessaire pour que le "update" de ShapeObserver puisse appeler le "update" de ShapeOptimizer.
		ShapeOptimizer & mShapeOptimizer;
	public:
		// Constructeur qui initialise mShapeOptimizer avec une r�f�rence de l'instance de ShapeOptimizer cr��e dans le "main" lors de la mise en
		// marche du programme.
		ShapeObserver(ShapeOptimizer & shapeOptimizer);
		~ShapeObserver() = default;

		//"update" est appel� lorsqu'une �volution est compl�t�e pour mettre � jour l'affichage et faire la lecture des entr�es au clavier
		// par l'entremise de la m�thode "update" de ShapeOptimizer.
		void update(GAEngine const & engine) override;
	};

	// Constructeur qui initialize mViewMenu et mViewRuntime avec les instances qui ont �t� cr��es dans le "main" lors de la mise en marche du programme.
	// Initialize �galement mShapeObserver avec sa propre instance et mCanvas avec l'instace du canevas qui est dans viewRuntime.
	ShapeOptimizer(ViewMenu & viewMenu, ViewRuntime & viewRuntime);
	~ShapeOptimizer() = default;

	// Boucle principale du programme qui g�re la mise en marche des diff�rentes composantes.
	// Associe les s�lections de l'usager dans le menu principal aux param�tres de la simulation (mParameters).
	// Enregistre l'observateur dans l'engin GAEngine (mEngine). Cycle entre la vue du menu principale et la vue de 
	// la simulation.
	void run();

	// Met � jour l'affichage et appelle la lecture des entr�es au clavier
	void update(GAEngine const & engine);

	// Dessine les formes g�om�triques (les solutions) de toutes les populations � l'�cran.
	void drawPopulations(windows_console::image & anImage) const;

	// Dessine seulement les meilleures solutions trouv�e par l'IA avec une couleur brillante pour chaque population.
	void drawOnlyBestSolutions(windows_console::image & anImage) const;

	// Augmente le nombre d'obstacle (mObstacleCount) affich�s � l'�cran par tranche de 10.
	void raiseObstacleCount();

	// Diminue le nombre d'obstacle (mObstacleCount) affich�s � l'�cran par tranche de 10.
	void lowerObstacleCount();

	// V�rifie si le nombre d'obstacke a �t� chang� par l'usager depuis la mise en marche du menu principal.
	// Si c'est le cas mObstacleCountChanged est mis � "true". les obstacles doivent obligatoirement �tre repositionn�s al�atoirement (mObstacleResetRequested
	// est bloqu� � "true").
	bool checkIfObstacleCountChanged();

	// Accesseur de la variable qui est mise � "true" lorsque le nombre d'obstacle a �t� chang� par l'usager (mObstacleCountChanged).
	bool obstacleCountChanged();

	// Change la variable "mObstacleResetRequested" � "true" si elle est "false" et vice versa.
	void cycleObstacleResetRequested();

	// Mutateur de la variable qui est mise � "true" lorsque le nombre d'obstacle a �t� chang� par l'usager (mObstacleCountChanged).
	void setObstacleCountChanged(bool answer);

	// Mutateur de la variable qui est mise � "true" lorsqu'un repositionnement al�atoire des obstacles est demand�.
	void setObstacleResetRequested(bool answer);

	// Mutateur de la variable qui indique le nombre de population qui seront simultan�ment �valu�e.
	void setPopulationCount(size_t newCount);

	// Permet de s�lectionner la forme qui sera �valu�e. 
	void cycleShape();

	// Mutateur de la variable qui indique si l'arr�t du programme a �t� demand� par l'usager.
	void setQuitProgram(bool quit);

	// Mutateur de la variable qui indique si l'arr�t de la simulation a �t� demand� par l'usager.
	void setExitRuntime(bool answer);

	// Accesseur de la variable qui indique le nombre d'obstascle qui seront affich� � l'�cran.
	size_t obstacleCount();

	// Accesseur de la variable qui indique le nombre d'obstacle qu'il y avait lors de la mise en marche du menu principal.
	// Utilis� pour v�rifier si l'usager a demand� un changement de nombre d'obstacle.
	size_t startingObstacleCount();

	// Accesseur de la variable qui est mise � "true" lorsqu'un repositionnement al�atoire des obstacles est demand�.
	bool obstacleResetRequested();

	// Accesseur de la variable qui indique le nombre de population qui seront simultan�ment �valu�e.
	size_t populationCount();

	// Accesseur de la variable qui indique si l'arr�t du programme a �t� demand� par l'usager.
	bool quitProgram();

	// Accesseur de la variable qui indique si l'arr�t de la simulation a �t� demand� par l'usager.
	bool exitRuntime();

	// Permet la traduction de l'�tat de la  variable bool�enne "mObstacleResetRequested" en string pour �tre affich�e � l'�cran (true = "oui" et false = "non")
	std::string resetRequestToString();

	// Permet la traduction de l'�tat de la variable mCurrentShape en string afin que le nom de la forme s�lectionn�e soit affich� � l'�cran.
	std::string shapeToString();

private:

	// Enum des diff�rentes formes g�om�triques pouvant �tre �valu�es.
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

	// Nombre d'obstacle lors de l'entr� dans le menu. Si mObstacleCount change la r�initialisation du positionnement des obstacles est forc�e.
	size_t mStartingObstacleCount{ 20 };
	bool mObstacleCountChanged{ false };
	bool mObstacleResetRequested{ false };
	size_t mPopulationCount{ 1 };
	ShapeObserver mShapeObserver;
	availableShapes_ec mCurrentShape{ availableShapes_ec::Circle };
	bool mQuitProgram{ false };
	bool mExitRuntime{ false };

	// Vecteur contenant les 2 intensit� de luminosit� possibles pour l'affichage des formes � l'�cran. On utilise ce vecteur � l'aide d'un index lors de l'affichage des formes.
	std::vector<windows_console::brightness_type> const & mBrightnessTypes{ windows_console::brightness_type::bright,windows_console::brightness_type::dark };
	
	// Vecteur contenant les 4 couleurs possibles pour l'affichage des populations � l'�cran. On utilise ce vecteur � l'aide d'un index lors de l'affichage des formes.
	// Lorsqu'on affiche la premi�re population on s�lectionne la premi�re couleur et ainsi de suite.
	std::vector<windows_console::color_type> const & mColorTypes{ windows_console::color_type::red, windows_console::color_type::blue, windows_console::color_type::green,windows_console::color_type::yellow };
	
	// Associe la forme s�lectionn�e � sa solution dans les param�tres (GAParameters).
	void loadSolution();

	// Dessine la forme g�om�trique d'une solution � l'�cran
	void drawOneSolution(int const & indexPopulation, int const & indexSolution, int const & indexBrightness, windows_console::image & anImage) const;

	// Dessine les formes g�om�triques (les solutions) d'une populations � l'�cran.
	void drawOnePopulation(int const & indexPopulation, windows_console::image & anImage) const;

	// Dessine la meilleure solution d'une population trouv�e par l'IA avec une couleur plus brillante. 
	void drawOneBestSolution(int const & indexPopulation, windows_console::image & anImage) const;

public:
	// Accesseur de la variable qui indique la forme s�lectionn�e par l'usager pour la simulation
	availableShapes_ec currentShape();


};



#endif // SHAPE_OPTIMIZER_H