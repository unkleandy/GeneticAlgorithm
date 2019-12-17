#pragma once
#ifndef TRIANGLESOLUTION_H
#define TRIANGLESOLUTION_H


#include "ShapeSolution.h"
#include "ShapeTriangle.h"


class TriangleSolution : public ShapeSolution
{
public:
	TriangleSolution(Canvas const & canvas);
	~TriangleSolution() override = default;

//	void randomize() override;
//	void encode() override;
//	void decode() override;
//	void copy(Solution const & from) override;
//	TriangleSolution * clone() const override;
//
//private:
//	ShapeTriangle mTriangle;
};


#endif // !TRIANGLESOLUTION_H