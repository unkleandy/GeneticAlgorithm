
#include "MutationByChromosome.h"



MutationByChromosome::MutationByChromosome()
{
	
}


MutationByChromosome::~MutationByChromosome()
{
}

void MutationByChromosome::mutate(Solution & offspring){
	static int randomDNAswitch;
	randomDNAswitch= RandomTools::generateRandomNumber(0, offspring.chromosome().size() - 1) ;
	offspring.chromosome()[randomDNAswitch] = !offspring.chromosome()[randomDNAswitch];
}
