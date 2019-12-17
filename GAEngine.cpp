#include "GAEngine.h"



GAEngine::GAEngine()
{
}

GAEngine::EvolutionStatus GAEngine::status() const
{
	return EvolutionStatus();
}

size_t GAEngine::currentGeneration() const
{
	//TODO: 
}

Population const & GAEngine::population(size_t populationIndex) const
{
	//TODO: 
}

std::vector<FitnessStatistics> const & GAEngine::fitnessStatistics(size_t populationIndex) const
{
	// TODO: insérer une instruction return ici
}

bool GAEngine::evolveUntilConvergence(GAParameters & parameters)
{
	return false;
}

void GAEngine::stopEvolution()
{
}

void GAEngine::registerObserver(EvolutionObserver & observer)
{
}

void GAEngine::unregisterObserver(EvolutionObserver & observer)
{
}

void GAEngine::unregisterObservers()
{
}

void GAEngine::updateObservers()
{
}
