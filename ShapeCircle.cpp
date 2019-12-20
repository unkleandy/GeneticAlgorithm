#define _USE_MATH_DEFINES
#include<cmath>
#include <console.h>
#include "ShapeCircle.h"
#include "RandomTools.h"


//ShapeCircle::ShapeCircle()
//	:
//	mRadius{ (double)RandomTools::generateRandomNumber(0,100) },
//	mCenter{Point(RandomTools::generateRandomNumber(mRadius,300-mRadius), RandomTools::generateRandomNumber(mRadius, 200 - mRadius))}
//{
//
//}


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

void ShapeCircle::draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const {
	using namespace windows_console;
	anImage << pen(dot, text_color(aBrightness, aColor), background_color(aBrightness, aColor))
		<< circle(mCenter.x(), mCenter.y(), mRadius);
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

void ShapeCircle::setShapeBrightness(windows_console::brightness_type aBrightness) {
	mShapeBrightness = aBrightness;
}

void ShapeCircle::setShapeColor(windows_console::color_type aColor) {
	mShapeColor = aColor;
}