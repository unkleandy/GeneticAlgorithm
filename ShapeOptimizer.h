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


class ViewMenu;
class ViewRuntime;

class ShapeOptimizer {

public:

	class ShapeObserver : public EvolutionObserver {
	private:
		ShapeOptimizer & mShapeOptimizer;
	public:
		ShapeObserver(ShapeOptimizer & shapeOptimizer);
		~ShapeObserver() = default;
		void update(GAEngine const & engine) override;
	};

	ShapeOptimizer(ViewMenu & viewMenu, ViewRuntime & viewRuntime);
	~ShapeOptimizer() = default;
	void run();
	void update(GAEngine const & engine);
	void drawPopulations();
	void raiseObstacleCount();
	void lowerObstacleCount();
	bool checkIfObstacleCountChanged();
	bool obstacleCountChanged();
	void cycleObstacleResetRequested();
	void setObstacleCountChanged(bool answer);
	void setObstacleResetRequested(bool answer);
	void setPopulationCount(size_t newCount);
	void cycleShape();
	void setQuitProgram(bool quit);
	void setExitRuntime(bool answer);
	size_t obstacleCount();
	size_t startingObstacleCount();
	bool obstacleResetRequested();
	size_t populationCount();
	bool quitProgram();
	bool exitRuntime();
	std::string resetRequestToString();
	std::string shapeToString();

private:
	enum class availableShapes_ec : size_t {
		Rectangle,
		Circle,
		Triangle,
		_count_
	};

	GAEngine mEngine;
	GAParameters mParameters;
	Canvas mCanvas;
	ViewMenu & mViewMenu;
	ViewRuntime & mViewRuntime;
	size_t mObstacleCount{ 20 };
	// Nombre d'obstacle lors de l'entr� dans le menu. Si mObstacleCount change la r�initialisation des obstacles est forc�e.
	size_t mStartingObstacleCount{ 20 };
	bool mObstacleCountChanged{ false };
	bool mObstacleResetRequested{ false };
	size_t mPopulationCount{ 1 };
	ShapeObserver mShapeObserver;
	availableShapes_ec mCurrentShape{ availableShapes_ec::Circle };
	bool mQuitProgram{ false };
	bool mExitRuntime{ false };


	//ShapeObserver mObserver;
	//size_t mPopulationSize;
	//size_t mElitismSize;
	//size_t mConcurrentPopulationCount;
	//size_t mMaximumGenerationCount;
	//std::string mChosenShape;
	void loadSolution();

public:
	availableShapes_ec currentShape();


};



#endif // SHAPE_OPTIMIZER_H