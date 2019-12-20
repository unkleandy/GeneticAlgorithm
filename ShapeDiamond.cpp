#include <console.h>
#include "ShapeDiamond.h"
#include "Rectangle.h"

void ShapeDiamond::set(int x, int y, Point center , int orientationDegrees ) {
	mDiamond.buildDiamond(x, y, center, orientationDegrees);
}

void ShapeDiamond::setX(int x) {
	mX = x;
}

void ShapeDiamond::setY(int y) {
	mY = y;
}

void ShapeDiamond::setOrientation(int orientation) {
	mOrientation = orientation;
}

void ShapeDiamond::setCenter(Point center) {
	mCenter = center;
}

int ShapeDiamond::x() {
	return mX;
}

int ShapeDiamond::y() {
	return mY;
}

int ShapeDiamond::orientation() {
	return mOrientation;
}

Point ShapeDiamond::center() {
	return mCenter;
}

bool ShapeDiamond::isValid() const {
	return mDiamond.isValid();
}

void ShapeDiamond::draw(windows_console::image & anImage) const {
	using namespace windows_console;
	anImage << pen(dot, text_color(bright, red), background_color(dark, red));
	for (int index{ 0 }; index < mDiamond.size(); ++index) {
		anImage << line(mDiamond[index].x(), mDiamond[index].y(), mDiamond[index+1].x(), mDiamond[index+1].y());
	}
	anImage << line(mDiamond[mDiamond.size()-1].x(), mDiamond[mDiamond.size() - 1].y(), mDiamond[0].x(), mDiamond[0].y());
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



