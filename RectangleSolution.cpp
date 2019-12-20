#include "RectangleSolution.h"



RectangleSolution::RectangleSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mRectangle;
}

void RectangleSolution::randomize()
{
}

void RectangleSolution::encode()
{
}

void RectangleSolution::decode()
{
}

void RectangleSolution::copy(Solution const & from)
{
}

RectangleSolution * RectangleSolution::clone() const
{
	return nullptr;
}