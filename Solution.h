// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe abstraite pour definir ce que chaque type de solution aura besoin comme methodes et attributs
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur :	Etienne Cote

#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H
#include <console.h>
#include "Fitness_t.h"
#include "Chromosome.h"


class Solution
{
public:
	Solution();
	virtual ~Solution() = default;

	//Accesseurs du chromosome de la solution//
	///////////////////////////////////////////
	Chromosome const & chromosome() const;
	Chromosome & chromosome();

	///////////////////////////////////////
	//Accesseur du fitness de la solution//
	///////////////////////////////////////
	fitness_t fitness() const;

	///////////////////////////////////////////////////////////////////////////////////////
	//Methode qui evalue les performances d'une solution et si elle devrait se reproduire//
	///////////////////////////////////////////////////////////////////////////////////////
	virtual void processFitness() = 0;

	///////////////////////////////////////////////////////////////////////////////
	//Methode qui randomise les valeurs de la shape dans les classes specialisees//
	///////////////////////////////////////////////////////////////////////////////
	virtual void randomize() = 0;

	////////////////////////////////////////////////////////////////////////////////////////
	//Methodes pour traduire de la vue au modele, les valeurs de la shape seront traduites//
	//dans le chromosome pour que les methodes generales du modele puissent travailler    //
	////////////////////////////////////////////////////////////////////////////////////////
	virtual void encode() = 0;
	virtual void decode() = 0;

	////////////////////////////////////////////////////////////////////////////
	//Methode qui copie les valeurs d'une solution et les assignent a celle ci//
	////////////////////////////////////////////////////////////////////////////
	virtual void copy(Solution const & from);

	///////////////////////////////////////////////////////////////
	//Methode qui cree une nouvelle solution identique a celle ci//
	///////////////////////////////////////////////////////////////
	virtual Solution * clone() const = 0;

	virtual void setSolutionBrightness(windows_console::brightness_type aBrightness) = 0;
	virtual void setSolutionColor(windows_console::color_type aColor) = 0;

protected:
	Chromosome mChromosome;

	/////////////////////////////////////////////////////////////////
	//Attribut representant la valeur de la solution et ses chances//
	//de se reproduire pour la prochaine evolution de la population//
	/////////////////////////////////////////////////////////////////
	fitness_t mFitness;

};

#endif // !SOLUTION_H