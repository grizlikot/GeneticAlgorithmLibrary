#pragma once
#include "Mutator.h"

class UniformMutator : public Mutator
{
private:
	unsigned int genomeLength;
	double geneValueCap;
	std::shared_ptr<double> genesPercentageMutation;
public:
	UniformMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> genesPercentageMutation);
	RankedParent mutate(RankedParent& instance) override;
	std::vector<RankedParent> mutate(std::vector<RankedParent>& population) override;
};
