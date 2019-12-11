#pragma once
#ifndef SHAPE_OBSERVER_H
#define SHAPE_OBSERVER_H

#include "GAEngine.h"
#include "EvolutionObserver.h"
#include "ShapeOptimizer.h"



class ShapeObserver : public EvolutionObserver
{
public:
	ShapeObserver();
	~ShapeObserver();
	/*
	void update(GAEngine const & engine) override;

private:
	ShapeOptimizer & mShapeOptimizer;
	*/
};

#endif // SHAPE_OBSERVER_H