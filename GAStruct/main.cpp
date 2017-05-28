#define _CRT_SECURE_NO_WARNINGS
#include "SimpleGenerator.h"
#include "AdvancedGenerator.h"
#include "BinaryTournamentSelector.h"
#include "MutationPropabilityTweaker.h"
#include "MutationUniformTweaker.h"
#include "MutationCustomTweaker.h"
#include "RankBasedSelector.h"
#include "SinglePointCrosser.h"
#include "UniformCrosser.h"
#include "CustomMutator.h"
#include "FlipBitMutator.h"
#include "TwoPointCrosser.h"
#include "GeneticEngine.h"
#include "UniformMutator.h"
#include "Grillage.h"
#include "MockElitism.h"
#include "json.hpp"
#include <fstream>

#include <Gamma/Gamma.h>
#include "Data.h"
#include "CameraController.h"
#include "Fundamentas.h"
#include "Polis.h"

using json = nlohmann::json;

volatile bool run = true;
std::vector<std::shared_ptr<Polis>> poliai;

void runGA() {
	srand(time(NULL));
	std::ifstream t("settings.json");
	json settings = json::parse(t);
	std::cout << settings << std::endl;
	unsigned int populationSize = settings["populationSize"];
	unsigned int contestantAmount = settings["contestantAmount"];
	unsigned int iterationCount = settings["iterationCount"];
	unsigned int geneDistance = settings["geneDistance"];
	unsigned int maxPopulationGeneration = settings["maxPopulationGeneration"];
	unsigned int elitismIndivides = settings["elitismIndivides"];
	unsigned int availableFitnessRepeats = settings["availableFitnessRepeats"];
	unsigned int participatingElites = settings["participatingElites"];
	bool sortedIndividual = settings["sortedIndividual"];
	bool useDiscretGeneration = settings["useDiscretGeneration"];
	std::shared_ptr<double> mutationPropability = std::make_shared<double>(settings["mutationPropability"]);
	std::shared_ptr<double> genesPercentageMutation = std::make_shared<double>(settings["genesPercentageMutation"]);
	std::shared_ptr<int> genesAmountMutation = std::make_shared<int>(settings["genesAmountMutation"]);
	std::shared_ptr<double> geneMutationPropability = std::make_shared<double>(settings["geneMutationPropability"]);
	std::shared_ptr<int> mutationDistance = std::make_shared<int>(settings["mutationDistance"]);
	t.close();
	double geneValueCap;
	double allowReaction;
	int genomeLength;
	ANALYSIS(&geneValueCap, &genomeLength, &allowReaction);
	AdvancedGenerator generator(genomeLength, geneValueCap, maxPopulationGeneration, geneDistance, sortedIndividual, useDiscretGeneration);
	RankBasedSelector selector(participatingElites);
	UniformCrosser crosser(genomeLength);
	MutationCustomTweaker tweaker(mutationPropability, geneMutationPropability, availableFitnessRepeats, mutationDistance);
	CustomMutator mutator(genomeLength, geneValueCap, mutationPropability, geneMutationPropability, mutationDistance);
	MockElitism elitism;
	GeneticEngine engine(&generator, &selector, &crosser, &mutator, &elitism, &tweaker);
	engine.runGA(iterationCount, populationSize);
}

int main()
{
	Gamma gamma;
	gamma.init();
	Data::defaultScene = gamma.getScene();
	Data::defaultScene->addObject(std::make_shared<CameraController>());
	std::thread gaThread(&runGA);
	std::chrono::seconds second(1);
	while(!Data::continueGamma.load()) {
		std::this_thread::sleep_for(second);
	}
	gamma.startMainLoop();
	run = false;
	gaThread.join();
	return 0;
}
