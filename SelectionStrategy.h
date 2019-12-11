#pragma once
#ifndef _SELECTIONSTRATEGY_H_
#define _SELECTIONSTRATEGY_H_

#include "Population.h"
#include "Solution.h"

class SelectionStrategy
{
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void prepare(Population const & population);
	//virtual Solution & const select(Population const & population);
};

#endif // !_SELECTIONSTRATEGY_H_
