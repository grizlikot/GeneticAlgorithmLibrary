#pragma once
#include "MutationTweaker.h"
#include <vector>
#include <memory>
#include "RankedParent.h"

class MutationPropabilityTweaker : public MutationTweaker
{
private: 
	std::shared_ptr<double> mutationPropability;
	int availableFitnessRepeats;
	double fitnessRepeatAmount;
public:
	MutationPropabilityTweaker(std::shared_ptr<double> mutationPropability, int availableFitnessRepeats);
	void checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) override;
};
