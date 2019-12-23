#include <console.h>
#include "ShapeEquilateralTriangle.h"
#include "Rectangle.h"


ShapeEquilateralTriangle::ShapeEquilateralTriangle() {
	mVertices.resize(3);
}

void ShapeEquilateralTriangle::set(Point bottomLeft, size_t sideLength) {
	mSideLength = sideLength;
	mVertices[0] = bottomLeft;
	mVertices[1] = Point(bottomLeft.x()+sideLength,bottomLeft.y()); // bottom right
	mVertices[2] = Point(bottomLeft.x() + (sideLength / 2), bottomLeft.y() - triangleHeight()); // top
	mTriangle.addVertex(mVertices[0]);
	mTriangle.addVertex(mVertices[1]);
	mTriangle.addVertex(mVertices[2]);
}

size_t ShapeEquilateralTriangle::triangleHeight() {
	return round(mSideLength * (sqrt(3) / 2));
}

void ShapeEquilateralTriangle::rotate(size_t orientationDegrees) {
	mTriangle.rotate(orientationDegrees);
}

void ShapeEquilateralTriangle::transform(size_t tX, size_t tY, size_t orientationDegrees, double relativeScale) {
	mTriangle.transform(tX, tY, orientationDegrees, relativeScale);
}


bool ShapeEquilateralTriangle::isValid() const {
	return mTriangle.isValid();
}

<<<<<<< HEAD
void ShapeEquilateralTriangle::draw(windows_console::image & anImage) const {
	using namespace windows_console;
=======
void ShapeEquilateralTriangle::draw() const {
	using namespace windows_console;
	image anImage;
>>>>>>> origin/Frederic
	csl >> anImage;
	anImage << pen(dot, text_color(bright, red), background_color(dark, red))
		<< line(mVertices[0].x(), mVertices[0].y(), mVertices[1].x(), mVertices[1].y())
		<< line(mVertices[1].x(), mVertices[1].y(), mVertices[2].x(), mVertices[2].y())
		<< line(mVertices[2].x(), mVertices[2].y(), mVertices[0].x(), mVertices[0].y());
	csl << anImage;
}

double ShapeEquilateralTriangle::area() const {
	return mTriangle.area();
}

Rectangle ShapeEquilateralTriangle::boundingRect() const {
	return mTriangle.boundingBox();
}

bool ShapeEquilateralTriangle::contains(Point const & p) const {
	return mTriangle.contained(p);
}

// Shape * ShapeEquilateralTriangle::clone() const {}



