#pragma once
#include "Mutator.h"

class FlipBitMutator : public Mutator
{
private:
	unsigned int genomeLength;
	double geneValueCap;
	std::shared_ptr<double> mutationPropability;
public:
	FlipBitMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> mutationPropability);
	RankedParent mutate(RankedParent& instance) override;
	std::vector<RankedParent> mutate(std::vector<RankedParent>& population) override;
};
