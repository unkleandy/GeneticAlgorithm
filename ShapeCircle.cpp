#define _USE_MATH_DEFINES
#include<cmath>
#include <console.h>
#include "ShapeCircle.h"


Point const & ShapeCircle::center() const {
	return mCenter;
}

double ShapeCircle::radius() const {
	return mRadius;
}

void ShapeCircle::setCenter(Point const & center) {
	mCenter = center;
}

void ShapeCircle::setRadius(double radius) {
	mRadius = radius;
}

void ShapeCircle::set(Point const & center, double radius) {
	setCenter(center);
	setRadius(radius);
}

bool ShapeCircle::isValid() const {
	if (mRadius == 0) {
		return false;
	}
	return true;
}

void ShapeCircle::draw() const {
	using namespace windows_console;
	image anImage;
	csl >> anImage;
	anImage << pen(dot, text_color(bright, red), background_color(dark, red))
		<< circle(mCenter.x(), mCenter.y(), mRadius);
	csl << anImage;
}

double ShapeCircle::area() const {
	return M_PI * mRadius * mRadius;
}

Rectangle ShapeCircle::boundingRect() const {
	return Rectangle(Point(mCenter.x() - mRadius, mCenter.y() - mRadius), Point(mCenter.x() + mRadius,mCenter.y()+mRadius)); // topLeft et bottomRight
}


bool ShapeCircle::contains(Point const & p) const{
	if(p.distance2(mCenter)<(mRadius * mRadius)) {
		return true;
	}
	return false;
}
