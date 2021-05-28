// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur : Andréa Cohen		

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
