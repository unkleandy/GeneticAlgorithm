#pragma once
#ifndef POPULATION_H
#define POPULATION_H

#include "vector"
#include "fitness_t.h"
#include "GAParameters.h"

//EFFACER UNE FOIS LA CLASSE SOLUTION EST FAITE
class Solution {
public:
	fitness_t fitness() const;
protected:
	fitness_t mFitness;
};
//---------------------------------------------

class Population
{
public:
	Population();
	~Population();

	//Retourne la taille de la population.
	size_t size() const;

	//Change la taille de la population.
	void set(size_t size, Solution & const SolutionSample);

	Solution & operator[](size_t pos);

	Solution const & operator[](size_t pos) const;

	//Applique la fitness.

	void processFitness();

	//Randomize la population.
	void randomize();

	//Transforme les statistiques dans un vecteur de bool.
	void encode();

	//Transforme un vecteur de bool en statistiques.
	void decode();

	//Place la population en ordre croissante.
	void sort();

	//Bye bye les vieux, bonjour les jeunes.
	void swap(Population & other);

private:
	std::vector<Solution*> mSolution;
	void quicksort(std::vector<Solution*> solutions, int left, int right);
};

#endif //POPULATION_H

