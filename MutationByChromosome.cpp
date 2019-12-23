
#include "MutationByChromosome.h"


MutationByChromosome::MutationByChromosome()
{
	setMutationRate(0.1);
}


MutationByChromosome::~MutationByChromosome()
{
}

void MutationByChromosome::mutate(Solution & offspring){
	static int randomDNAswitch{ RandomTools::generateRandomNumber(0, offspring.chromosome().size() - 1) };
	offspring.chromosome()[randomDNAswitch].flip();
}
