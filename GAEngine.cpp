#include "GAEngine.h"

GAEngine::GAEngine()
{
}

EvolutionStatus GAEngine::status() const
{
	return mEvolutionStatus;
}

size_t GAEngine::currentGeneration(size_t populationIndex) const
{
	return (mEvolutionEngines[populationIndex]).currentGeneration();
}

Population const & GAEngine::population(size_t populationIndex) const
{
	return (mEvolutionEngines[populationIndex]).population();
}

std::vector<FitnessStatistics> const & GAEngine::fitnessStatistics(size_t populationIndex) const
{
	return (mEvolutionEngines[populationIndex]).fitnessStatistics();
}

void GAEngine::evolveUntilConvergence(GAParameters & parameters)
{
	mEvolutionEngines.resize(parameters.concurrentPopulationCount());
	int index = 0; // utilis� pour it�rer dans les couleurs de population
	for (EvolutionEngine & ee : mEvolutionEngines) 
	{
		ee.setup(parameters);
		ee.setPopulationColor(index);
		index++;
	}
	mEvolutionStatus = InProcess;
	while (currentGeneration() < parameters.maximumGenerationCount() && mEvolutionStatus == InProcess)
	{
		updateObservers();
		for (EvolutionEngine  & ee : mEvolutionEngines) {
			ee.evolveOneGeneration(parameters);
		}
		updateObservers();
	}
	mEvolutionStatus = SolutionAvailable;
}

void GAEngine::stopEvolution()
{
	mEvolutionStatus = SolutionAvailable;
}

void GAEngine::registerObserver(EvolutionObserver & observer)
{
	mObservers.push_back(&observer);
}

void GAEngine::unregisterObserver(EvolutionObserver & observer)
{
	mObservers.remove(&observer);
}

void GAEngine::unregisterObservers()
{
	mObservers.clear();
}

void GAEngine::updateObservers()
{
	for (EvolutionObserver* o : mObservers) {
		o->update(*this);
	}
}
