// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe representant une solution en forme de losange
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur : Etienne Cote
// -Autre : Frederic Belanger

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

	////////////////////////////////////////////////////////////////////////////
	//Methodes redefinies deja expliquees dans les classes parentes abstraites//
	////////////////////////////////////////////////////////////////////////////
	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	DiamondSolution * clone() const override;

private:
	ShapeDiamond mDiamond;

	///////////////////////////////////////////////////////////////////////////////////
	//Nombre de bits allouees dans le chromosome pour chaque informations de la forme//
	///////////////////////////////////////////////////////////////////////////////////
	size_t mNbBitsHalfWidth;
	size_t mNbBitsHalfHeight;
	size_t mNbBitsX;
	size_t mNbBitsY;
	size_t mNbBitsOrientation;
	size_t mCanvasWidth;
	size_t mCanvasHeight;

};

#endif // !DIAMOND_SOLUTION_H
