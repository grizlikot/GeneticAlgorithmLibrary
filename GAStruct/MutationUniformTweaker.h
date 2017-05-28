#pragma once
#include "MutationTweaker.h"
#include <vector>
#include <memory>
#include "RankedParent.h"

class MutationUniformTweaker : public MutationTweaker
{
private:
	std::shared_ptr<double> genesPercentageMutation;
	int availableFitnessRepeats;
	double fitnessRepeatAmount;
public:
	MutationUniformTweaker(std::shared_ptr<double> genesPercentageMutation, int availableFitnessRepeats);
	void checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) override;
};
