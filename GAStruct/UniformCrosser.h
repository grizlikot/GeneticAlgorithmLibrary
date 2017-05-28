#pragma once
#include "Crosser.h"

class UniformCrosser : public Crosser
{
private:
	unsigned int genomeLength;
public:
	UniformCrosser(unsigned int genomeLength);
	RankedParent cross(RankedParent& a, RankedParent& b) override;
	std::vector<RankedParent> cross(std::vector<std::pair<RankedParent, RankedParent>>& parents) override;
};