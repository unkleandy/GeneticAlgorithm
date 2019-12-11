#pragma once
#ifndef _CROSSOVERSTRATEGY_H_
#define _CROSSOVERSTRATEGY_H_
#include <Solution.h>


class CrossoverStrategy
{
public:

	virtual Solution breed(Solution const & genitor1, Solution const & genitor2, Solution & offspring);
	CrossoverStrategy();
	~CrossoverStrategy();
};

#endif // !_CROSSOVERSTRATEGY_H_
