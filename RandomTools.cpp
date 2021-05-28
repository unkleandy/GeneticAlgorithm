#include<random>
#include"RandomTools.h"
#include <chrono>




//std::random_device RandomTools::randomDevice; // obtenir un nombre aléatoire du matériel (hardware)
//std::mt19937 RandomTools::randomGenerator(randomDevice()); // donne un germe aléatoire au générateur

bool RandomTools::generateEvent(double probability)
{
	//std::random_device randomDevice(std::chrono::steady_clock::now().time_since_epoch().count());
	std::mt19937 randomGenerator(static_cast<size_t>(std::chrono::steady_clock::now().time_since_epoch().count()));
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

int RandomTools::generateRandomNumber(int min, int max) {
	//std::uniform_int_distribution<> definer(min, max); // définit le range de la génération aléatoire
	//return definer(randomGenerator);
	//std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(static_cast<size_t>(std::chrono::steady_clock::now().time_since_epoch().count())); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}



 

