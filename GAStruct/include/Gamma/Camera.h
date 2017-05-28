//
// Created by Deiwid on 2017-04-09.
//

#ifndef GAMMA_CAMERA_H
#define GAMMA_CAMERA_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    float fov = 45.0f;
    float width;
    float height;
    glm::mat4 ortho;
    glm::mat4 persp;
    glm::mat4 view;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 normalizedRotation;
public:
    Camera() {
        ortho = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
        view = glm::lookAt(position, normalizedRotation, { 0.0f, 0.0f, 1.0f });
    }
    void setPosition(glm::vec3 newPos) {
        position = newPos;
        view = glm::lookAt(position, normalizedRotation, { 0.0f, 0.0f, 1.0f });
    }
    void setRotation(glm::vec3 newRot) {
        rotation = newRot;
        normalizedRotation = glm::normalize(rotation);
        view = glm::lookAt(position, normalizedRotation, { 0.0f, 0.0f, 1.0f });
    }
    void lookAt(glm::vec3 pos) {
        normalizedRotation = pos;
        view = glm::lookAt(position, normalizedRotation, { 0.0f, 0.0f, 1.0f });
    }
    glm::mat4 getView() {
        return view;
    }
    void setFov(float fov) {
    this->fov = fov;
        persp = glm::infinitePerspective(fov, width/height, 0.1f);
    }
    void updateSize(float width, float height) {
        this->width = width;
        this->height = height;
        persp = glm::infinitePerspective(fov, width/height, 0.1f);
    }
    glm::mat4 getPerspProjection() {
        return persp;
    }
    glm::mat4 getOrthoProjection() {
        return ortho;
    }
};

#endif //GAMMA_CAMERA_H
