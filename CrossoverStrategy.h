// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:	Classe abstraie de strat�gie de reproduction entre deux solutions s�lectionn�es		
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :	Andr�a Cohen

#pragma once
#ifndef _CROSSOVERSTRATEGY_H_
#define _CROSSOVERSTRATEGY_H_
#include "Solution.h"


class CrossoverStrategy
{
public:
	virtual Solution const & breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) = 0;
};

#endif // !_CROSSOVERSTRATEGY_H_
