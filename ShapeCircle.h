#pragma once
#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H

#include <console.h>
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"

class ShapeCircle : public Shape {
public:
	ShapeCircle() = default;
	~ShapeCircle() = default;

	Point const & center() const;
	double radius() const;
	void setCenter(Point const & center);
	void setRadius(double radius);
	void set(Point const & center, double radius);
	bool isValid() const override; // pas mRadius = 0, 
	void draw(windows_console::image & anImage) const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;   // utiliser distance2 < mRadius * mRadius
	// Shape * clone() const override;



private:
	Point mCenter{Point(10,10)};
	double mRadius{1};


};

#endif // SHAPE_CIRCLE_H