#include <cmath>

#include "DiamondSolution.h"
#include "Canvas.h"
#include "RandomTools.h"


DiamondSolution::DiamondSolution(Canvas const & canvas)
	: ShapeSolution(canvas)
{
	mShape = &mDiamond;
	mCanvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
	mCanvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
	mNbBitsHalfWidth = static_cast<size_t>(ceil(log2(mCanvasWidth / 2.0)));
	mNbBitsHalfHeight = static_cast<size_t>(ceil(log2(mCanvasHeight / 2.0)));
	mNbBitsX = static_cast<size_t>(ceil(log2(mCanvasWidth - 1.0)));
	mNbBitsY = static_cast<size_t>(ceil(log2(mCanvasHeight - 1.0)));
	mNbBitsOrientation = static_cast<size_t>(ceil(log2(360)));
	mChromosome.resize(mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX + mNbBitsY + mNbBitsOrientation);
}

void DiamondSolution::randomize()
{
	mDiamond.setHalfWidth(RandomTools::generateRandomNumber(0, static_cast<int>(mCanvasWidth / 2)));
	mDiamond.setHalfWidth(RandomTools::generateRandomNumber(0, static_cast<int>(mCanvasHeight / 2)));
	mDiamond.setCenter(Point(RandomTools::generateRandomNumber(mDiamond.halfWidth(), static_cast<int>(mCanvasWidth - mDiamond.halfWidth())), RandomTools::generateRandomNumber(mDiamond.halfHeight(), static_cast<int>(mCanvasHeight - mDiamond.halfHeight()))));
	mDiamond.setOrientation(RandomTools::generateRandomNumber(0, 360));
}

void DiamondSolution::encode()
{
	mChromosome.write(static_cast<uint32_t>(mDiamond.halfWidth()), 0, mNbBitsHalfWidth);
	mChromosome.write(static_cast<uint32_t>(mDiamond.halfHeight()), mNbBitsHalfWidth, mNbBitsHalfHeight);
	mChromosome.write(static_cast<uint32_t>(mDiamond.center().x()), mNbBitsHalfWidth + mNbBitsHalfHeight, mNbBitsX);
	mChromosome.write(static_cast<uint32_t>(mDiamond.center().y()), mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX, mNbBitsY);
	mChromosome.write(static_cast<uint32_t>(mDiamond.orientation()), mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX + mNbBitsY, mNbBitsOrientation);
}

void DiamondSolution::decode()
{
	uint32_t W{}, H{}, X{}, Y{}, O{};

	mChromosome.read(W, 0, mNbBitsHalfWidth);
	mChromosome.read(H, mNbBitsHalfWidth, mNbBitsHalfHeight);
	mChromosome.read(X, mNbBitsHalfWidth + mNbBitsHalfHeight, mNbBitsX);
	mChromosome.read(Y, mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX, mNbBitsY);
	mChromosome.read(O, mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX + mNbBitsY, mNbBitsOrientation);

	mDiamond.set(W, H, Point(X, Y), O);
}

void DiamondSolution::copy(Solution const & from)
{
	Solution::copy(from);
	mDiamond = static_cast<DiamondSolution const &>(from).mDiamond;
}

DiamondSolution * DiamondSolution::clone() const
{
	DiamondSolution * temp{ new DiamondSolution(mCanvas) };
	temp->copy(*this);
	return temp;
}