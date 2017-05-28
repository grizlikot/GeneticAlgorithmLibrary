#pragma once
#include <vector>
#include "RankedParent.h"


class Selector
{
public:
	virtual RankedParent selectOne(std::vector<RankedParent>& parents) = 0;
	virtual std::vector<std::pair<RankedParent, RankedParent>> select(std::vector<RankedParent>& parents) = 0;
	virtual ~Selector() {};
};