#include <cmath>

#include "CircleSolution.h"
#include "Canvas.h"


CircleSolution::CircleSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mCircle;
	size_t canvasWidth = (size_t)mCanvas.rectangle().size().width();
	size_t canvasHeight = (size_t)mCanvas.rectangle().size().height();
	size_t nbBitsX = size_t(ceil(log2(canvasWidth)));
	size_t nbBitsY = size_t(ceil(log2(canvasHeight)));
	size_t nbBitsRadius;
	if (canvasWidth < canvasHeight) {
		nbBitsRadius = size_t(ceil(log2((canvasWidth / 2) - 1)));
	} else {
		nbBitsRadius = size_t(ceil(log2((canvasHeight / 2) - 1)));
	}
	mChromosome.resize(nbBitsX + nbBitsY + nbBitsRadius);
}

void CircleSolution::randomize()
{
	mChromosome.randomize();
}

void CircleSolution::encode()
{
	mChromosome.write(uint32_t(mCircle.center().x()), 0, mNbBitsX);
	mChromosome.write(uint32_t(mCircle.center().y()), mNbBitsX, mNbBitsY);
	mChromosome.write(uint32_t(mCircle.radius()), mNbBitsX + mNbBitsY, mNbBitsRadius);
}

void CircleSolution::decode()
{	
	uint32_t X, Y, R;
	
	mChromosome.read(X, 0, mNbBitsX);
	mChromosome.read(Y, mNbBitsX, mNbBitsY);
	mChromosome.read(R, mNbBitsX + mNbBitsY, mNbBitsRadius);

	mCircle.set(Point(X, Y), R);
}

void CircleSolution::copy(Solution const & from)
{
	Solution::copy(from);
	mCircle = static_cast<CircleSolution const &>(from).mCircle;
}

CircleSolution * CircleSolution::clone() const
{
	CircleSolution * temp{ new CircleSolution(mCanvas) };
	temp->copy(*this);
	return temp;
}