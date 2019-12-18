#include "Solution.h"


Solution::Solution()
	: mFitness{}
{
}

Chromosome const & Solution::chromosome() const
{
	return mChromosome;
}

Chromosome & Solution::chromosome()
{
	return mChromosome;
}

fitness_t Solution::fitness() const
{
	return mFitness;
}

void Solution::copy(Solution const & from)
{
	mChromosome = from.mChromosome;
	mFitness = from.mFitness;
	std::vector<int>mGeneLenths;
}