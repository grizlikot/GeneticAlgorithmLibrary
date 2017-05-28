//
// Created by Deiwid on 2017-04-04.
//

#ifndef GAMMA_TRANSFORM_H
#define GAMMA_TRANSFORM_H

#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>

struct Transform {
    glm::mat4 *mvp=nullptr;
    glm::mat4 model;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale = { 1.0f, 1.0f, 1.0f };
};

#endif //GAMMA_TRANSFORM_H
