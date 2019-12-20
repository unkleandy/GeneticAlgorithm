#pragma once
#ifndef DIAMOND_SOLUTION_H
#define DIAMOND_SOLUTION_H


#include "Solution.h"
#include "ShapeSolution.h"
#include "ShapeDiamond.h"


class DiamondSolution : public ShapeSolution
{
public:
	DiamondSolution(Canvas const & canvas);
	~DiamondSolution() override = default;

	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	DiamondSolution * clone() const override;

private:
	ShapeDiamond mDiamond;
	size_t mNbBitsHalfWidth;
	size_t mNbBitsHalfHeight;
	size_t mNbBitsCenter;
	size_t mNbBitsOrientation;
};


#endif // !DIAMOND_SOLUTION_H
