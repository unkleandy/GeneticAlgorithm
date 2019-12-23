#include "RectangleSolution.h"
#include "RandomTools.h"
#include "Point2d.h"


RectangleSolution::RectangleSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mRectangle;

	mCanvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	mCanvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	mNbBitsX = static_cast<size_t>(ceil(log2(mCanvasWidth - 1.0)));
	mNbBitsY = static_cast<size_t>(ceil(log2(mCanvasHeight - 1.0)));
	mNbBitsWidth = static_cast<size_t>(ceil(log2(mCanvasWidth)));
	mNbBitsHeight = static_cast<size_t>(ceil(log2(mCanvasHeight)));

	mChromosome.resize(mNbBitsX + mNbBitsY + mNbBitsWidth + mNbBitsHeight);
}

void RectangleSolution::randomize()
{
	size_t canvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	size_t canvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	size_t randLeft = RandomTools::generateRandomNumber(0, canvasWidth);
	size_t randRight = RandomTools::generateRandomNumber(randLeft, canvasWidth);
	size_t randTop = RandomTools::generateRandomNumber(0, canvasHeight);
	size_t randBottom = RandomTools::generateRandomNumber(randTop, canvasHeight);

	mRectangle.setTopLeft((randLeft, randTop));
	mRectangle.setBottomRight((randRight, randBottom));
}

void RectangleSolution::encode()
{
	mChromosome.write(static_cast<uint32_t>(mRectangle.topLeft().x()), 0, mNbBitsX);
	mChromosome.write(static_cast<uint32_t>(mRectangle.topLeft().y()), mNbBitsX, mNbBitsY);
	mChromosome.write(static_cast<uint32_t>(mRectangle.size().width()), mNbBitsX + mNbBitsY, mNbBitsWidth);
	mChromosome.write(static_cast<uint32_t>(mRectangle.size().height()), mNbBitsX + mNbBitsY + mNbBitsWidth, mNbBitsHeight);
}

void RectangleSolution::decode()
{
	uint32_t X{}, Y{}, W{}, H{};

	mChromosome.read(X, 0, mNbBitsX);
	mChromosome.read(Y, mNbBitsX, mNbBitsY);
	mChromosome.read(W, mNbBitsX + mNbBitsY, mNbBitsWidth);
	mChromosome.read(H, mNbBitsX + mNbBitsY + mNbBitsWidth, mNbBitsHeight);

	mRectangle.set(Point(X, Y), Point(X + W, Y + H));
}

void RectangleSolution::copy(Solution const & from)
{
	Solution::copy(from);
	mRectangle = static_cast<RectangleSolution const &>(from).mRectangle;
}

RectangleSolution * RectangleSolution::clone() const
{
	RectangleSolution * temp{ new RectangleSolution(mCanvas) };
	temp->copy(*this);
	return temp;
}