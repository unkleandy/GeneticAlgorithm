// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :		

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
