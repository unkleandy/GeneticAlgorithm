#include "MutationStrategy.h"



void MutationStrategy::setMutationRate(double mutationRate)
{
	mMutationRate = mutationRate;
}

double MutationStrategy::mutationRate() const
{
	return mMutationRate;
}

void MutationStrategy::mutate(Solution & offspring) {}

MutationStrategy::MutationStrategy() {}


MutationStrategy::~MutationStrategy() {}
