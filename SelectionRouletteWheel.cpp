#include "SelectionRouletteWheel.h"
#include "RandomTools.h"


SelectionRouletteWheel::SelectionRouletteWheel()
{
}


SelectionRouletteWheel::~SelectionRouletteWheel()
{
}

void SelectionRouletteWheel::prepare(Population const & population)
{
	mRankWeight.resize(population.size());
	fitness_t fitness_sum = 0;
	for (size_t i{}; i < population.size(); ++i)
	{
		fitness_sum += population[i].fitness();
		mRankWeight[i] = fitness_sum;
	}

}

Solution const & SelectionRouletteWheel::select(Population const & population)
{
	//std::uniform_real_distribution<double> unif(0, mRankWeight[population.size()-1]);
	//std::default_random_engine re;
	//fitness_t lady_luck = unif(re); // Luck be my lady tonight!
	fitness_t lady_luck = RandomTools::generateRandomNumber(0, mRankWeight[population.size() - 1]);


	int i{ 0 };
	while (lady_luck > mRankWeight[i])
	{
		++i;
	}
	return population[i];
}
