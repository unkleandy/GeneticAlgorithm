#include "MutationAggregator.h"
#include "CircleMutationByGene.h"

MutationAggregator::MutationAggregator() {
	mAggregations.push_back(std::pair<double, MutationStrategy*>(0.7, static_cast<MutationStrategy*>(new CircleMutationByGene())));
	mAggregations.push_back(std::pair<double, MutationStrategy*>(1, static_cast<MutationStrategy*>(new MutationByChromosome())));
}

MutationAggregator::~MutationAggregator() {
}

void MutationAggregator::mutate(Solution & offspring) {
	double d{ ((double)rand() / (RAND_MAX)) };
	for (std::pair<double, MutationStrategy*> p : mAggregations) {
		if (d < p.first ){
			p.second->mutate(offspring);
			break;
		}
	}
}
