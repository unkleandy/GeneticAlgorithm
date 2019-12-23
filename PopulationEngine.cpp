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
	mCurrentPopulation.randomize();
	mNextPopulation.randomize();
	finalizeCurrentEvolution();
}

void PopulationEngine::evolveOneGeneration(GAParameters & parameters){
	parameters.selectionStrategy().prepare(mCurrentPopulation);
	processElitism(parameters.ellitismSize());
	for (size_t i{ parameters.ellitismSize() }; i < mCurrentPopulation.size(); ++i) {
		processOneOffspring(parameters, i);
	}
 	finalizeCurrentEvolution();
}

void PopulationEngine::processElitism(size_t elitismSize){
	for (size_t i{ 0 }; i < elitismSize; ++i) {
		mNextPopulation[i].copy(mCurrentPopulation[mCurrentPopulation.size() - 1]);
	}
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
	processStatistics();
}

void PopulationEngine::processStatistics() {
	fitness_t min{ mCurrentPopulation[0].fitness() }, max{ 0 }, avg{ 0 };
	for (size_t i{ 0 }; i < mCurrentPopulation.size(); ++i) {
		avg += mCurrentPopulation[i].fitness();
	}
	mFitnessStatistics.maximum = mCurrentPopulation[mCurrentPopulation.size()-1].fitness();
	mFitnessStatistics.minimum = mCurrentPopulation[0].fitness();
	mFitnessStatistics.average = avg / mCurrentPopulation.size();
}
