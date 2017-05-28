#include "BinaryTournamentSelector.h"
#include "time.h"

BinaryTournamentSelector::BinaryTournamentSelector(unsigned int contestantCount, unsigned int participatingElites)
{
	this->contestantCount = contestantCount;
	this->participatingElites = participatingElites;
}

RankedParent BinaryTournamentSelector::doSelect(std::vector<RankedParent> candidates)
{
	RankedParent minimum = candidates[0];
	for (int i = 0; i < candidates.size(); i++) {
		if (candidates[i].getFitness() < minimum.getFitness()) {
			minimum = candidates[i];
		}
	}
	return minimum;
}

RankedParent BinaryTournamentSelector::selectOne(std::vector<RankedParent>& parents)
{
	std::vector<RankedParent> candidates;
	for (int j = 0; j < contestantCount; j++) {
		int index = rand() % (parents.size() - 1);
		candidates.push_back(parents[index]);
	}
	RankedParent winner = doSelect(candidates);
	return winner;
}

std::vector<std::pair<RankedParent, RankedParent>> BinaryTournamentSelector::select(std::vector<RankedParent>& parents)
{
	std::vector<std::pair<RankedParent, RankedParent>> newPopulation;
	RankedParent theBest = parents[0];
	for (int i = parents.size() - 1; i >= parents.size() - participatingElites; i--)
	{
		RankedParent theBest = parents[i];
		newPopulation.push_back(std::pair<RankedParent, RankedParent>(theBest, selectOne(parents)));
	}
	for(int i = participatingElites; i < parents.size(); i++)
	{
		newPopulation.push_back(std::pair<RankedParent, RankedParent>(selectOne(parents), selectOne(parents)));
	}
	return newPopulation;
}
