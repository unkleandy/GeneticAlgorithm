// ...
// ...
// ...

#ifndef RANDOM_UTIL_H
#define RANDOM_UTIL_H


#include <random>

//////////////////////////////////////////////////////////////////////////
//! \brief Classe consolidant plusieurs fonctions 
//! utilitaires liées à la génération des nombres aléatoires.
//! 
//! Les fonctions sont statiques et ne requièrent pas d'instance de la 
//! classe.
//////////////////////////////////////////////////////////////////////////
class RandomUtil
{
public:
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le constructeur est retiré puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	RandomUtil() = delete;
	//////////////////////////////////////////////////////////////////////////
	//! \brief Le destructeur est retiré puisqu'aucune instance de 
	//! cette classe n'est attendue.
	//////////////////////////////////////////////////////////////////////////
	~RandomUtil() = delete;

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

private:
	static std::random_device randomDevice;
	static std::mt19937 randomGenerator;
};



#endif // RANDOM_UTIL_H