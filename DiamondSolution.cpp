#include <cmath>

#include "DiamondSolution.h"
#include "Canvas.h"
#include "RandomTools.h"

//
//DiamondSolution::DiamondSolution(Canvas const & canvas)
//	: ShapeSolution(canvas)
//{
//	mShape = & mDiamond;
//	size_t canvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
//	size_t canvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
//	mNbBitsHalfWidth = static_cast<size_t>(ceil(log2(canvasWidth)));
//	mNbBitsHalfHeight = static_cast<size_t>(ceil(log2(canvasHeight)));
//	mNbBitsCenter = static_cast<size_t>(ceil(log2((std::min(canvasWidth, canvasHeight) / 2.0) - 1.0)));
//	mNbBitsOrientation = 
//	mChromosome.resize(mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsCenter + mNbBitsOrientation);
//}
//
//void DiamondSolution::randomize()
//{
//	size_t canvasWidth = static_cast<size_t>(mCanvas.rectangle().size().width());
//	size_t canvasHeight = static_cast<size_t>(mCanvas.rectangle().size().height());
//	mDiamond.setHalfWidth(RandomTools::generateRandomNumber(0, canvasWidth / 2));
//	mDiamond.setHalfWidth(RandomTools::generateRandomNumber(0, canvasHeight / 2));
//	mDiamond.setOrientation(RandomTools::generateRandomNumber(0, 360));
//	mDiamond.setCenter(Point(RandomTools::generateRandomNumber(mDiamond.halfWidth(), canvasWidth - mDiamond.halfWidth()), RandomTools::generateRandomNumber(mDiamond.halfHeight(), canvasWidth - mDiamond.halfHeight())));
//	//mChromosome.randomize();
//	//decode();
//}
//
//void DiamondSolution::encode()
//{
//	mChromosome.write(uint32_t(mDiamond.center().x()), 0, mNbBitsX);
//	mChromosome.write(uint32_t(mDiamond.center().y()), mNbBitsX, mNbBitsY);
//	mChromosome.write(uint32_t(mDiamond.radius()), mNbBitsX + mNbBitsY, mNbBitsRadius);
//}
//
//void DiamondSolution::decode()
//{
//	uint32_t X{}, Y{}, R{};
//
//	mChromosome.read(X, 0, mNbBitsX);
//	mChromosome.read(Y, mNbBitsX, mNbBitsY);
//	mChromosome.read(R, mNbBitsX + mNbBitsY, mNbBitsRadius);
//
//	mDiamond.set(Point(X, Y), R);
//}
//
//void DiamondSolution::copy(Solution const & from)
//{
//	Solution::copy(from);
//	mDiamond = static_cast<DiamondSolution const &>(from).mDiamond;
//}
//
//DiamondSolution * DiamondSolution::clone() const
//{
//	DiamondSolution * temp{ new DiamondSolution(mCanvas) };
//	temp->copy(*this);
//	return temp;
//}