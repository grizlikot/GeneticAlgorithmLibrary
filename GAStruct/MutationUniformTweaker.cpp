#include "MutationUniformTweaker.h"

MutationUniformTweaker::MutationUniformTweaker(std::shared_ptr<double>  genesPercentageMutation, int availableFitnessRepeats) 
{
	this->availableFitnessRepeats = availableFitnessRepeats;
	this->genesPercentageMutation = genesPercentageMutation;
	fitnessRepeatAmount = 0;
}

void MutationUniformTweaker::checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) {
	if (oldFitness == newFitness) {
		fitnessRepeatAmount++;
	}
	else {
		fitnessRepeatAmount = 0;
		if (newFitness > oldFitness && *genesPercentageMutation > 0.05) {
			*genesPercentageMutation -= 0.05;
		}
		if (newFitness < oldFitness && *genesPercentageMutation > 0.05) {
			*genesPercentageMutation = 0.05;
		}
	}
	if (fitnessRepeatAmount >= availableFitnessRepeats && *genesPercentageMutation <= 0.5) {
		*genesPercentageMutation = 0.1;
	}
}