// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur : Andr�a Cohen		

#pragma once
#ifndef _SELECTIONSTRATEGY_H_
#define _SELECTIONSTRATEGY_H_

#include "Population.h"
#include "Solution.h"

class SelectionStrategy
{
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void prepare(Population const & population) = 0;
	virtual Solution const & select(Population const & population) = 0;
};

#endif // !_SELECTIONSTRATEGY_H_
