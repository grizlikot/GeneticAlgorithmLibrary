#include "RankBasedSelector.h"

RankBasedSelector::RankBasedSelector(unsigned int participatingElites)
{
	this->participatingElites = participatingElites;
	totalRank = 0;
	totalFitness = 0;
}

void RankBasedSelector::calculateTotalFitness(std::vector<RankedParent> parents)
{
	double sum = 0.0f;
	for (int i = 0; i < parents.size(); i++) {
		sum += parents[i].getFitness();
	}
	setTotalFitness(sum);
}

void RankBasedSelector::setTotalFitness(double totalFitness)
{
	this->totalFitness = totalFitness;
}

void RankBasedSelector::setTotalRank(int totalRank) {
	this->totalRank = totalRank;
}

void RankBasedSelector::setRanks(std::vector<RankedParent> &parents) {
	int sumRank = 0;
	for (int i = 0; i < parents.size(); i++) {
		parents[i].setRank(i + 1);
		sumRank += i + 1;
	}
	setTotalRank(sumRank);
}

double RankBasedSelector::getTotalFitness() const
{
	return totalFitness;
}

int RankBasedSelector::getTotalRank() const
{
	return totalRank;
}

void RankBasedSelector::setPropabilities(std::vector<RankedParent>& parents) {
	for (int i = 0; i < parents.size(); i++) {
		double propability = 1 - parents[i].getFitness() / this->getTotalFitness();
		parents[i].setPropability(propability);
	}
}

RankedParent RankBasedSelector::selectOne(std::vector<RankedParent>& parents)
{
	int totalRank = this->getTotalRank();
	int random = rand() % totalRank;
	int offset = 0, index = 0;
	while (index < parents.size() - 1 && offset < random) {
		offset += parents[index].getRank();
		index++;
	}
	return parents[index];
}

std::vector<std::pair<RankedParent, RankedParent>> RankBasedSelector::select(std::vector<RankedParent>& parents)
{
	std::vector<std::pair<RankedParent, RankedParent>> newPopulation;
	calculateTotalFitness(parents);
	sort(parents.begin(), parents.end(), RankedParent::compareDesc);
	setRanks(parents);
	for (int i = parents.size() - 1; i >= parents.size() - participatingElites; i--)
	{
		RankedParent theBest = parents[i];
		newPopulation.push_back(std::pair<RankedParent, RankedParent>(theBest, selectOne(parents)));
	}
	for (int i = participatingElites; i < parents.size(); i++)
	{
		newPopulation.push_back(std::pair<RankedParent, RankedParent>(selectOne(parents), selectOne(parents)));
	}
	return newPopulation;
}