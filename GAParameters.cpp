#include "GAParameters.h"
#include "MutationStrategy.h"
#include "SelectionStrategy.h"
#include "SelectionRouletteWheel.h"
#include "CrossoverSinglePointByChromosome.h"
#include "MutationByChromosome.h"
#include "ResetPointer.h"



GAParameters::GAParameters()
{
}


GAParameters::~GAParameters()
{
	clearAll();
}

bool GAParameters::isValid() const
{
	if (mPopulationSize < 3)
		return false;
	else if (mEllitismSize < 1 || mEllitismSize >= mPopulationSize)
		return false;
	else if (mConcurrentPopulationCount < 1 || mConcurrentPopulationCount>6)
		return false;
	else if (mMaximumGenerationCount < 3)
		return false;
	else if (mSolutionSample == nullptr)
		return false;
	else if (mSelectionStrategy == nullptr)
		return false;
	else if (mCrossoverStrategy == nullptr)
		return false;
	else if (mMutationStrategy == nullptr)
		return false;
	else
		return true;
}

size_t GAParameters::populationSize() const
{
	return mPopulationSize;
}

size_t GAParameters::ellitismSize() const
{
	return size_t();
}

size_t GAParameters::concurrentPopulationCount()
{
	return mEllitismSize;
}

size_t GAParameters::maximumGenerationCount() const
{
	return mMaximumGenerationCount;
}

SelectionStrategy & GAParameters::selectionStrategy()
{
	return  *mSelectionStrategy ;
}

CrossoverStrategy & GAParameters::crossoverStrategy()
{
	return * mCrossoverStrategy;
}

MutationStrategy & GAParameters::mutationStrategy()
{
	return *mMutationStrategy;
}

Solution const & GAParameters::solutionSample() const
{
	return * mSolutionSample;
}

void GAParameters::setPopulationSize(size_t size)
{
	mPopulationSize = size;
}

void GAParameters::setEllitismSize(size_t size)
{
	mEllitismSize = mEllitismSize;
}

void GAParameters::setConcurrentPopulationCount(size_t count)
{
	mConcurrentPopulationCount = count;
}

void GAParameters::setMaximumGenerationCount(size_t count)
{
	mMaximumGenerationCount = count;
}

void GAParameters::setSelectionStrategy(SelectionStrategy * strategy)
{
	delete(mSelectionStrategy);
	mSelectionStrategy = strategy;
}

void GAParameters::setCrossoverStrategy(CrossoverStrategy * strategy)
{
	delete (mCrossoverStrategy);
	mCrossoverStrategy = strategy;
}

void GAParameters::setMutationStrategy(MutationStrategy * strategy)
{
	delete (mMutationStrategy);
	mMutationStrategy = strategy;
}

void GAParameters::setSolutionSample(Solution * solution)
{
	delete (mSolutionSample);
	mSolutionSample = solution;
}

void GAParameters::clearAll()
{
	pDelete(mSelectionStrategy);
	pDelete (mCrossoverStrategy);
	pDelete (mMutationStrategy);
	pDelete (mSolutionSample);
}

void GAParameters::setToDefault()
{
	mPopulationSize = 50;
	mEllitismSize = 3;
	mConcurrentPopulationCount = 1;
	mMaximumGenerationCount = 150;
	pDelete(mSolutionSample);
	setSelectionStrategy(new SelectionRouletteWheel());
	setCrossoverStrategy(new CrossoverSinglePointByChromosome());
	setMutationStrategy(new MutationByChromosome());
}
