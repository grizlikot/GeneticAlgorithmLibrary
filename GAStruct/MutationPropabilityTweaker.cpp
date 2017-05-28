#include "MutationPropabilityTweaker.h"

MutationPropabilityTweaker::MutationPropabilityTweaker(std::shared_ptr<double> mutationPropability, int availableFitnessRepeats) {
	this->availableFitnessRepeats = availableFitnessRepeats;
	this->mutationPropability = mutationPropability;
	fitnessRepeatAmount = 0;
}

void MutationPropabilityTweaker::checkFitnessRepeat(double oldFitness, double newFitness, std::vector<RankedParent> population) {
	if (oldFitness == newFitness) {
		fitnessRepeatAmount++;
	}
	else {
		fitnessRepeatAmount = 0;
		if (*mutationPropability > 0.1) {
			*mutationPropability =- 0.1;
		}
	}
	if (fitnessRepeatAmount > availableFitnessRepeats && *mutationPropability <= 0.8) {
		*mutationPropability += 0.1;
	}
}