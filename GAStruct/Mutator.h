#pragma once
#include <vector>
#include "RankedParent.h"
#include <memory>


class Mutator
{
public:
	virtual RankedParent mutate(RankedParent& instance) = 0;
	virtual std::vector<RankedParent> mutate(std::vector<RankedParent>& population) = 0;
	virtual ~Mutator() {};
};
