#pragma once
#ifndef EVOLUTIONENGINE_H
#define EVOLUTIONENGINE_H

#include "PopulationEngine.h"
#include "fitnessStatisticsOverTime.h"

class EvolutionEngine
{
public:
	EvolutionEngine();
	~EvolutionEngine();

	size_t currentGeneration() const;
	Population const & population() const;
	void setup(GAParameters & parameters);
	void evolveOneGeneration(GAParameters & parameters);
	fitnessStatisticsOverTime const & fitnessStatistics() const;

private:
	size_t mCurrentGeneration{};
	PopulationEngine mPopulationEngine{};
	fitnessStatisticsOverTime mFitnessStatisticsOverEpoch{};
};

#endif //EVOLUTIONENGINE_H

