#pragma once
#ifndef SHAPE_OPTIMIZER_H
#define SHAPE_OPTIMIZER_H

#include "GAEngine.h"
#include "Canvas.h"
#include "ShapeObserver.h"
#include "GAParameters.h"

class ShapeOptimizer
{
public:
	ShapeOptimizer() = default;
	~ShapeOptimizer() = default;
	void run();

	size_t mPopulationSize;
	size_t mElitismSize;
	size_t mConcurrentPopulationCount;
	size_t mMaximumGenerationCount;
	std::string mChosenShape;
	

private:
	GAEngine mEngine;
	GAParameters mParameters;
	Canvas mCanvas;
	//ShapeObserver mObserver;

	void update(GAEngine const & engine);
	
};

#endif // SHAPE_OPTIMIZER_H