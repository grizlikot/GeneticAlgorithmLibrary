#pragma once
#include "Elitism.h"
class MockElitism : public Elitism {
public:
	MockElitism();
	void setSavedIndivides(std::vector<RankedParent> savedIndivides) override;
	void saveBestIndivides(std::vector<RankedParent>& parents) override;
	std::vector<RankedParent> addToNewPopulation(std::vector<RankedParent>& newPopulation) override;
};