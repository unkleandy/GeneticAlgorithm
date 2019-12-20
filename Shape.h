#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <console.h>
#include "Rectangle.h"
#include "Point.h"

class Shape
{
public:
	Shape() = default;
	~Shape() = default;
	
	virtual bool isValid() const = 0;
	virtual void draw(windows_console::image & anImage) const = 0;
	virtual double area() const = 0;
	virtual Rectangle boundingRect() const = 0 ;
	virtual bool contains(Point const & p) const = 0;
	virtual void setShapeBrightness(windows_console::brightness_type aBrightness) = 0;
	virtual void setShapeColor(windows_console::color_type aColor)=0;



protected:
	windows_console::brightness_type mShapeBrightness{ windows_console::brightness_type::dark};
	windows_console::color_type mShapeColor{ windows_console::color_type::red};

};

#endif // SHAPE_H