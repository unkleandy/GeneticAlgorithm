#pragma once
#ifndef _EVOLUTIONOBSERVER_H_
#define _EVOLUTIONOBSERVER_H_
#include "GAEngine.h"


class EvolutionObserver
{
public:
	EvolutionObserver();
	~EvolutionObserver();
	virtual void update(GAEngine engine) = 0;
};

#endif // !_EVOLUTIONOBSERVER_H_
