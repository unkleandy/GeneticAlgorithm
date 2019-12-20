#include "EvolutionEngine.h"



EvolutionEngine::EvolutionEngine()
{
}


EvolutionEngine::~EvolutionEngine(){
}

size_t EvolutionEngine::currentGeneration() const{
	return mCurrentGeneration;
}

Population const & EvolutionEngine::population() const{
	return mPopulationEngine.population();
}

fitnessStatisticsOverTime const & EvolutionEngine::fitnessStatistics() const{
	return mFitnessStatisticsOverEpoch;
}

void EvolutionEngine::setup(GAParameters & parameters){
	mPopulationEngine.setup(parameters);
}

void EvolutionEngine::evolveOneGeneration(GAParameters & parameters){
	mPopulationEngine.evolveOneGeneration(parameters);
}
