//
// Created by Deiwid on 2017-03-22.
//

#ifndef GAMMA_VULKANIMAGEHANDLER_H
#define GAMMA_VULKANIMAGEHANDLER_H


#include <vulkan/vulkan.hpp>
#include <gli/texture2d.hpp>
#include "VulkanResourceHandler.h"
#include "QueueW.h"

class VulkanImageHandler : public VulkanResourceHandler<vk::Image, vk::ImageView, vk::ImageCreateInfo, vk::ImageViewCreateInfo> {
private:
    vk::Device vkDevice;
    vk::Image vkImage;
    bool imageOwner;
    vk::DeviceMemory vkMemory;
    vk::ImageView vkImageView;
    vk::ImageCreateInfo imageCreateInfo = {};
    vk::ImageViewCreateInfo imageViewCreateInfo = {};
public:
    VulkanImageHandler();
    VulkanImageHandler(vk::Device device, vk::ImageCreateInfo imageCreateInfo, vk::ImageViewCreateInfo imageViewCreateInfo, vk::PhysicalDeviceMemoryProperties memoryProperties);
    VulkanImageHandler(vk::Device device, vk::Image resource, vk::ImageCreateInfo createInfo, vk::ImageViewCreateInfo viewCreateInfo);
    VulkanImageHandler(VulkanImageHandler &&other);
    void create(vk::Device device, vk::ImageCreateInfo imageCreateInfo, vk::ImageViewCreateInfo imageViewCreateInfo, vk::PhysicalDeviceMemoryProperties memoryProperties) override;
    void create(vk::Device device, vk::Image image, vk::ImageCreateInfo createInfo, vk::ImageViewCreateInfo viewCreateInfo);
    void loadTextureViaStagingBuffer(gli::texture2d texture, vk::CommandPool commandPool, QueueW queue, vk::PhysicalDeviceMemoryProperties memoryProperties);
    void *mapMemory();
    void unmapMemory();
    void destroy() override;
    operator vk::Image() override;
    operator vk::ImageView() override;
    vk::ImageCreateInfo getCreateInfo() override;
    vk::ImageViewCreateInfo getViewCreateInfo() override;
    virtual ~VulkanImageHandler();
};


#endif //GAMMA_VULKANIMAGEHANDLER_H
