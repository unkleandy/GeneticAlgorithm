// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
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