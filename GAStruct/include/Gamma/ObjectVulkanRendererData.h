//
// Created by Deiwid on 2017-04-04.
//

#ifndef GAMMA_VULKANRENDERERDATA_H
#define GAMMA_VULKANRENDERERDATA_H

#include "ObjectRendererData.h"
#include "VulkanBufferHandler.h"

class ObjectVulkanRendererData : public ObjectRendererData {
public:
    ObjectVulkanRendererData(vk::Device device) : device(device) {};
    VulkanBufferHandler vertexBuffer;
    VulkanBufferHandler indexBuffer;
    VulkanBufferHandler uniformBuffer;
    vk::DescriptorSet descriptorSet;
    std::vector<vk::CommandBuffer> commandBuffers;
    vk::Sampler textureSampler;
    VulkanImageHandler texture;
    vk::Device device;
    PipelineW pipeline;
    virtual ~ObjectVulkanRendererData() {
        vertexBuffer.destroy();
        indexBuffer.destroy();
        uniformBuffer.destroy();
        texture.destroy();
        if(textureSampler) device.destroySampler(textureSampler);
        // TODO: free command buffers and descriptor set?
    }
};

#endif //GAMMA_VULKANRENDERERDATA_H
