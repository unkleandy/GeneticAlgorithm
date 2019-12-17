// Contexte de r�alisation: cours B51 - D�veloppement en environnement de base de donn�es
//
// Description:				Outils divers li�s � la g�n�ration de nombre al�atoire et ayant des applications possibles sur diff�rents programmes
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/11/29
// Auteurs : 
// - principaux :			Fr�d�ric B�langer
// - autre :				Jean Christophe Demers

#ifndef ECA_RANDOM_TOOLS_H
#define ECA_RANDOM_TOOLS_H


#include <random>

//////////////////////////////////////////////////////////////////////////
//! \brief Classe consolidant plusieurs fonctions 
//! utilitaires li�es � la g�n�ration des nombres al�atoires.
//! 
//! Les fonctions sont statiques et ne requi�rent pas d'instance de la 
//! classe.
//////////////////////////////////////////////////////////////////////////
class EcaRandomTools
{
public:
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le constructeur est retir� puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	EcaRandomTools() = delete;
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le destructeur est retir� puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	~EcaRandomTools() = delete;

	//////////////////////////////////////////////////////////////////////////
//! \brief Fonction g�n�rant un �v�nement al�atoire selon une certaine 
//! probabilit�.
//!
//! Cette fonction utilise une distribution de Bernouilli.
//!
//! \param probability la probabilit� de g�n�rer un �v�nement 
//! (entre 0.0 et 1.0)
//! \return retourne vrai si l'�v�nement a lieu, retourne faux sinon
//////////////////////////////////////////////////////////////////////////
	static bool generateEvent(double probability = 0.5);

	//////////////////////////////////////////////////////////////////////////
	//! \brief Fonction g�n�rant un �v�nement al�atoire selon une certaine 
	//! probabilit�.
	//!
	//! Cette fonction utilise une distribution de Bernouilli.
	//!
	//! \param probability la probabilit� de g�n�rer un �v�nement 
	//! (entre 0.0 et 1.0)
	//! \return retourne vrai si l'�v�nement a lieu, retourne faux sinon
	//////////////////////////////////////////////////////////////////////////
	static int generateRandomNumber(int min, int max);

private:

};



#endif // ECA_RANDOM_TOOLS_H