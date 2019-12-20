#pragma once
#ifndef SHAPE_EQUILATERAL_TRIANGLE_H
#define SHAPE_EQUILATERAL_TRIANGLE_H

#include <Polygon2d.h>
#include "Shape.h"
#include "Point.h"

class ShapeEquilateralTriangle : public Shape {

private:
	bg::Polygon2d mTriangle;
	std::vector<Point> mVertices;
	size_t const & mNbSides{3};
	size_t mSideLength{};
	size_t triangleHeight();

public:
	ShapeEquilateralTriangle();
	~ShapeEquilateralTriangle() = default;

	void set(Point bottomLeft, size_t sideLength);
	void rotate(size_t orientationDegrees);
	void transform(size_t tX, size_t tY, size_t orientationDegrees, double relativeScale);
	bool isValid() const override;
	void draw() const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;
	// Shape * clone() const override;



};

#endif // SHAPE_EQUILATERAL_TRIANGLE_H

