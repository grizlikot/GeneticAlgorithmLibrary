#include "CameraController.h"

#define LOOK_AT_X 4.0f
#define LOOK_AT_Y -6.0f

void CameraController::init() {
    scene->camera.lookAt({ LOOK_AT_X, LOOK_AT_Y, 0.0f });
    scene->camera.setPosition({ 0.0f, -10.0f, -10.0f });
    setReady(true);
}

void CameraController::update(double deltaTime) {
    rot += deltaTime*20;
    scene->camera.setPosition({ glm::sin(glm::radians(rot))*10+LOOK_AT_X, glm::cos(glm::radians(rot))*10+LOOK_AT_Y, -10.0f });
}
