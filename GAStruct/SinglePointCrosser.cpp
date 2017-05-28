#include "SinglePointCrosser.h"
#include "Grillage.h"

SinglePointCrosser::SinglePointCrosser(unsigned int genomeLength)
{
	this->genomeLength = genomeLength;
}

RankedParent SinglePointCrosser::cross(RankedParent& a, RankedParent& b)
{
	double fitness = 0.0f;
	int splitPoint = rand() % (genomeLength - 1);
	std::vector<double> genome;
	auto aVal = a.getValues();
	auto bVal = b.getValues();
	for (auto i = 0; i < genomeLength; i++)
	{
		if(i < splitPoint)
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

std::vector<RankedParent> SinglePointCrosser::cross(std::vector<std::pair<RankedParent, RankedParent>>& parents)
{
	std::vector<RankedParent> newPopulation;
	for(auto i = parents.begin(); i != parents.end(); i++)
	{
		auto parentPair = *i;
		newPopulation.push_back(cross(parentPair.first, parentPair.second));
	}
	return newPopulation;
}
