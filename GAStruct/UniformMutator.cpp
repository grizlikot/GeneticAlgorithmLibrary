#include "UniformMutator.h"

UniformMutator::UniformMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> genesPercentageMutation)
{
	this->genomeLength = genomeLength;
	this->geneValueCap = geneValueCap;
	this->genesPercentageMutation = genesPercentageMutation;
}

RankedParent UniformMutator::mutate(RankedParent& instance)
{
	std::vector<double> genome(instance.getValues());
	auto size = genome.size();
	int genesToMutate = genomeLength* * genesPercentageMutation;
	for (int i = 0; i < genesToMutate; i++) {
		int random = rand() % (genomeLength - 1);
		genome[random] = (geneValueCap - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
	}
	return RankedParent(genome);
}

std::vector<RankedParent> UniformMutator::mutate(std::vector<RankedParent>& population)
{
	std::vector<RankedParent> mutatedPopulation;
	for (auto i = population.begin(); i != population.end(); i++)
	{
		mutatedPopulation.push_back(mutate(*i));
	}
	return mutatedPopulation;
}

