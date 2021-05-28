#pragma once
#ifndef CircleMutationByGene

#endif // !CircleMutationByGene

#include "MutationStrategy.h"
class CircleMutationByGene :
	public MutationStrategy
{
public:
	CircleMutationByGene();
	void mutate(Solution & offspring) override;
};

