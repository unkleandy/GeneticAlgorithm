#pragma once

#ifndef POPULATIONENGINE_H
#define POPULATIONENGINE_H


#include "population.h"
#include "FitnessStatistics.h"
class GAParameter;


class PopulationEngine
{
public:
	PopulationEngine();
	~PopulationEngine();

	Population const & population() const;
	FitnessStatistics const & fitnessStatistics() const;
	void setup(GAParameters & parameters);
	void evolveOneGeneration(GAParameters & parameters);


private:
	Population mCurrentPopulation;
	Population mNextPopulation;
	FitnessStatistics mFitnessStatistics;

	void processElitism(size_t elitismSize);
	void processOneOffspring(GAParameters & parameters, size_t pos);
	void finalizeCurrentEvolution();
	void processStatistics();
};

#endif //POPULATIONENGINE_H

