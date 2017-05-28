#include "MutationCustomTweaker.h"

MutationCustomTweaker::MutationCustomTweaker(std::shared_ptr<double> mutationPropability, std::shared_ptr<double> geneMutationPropability, int availableFitnessRepeats , std::shared_ptr<int> mutationDistance) {
	this->availableFitnessRepeats = availableFitnessRepeats;
	this->mutationPropability = mutationPropability;
	this->geneMutationPropability = geneMutationPropability;
	this-> mutationDistance = mutationDistance;
	fitnessRepeatAmount = 0;
}

void MutationCustomTweaker::checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) {
	if (oldFitness == newFitness) {
		fitnessRepeatAmount++;
	}
	if (population[6].getFitness() - population[0].getFitness() <= 0.05)
	{
		*mutationPropability = 0.8;
		*geneMutationPropability = 0.4;
	}
	else {
		fitnessRepeatAmount = 0;
		*geneMutationPropability = 0.1;
		*mutationPropability = 0.2;
	}

}