#include "ShapeOptimizer.h"
#include "Solution.h"
#include "RectangleSolution.h"
#include "CircleSolution.h"
#include "DiamondSolution.h"


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
		if (!mQuitProgram) { // A voir: possible de pas répéter 2x la meme condition ? 
			mViewRuntime.setupWindow();
			mParameters.setToDefault();
			mParameters.setConcurrentPopulationCount(mPopulationCount);
			loadSolution();
			mParameters.setConcurrentPopulationCount(mPopulationCount);
			mEngine.registerObserver(mShapeObserver);
			mEngine.evolveUntilConvergence(mParameters);
		}
		mParameters.clearAll();
	}
}

void ShapeOptimizer::loadSolution() {
	//Solution * solutionPtr{};
	switch (mCurrentShape) {
	case  availableShapes_ec::Rectangle:
		mParameters.setSolutionSample(new RectangleSolution(mCanvas)); 
		break;
	case  availableShapes_ec::Circle:
		mParameters.setSolutionSample(new CircleSolution(mCanvas));
		break;
	case  availableShapes_ec::Losange:
		mParameters.setSolutionSample(new DiamondSolution(mCanvas)); 
		break;
	} 
}

void ShapeOptimizer::update(GAEngine const & engine) {
	mViewRuntime.update();
	if (mExitRuntime) {
		mEngine.stopEvolution();
		mExitRuntime = false;
	}
}

void ShapeOptimizer::drawPopulations(windows_console::image & anImage) const{
	for (size_t indexPopulation{ 0 }; indexPopulation < mPopulationCount; ++indexPopulation) {
		drawOnePopulation(indexPopulation, anImage);
	}
}

void ShapeOptimizer::drawOnePopulation(int const & indexPopulation, windows_console::image & anImage) const {
	int indexBrightness = 1;
	for (size_t indexSolution{ 0 }; indexSolution < mParameters.populationSize(); ++indexSolution) {
		if (indexSolution == mParameters.populationSize() - 1) {
			drawOneBestSolution(indexPopulation, anImage);
		}
		else {
			drawOneSolution(indexPopulation, indexSolution, indexBrightness, anImage);
		}
	}
}

void ShapeOptimizer::drawOneSolution(int const & indexPopulation, int const & indexSolution, int const & indexBrightness, windows_console::image & anImage) const {
	static_cast<ShapeSolution const &>(mEngine.population(indexPopulation)[indexSolution]).draw(anImage, mBrightnessTypes[indexBrightness], mColorTypes[indexPopulation]);

}

void ShapeOptimizer::drawOnlyBestSolutions(windows_console::image & anImage) const {
	int indexBrightness = 0;
	for (size_t indexPopulation{ 0 }; indexPopulation < mPopulationCount; ++indexPopulation) {
		drawOneBestSolution(indexPopulation, anImage);
	}
}

void ShapeOptimizer::drawOneBestSolution(int const & indexPopulation, windows_console::image & anImage) const {
	int indexBrightness = 0;
	int indexSolution = mParameters.populationSize() - 1;
	drawOneSolution(indexPopulation, indexSolution, indexBrightness, anImage);
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
	case ShapeOptimizer::availableShapes_ec::Losange:
		return "losange";
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
