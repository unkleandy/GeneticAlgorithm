#pragma once

#ifndef GAENGINE_H
#define GAENGINE_H

#include <vector>
#include <list>
#include <memory>

class GAParameters;
class EvolutionEngine;              // *
class Population;                   // *
struct FitnessStatistics;           // *

class GAEngine
{
public:
	class EvolutionObserver;
	enum class EvolutionStatus { NeverStarted, InProcess, SolutionAvailable };

	GAEngine();
	GAEngine(GAEngine const &) = default;
	GAEngine(GAEngine &&) = default;
	GAEngine& operator=(GAEngine const &) = default;
	GAEngine& operator=(GAEngine &&) = default;
	~GAEngine() = default;

	EvolutionStatus status() const;
	size_t currentGeneration() const;
	Population const & population(size_t populationIndex = 0) const;
	std::vector<FitnessStatistics> const & fitnessStatistics(size_t populationIndex = 0) const; // *

	bool evolveUntilConvergence(GAParameters & parameters);
	void stopEvolution();

	void registerObserver(EvolutionObserver & observer);
	void unregisterObserver(EvolutionObserver & observer);
	void unregisterObservers();

private:
	EvolutionStatus mEvolutionStatus{ EvolutionStatus::NeverStarted };
	std::vector<std::shared_ptr<EvolutionEngine>> mEvolutionEngines;        // *
	std::list<EvolutionObserver*> mObservers;

	void updateObservers();
};

class GAEngine::EvolutionObserver{
public:
	EvolutionObserver() = default;
	EvolutionObserver(EvolutionObserver const &) = default;
	EvolutionObserver(EvolutionObserver &&) = default;
	EvolutionObserver& operator=(EvolutionObserver const &) = default;
	EvolutionObserver& operator=(EvolutionObserver &&) = default;
	virtual ~EvolutionObserver() = default;

	virtual void update(GAEngine const & engine) = 0;
};


#endif // GAENGINE_H
