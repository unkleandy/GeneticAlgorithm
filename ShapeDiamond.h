#pragma once
#ifndef SHAPE_DIAMOND_H
#define SHAPE_DIAMOND_H

#include <console.h>
#include <Polygon2d.h>
#include "Shape.h"
#include "Point.h"

class ShapeDiamond : public Shape {

private:
	bg::Polygon2d mDiamond;
	int mX;
	int mY;
	int mOrientation;
	Point mCenter;



public:
	ShapeDiamond() = default;
	~ShapeDiamond() = default;

	void set(int a, int b, Point center = Point(0.0, 0.0), int orientationDegrees = 0);
	void setX(int x);
	void setY(int y);
	void setOrientation(int orientation);
	void setCenter(Point center);
	int x();
	int y();
	int orientation();
	Point center();
	bool isValid() const override;
	void draw(windows_console::image & anImage) const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;
	// Shape * clone() const override;



};

#endif // SHAPE_DIAMOND_H