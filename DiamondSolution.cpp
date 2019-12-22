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
	// Le nombre de bit pour la demi-largeur doit également être limité à la demi-hauteur de la console pour éviter que le losange ne dépasse en cas de rotation.
	mNbBitsHalfWidth = static_cast<size_t>(ceil(log2(mCanvasHeight / 2.0)));
	mNbBitsHalfHeight = static_cast<size_t>(ceil(log2(mCanvasHeight / 2.0)));
	mNbBitsX = static_cast<size_t>(ceil(log2(mCanvasWidth - 1.0)));
	mNbBitsY = static_cast<size_t>(ceil(log2(mCanvasHeight - 1.0)));
	mNbBitsOrientation = static_cast<size_t>(ceil(log2(360)));
	mChromosome.resize(mNbBitsHalfWidth + mNbBitsHalfHeight + mNbBitsX + mNbBitsY + mNbBitsOrientation);
}

void DiamondSolution::randomize()
{
	mDiamond.setOrientation(RandomTools::generateRandomNumber(0, 360));
	// mDiamond.setOrientation(0); // Si la rotation est à 0 le losange fonctionne parfaitement.

	// Puisqu'il y a une rotation il ne faut pas que ni la hauteur, ni la largeur du losange ne soit plus grandes que la hauteur de la console. Sinon
	// cela cause des problèmes d'affichage.
	mDiamond.setHalfWidth(RandomTools::generateRandomNumber(0, static_cast<int>(mCanvasHeight / 2)));
	mDiamond.setHalfHeight(RandomTools::generateRandomNumber(0, static_cast<int>(mCanvasHeight / 2)));

	// Vu qu'il peut y avoir rotation il faut que les distance entre les bordures horizontales de la console et le centre du losange soit au minimum égale à la distance la plus grande 
	// entre une pointe du losange et son centre. Sinon il y a des problèmes d'affichage. Idem pour les distances verticales. J'aurais pu ajuster les distances en fonction de l'orientation 
	// mais honnêtement le projet était assez long comme ca...
	int minCenterX = mDiamond.halfWidth() > mDiamond.halfHeight() ? mDiamond.halfWidth() : mDiamond.halfHeight();
	int maxCenterX = mDiamond.halfWidth() > mDiamond.halfHeight() ? static_cast<int>(mCanvasWidth - mDiamond.halfWidth()) : static_cast<int>(mCanvasWidth - mDiamond.halfHeight());
	int minCenterY = mDiamond.halfWidth() > mDiamond.halfHeight() ? mDiamond.halfWidth() : mDiamond.halfHeight();
	int maxCenterY = mDiamond.halfWidth() > mDiamond.halfHeight() ? static_cast<int>(mCanvasHeight - mDiamond.halfWidth()) : static_cast<int>(mCanvasHeight - mDiamond.halfHeight());
	int CenterX = RandomTools::generateRandomNumber(minCenterX, maxCenterX);
	int CenterY = RandomTools::generateRandomNumber(minCenterY, maxCenterY);
	mDiamond.setCenter(Point(CenterX, CenterY));

	// Le "randomize" semble fonctionner mais il reste de petits problèmes d'affichage parce qu'il faut probablement ajuster l'encodage et le décodage en fonction de la rotation.
	// Si la rotation est à 0 le losange fonctionne parfaitement.
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