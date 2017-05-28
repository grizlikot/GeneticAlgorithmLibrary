#include "UniformCrosser.h"

UniformCrosser::UniformCrosser(unsigned int genomeLength)
{
	this->genomeLength = genomeLength;
}

RankedParent UniformCrosser::cross(RankedParent& a, RankedParent& b)
{
	std::vector<double> genome;
	auto aVal = a.getValues();
	auto bVal = b.getValues();
	for (auto i = 0; i < genomeLength; i++)
	{
		if ((1.0 - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0 < 0.5)
		{
			genome.push_back(aVal[i]);
		}
		else
		{
			genome.push_back(bVal[i]);
		}
	}
	return RankedParent(genome);
}

std::vector<RankedParent> UniformCrosser::cross(std::vector<std::pair<RankedParent, RankedParent>>& parents)
{
	std::vector<RankedParent> newPopulation;
	for (auto i = parents.begin(); i != parents.end(); i++)
	{
		auto parentPair = *i;
		newPopulation.push_back(cross(parentPair.first, parentPair.second));
	}
	return newPopulation;
}