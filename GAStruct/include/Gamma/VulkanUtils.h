//
// Created by Deiwid on 2017-03-23.
//

#ifndef GAMMA_VULKANUTILS_H
#define GAMMA_VULKANUTILS_H


#include <vulkan/vulkan.hpp>
#include "VulkanShaderHandler.h"

class VulkanUtils {
public:
    static vk::ImageCreateInfo map(vk::SwapchainCreateInfoKHR swapchainCreateInfo);
    static uint32_t getMemoryTypeIndex(vk::PhysicalDeviceMemoryProperties memoryProperties, vk::MemoryRequirements requirements, vk::MemoryPropertyFlags requiredProperties);
};


#endif //GAMMA_VULKANUTILS_H
