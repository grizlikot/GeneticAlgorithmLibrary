//
// Created by Deiwid on 2017-03-26.
//

#ifndef GAMMA_VULKANSHADERHANDLER_H
#define GAMMA_VULKANSHADERHANDLER_H


#include <vulkan/vulkan.hpp>
#include <regex>

class VulkanShaderHandler {
private:
    static std::regex vertStage;
    static std::regex tescStage;
    static std::regex teseStage;
    static std::regex geomStage;
    static std::regex fragStage;
    static std::regex compStage;
    vk::Device device;
    std::vector<char> shaderData;
    vk::ShaderModule shaderModule;
    vk::PipelineShaderStageCreateInfo stageCreateInfo;
    vk::ShaderStageFlagBits resolveStage(const std::string &shaderPath);
public:
    VulkanShaderHandler();
    VulkanShaderHandler(VulkanShaderHandler &&other);
    VulkanShaderHandler(vk::Device device, const std::string &shaderPath,
                        vk::ShaderStageFlagBits shaderStage = vk::ShaderStageFlagBits());
    void create(vk::Device device, const std::string &shaderPath, vk::ShaderStageFlagBits shaderStage = vk::ShaderStageFlagBits());
    operator vk::ShaderModule&();
    operator vk::PipelineShaderStageCreateInfo&();
    void destroy();
    virtual ~VulkanShaderHandler();
};


#endif //GAMMA_VULKANSHADERHANDLER_H
