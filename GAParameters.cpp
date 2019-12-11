#include "GAParameters.h"



GAParameters::GAParameters()
{
}


GAParameters::~GAParameters()
{
}

bool GAParameters::isValid() const
{
	return false;
}

size_t GAParameters::populationSize() const
{
	return size_t();
}

size_t GAParameters::ellitismSize() const
{
	return size_t();
}

size_t GAParameters::concurrentPopulationCount()
{
	return size_t();
}

size_t GAParameters::maximumGenerationCount() const
{
	return size_t();
}

//SelectionStrategy & GAParameters::selectionStrategy()
//{
//	// TODO: insérer une instruction return ici
//}

//CrossoverStrategy & GAParameters::crossoverStrategy()
//{
//	// TODO: insérer une instruction return ici
//}

//MutationStrategy & GAParameters::mutationStrategy()
//{
//	// TODO: insérer une instruction return ici
//}

//Solution const & GAParameters::solutionSample() const
//{
//	// TODO: insérer une instruction return ici
//}

void GAParameters::setPopulationSize(size_t size)
{
}

void GAParameters::setEllitismSize(size_t size)
{
}

void GAParameters::setConcurrentPopulationCount(size_t count)
{
}

void GAParameters::setMaximumGenerationCount(size_t count)
{
}

void GAParameters::setSelectionStrategy(SelectionStrategy * strategy)
{
}

void GAParameters::setCrossoverStrategy(CrossoverStrategy * strategy)
{
}

void GAParameters::setMutationStrategy(MutationStrategy * strategy)
{
}

void GAParameters::setSolutionSample(Solution * solution)
{
}

void GAParameters::clearAll()
{
}

void GAParameters::setToDefault()
{
}
