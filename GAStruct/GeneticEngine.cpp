#include "GeneticEngine.h"
#include "Grillage.h"
#include "StopWatch.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <glm/detail/type_vec2.hpp>
#include "Data.h"
#include "Polis.h"
#include "Fundamentas.h"

GeneticEngine::GeneticEngine(Generator* generator, Selector* selector, Crosser* crosser, Mutator* mutator, Elitism *elitism, MutationTweaker *tweaker)
{
	generation = 0;
	bestFitness = 0.0f;
	sameFitnessCount = 0;
	this->generator = generator;
	this->selector = selector;
	this->crosser = crosser;
	this->mutator = mutator;
	this->elitism = elitism;
	this->tweaker = tweaker;
}

void GeneticEngine::runGA(unsigned int iterationCount, unsigned int populationSize)
{
	Stopwatch watch;
	generation = 0;
    printf("Generating population...");
	population = generator->generatePopulation(populationSize);
	bestFitness = population[0].getFitness();
	for(; generation < iterationCount; generation++)
	{
		elitism->saveBestIndivides(population);
		printf("Selecting parents...");
		auto parents = selector->select(population);
		printf("%.3f ms\nCrossing parents...", watch.check());
		auto newPopulation = crosser->cross(parents);
		printf("%.3f ms\nMutating children...", watch.check());
		population = mutator->mutate(newPopulation);
		population = elitism->addToNewPopulation(population);
		printf("%.3f ms\nCalculating fitness...", watch.check());
		calculateFitness();
		printf("%.3f ms\n", watch.check());
		auto newFitness = calculateBestFitness();
		printIteration(newFitness);
		writeBestFitnessToFile();
		tweaker->checkFitnessRepeat(bestFitness, newFitness, population);
		if (newFitness < bestFitness)
		{
			bestFitness = newFitness;
		}	
		if(generation==0)
		{
			std::vector<std::pair<glm::vec2, glm::vec2>> fundam = Data::getFundamCoords();
			std::vector<glm::vec2> pol = Data::getPoliaiCoords();
			std::vector<std::shared_ptr<Object>> objects;
			for(auto& f : fundam)
			{
				objects.push_back(std::make_shared<Fundamentas>(f.first, f.second));
			}
			for (auto& p : pol)
			{
				std::shared_ptr<Polis> temp = std::make_shared<Polis>(p);
				objects.push_back(temp);
				Data::poliai.push_back(temp);
			}
			Data::defaultScene->addObjects(objects);
			Data::continueGamma.store(true);
		}
		else
		{
			std::vector<glm::vec2> pol = Data::getPoliaiCoords();
			for(int i = 0; i<pol.size(); i++)
			{
				glm::vec2 temp = pol[i];
				Data::poliai[i]->setPosition({ temp.x, temp.y, 0.0f });
			}
		}
	}
	printBestFitness();
}

void GeneticEngine::calculateFitness() {
	int populationSize = population.size();
	int size = population[0].getValues().size();
	for (int i = 0; i < populationSize; i++)
	{
		double fitness = 0.0f;
		OBJECTIVE_FUNCTION(&(population[i].getValues()[0]), &size, &fitness);
		population[i].setFitness(fitness);
	}
	std::sort(population.begin(), population.end(), RankedParent::compareAsc);
}

double GeneticEngine::calculateBestFitness() {
	double min = population[0].getFitness();
	for (int i = 0; i < population.size(); i++) 
	{
		if (population[i].getFitness() < min) 
		{
			min = population[i].getFitness();
			bestValues = population[i].getValues();
		}	
	}
	return min;
}


void GeneticEngine::printIteration(double newFitness)
{
	std::cout << "Iteration number: " << generation << std::endl;
	//for (int i = 0; i < population.size(); i++) {
		// std::cout << i->toString() << std::endl;
	//}
	std::cout << "Fitness: " << newFitness << " " << std::endl;
}

void GeneticEngine::writeBestFitnessToFile() {
	RankedParent best = population[0];
	std::ofstream out("rezultatai.txt");
	for (int i = 0; i < population.size(); i++)
	{
		if (population[i].getFitness() < best.getFitness())
		{
			best = population[i];
		}
	}
	out << "   " << best.getFitness() << "       rmax\n";
	std::vector<double> values = best.getValues();
	for (int i = 0; i < values.size(); i++)
	{
		out << "   " << values[i] << "     \n";
	}
	out.close();
	DRAW_FOR_CPP();
}


void GeneticEngine::printBestFitness()
{
	std::cout << "The best fitness was: " << bestFitness << std::endl;
}
