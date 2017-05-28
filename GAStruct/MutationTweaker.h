#pragma once
#include <vector>
#include "RankedParent.h"
class MutationTweaker
{
public:
	virtual void checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) = 0;
	virtual ~MutationTweaker() {};
};