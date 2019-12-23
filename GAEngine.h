// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :			

#pragma once

#ifndef GAENGINE_H
#define GAENGINE_H

#include <vector>
#include <list>
#include <memory>
#include "GAParameters.h"
#include "EvolutionEngine.h"
#include "Population.h"
#include "FitnessStatistics.h"
#include "EvolutionStatus.h"
#include "EvolutionObserver.h"

class EvolutionObserver
{
public:
	EvolutionObserver() = default;
	~EvolutionObserver() = default;
	virtual void update(GAEngine const & engine) = 0;
};

class GAEngine
{
public:
	

	GAEngine();
	GAEngine(GAEngine const &) = default;
	GAEngine(GAEngine &&) = default;
	GAEngine& operator=(GAEngine const &) = default;
	GAEngine& operator=(GAEngine &&) = default;
	~GAEngine() = default;

	EvolutionStatus status() const;
	size_t currentGeneration(size_t populationIndex = 0) const;
	Population const & population(size_t populationIndex = 0) const;
	std::vector<FitnessStatistics> const & fitnessStatistics(size_t populationIndex = 0) const; // *

	void evolveUntilConvergence(GAParameters & parameters);
	void stopEvolution();

	void registerObserver(EvolutionObserver & observer);
	void unregisterObserver(EvolutionObserver & observer);
	void unregisterObservers();

private:
	EvolutionStatus mEvolutionStatus;
	std::vector<EvolutionEngine> mEvolutionEngines;        // *
	std::list<EvolutionObserver*> mObservers;

	void updateObservers();
};

#endif // GAENGINE_H
