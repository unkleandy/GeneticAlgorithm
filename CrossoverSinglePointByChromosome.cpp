#include "CrossoverSinglePointByChromosome.h"


Solution const & CrossoverSinglePointByChromosome::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	static int crossoverPoint{ RandomTools::generateRandomNumber(0, offspring.chromosome().size()-1) };

	for (int i{}; i < crossoverPoint; ++i)
	{
		offspring.chromosome()[i] = genitor1.chromosome()[i];
	}
	for (int i{ crossoverPoint }; i < offspring.chromosome().size(); ++i)
	{
		offspring.chromosome()[i] = genitor2.chromosome()[i];
	}
	return offspring;
}

CrossoverSinglePointByChromosome::CrossoverSinglePointByChromosome()
{
}


CrossoverSinglePointByChromosome::~CrossoverSinglePointByChromosome()
{
}
