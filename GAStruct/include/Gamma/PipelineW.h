//
// Created by Deiwid on 2017-04-11.
//

#ifndef GAMMA_PIPELINEW_H
#define GAMMA_PIPELINEW_H

#include <vulkan/vulkan.hpp>

struct PipelineW {
    vk::Pipeline pipeline;
    vk::PipelineLayout layout;
};

#endif //GAMMA_PIPELINEW_H
