// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :				

#pragma once
#ifndef _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#define _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#include "CrossoverStrategy.h"
#include "Solution.h"



class CrossoverSinglePointByChromosome : public CrossoverStrategy
{
public:
	Solution const & breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;
};

#endif // !_CROSSOVERSINGLEPOINTBYCHROMOSOME_H_