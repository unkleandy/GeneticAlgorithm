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
	if (isObstaclesIntersect() || !isInsideCanvas()) {
		mFitness = 0.0;
	} else {
		mFitness = mShape->area();
	}
}

bool ShapeSolution::isInsideCanvas() const
{
	return mCanvas.rectangle().contains(mShape->boundingRect().topLeft()) && mCanvas.rectangle().contains(mShape->boundingRect().bottomRight());
}

bool ShapeSolution::isObstaclesIntersect() const
{
	for (Point p : mCanvas.obstacles()) {
		if (mShape->contains(p)) {
			return true;
		}
	}
	return false;
}