#include "EvolutionEngine.h"



EvolutionEngine::EvolutionEngine(){
}


EvolutionEngine::~EvolutionEngine(){
}

size_t EvolutionEngine::currentGeneration() const{
	return size_t();
}

Population const & EvolutionEngine::population() const{
	return mPopulationEngine.population();
}

fitnessStatisticsOverTime const & EvolutionEngine::fitnessStatistics() const{
	return mFitnessStatisticsOverEpoch;
}

void EvolutionEngine::setup(GAParameters & parameters){

}

void EvolutionEngine::evolveOneGeneration(GAParameters & parameters){
}
