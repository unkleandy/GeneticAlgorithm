
#include "MutationByChromosome.h"



MutationByChromosome::MutationByChromosome()
{
}


MutationByChromosome::~MutationByChromosome()
{
}

void MutationByChromosome::mutate(Solution & offspring)
{
	static int chromosome_size;
	static int randomDNAswitch;

	chromosome_size = offspring.chromosome().size();
	randomDNAswitch = (rand() % chromosome_size);
	offspring.chromosome()[randomDNAswitch] = !offspring.chromosome()[randomDNAswitch];
}
