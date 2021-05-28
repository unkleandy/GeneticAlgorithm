#include <size2d.h>
#include <console.h>
#include "ShapeRectangle.h"


bool const & ShapeRectangle::isValid() const {
	return Rect2d::isValid();
}

void ShapeRectangle::draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const {
	using namespace windows_console;
	anImage << pen(dot, text_color(aBrightness, aColor), background_color(aBrightness, aColor))
		<< rectangle(this->topLeft().x(), this->topLeft().y(), this->size().height(),this->size().width());
}

double const & ShapeRectangle::area() const {
	return Rect2d::area();
}

Rectangle ShapeRectangle::boundingRect() const {
	return Rectangle(this->topLeft(),this->size() );
}

bool const & ShapeRectangle::contains(Point const & p) const {
	return Rect2d::contains(p);
}

void ShapeRectangle::setShapeBrightness(windows_console::brightness_type const & aBrightness) {
	mShapeBrightness = aBrightness;
}

void ShapeRectangle::setShapeColor(windows_console::color_type const & aColor) {
	mShapeColor = aColor;
}