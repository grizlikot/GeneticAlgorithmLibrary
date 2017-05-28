#ifndef GAMMA_DATA_H
#define GAMMA_DATA_H


#include <glm/vec2.hpp>
#include <utility>
#include <vector>
#include <glm/detail/type_mat.hpp>
#include <vector>
#include "Polis.h"

class Data {
public:
	static std::atomic<bool> continueGamma;
	static std::shared_ptr<Scene> defaultScene;
    static std::vector<std::shared_ptr<Polis>> poliai;
	static std::vector<std::pair<glm::vec2, glm::vec2>> getFundamCoords();
	static std::vector<glm::vec2> getPoliaiCoords();
};


#endif 