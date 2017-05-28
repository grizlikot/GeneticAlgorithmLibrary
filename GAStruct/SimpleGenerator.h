#pragma once
#include "Generator.h"

class SimpleGenerator : public Generator
{
private:
	unsigned int genomeLength;
	double geneValueCap;
	std::vector<double> generateGenome();
public:
	SimpleGenerator(unsigned int genomeLength, double geneValueCap);
	std::vector<RankedParent> generatePopulation(unsigned int size) override;
};
