// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :			

#pragma once
#ifndef _CROSSOVERSTRATEGY_H_
#define _CROSSOVERSTRATEGY_H_
#include "Solution.h"


class CrossoverStrategy
{
public:

	virtual Solution const & breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) = 0;
	CrossoverStrategy();
	~CrossoverStrategy();
};

#endif // !_CROSSOVERSTRATEGY_H_
