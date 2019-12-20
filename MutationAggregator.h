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