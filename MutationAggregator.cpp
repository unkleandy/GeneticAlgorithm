#include "MutationAggregator.h"
#include "CircleMutationByGene.h"

MutationAggregator::MutationAggregator() {
	setMutationRate(0.09);
	mAggregations.push_back(std::pair<double, MutationStrategy*>(0.65, static_cast<MutationStrategy*>(new MutationByChromosome())));
	mAggregations.push_back(std::pair<double, MutationStrategy*>(1, static_cast<MutationStrategy*>(new CircleMutationByGene())));
}

MutationAggregator::~MutationAggregator() {
}

void MutationAggregator::mutate(Solution & offspring) {
	

	double d{ ((double)rand() / (RAND_MAX)) };
	if (d < mutationRate()) {
		d = ((double)rand() / (RAND_MAX));
		for (std::pair<double, MutationStrategy*> p : mAggregations) {
			if (d < p.first) {
				p.second->mutate(offspring);
				break;
			}
		}
	}
}
