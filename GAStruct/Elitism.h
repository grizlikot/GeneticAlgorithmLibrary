#pragma once
#include <vector>
#include "RankedParent.h"

class Elitism {
private:
	std::vector<RankedParent> savedIndivides;
	int elitismIndivides;
public:
	Elitism();
	Elitism(int elitismIndivides);
	virtual void setSavedIndivides(std::vector<RankedParent> savedIndivides);
	virtual void saveBestIndivides(std::vector<RankedParent>& parents);
	virtual std::vector<RankedParent> addToNewPopulation(std::vector<RankedParent>& newPopulation);
	virtual ~Elitism() {};
};