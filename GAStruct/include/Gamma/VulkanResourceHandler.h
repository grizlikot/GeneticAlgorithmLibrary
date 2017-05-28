//
// Created by Deiwid on 2017-03-23.
//

#ifndef GAMMA_VULKANRESOURCEHANDLER_H
#define GAMMA_VULKANRESOURCEHANDLER_H




template<typename T, typename TV, typename TCI, typename TVCI>
class VulkanResourceHandler {
public:
    virtual void create(vk::Device device, TCI createInfo, TVCI viewCreateInfo, vk::PhysicalDeviceMemoryProperties memoryProperties) = 0;
    virtual void destroy() = 0;
    virtual operator T() = 0;
    virtual operator TV() = 0;
    virtual TCI getCreateInfo() = 0;
    virtual TVCI getViewCreateInfo() = 0;
    virtual ~VulkanResourceHandler() {}
};

#endif //GAMMA_VULKANRESOURCEHANDLER_H
