#include <cmath>

#include "CircleSolution.h"
#include "Canvas.h"
#include "RandomTools.h"


CircleSolution::CircleSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mCircle;
	size_t canvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	size_t canvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	mNbBitsX = static_cast<size_t>(ceil(log2(canvasWidth)));
	mNbBitsY = static_cast<size_t>(ceil(log2(canvasHeight)));
	mNbBitsRadius = static_cast<size_t>(ceil(log2((std::min(canvasWidth, canvasHeight) / 2.0) - 1.0)));
	mChromosome.resize(mNbBitsX + mNbBitsY + mNbBitsRadius);
}

void CircleSolution::randomize()
{
	size_t canvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	size_t canvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	mCircle.setRadius(RandomTools::generateRandomNumber(0, canvasHeight / 2));
	mCircle.setCenter(Point(RandomTools::generateRandomNumber(mCircle.radius(), canvasWidth - mCircle.radius()), RandomTools::generateRandomNumber(mCircle.radius(), canvasHeight - mCircle.radius())));
	//mChromosome.randomize();
	//decode();
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