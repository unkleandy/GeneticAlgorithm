// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :			

#pragma once
#ifndef _MUTATIONBYCHROMOSOME_H_
#define _MUTATIONBYCHROMOSOME_H_

#include "MutationStrategy.h"
#include "RandomTools.h"

class MutationByChromosome : public MutationStrategy
{
public:
	MutationByChromosome();
	~MutationByChromosome();
	void mutate(Solution & offspring) override;

};

#endif // !_MUTATIONBYCHROMOSOME_H_
