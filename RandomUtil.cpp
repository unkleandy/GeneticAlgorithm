#include "RandomUtil.h"


std::random_device RandomUtil::randomDevice;
std::mt19937 RandomUtil::randomGenerator(randomDevice());


bool RandomUtil::generateEvent(double probability)
{
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

