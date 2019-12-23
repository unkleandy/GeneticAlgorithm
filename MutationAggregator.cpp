#include "MutationAggregator.h"
#include "CircleMutationByGene.h"
#include "ShapeOptimizer.h"

MutationAggregator::MutationAggregator() {
	setMutationRate(0.95);
	mAggregations.push_back(std::pair<double, MutationStrategy*>(0.5, static_cast<MutationStrategy*>(new CircleMutationByGene())));
	mAggregations.push_back(std::pair<double, MutationStrategy*>(1, static_cast<MutationStrategy*>(new MutationByChromosome())));
}

MutationAggregator::~MutationAggregator() {
}

void MutationAggregator::mutate(Solution & offspring) {
	//premier if pour voir si on mutate
	double d{ ((double)rand() / (RAND_MAX)) };
	if (d < mutationRate()) {
		//deuxieme if pour choisir quelle strategy on utilise
		d = ((double)rand() / (RAND_MAX));
		for (std::pair<double, MutationStrategy*> p : mAggregations) {
			if (d < p.first) {
				p.second->mutate(offspring);
				break;
			}
		}
	}
}
