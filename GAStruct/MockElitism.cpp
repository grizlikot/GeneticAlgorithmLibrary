#include "MockElitism.h"

MockElitism::MockElitism() {}

void MockElitism::setSavedIndivides(std::vector<RankedParent> savedIndivides) {}

void MockElitism::saveBestIndivides(std::vector<RankedParent>& parents) {}

std::vector<RankedParent> MockElitism::addToNewPopulation(std::vector<RankedParent>& population)
{
	return population;
}