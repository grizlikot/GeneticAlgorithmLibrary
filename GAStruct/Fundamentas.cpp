#include "Fundamentas.h"

Fundamentas::Fundamentas(glm::vec2 topLeft, glm::vec2 bottomRight) {
    setPosition({ topLeft.x+0.5f, topLeft.y-0.5f, 0.0f });
    float widthScale = topLeft.x-bottomRight.x;
    float depthScale = topLeft.y-bottomRight.y;
    int widthR = 0;
    int depthR = 0;
    if(widthScale<0.0f) {
        widthR = 1;
    }
    if(depthScale<0.0f) {
        depthR = 1;
    }
    if(glm::abs(widthScale) < 0.5f) widthScale = 1.0f;
    if(glm::abs(depthScale) < 0.5f) depthScale = 1.0f;
    setScale({ glm::abs(widthScale), glm::abs(depthScale), 1.0f });
    setRotation({ 0.0f, 0.0f, (widthR+depthR) > 0 ? 180.0f : 0.0f });
    loadObject("assets/objs/fundamentas.blend", "assets/textures/fundamentasedited.ktx");
}

void Fundamentas::init() {

}

void Fundamentas::update(double deltaTime) {

}
