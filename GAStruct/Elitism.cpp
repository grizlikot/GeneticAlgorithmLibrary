#include "Elitism.h"
#include <algorithm>

Elitism::Elitism() {}

Elitism::Elitism(int elitismIndivides) {
	this->elitismIndivides = elitismIndivides;
}

void Elitism::setSavedIndivides(std::vector<RankedParent> savedIndivides) {
	this->savedIndivides = savedIndivides;
}

void Elitism::saveBestIndivides(std::vector<RankedParent>& parents) 
{
	std::vector<RankedParent> population;
	sort(parents.begin(), parents.end(), RankedParent::compareAsc);
	for (int i = 0; i < elitismIndivides; i++) {
		population.push_back(parents[i]);
	}
	parents.erase(parents.begin(), parents.begin() + elitismIndivides);
	setSavedIndivides(population);
}

std::vector<RankedParent> Elitism::addToNewPopulation(std::vector<RankedParent>& population) 
{
	for (int i = 0; i < savedIndivides.size(); i++) {
		population.push_back(savedIndivides[i]);
	}
	return population;
}