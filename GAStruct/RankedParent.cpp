#include "RankedParent.h"
RankedParent::RankedParent(std::vector<double> values) {
	this->values = values;
}

RankedParent::RankedParent(std::vector<double> values, double fitness) {
	this->values = values;
	this->fitness = fitness;
}
std::vector<double> RankedParent::getValues() {
	return values;
}
void RankedParent::setFitness(double fitness) {
	this->fitness = fitness;
}
double RankedParent::getFitness() {
	return fitness;
}

void RankedParent::setRank(int rank) {
	this->rank = rank;
}

int RankedParent::getRank() {
	return rank;
}

bool RankedParent::compareAsc(RankedParent a, RankedParent b) {
	return a.getFitness() < b.getFitness();
}

bool RankedParent::compareDesc(RankedParent a, RankedParent b) {
	return a.getFitness() > b.getFitness();
}

std::string RankedParent::toString()
{
	std::string val = "Fitness: " + std::to_string(fitness) + "\n";
	val += "Chromosomes: \n";
	for(auto i = values.begin(); i != values.end(); i++)
	{
		val += std::to_string(*i) + " ";
	}
	return val;
}
void RankedParent::setPropability(double propability) {
	this->propability = propability;
}
double RankedParent::getPropability() {
	return propability;
}

bool RankedParent::operator!=(RankedParent &other) {
	for (int i = 0; i < this->values.size(); i++) {
		if (this->values[i] != other.values[i])
		{
			return true;
		}
	}
	return this->fitness != other.fitness;
}