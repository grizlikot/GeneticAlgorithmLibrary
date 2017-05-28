#include <random>
#include "RandomGenerator.h"
using namespace std;

int RandomGenerator::getRandomInt(int minValue, int maxValue) {
	return std::uniform_int_distribution<int>{minValue, maxValue} (eng);
}

double RandomGenerator::getRandomDouble(double minValue, double maxValue) {
	return std::uniform_real_distribution<double>{minValue, maxValue} (eng);
}
