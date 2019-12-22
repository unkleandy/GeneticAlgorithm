#include "CrossoverSinglePointByChromosome.h"
#include "Chromosome.h"
#include "Solution.h"

Solution const & CrossoverSinglePointByChromosome::breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring)
{
	static int gene_size;
	static int crossoverPoint;

	gene_size = offspring.chromosome().size();
	crossoverPoint = (rand() % gene_size);

	for (int i{}; i < crossoverPoint; ++i) {
		offspring.chromosome()[i] = genitor1.chromosome()[i];
	}
	for (int i{ crossoverPoint }; i < gene_size; ++i) {
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
