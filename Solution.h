#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H


#include "Fitness_t.h"
#include "Chromosome.h"


class Solution
{
public:
	Solution() = default;
	Solution(Solution const &) = default;
	Solution(Solution &&) = default;
	Solution& operator=(Solution const &) = delete;
	Solution& operator=(Solution &&) = delete;
	virtual ~Solution() = default;

	Chromosome const & chromosome() const;
	Chromosome & chromosome();
	fitness_t fitness() const;

	virtual void processFitness() = 0;
	virtual void randomize() = 0;
	virtual void encode() = 0;
	virtual void decode() = 0;

	virtual void copy(Solution const & from);
	virtual Solution * clone() const = 0;

protected:
	Chromosome mChromosome;
	fitness_t mFitness;
};


#endif // SOLUTION_H