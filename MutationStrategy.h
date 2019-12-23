// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :	Andr�a Cohen	

#pragma once
#ifndef _MUTATIONSTRATEGY_H_
#define _MUTATIONSTRATEGY_H_

#include "Solution.h"

class MutationStrategy
{
private:
	double mMutationRate;
public:
	MutationStrategy();
	~MutationStrategy();
	//setters
	void setMutationRate(double mutationRate);
	//getters
	double mutationRate()const;
	virtual void mutate(Solution & offspring) = 0;
};

#endif // !_MUTATIONSTRATEGY_H_
