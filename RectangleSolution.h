#pragma once
#ifndef RECTANGLESOLUTION_H
#define RECTANGLESOLUTION_H


#include "ShapeSolution.h"
#include "ShapeRectangle.h"


class RectangleSolution : public ShapeSolution
{
public:
	RectangleSolution(Canvas const & canvas);
	~RectangleSolution() override = default;

	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	RectangleSolution * clone() const override;

private:
	ShapeRectangle mRectangle;
};


#endif // !RECTANGLESOLUTION_H