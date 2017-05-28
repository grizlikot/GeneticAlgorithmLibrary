//
// Created by Deiwid on 2017-04-12.
//

#ifndef GAMMA_TEXTUREDVERTEX_H
#define GAMMA_TEXTUREDVERTEX_H

#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>

struct TexturedVertex {
    glm::vec3 pos;
    glm::vec2 uv;

    static vk::VertexInputBindingDescription getBindingDescription() {
        vk::VertexInputBindingDescription description = {};
        description.binding     = 0;
        description.stride      = sizeof(TexturedVertex);
        description.inputRate   = vk::VertexInputRate::eVertex;
        return description;
    }

    static std::vector<vk::VertexInputAttributeDescription> getAttibuteDescriptions() {
        vk::VertexInputAttributeDescription positionDescription = {};
        vk::VertexInputAttributeDescription textureDescription = {};

        positionDescription.location    = 0;
        positionDescription.binding     = 0;
        positionDescription.format      = vk::Format::eR32G32B32Sfloat;
        positionDescription.offset      = offsetof(TexturedVertex, pos);

        textureDescription.location   = 1;
        textureDescription.binding    = 0;
        textureDescription.format     = vk::Format::eR32G32Sfloat;
        textureDescription.offset     = offsetof(TexturedVertex, uv);

        return { positionDescription, textureDescription };
    }
};

#endif //GAMMA_TEXTUREDVERTEX_H
