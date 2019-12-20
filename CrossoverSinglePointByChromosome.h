#pragma once
#ifndef _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#define _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#include "CrossoverStrategy.h"
#include "Solution.h"
#include "Chromosome.h"
#include "RandomUtil.h"
#include "RandomTools.h"

class CrossoverSinglePointByChromosome : public CrossoverStrategy
{
public:
	Solution const & breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;
	CrossoverSinglePointByChromosome();
	~CrossoverSinglePointByChromosome();
};

#endif // !_CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
