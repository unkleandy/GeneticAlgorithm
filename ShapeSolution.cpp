#include "ShapeSolution.h"
#include "ShapeCircle.h"


ShapeSolution::ShapeSolution(Canvas const & canvas)
	: mCanvas{ canvas }
{
}

void ShapeSolution::draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const
{
	mShape->draw(anImage, aBrightness, aColor);
}


void ShapeSolution::processFitness()
{

	if (isObstaclesIntersect() || !isInsideCanvas()) {

		mFitness = 0.0;

	}
	else {

		mFitness = mShape->area();

	}
}

bool ShapeSolution::isInsideCanvas() const
{

	return mCanvas.rectangle().contains(mShape->boundingRect().topLeft()) && mCanvas.rectangle().contains(mShape->boundingRect().bottomRight());

}


bool ShapeSolution::isObstaclesIntersect() const
{

	for (Point const & p : mCanvas.obstacles()) {

		if (mShape->contains(p)) {

			return true;
		}
	}
	return false;

}

Shape const & ShapeSolution::shape() const
{
	return *mShape;
}

void ShapeSolution::setShape(Shape * shape)
{
	mShape = shape;
}

void ShapeSolution::setSolutionBrightness(windows_console::brightness_type aBrightness) {
	mShape->setShapeBrightness(aBrightness);

}

void ShapeSolution::setSolutionColor(windows_console::color_type aColor) {
	mShape->setShapeColor(aColor);
}
