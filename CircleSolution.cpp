#include <cmath>

#include "CircleSolution.h"
#include "Canvas.h"
#include "RandomTools.h"


CircleSolution::CircleSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mCircle;

	mCanvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	mCanvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	mNbBitsX = static_cast<size_t>(ceil(log2(mCanvasWidth - 1.0)));
	mNbBitsY = static_cast<size_t>(ceil(log2(mCanvasHeight - 1.0)));
	mNbBitsRadius = static_cast<size_t>(ceil(log2((std::min(mCanvasWidth, mCanvasHeight) / 2.0) - 1.0)));
	mChromosome.resize(mNbBitsX + mNbBitsY + mNbBitsRadius);
}

void CircleSolution::randomize()
{
	mCircle.setRadius(RandomTools::generateRandomNumber(0, mCanvasHeight / 2));
	mCircle.setCenter(Point(RandomTools::generateRandomNumber(static_cast<int>(mCircle.radius()), static_cast<size_t>(mCanvasWidth - mCircle.radius())), static_cast<size_t>(RandomTools::generateRandomNumber(mCircle.radius(), mCanvasHeight - mCircle.radius()))));
	encode();
}

void CircleSolution::encode()
{
	mChromosome.write(uint32_t(mCircle.center().x()), 0, mNbBitsX);
	mChromosome.write(uint32_t(mCircle.center().y()), mNbBitsX, mNbBitsY);
	mChromosome.write(uint32_t(mCircle.radius()), mNbBitsX + mNbBitsY, mNbBitsRadius);
}

void CircleSolution::decode()
{
	uint32_t X{}, Y{}, R{};

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

size_t const & CircleSolution::nbBitsX()
{
	return mNbBitsX;
}

size_t const & CircleSolution::nbBitsY()
{
	return mNbBitsY;
}

size_t const & CircleSolution::nbBitsRadius()
{
	return mNbBitsRadius;
}
