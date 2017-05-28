#include "AdvancedGenerator.h"
#include "Grillage.h"
#include <algorithm>

AdvancedGenerator::AdvancedGenerator(unsigned int genomeLength, double geneValueCap, unsigned int maxPopulationLength, double geneDistance, bool sortedIndividual, bool useDiscretGeneration)
{
	this->genomeLength = genomeLength;
	this->geneValueCap = geneValueCap;
	this->maxPopulationLength = maxPopulationLength;
	this->geneDistance = geneDistance;
	this->sortedIndividual = sortedIndividual;
	this->useDiscretGeneration = useDiscretGeneration;
}

std::vector<double> AdvancedGenerator::generateSorted()
{
	std::vector<double> genes;
	int i = 0;
	bool fits = true;
	if (useDiscretGeneration) {
		while (i != genomeLength) {
			double gene = rand() % 1000 * geneValueCap / genomeLength / 1000 + geneValueCap / genomeLength * i;
			if (gene > 0 && gene < geneValueCap) {
				i++;
				genes.push_back(gene);
			}
		}
	}
	else {
		while (i != genomeLength) {
			double gene = (geneValueCap - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
			double start = gene - geneDistance;
			double end = gene + geneDistance;
			for (int j = 0; j < genes.size(); j++)
			{
				if (genes[j] > start && genes[j] < end)
				{
					fits = false;
					break;
				}
			}
			if (fits)
			{
				genes.push_back(gene);
				i++;
			}
			sort(genes.begin(), genes.end());
			fits = true;
		} 
	}
	sort(genes.begin(), genes.end());
	return genes;
}

std::vector<double> AdvancedGenerator::generateUnsorted()
{
	std::vector<double> genes;
	genes.push_back((geneValueCap - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0);
	int i = 1;
	while (i != genomeLength) 
	{
		double gene = (geneValueCap - 0.0) * ((double)rand() / (double)RAND_MAX) + 0.0;
		if (abs(gene - genes[i-1]) > geneDistance)
		{
			genes.push_back(gene);
			i++;
		}
	}
	return genes;
}

std::vector<double> AdvancedGenerator::generateGenome()
{
	if (sortedIndividual)
	{
		return generateSorted();
	}
	else 
	{
		return generateUnsorted();
	}
}

std::vector<RankedParent> AdvancedGenerator::getBestPopulation(std::vector<RankedParent> candidates, unsigned int size) {
	std::vector<RankedParent> population;
	std::sort(candidates.begin(), candidates.end(), RankedParent::compareAsc);
	for (auto i = 0; i < size; i++) {
		population.push_back(candidates[i]);
	}
	return population;
}

std::vector<RankedParent> AdvancedGenerator::generatePopulation(unsigned int size)
{
	std::vector<RankedParent> population;
	std::vector<RankedParent> massivePopulation;
	for (auto i = 0; i < maxPopulationLength; i++)
	{
		auto genome = generateGenome();
		double fitness = 0.0f;
		OBJECTIVE_FUNCTION(&(genome[0]), (int*)&genomeLength, &fitness);
		massivePopulation.push_back(RankedParent(genome, fitness));
	}
	population = getBestPopulation(massivePopulation, size);
	return population;
}
