#include <console.h>
#include "ShapeDiamond.h"
#include "Rectangle.h"


ShapeDiamond::ShapeDiamond() {
	mVertices.resize(3);
}

/*
void ShapeDiamond::set(double a, double b, Point center = Point(0.0, 0.0), double orientationDegrees = 0.0) {
	mDiamond.buildDiamond(x, y, center, orientationDegrees);
	mSideLength = sideLength;
	mVertices[0] = bottomLeft;
	mVertices[1] = Point(bottomLeft.x() + sideLength, bottomLeft.y()); // bottom right
	mVertices[2] = Point(bottomLeft.x() + (sideLength / 2), bottomLeft.y() - triangleHeight()); // top
	mDiamond.addVertex(mVertices[0]);
	mDiamond.addVertex(mVertices[1]);
	mDiamond.addVertex(mVertices[2]);
}
*/

size_t ShapeDiamond::triangleHeight() {
	return round(mSideLength * (sqrt(3) / 2));
}

void ShapeDiamond::rotate(size_t orientationDegrees) {
	mDiamond.rotate(orientationDegrees);
}

void ShapeDiamond::transform(size_t tX, size_t tY, size_t orientationDegrees, double relativeScale) {
	mDiamond.transform(tX, tY, orientationDegrees, relativeScale);
}


bool ShapeDiamond::isValid() const {
	return mDiamond.isValid();
}

void ShapeDiamond::draw() const {
	using namespace windows_console;
	image anImage;
	csl >> anImage;
	anImage << pen(dot, text_color(bright, red), background_color(dark, red))
		<< line(mVertices[0].x(), mVertices[0].y(), mVertices[1].x(), mVertices[1].y())
		<< line(mVertices[1].x(), mVertices[1].y(), mVertices[2].x(), mVertices[2].y())
		<< line(mVertices[2].x(), mVertices[2].y(), mVertices[0].x(), mVertices[0].y());
	csl << anImage;
}

double ShapeDiamond::area() const {
	return mDiamond.area();
}

Rectangle ShapeDiamond::boundingRect() const {
	return mDiamond.boundingBox();
}

bool ShapeDiamond::contains(Point const & p) const {
	return mDiamond.contained(p);
}

// Shape * ShapeDiamond::clone() const {}



