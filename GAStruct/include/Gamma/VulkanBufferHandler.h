//
// Created by Deiwid on 2017-04-03.
//

#ifndef GAMMA_VULKANBUFFERHANDLER_H
#define GAMMA_VULKANBUFFERHANDLER_H


#include <vulkan/vulkan.hpp>
#include "VulkanResourceHandler.h"
#include "QueueW.h"

class VulkanBufferHandler {
private:
    vk::Device vkDevice;
    vk::Buffer vkBuffer;
    vk::DeviceMemory vkMemory;
    vk::BufferView vkBufferView;
    vk::BufferCreateInfo bufferCreateInfo = {};
    vk::BufferViewCreateInfo bufferViewCreateInfo = {};
public:
    VulkanBufferHandler();
    VulkanBufferHandler(VulkanBufferHandler &&other);
    VulkanBufferHandler(vk::Device device, vk::BufferCreateInfo createInfo, vk::BufferViewCreateInfo viewCreateInfo, vk::PhysicalDeviceMemoryProperties memoryProperties);
    VulkanBufferHandler(vk::Device device, vk::BufferCreateInfo createInfo, vk::PhysicalDeviceMemoryProperties memoryProperties, bool isStagingBuffer = false);
    void create(vk::Device device, vk::BufferCreateInfo createInfo, vk::BufferViewCreateInfo viewCreateInfo, vk::PhysicalDeviceMemoryProperties memoryProperties);
    void create(vk::Device device, vk::BufferCreateInfo createInfo, vk::PhysicalDeviceMemoryProperties memoryProperties, bool isStagingBuffer = false);
    void *mapMemory();
    void unmapMemory();
    void destroy();
    operator vk::Buffer();
    operator vk::BufferView();
    vk::BufferCreateInfo getCreateInfo();
    vk::BufferViewCreateInfo getViewCreateInfo();
    template<class T>
    void loadDataViaStagingBuffer(std::vector<T> data, vk::CommandPool commandPool, QueueW queue,
                                      vk::PhysicalDeviceMemoryProperties memoryProperties);
    template<class T>
    void loadData(std::vector<T> data);
    template<class T>
    void loadSingleElement(T data);
    void copy(VulkanBufferHandler &dst, QueueW queue, vk::CommandPool commandPool);
    static void copy(VulkanBufferHandler &src, VulkanBufferHandler &dst, QueueW queue, vk::CommandPool commandPool,
                         vk::Device device);
    virtual ~VulkanBufferHandler();
};

template<class T>
void VulkanBufferHandler::loadDataViaStagingBuffer(std::vector<T> data, vk::CommandPool commandPool, QueueW queue,
                                                   vk::PhysicalDeviceMemoryProperties memoryProperties) {
    vk::BufferCreateInfo stagingBufferCreateInfo = bufferCreateInfo;
    stagingBufferCreateInfo.usage = ( stagingBufferCreateInfo.usage &
                                            (~vk::BufferUsageFlagBits::eTransferDst) ) | vk::BufferUsageFlagBits::eTransferSrc;
    VulkanBufferHandler stagingBuffer(vkDevice, stagingBufferCreateInfo, memoryProperties, true);
    void *dst = stagingBuffer.mapMemory();
    memcpy(dst, data.data(), data.size() * sizeof(T));
    stagingBuffer.unmapMemory();
    stagingBuffer.copy(*this, queue, commandPool);
}

template<class T>
void VulkanBufferHandler::loadData(std::vector<T> data) {
    void *dst = mapMemory();
    memcpy(dst, data.data(), data.size() * sizeof(T));
    unmapMemory();
}

template<class T>
void VulkanBufferHandler::loadSingleElement(T data) {
    void *dst = mapMemory();
    memcpy(dst, &data, sizeof(T));
    unmapMemory();
}


#endif //GAMMA_VULKANBUFFERHANDLER_H
