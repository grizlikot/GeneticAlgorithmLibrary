#pragma once
#include "Mutator.h"

class CustomMutator : public Mutator
{
private:
	unsigned int genomeLength;
	double geneValueCap;
	std::shared_ptr<double> mutationPropability;
	std::shared_ptr<double> geneMutationPropability;
	std::shared_ptr<int> mutationDistance;
public:
	CustomMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> mutationPropability, std::shared_ptr<double> geneMutationPropability, std::shared_ptr<int> mutationDistance);
	RankedParent mutate(RankedParent& instance) override;
	std::vector<RankedParent> mutate(std::vector<RankedParent>& population) override;
};
