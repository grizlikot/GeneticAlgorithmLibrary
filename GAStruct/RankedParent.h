#pragma once
#include <vector>
#include <string>
#include <random>

class RankedParent
{
private:
	std::vector<double> values;
	double fitness;
	double propability;
	int rank;
	int totalRank;
public:
	RankedParent(std::vector<double>);
	RankedParent(std::vector<double>, double);
	bool operator!=(RankedParent &other);
	std::vector<double> getValues();
	double getFitness();
	void setFitness(double fitness);
	void setPropability(double propability);
	double getPropability();
	void setRank(int rank);
	int getRank();
	static bool compareAsc(RankedParent, RankedParent);
	static bool compareDesc(RankedParent, RankedParent);
	std::string toString();
};
