#pragma once
#include "fitness_t.h"

#ifndef FITNESSSTATISTICS_H
#define FITNESSSTATISTICS_H


struct FitnessStatistics {
	size_t count = 0;
	fitness_t minimum = 0.0;
	fitness_t maximum = 0.0;
	fitness_t average = 0.0;

	//retour de tout les variables a 0
	void reset() {
		size_t count = 0;
		fitness_t minimum = 0.0;
		fitness_t maximum = 0.0;
		fitness_t average = 0.0;
	};
};
#endif //FITNESSSTATISTICS_H