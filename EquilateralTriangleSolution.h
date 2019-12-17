#pragma once
#ifndef EQUILATERALTRIANGLESOLUTION_H
#define EQUILATERALTRIANGLESOLUTION_H


#include "ShapeSolution.h"
#include "ShapeEquilateralTriangle.h"


class EquilateralTriangleSolution : public ShapeSolution
{
public:
	EquilateralTriangleSolution(Canvas const & canvas);
	~EquilateralTriangleSolution() override = default;

	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	EquilateralTriangleSolution * clone() const override;

private:
	ShapeEquilateralTriangle mTriangle;
};


#endif // !EQUILATERALTRIANGLESOLUTION_H