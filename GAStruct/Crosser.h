#pragma once
#include <vector>
#include "RankedParent.h"

class Crosser
{
public:
	virtual RankedParent cross(RankedParent& a, RankedParent& b) = 0;
	virtual std::vector<RankedParent> cross(std::vector<std::pair<RankedParent, RankedParent>>& parents) = 0;
	virtual ~Crosser() {};
};
