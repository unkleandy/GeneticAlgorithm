#include "ShapeOptimizer.h"
#include "Solution.h"
#include "RectangleSolution.h"
#include "CircleSolution.h"


ShapeOptimizer::ShapeObserver::ShapeObserver(ShapeOptimizer & shapeOptimizer)
	:
	mShapeOptimizer{shapeOptimizer}
{
	
}

void ShapeOptimizer::ShapeObserver::update(GAEngine const & engine) {
	mShapeOptimizer.update(engine);
}


ShapeOptimizer::ShapeOptimizer(ViewMenu & viewMenu, ViewRuntime & viewRuntime)
	:
	mShapeObserver{ *this },
	mViewMenu{viewMenu},
	mViewRuntime{viewRuntime},
	mCanvas{viewRuntime.canvas()}
{
}

void ShapeOptimizer::run() {
	while (!mQuitProgram) {
		mStartingObstacleCount = mObstacleCount;
		mViewMenu.run();
		if (!mQuitProgram) { // Possible de pas répéter 2x la meme condition ? 
			mViewRuntime.setupWindow();
			mParameters.setToDefault();
			mParameters.setConcurrentPopulationCount(mPopulationCount);
			mParameters.setSolutionSample(new CircleSolution(mCanvas));
			mEngine.registerObserver(mShapeObserver);
			mEngine.evolveUntilConvergence(mParameters);
		}
	}
}

void ShapeOptimizer::loadSolution() {
	Solution * solutionPtr{};
	switch (mCurrentShape) {
	case  availableShapes_ec::Rectangle:
		solutionPtr = new RectangleSolution(mCanvas);
		break;
	case  availableShapes_ec::Circle:
		solutionPtr = new RectangleSolution(mCanvas);
		break;
	}
	mParameters.setSolutionSample(solutionPtr);
}

void ShapeOptimizer::update(GAEngine const & engine) {
	mViewRuntime.update();
	if (mExitRuntime) {
		mEngine.stopEvolution();
		mExitRuntime = false;
	}
}

void ShapeOptimizer::drawPopulations() {
	using namespace windows_console;
	image  anImage;
	csl >> anImage;
	for (size_t index{ 0 }; index < mPopulationCount; ++index) {
		for (size_t indexSolution{ 0 }; indexSolution < mParameters.populationSize();++indexSolution) {
			static_cast<ShapeSolution const &>(mEngine.population(index)[indexSolution]).draw(anImage);
		}
	}
	csl << anImage;
}

void ShapeOptimizer::raiseObstacleCount() {
	mObstacleCount += mObstacleCount < 250 ? 10 : 0;
	mObstacleResetRequested = true;
}

void ShapeOptimizer::lowerObstacleCount() {
	mObstacleCount -= mObstacleCount > 0 ? 10 : 0;
	mObstacleResetRequested = true;
}

bool ShapeOptimizer::checkIfObstacleCountChanged() {
	return mStartingObstacleCount != mObstacleCount ? true:false;
}

bool ShapeOptimizer::obstacleCountChanged() {
	return mObstacleCountChanged;
}

void ShapeOptimizer::cycleObstacleResetRequested() {
	if (!checkIfObstacleCountChanged()) {
		mObstacleResetRequested = !mObstacleResetRequested;
	}
}

void ShapeOptimizer::setObstacleCountChanged(bool answer) {
	mObstacleCountChanged = answer;
}

void ShapeOptimizer::setObstacleResetRequested(bool answer) {
	mObstacleResetRequested = answer;
}

void ShapeOptimizer::setPopulationCount(size_t newCount) {
	mPopulationCount = newCount;
}

void ShapeOptimizer::cycleShape() {
	mCurrentShape = (availableShapes_ec)(((size_t)mCurrentShape + 1) % (size_t)availableShapes_ec::_count_);
}

void ShapeOptimizer::setQuitProgram(bool quit) {
	mQuitProgram = quit;
}

void ShapeOptimizer::setExitRuntime(bool answer) {
	mExitRuntime = answer;
}

size_t ShapeOptimizer::obstacleCount() {
	return mObstacleCount;
}

size_t ShapeOptimizer::startingObstacleCount() {
	return mStartingObstacleCount;
}

bool ShapeOptimizer::obstacleResetRequested() {
	return mObstacleResetRequested;
}

size_t ShapeOptimizer::populationCount() {
	return mPopulationCount;
}

ShapeOptimizer::availableShapes_ec ShapeOptimizer::currentShape() {
	return mCurrentShape;
}

bool ShapeOptimizer::quitProgram() {
	return mQuitProgram;
}

bool ShapeOptimizer::exitRuntime() {
	return mExitRuntime;
}

// Aurait également pu être fait avec un map
std::string ShapeOptimizer::shapeToString() {
	switch (mCurrentShape) {
	case ShapeOptimizer::availableShapes_ec::Rectangle:
		return "rectangle";
		break;
	case ShapeOptimizer::availableShapes_ec::Circle:
		return "cercle";
		break;
	case ShapeOptimizer::availableShapes_ec::Triangle:
		return "triangle";
		break;
	default:
		return "";
		break;
	}
}

// Aurait également pu être fait avec un map
std::string ShapeOptimizer::resetRequestToString() {
	switch (mObstacleResetRequested) {
	case true:
		return "oui";
		break;
	case false:
		return "non";
		break;
	}
	return "";
}
