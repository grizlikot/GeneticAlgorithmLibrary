#pragma once
#include "MutationTweaker.h"
#include <vector>
#include <memory>
#include "RankedParent.h"

class MutationCustomTweaker : public MutationTweaker
{
private:
	std::shared_ptr<double> mutationPropability;
	std::shared_ptr<double> geneMutationPropability;
	std::shared_ptr<int> mutationDistance;
	int availableFitnessRepeats;
	double fitnessRepeatAmount;
public:
	MutationCustomTweaker(std::shared_ptr<double> mutationPropability, std::shared_ptr<double> geneMutationPropability, int availableFitnessRepeats, std::shared_ptr<int> mutationDistance);
	void checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) override;
};