#include "Polis.h"

Polis::Polis(glm::vec2 startingPos) {
    setPosition({ startingPos.x, startingPos.y, 0.0f });
    loadObject("assets/objs/polis.blend", "assets/textures/polisedited.ktx");
}

void Polis::init() {
}

void Polis::update(double deltaTime) {

}
