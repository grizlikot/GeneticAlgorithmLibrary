//
// Created by Deiwid on 2017-04-05.
//

#ifndef GAMMA_QUEUEW_H
#define GAMMA_QUEUEW_H

#include <vulkan/vulkan.hpp>

struct QueueW {
    vk::Queue queue;
    uint32_t familyIndex;
};

#endif //GAMMA_QUEUEW_H
