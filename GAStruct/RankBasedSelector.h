#pragma once
#include "Selector.h"
#include <algorithm>

class RankBasedSelector : public Selector
{
	double totalFitness;
	double totalRank;
	unsigned int participatingElites;
public:
	void calculateTotalFitness(std::vector<RankedParent>);
	void setTotalRank(int);
	int getTotalRank() const;
	void setTotalFitness(double);
	void setPropabilities(std::vector<RankedParent>&);
	double getTotalFitness() const;
	void setRanks(std::vector<RankedParent>&);
	RankBasedSelector(unsigned int participatingElites);
	RankedParent selectOne(std::vector<RankedParent>& parents) override;
	std::vector<std::pair<RankedParent, RankedParent>> select(std::vector<RankedParent>& parents) override;
};