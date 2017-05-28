#include "FlipBitMutator.h"

FlipBitMutator::FlipBitMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> mutationPropability)
{
	this->genomeLength = genomeLength;
	this->geneValueCap = geneValueCap;
	this->mutationPropability = mutationPropability;
}

RankedParent FlipBitMutator::mutate(RankedParent& instance)
{
	double fitness = 0.0f;
	std::vector<double> genome(instance.getValues());
	auto size = genome.size();
	int random = rand() % genomeLength - 1;
	if (random < 0) {
		random = 0;
	}
	double mutRandom = (1.0 - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
	if (*mutationPropability > mutRandom) {
		genome[random] = (geneValueCap - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
	}
	return RankedParent(genome);
}

std::vector<RankedParent> FlipBitMutator::mutate(std::vector<RankedParent>& population)
{
	std::vector<RankedParent> mutatedPopulation;
	for(auto i = population.begin(); i != population.end(); i++)
	{
		mutatedPopulation.push_back(mutate(*i));
	}
	return mutatedPopulation;
}

