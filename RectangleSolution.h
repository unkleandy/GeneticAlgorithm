// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe representant une solution de forme rectangulaire
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur :	Etienne Cote

#pragma once
#ifndef RECTANGLESOLUTION_H
#define RECTANGLESOLUTION_H


#include "ShapeSolution.h"
#include "ShapeRectangle.h"


class RectangleSolution : public ShapeSolution
{
public:
	RectangleSolution(Canvas const & canvas);
	~RectangleSolution() override = default;

	////////////////////////////////////////////////////////////////////////////
	//Methodes redefinies deja expliquees dans les classes parentes abstraites//
	////////////////////////////////////////////////////////////////////////////
	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	RectangleSolution * clone() const override;

private:
	ShapeRectangle mRectangle;

	///////////////////////////////////////////////////////////////////////////////////
	//Nombre de bits allouees dans le chromosome pour chaque informations de la forme//
	///////////////////////////////////////////////////////////////////////////////////
	size_t mNbBitsX;
	size_t mNbBitsY;
	size_t mNbBitsWidth;
	size_t mNbBitsHeight;
	size_t mCanvasWidth;
	size_t mCanvasHeight;

};


#endif // !RECTANGLESOLUTION_H