#include <size2d.h>
#include <console.h>
#include "ShapeRectangle.h"


// faire un triangle de 1 par 1 et transform

bool ShapeRectangle::isValid() const {
	return Rect2d::isValid();
}

void ShapeRectangle::draw(windows_console::image & anImage) const {
	using namespace windows_console;
	anImage << pen(dot, text_color(bright, red), background_color(dark, red))
		<< rectangle(this->topLeft().x(), this->topLeft().y(), this->size().height(),this->size().width());
}

double ShapeRectangle::area() const {
	return Rect2d::area();
}

Rectangle ShapeRectangle::boundingRect() const {
	return Rectangle(this->topLeft(),this->size() );
}


bool ShapeRectangle::contains(Point const & p) const {
	return Rect2d::contains(p);
}
