#include "TwoPointCrosser.h"

TwoPointCrosser::TwoPointCrosser(unsigned int genomeLength)
{
	this->genomeLength = genomeLength;
}

RankedParent TwoPointCrosser::cross(RankedParent& a, RankedParent& b)
{
	double fitness = 0.0f;
	int first = rand() % (genomeLength - 1);
	int second = rand() % (genomeLength - 1);
	while (first == second) {
		second = rand() % (genomeLength - 1);
	}
	if (first > second) {
		int temp = first;
		first = second;
		second = temp;
	}
	std::vector<double> genome;
	auto aVal = a.getValues();
	auto bVal = b.getValues();
	for (auto i = 0; i < genomeLength; i++)
	{
		if (i > first && i < second)
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

std::vector<RankedParent> TwoPointCrosser::cross(std::vector<std::pair<RankedParent, RankedParent>>& parents)
{
	std::vector<RankedParent> newPopulation;
	for (auto i = parents.begin(); i != parents.end(); i++)
	{
		auto parentPair = *i;
		newPopulation.push_back(cross(parentPair.first, parentPair.second));
	}
	return newPopulation;
}