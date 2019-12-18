#pragma once
#ifndef _SELECTIONROULETTEWHEEL_H_
#define _SELECTIONROULETTEWHEEL_H_

#include <vector>
#include "SelectionStrategy.h"


class SelectionRouletteWheel : public SelectionStrategy
{
public:
	SelectionRouletteWheel();
	~SelectionRouletteWheel();
	void prepare(Population const & population) override;
	Solution const & select(Population const & population) override;

protected:
	std::vector<double> mRankWeight;
};

#endif // !_SELECTIONROULETTEWHEEL_H_
