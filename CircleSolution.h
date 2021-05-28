// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe representant une solution de forme circulaire
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur :	Etienne Cote	

#pragma once
#ifndef CIRCLESOLUTION_H
#define CIRCLESOLUTION_H


#include "Solution.h"
#include "ShapeSolution.h"
#include "ShapeCircle.h"


class CircleSolution : public ShapeSolution
{
public:
	CircleSolution(Canvas const & canvas);
	~CircleSolution() override = default;

	///////////////////////////////////////////////////////////////////////////////////
	//Nombre de bits allouees dans le chromosome pour chaque informations de la forme//
	///////////////////////////////////////////////////////////////////////////////////
	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	CircleSolution * clone() const override;
	size_t const & nbBitsX();
	size_t const & nbBitsY();
	size_t const & nbBitsRadius();

private:
	ShapeCircle mCircle;

	size_t mNbBitsX;
	size_t mNbBitsY;
	size_t mNbBitsRadius;
	size_t mCanvasWidth;
	size_t mCanvasHeight;
};


#endif // !CIRCLESOLUTION_H