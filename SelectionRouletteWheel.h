// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Sous-classe de selecion strategy qui choisit le aléatoirement par poids
//							de score de fitness les solutions sélectionés pour la reproduction
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Andréa Cohen

#pragma once
#ifndef _SELECTIONROULETTEWHEEL_H_
#define _SELECTIONROULETTEWHEEL_H_

#include <vector>
#include "SelectionStrategy.h"


class SelectionRouletteWheel : public SelectionStrategy
{
public:
	SelectionRouletteWheel();
	~SelectionRouletteWheel();
	void prepare(Population const & population) override;
	Solution const & select(Population const & population) override;

protected:
	std::vector<double> mRankWeight;
};

#endif // !_SELECTIONROULETTEWHEEL_H_
