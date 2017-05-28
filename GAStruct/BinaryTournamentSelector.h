#pragma once
#include "Selector.h"

class BinaryTournamentSelector : public Selector
{
	unsigned int contestantCount;
	unsigned int participatingElites;
	static RankedParent doSelect(std::vector<RankedParent> candidates);
public:
	BinaryTournamentSelector(unsigned int contestantCount, unsigned int participatingElites);
	RankedParent selectOne(std::vector<RankedParent>& parents) override;
	std::vector<std::pair<RankedParent, RankedParent>> select(std::vector<RankedParent>& parents) override;
};
