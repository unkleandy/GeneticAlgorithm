#pragma once
#ifndef _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#define _CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
#include "CrossoverStrategy.h"

class CrossoverSinglePointByChromosome : public CrossoverStrategy
{
public:
	Solution const & breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring) override;
};

#endif // !_CROSSOVERSINGLEPOINTBYCHROMOSOME_H_
