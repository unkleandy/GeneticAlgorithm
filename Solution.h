#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include <console.h>
#include "Fitness_t.h"
#include "Chromosome.h"


class Solution
{
public:
	Solution();
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
	virtual void setSolutionBrightness(windows_console::brightness_type aBrightness) =0;
	virtual void setSolutionColor(windows_console::color_type aColor)=0;


protected:
	Chromosome mChromosome;
	fitness_t mFitness;
	

};


#endif // !SOLUTION_H