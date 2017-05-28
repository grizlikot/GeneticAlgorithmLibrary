#include "Data.h"
#include <string>
#include <fstream>

#define FUNDAM_LINES 7

std::shared_ptr<Scene> Data::defaultScene;
std::vector<std::shared_ptr<Polis>> Data::poliai;


std::atomic<bool> Data::continueGamma = { false };

std::vector<glm::vec2> Data::getPoliaiCoords()
{
	std::vector<glm::vec2> result;
	std::ifstream readFundament;
	readFundament.open("plotting.txt");
	std::string omitLine;
	for (int i = 0; i < FUNDAM_LINES + 1; i++) {
		std::getline(readFundament, omitLine);
	}
	int coordsAmount;
	readFundament >> coordsAmount;
	for (int i = 0; i < coordsAmount; i++)
	{
		double coordX, coordY;
		readFundament >> coordX >> coordY;
		result.push_back(glm::vec2(coordX, coordY));
	}
	readFundament.close();
	return result;
}

std::vector<std::pair<glm::vec2, glm::vec2>> Data::getFundamCoords()
{
	std::vector<std::pair<glm::vec2, glm::vec2>> result;
	std::ifstream readFundament;
	readFundament.open("plotting.txt");
	int coordsAmount;
	readFundament >> coordsAmount;
	for (int i = 0; i < coordsAmount; i++)
	{
		double dx, dy, kx, ky;
		readFundament >> dx >> dy >> kx >> ky;
		result.push_back({ glm::vec2(dx,  dy), glm::vec2(kx, ky) });
	}
	readFundament.close();
	return result;
}