// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :	Francis Labine	

#pragma once
#ifndef POPULATION_H
#define POPULATION_H

#include "vector"
#include "console.h"
#include "fitness_t.h"
#include "GAParameters.h"
#include "Solution.h"
#include <algorithm>

class Population
{
public:
	Population();
	~Population();


	struct fitness_comparator {
		inline bool operator()(Solution * s1, Solution * s2) {
			return(s1->fitness() < s2->fitness());
		}
	};

	//Retourne la taille de la population.
	size_t size() const;

	//Change la taille de la population.
	void set(size_t size, Solution const &  SolutionSample);

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

	void setPopulationColor(int index);

private:
	std::vector<Solution*> mSolutions;
	void quicksort(std::vector<Solution*> solutions, int left, int right);
	std::vector<windows_console::color_type> const & mColorTypes{ windows_console::color_type::red, windows_console::color_type::blue, windows_console::color_type::green,windows_console::color_type::yellow };
	windows_console::color_type mPopulationColor{ windows_console::color_type::red};
};

#endif //POPULATION_H
