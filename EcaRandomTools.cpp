#include<random>
#include"EcaRandomTools.h"




//std::random_device RandomTools::randomDevice; // obtenir un nombre aléatoire du matériel (hardware)
//std::mt19937 RandomTools::randomGenerator(randomDevice()); // donne un germe aléatoire au générateur

bool EcaRandomTools::generateEvent(double probability)
{
	std::random_device randomDevice;
	std::mt19937 randomGenerator(randomDevice());
	std::bernoulli_distribution randomDistribution(probability);
	return randomDistribution(randomGenerator);
}

int EcaRandomTools::generateRandomNumber(int min, int max) {
	//std::uniform_int_distribution<> definer(min, max); // définit le range de la génération aléatoire
	//return definer(randomGenerator);
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}



 

