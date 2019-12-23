#pragma once
#ifndef SHAPE_OBSERVER_H
#define SHAPE_OBSERVER_H

#include "GAEngine.h"
#include "ShapeOptimizer.h"



class ShapeObserver : public EvolutionObserver
{
public:
<<<<<<< HEAD
	ShapeObserver();
	~ShapeObserver();
	
	//void update(GAEngine const & engine) override;
=======
	ShapeObserver() = default;
	~ShapeObserver() = default;
	/*
	void update(GAEngine const & engine) override;
>>>>>>> origin/Frederic

private:
//	ShapeOptimizer & mShapeOptimizer;
	
};

#endif // SHAPE_OBSERVER_H