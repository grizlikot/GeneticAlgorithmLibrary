#pragma once
#include "Generator.h"
#include "Selector.h"
#include "Mutator.h"
#include "Crosser.h"
#include "Elitism.h"
#include "MutationTweaker.h"

class GeneticEngine
{
private:
	Generator *generator;
	Selector *selector;
	Crosser *crosser;
	Mutator *mutator;
	Elitism *elitism;
	MutationTweaker *tweaker;
	std::vector<RankedParent> population;
	unsigned long long int generation;
	double bestFitness;
	unsigned int sameFitnessCount;
	std::vector<double> bestValues;
public:
	GeneticEngine(Generator *generator, Selector *selector, Crosser *crosser, Mutator *mutator, Elitism *elitism, MutationTweaker *tweaker);
	void runGA(unsigned int iterationCount, unsigned int populationSize);
	void calculateFitness();
	double calculateBestFitness();
	void printIteration(double newFitness);
	void printBestFitness();
	void writeBestFitnessToFile();
};
