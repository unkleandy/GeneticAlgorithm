// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteurs :				

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

	void randomize() override;
	void encode() override;
	void decode() override;
	void copy(Solution const & from) override;
	CircleSolution * clone() const override;

private:
	ShapeCircle mCircle;
	size_t mNbBitsX;
	size_t mNbBitsY;
	size_t mNbBitsRadius;
};


#endif // !CIRCLESOLUTION_H