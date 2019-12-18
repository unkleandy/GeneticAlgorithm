#pragma once
#ifndef SHAPE_DIAMOND_H
#define SHAPE_DIAMOND_H

#include <Polygon2d.h>
#include "Shape.h"
#include "Point.h"

class ShapeDiamond : public Shape {

private:
	bg::Polygon2d mDiamond;
	std::vector<Point> mVertices;
	size_t const & mNbSides{ 3 };
	size_t mSideLength{};
	size_t triangleHeight();

public:
	ShapeDiamond();
	~ShapeDiamond() = default;

	void set(double a, double b, Point center = Point(0.0, 0.0), double orientationDegrees = 0.0);
	void rotate(size_t orientationDegrees);
	void transform(size_t tX, size_t tY, size_t orientationDegrees, double relativeScale);
	bool isValid() const override;
	void draw() const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;
	// Shape * clone() const override;



};

#endif // SHAPE_DIAMOND_H