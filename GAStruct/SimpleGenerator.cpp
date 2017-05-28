#include "SimpleGenerator.h"
#include "Grillage.h"

SimpleGenerator::SimpleGenerator(unsigned int genomeLength, double geneValueCap)
{
	this->genomeLength = genomeLength;
	this->geneValueCap = geneValueCap;
}

std::vector<double> SimpleGenerator::generateGenome()
{
	std::vector<double> genes;
	for(auto i = 0; i < genomeLength; i++)
	{
		genes.push_back(((double)rand() / (double)RAND_MAX) * geneValueCap);
	}
	return genes;
}

std::vector<RankedParent> SimpleGenerator::generatePopulation(unsigned int size)
{
	std::vector<RankedParent> population;
	for(auto i = 0; i < size; i++)
	{
		auto genome = generateGenome();
		double fitness = 0.0f;
		OBJECTIVE_FUNCTION(&(genome[0]), (int*)&genomeLength, &fitness);
		population.push_back(RankedParent(genome, fitness));
	}
	return population;
}
