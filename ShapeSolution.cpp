#include "ShapeSolution.h"


ShapeSolution::ShapeSolution(Canvas const & canvas)
	: mCanvas{ canvas }
{
}

void ShapeSolution::draw() const
{
	mShape->draw();
}

void ShapeSolution::processFitness()
{
}

bool ShapeSolution::isInsideCanvas() const
{
	return false;
}

bool ShapeSolution::isObstaclesIntersect() const
{
	return false;
}