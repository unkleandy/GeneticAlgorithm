// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :	Francis Labine

#pragma once
#include "Population.h"
#include "FitnessStatistics.h"
#include "SelectionStrategy.h"
#include "CrossOverStrategy.h"
#include "MutationStrategy.h"

#ifndef POPULATIONENGINE_H
#define POPULATIONENGINE_H

class PopulationEngine
{
public:
	PopulationEngine();
	~PopulationEngine();

	Population const & population() const;
	FitnessStatistics const & fitnessStatistics() const;
	void setup(GAParameters & parameters);
	void evolveOneGeneration(GAParameters & parameters);
	void setPopulationColor(int index);


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

