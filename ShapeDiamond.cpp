#include <console.h>
#include "ShapeDiamond.h"
#include "Rectangle.h"

void ShapeDiamond::set(int const & halfWidth, int const & halfHeight, Point const & center , int const & orientationDegrees ) {
	mDiamond.buildDiamond(halfWidth, halfHeight, center, orientationDegrees);
}

void ShapeDiamond::setHalfWidth(int const & halfWidth) {
	mHalfWidth = halfWidth;
}

void ShapeDiamond::setHalfHeight(int const & halfHeight) {
	mHalfHeight = halfHeight;
}

void ShapeDiamond::setOrientation(int const & orientation) {
	mOrientation = orientation;
}

void ShapeDiamond::setCenter(Point const & center) {
	mCenter = center;
}

int const & ShapeDiamond::halfWidth() const {
	return mHalfWidth;
}

int const & ShapeDiamond::halfHeight() const {
	return mHalfHeight;
}

int const & ShapeDiamond::orientation() const {
	return mOrientation;
}

Point const & ShapeDiamond::center() const {
	return mCenter;
}

bool const & ShapeDiamond::isValid() const {
	return mDiamond.isValid();
}

void ShapeDiamond::draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const {
	using namespace windows_console;
	anImage << pen(dot, text_color(aBrightness, aColor), background_color(aBrightness, aColor));
	for (int index{ 0 }; index < mDiamond.size()-1; ++index) {
		anImage << line(mDiamond[index].x(), mDiamond[index].y(), mDiamond[index+1].x(), mDiamond[index+1].y());
	}
	anImage << line(mDiamond[mDiamond.size()-1].x(), mDiamond[mDiamond.size() - 1].y(), mDiamond[0].x(), mDiamond[0].y());
}

double const & ShapeDiamond::area() const {
	return mDiamond.area();
}

Rectangle ShapeDiamond::boundingRect() const {
	return mDiamond.boundingBox();
}

bool const & ShapeDiamond::contains(Point const & p) const {
	return mDiamond.contained(p);
}

void ShapeDiamond::setShapeBrightness(windows_console::brightness_type const & aBrightness) {
	mShapeBrightness = aBrightness;
}

void ShapeDiamond::setShapeColor(windows_console::color_type const & aColor) {
	mShapeColor = aColor;
}



