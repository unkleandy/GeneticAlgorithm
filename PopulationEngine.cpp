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
	mCurrentPopulation.set(parameters.populationSize(), parameters.solutionSample());
	mNextPopulation.set(parameters.populationSize(), parameters.solutionSample());
	mFitnessStatistics.reset();
	mNextPopulation.randomize();
	finalizeCurrentEvolution();
}

void PopulationEngine::evolveOneGeneration(GAParameters & parameters){
	parameters.selectionStrategy().prepare(mNextPopulation);
	processElitism(parameters.ellitismSize());

	for (int i{ 0 }; i < mCurrentPopulation.size()-1; ++i) {
		processOneOffspring(parameters, i);
	}
	finalizeCurrentEvolution();
	processStatistics();
}

void PopulationEngine::processElitism(size_t elitismSize){

}

void PopulationEngine::processOneOffspring(GAParameters & parameters, size_t pos){
	parameters.crossoverStrategy().breed(parameters.selectionStrategy().select(mCurrentPopulation), parameters.selectionStrategy().select(mCurrentPopulation), mNextPopulation[pos]);
	parameters.mutationStrategy().mutate(mNextPopulation[pos]);
}

void PopulationEngine::finalizeCurrentEvolution(){
	mNextPopulation.decode();
	mNextPopulation.processFitness();
	mNextPopulation.sort();
	mCurrentPopulation.swap(mNextPopulation);
}

void PopulationEngine::processStatistics(){
	fitness_t min{ 0 }, max{ 0 }, avg{ 0 };
	for (int i{ 0 }; i < mCurrentPopulation.size(); ++i) {
		mCurrentPopulation[i];
	}
}
