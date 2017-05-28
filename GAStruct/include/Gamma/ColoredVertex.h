//
// Created by Deiwid on 2017-04-03.
//

#ifndef GAMMA_VERTEX_H
#define GAMMA_VERTEX_H

#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>


struct ColoredVertex {
    glm::vec3 pos;
    glm::vec4 color;

    static vk::VertexInputBindingDescription getBindingDescription() {
        vk::VertexInputBindingDescription description = {};
        description.binding     = 0;
        description.stride      = sizeof(ColoredVertex);
        description.inputRate   = vk::VertexInputRate::eVertex;
        return description;
    }

    static std::vector<vk::VertexInputAttributeDescription> getAttibuteDescriptions() {
        vk::VertexInputAttributeDescription positionDescription = {};
        vk::VertexInputAttributeDescription colorDescription = {};

        positionDescription.location    = 0;
        positionDescription.binding     = 0;
        positionDescription.format      = vk::Format::eR32G32B32Sfloat;
        positionDescription.offset      = offsetof(ColoredVertex, pos);

        colorDescription.location   = 1;
        colorDescription.binding    = 0;
        colorDescription.format     = vk::Format::eR32G32B32A32Sfloat;
        colorDescription.offset     = offsetof(ColoredVertex, color);

        return { positionDescription, colorDescription };
    }
};


#endif //GAMMA_VERTEX_H
