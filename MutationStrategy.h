#pragma once
#ifndef _MUTATIONSTRATEGY_H_
#define _MUTATIONSTRATEGY_H_

#include <Solution.h>

class MutationStrategy
{
private:
	double mMutationRate;
public:
	MutationStrategy();
	~MutationStrategy();
	//setters
	void setMutationRate(double mutationRate);
	//getters
	double mutationRate();
	virtual void mutate(Solution & offspring) = 0;
};

#endif // !_MUTATIONSTRATEGY_H_
