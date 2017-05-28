#pragma once
#include "Generator.h"

class AdvancedGenerator : public Generator
{
private:
	unsigned int genomeLength;
	double geneValueCap;
	unsigned int maxPopulationLength;
	double geneDistance;
	bool sortedIndividual;
	bool useDiscretGeneration;
	std::vector<double> generateGenome();
	std::vector<double> generateSorted();
	std::vector<double> generateUnsorted();
public:
	AdvancedGenerator(unsigned int genomeLength, double geneValueCap, unsigned int maxPopulationLength, double geneDistance, bool sortedIndividual, bool useDiscretGeneration);
	std::vector<RankedParent> generatePopulation(unsigned int size) override;
	std::vector<RankedParent> getBestPopulation(std::vector<RankedParent> candidates, unsigned int size);
};
