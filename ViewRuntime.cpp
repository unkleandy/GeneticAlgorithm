#include "ViewRuntime.h"

ViewRuntime::ViewRuntime() 
: mCanvas(Rectangle(0, 0, consoleWidth, consoleHeight), (size_t)20)
{
	using namespace windows_console;
	using namespace std;
	// mBlankImage est un buffer vide
	mBlankImage << fill;
}

void ViewRuntime::setupWindow() {
	using namespace windows_console;
	csl << window::title(sTxtTitle);

	csl << window::fit(consoleWidth, consoleHeight, sFontStyle, mRunningFontSize, mRunningFontRatio)
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;
	csl >> mImage;
	csl >> mBlankImage;

	assert(mCanvas.isValid());
	if (mShapeOptimizer->checkIfObstacleCountChanged()) {
		mCanvas.setObstacles(mShapeOptimizer->obstacleCount());
		//mShapeOptimizer->setObstacleCountChanged(false);
	}
	if (mShapeOptimizer->obstacleResetRequested()) {
		mCanvas.randomizeObstacles();
		mShapeOptimizer->setObstacleResetRequested(false);
	}
}

void ViewRuntime::setShapeOptimizer(ShapeOptimizer * shapeOptimizer) {
	mShapeOptimizer = shapeOptimizer;
}

void ViewRuntime::update() {
	readInput();
	doAction();
	drawAsSolutionDisplaySelected();
}

void ViewRuntime::drawAsSolutionDisplaySelected(){
	using namespace windows_console;
	image  anImage;

	switch (mSolutionDisplay) {
	case solutionDisplay_ec::None:
		anImage << fill;
		break;
	case solutionDisplay_ec::All:
		mShapeOptimizer->drawPopulations(anImage);
		break;
	case solutionDisplay_ec::The_Best:
		mShapeOptimizer->drawOnlyBestSolutions(anImage);
		break;
	}
	mCanvas.drawObstacles(anImage);
	csl << anImage;
}

Canvas const & ViewRuntime::canvas() const {
	return mCanvas;
}

void ViewRuntime::clearScreen() {
	using namespace windows_console;
	csl << mBlankImage;
}

void ViewRuntime::readInput() {
	using namespace windows_console;
	console_events ce;

	ce.read_events();
	if (ce.key_events_count()) { // Le if fonctionne aussi bien que le while
		mInputKey = (keyBinding_ec)ce.next_key_event().ascii_value();
	}
}

void ViewRuntime::doAction() {
	switch (mInputKey) {
	case keyBinding_ec::Exit_Runtime:
		mShapeOptimizer->setExitRuntime(true);
		break;
	case keyBinding_ec::Cycle_Solution_Display:
   		cycleSolutionDisplay();
		break;
	}
	mInputKey = keyBinding_ec::None;
}

void ViewRuntime::cycleSolutionDisplay() {
	mSolutionDisplay = (solutionDisplay_ec)(((size_t)mSolutionDisplay + 1) % (size_t)solutionDisplay_ec::_count_);
}

ViewRuntime::solutionDisplay_ec const & ViewRuntime::solutionDisplay() const {
	return mSolutionDisplay;
}
