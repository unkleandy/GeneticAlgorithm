// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe pour representer les valeurs d'une solution, peu importe laquelle
// 				 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur :	Etienne Cote

#pragma once
#ifndef CHROMOSOME_H
#define CHROMOSOME_H


#include <vector>


class Chromosome
{
public:
	Chromosome();
	~Chromosome() = default;

	////////////////////////////////////
	//Retourne la taille du chromosome//
	////////////////////////////////////
	size_t size() const;

	/////////////////////////////////////////////////////
	//Ajuste la taille du chromosome a la valeur voulue//
	/////////////////////////////////////////////////////
	void resize(size_t size);

	///////////////////////////////////////////////////////////////////////////////
	//Redefinition des operateurs crochets pour avoir acces a un index du vecteur//
	//du chromosome sans compromettre l'interface de programmation, plus elegant //
	///////////////////////////////////////////////////////////////////////////////
	std::vector<bool>::reference operator[](size_t pos);
	bool operator[](size_t pos) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Methodes pour lire les valeurs encodees dans le chromosome et mettre a jour les informations de la solution.//
	//Ecrit aussi une valeur voulue dans le chromosome a partir d'un index d'une taille predeterminee             //
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void read(uint32_t & value, size_t from, size_t length) const;
	void write(uint32_t value, size_t from, size_t length);

	////////////////////////////////////////////////////////////////
	//Methode appelee durant la mutation d'une solution, change la//
	//valeur d'un bit dans le chromosome selon la position donnee //
	////////////////////////////////////////////////////////////////
	void flip(size_t pos);

	///////////////////////////////////////////////////////////////////////////////////
	//Deux methodes pour randomiser le chromosome au complet ou bien un bit a la fois//
	///////////////////////////////////////////////////////////////////////////////////
	void randomize(double probability = 0.5);
	void randomize(size_t from, size_t to, double probability = 0.5);

private:
	////////////////////////////////////////////////////////////////////////////////
	//Les valeurs de la dite solution seront encodees dans ce vecteur de booleens,//
	//sa taille sera ajustee selon le type de forme dans des classes specialisees //
	////////////////////////////////////////////////////////////////////////////////
	std::vector<bool> mData;

};


#endif // !CHROMOSOME_H