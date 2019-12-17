#pragma once
#ifndef SHAPESOLUTION_H
#define SHAPESOLUTION_H


#include "Solution.h"
#include "Canvas.h"
#include "Shape.h"


class ShapeSolution : public Solution
{
public:
	ShapeSolution(Canvas const & canvas);
	~ShapeSolution() override = default;

	void draw() const;
	void processFitness() override;
	bool isInsideCanvas() const;
	bool isObstaclesIntersect() const;

protected:
	Canvas const & mCanvas;
	Shape * mShape;
};


#endif // !SHAPESOLUTION_H