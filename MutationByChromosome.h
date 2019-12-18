#pragma once
#ifndef _MUTATIONBYCHROMOSOME_H_
#define _MUTATIONBYCHROMOSOME_H_

#include "MutationStrategy.h"

class MutationByChromosome : public MutationStrategy
{
public:
	MutationByChromosome();
	~MutationByChromosome();
	void mutate(Solution & offspring) override;

};

#endif // !_MUTATIONBYCHROMOSOME_H_
