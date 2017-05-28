#include "CustomMutator.h"
#include <algorithm>

CustomMutator::CustomMutator(unsigned int genomeLength, double geneValueCap, std::shared_ptr<double> mutationPropability, std::shared_ptr<double> geneMutationPropability, std::shared_ptr<int> mutationDistance)
{
	this->genomeLength = genomeLength;
	this->geneValueCap = geneValueCap;
	this->mutationPropability = mutationPropability;
	this->geneMutationPropability = geneMutationPropability;
	this->mutationDistance = mutationDistance;
}

RankedParent CustomMutator::mutate(RankedParent& instance)
{
	std::vector<double> genome(instance.getValues());
	double mutRandom = (1.0 - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
	int md = *mutationDistance;
	if (*mutationPropability > mutRandom) {
		for (int i = 0; i < genomeLength - 1; i++) {
			double geneMutRandom = (1.0 - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
			if (*geneMutationPropability > geneMutRandom) {
				if (i + md > genomeLength - 1) {
					genome[i] = (genome[i] - genome[i - md]) * ((double)rand() / (double)RAND_MAX) + genome[i - md];
				}
				else if (i - md <= 0) {
					genome[i] = (genome[i + md] - genome[i]) * ((double)rand() / (double)RAND_MAX) + genome[i];
				}
				else {
					genome[i] = (genome[i + md] - genome[i - md]) * ((double)rand() / (double)RAND_MAX) + genome[i - md];
				}
			}
		}
	}
	sort(genome.begin(), genome.end());
	return RankedParent(genome);
}

std::vector<RankedParent> CustomMutator::mutate(std::vector<RankedParent>& population)
{
	std::vector<RankedParent> mutatedPopulation;
	for (auto i = population.begin(); i != population.end(); i++)
	{
		mutatedPopulation.push_back(mutate(*i));
	}
	return mutatedPopulation;
}

