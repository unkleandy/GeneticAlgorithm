// Contexte de réalisation: cours B51 - Développement en environnement de base de données
//
// Description:				Outils divers liés à la génération de nombre aléatoire et ayant des applications possibles sur différents programmes
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/11/29
// Auteurs : 
// - principaux :			Frédéric Bélanger
// - autre :				Jean Christophe Demers

#ifndef ECA_RANDOM_TOOLS_H
#define ECA_RANDOM_TOOLS_H


#include <random>

//////////////////////////////////////////////////////////////////////////
//! \brief Classe consolidant plusieurs fonctions 
//! utilitaires liées à la génération des nombres aléatoires.
//! 
//! Les fonctions sont statiques et ne requièrent pas d'instance de la 
//! classe.
//////////////////////////////////////////////////////////////////////////
class EcaRandomTools
{
public:
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le constructeur est retiré puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	EcaRandomTools() = delete;
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le destructeur est retiré puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	~EcaRandomTools() = delete;

	//////////////////////////////////////////////////////////////////////////
//! \brief Fonction générant un évènement aléatoire selon une certaine 
//! probabilité.
//!
//! Cette fonction utilise une distribution de Bernouilli.
//!
//! \param probability la probabilité de générer un évènement 
//! (entre 0.0 et 1.0)
//! \return retourne vrai si l'évènement a lieu, retourne faux sinon
//////////////////////////////////////////////////////////////////////////
	static bool generateEvent(double probability = 0.5);

	//////////////////////////////////////////////////////////////////////////
	//! \brief Fonction générant un évènement aléatoire selon une certaine 
	//! probabilité.
	//!
	//! Cette fonction utilise une distribution de Bernouilli.
	//!
	//! \param probability la probabilité de générer un évènement 
	//! (entre 0.0 et 1.0)
	//! \return retourne vrai si l'évènement a lieu, retourne faux sinon
	//////////////////////////////////////////////////////////////////////////
	static int generateRandomNumber(int min, int max);

private:

};



#endif // ECA_RANDOM_TOOLS_H