#include "PopulationEngine.h"

PopulationEngine::PopulationEngine(){
}

PopulationEngine::~PopulationEngine(){
}

Population const & PopulationEngine::population() const{
	return mCurrentPopulation;
}

FitnessStatistics const & PopulationEngine::fitnessStatistics() const{
	return mFitnessStatistics;
}

void PopulationEngine::setup(GAParameters & parameters){
}

void PopulationEngine::evolveOneGeneration(GAParameters & parameters){
}

void PopulationEngine::processElitism(size_t elitismSize){
}

void PopulationEngine::processOneOffspring(GAParameters & parameters, size_t pos){
}

void PopulationEngine::finalizeCurrentEvolution(){
}

void PopulationEngine::processStatistics(){
}
