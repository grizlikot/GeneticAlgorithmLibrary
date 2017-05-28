#pragma once
#include "RankedParent.h"
#include <vector>

class Generator
{
public:
	virtual std::vector<RankedParent> generatePopulation(unsigned int size) = 0;
	virtual ~Generator() {};
};
