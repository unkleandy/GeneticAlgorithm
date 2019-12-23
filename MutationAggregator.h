// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :	Francis Labine		

#pragma once
#ifndef MUTATIONAGGREGATOR_H
#define MUTATIONAGGREGATOR_H
#include "MutationStrategy.h"
#include "MutationByChromosome.h"
#include <list>
class MutationAggregator : public MutationStrategy
{
public:
	MutationAggregator();
	~MutationAggregator();

	void mutate(Solution & offspring) override;

private:
	std::list<std::pair<double, MutationStrategy*>> mAggregations;
};

#endif // MUTATIONAGGREGATOR_H