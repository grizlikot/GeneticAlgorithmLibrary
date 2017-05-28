#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H

#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan.h>
#include "Renderer.h"
#include "VulkanWindow.h"
#include "VulkanDebugExtHandler.h"
#include "VulkanImageHandler.h"
#include "VulkanShaderHandler.h"
#include "QueueW.h"
#include "PipelineW.h"

class VulkanRenderer : public Renderer {
private:
    vk::Instance vkInstance;
    vk::PhysicalDevice vkPhysicalDevice;
    vk::Device vkDevice;
    QueueW vkQueue;
    vk::SurfaceKHR vkSurface;
    vk::Extent2D currentExtent;
    vk::SwapchainKHR vkSwapchain;
    std::vector<VulkanImageHandler> vkScImages;
    VulkanImageHandler depthImage;
    vk::RenderPass vkRenderPass;
    std::vector<vk::Framebuffer> vkScFramebuffers;
    vk::DescriptorSetLayout vkUBODescriptorSetLayout;
    vk::DescriptorSetLayout vkSamplerDescriptorSetLayout;
    vk::DescriptorPool vkDescriptorPool;
    vk::PipelineCache vkPipelineCache;
    PipelineW coloredVertexPipeline;
    PipelineW texturedVertexPipeline;
    vk::CommandPool vkCommandPool;
    std::vector<std::pair<vk::CommandBuffer, vk::Fence>> vkPrimaryCmdBuffers;
    /// \brief A semaphore, which is signalled when an image is acquired from the swapchain,
    /// and rendering to the image can start
    vk::Semaphore canRender;
    /// \brief A semaphore, which is signalled when the rendering to the image has finished
    /// and the image can be presented to the screen
    vk::Semaphore canPresent;
    VulkanDebugExtHandler debugHandler;
    std::shared_ptr<VulkanWindow> window;
    /// Returns missing Vulkan instance layers, if any
    /// \param [in] layers The required instance layers
    /// \return missing instance layers, if any
    std::vector<std::string> getMissingInstanceLayers(const std::vector<std::string> &layers);
    /// Returns missing Vulkan instance extensions, if any
    /// \param [in] extensions The required instance extensions
    /// \return missing instance extensions, if any
    std::vector<std::string> getMissingInstanceExtensions(const std::vector<std::string> &extensions);
    /// Returns missing Vulkan device extensions, if any
    /// \param [in] extensions The required device extensions
    /// \return missing device extensions, if any
    std::vector<std::string> getMissingDeviceExtensions(vk::PhysicalDevice device, const std::vector<std::string> &extensions);
    /// \brief Initializes the Vulkan instance
    void initInstance();
    /// \brief Initializes the Vulkan device
    void initDevice();
    /// \brief Initializes the swapchain
    void initSwapchain();
    /// \brief Initializes the renderpass
    void initRenderPass();
    /// \brief Initializes the swapchain framebuffers
    void initFramebuffers();
    /// \brief Initializes the ubo descriptor set layout
    void initDescriptorSetLayouts();
    /// \brief Initializes the descriptor pool
    void initDescriptorPool();
    /// \brief Initializes the pipeline
    void initPipeline();
    /// \brief Initializes the command pool
    void initCommandPool();
    /// \brief Initializes the primary command buffer
    void initPrimaryCommandBuffer();
    /// \brief Init semaphores
    void initSemaphores();
    /// \brief Selects a physical device in accordance to the configuration
    /// \return the selected physical device
    vk::PhysicalDevice selectPhysicalDevice(vk::SurfaceKHR surface);
    /// \brief Checks if the physical device contains a graphics queue family
    int32_t getGraphicsQueueFamilyIndex(vk::PhysicalDevice device, vk::SurfaceKHR surface);
    /// \brief Tries to convert the provided present mode to an enum
    vk::PresentModeKHR resolvePresentMode();
public:
    VulkanRenderer(std::shared_ptr<VulkanWindow> window);
    void init() override;
    void drawFrame(std::shared_ptr<Scene> scene) override;
    void deinit() override;
    void onObjectChange(Object *obj) override;
    void onSceneChange(Scene *scene) override;
    virtual ~VulkanRenderer();
    void deinitRenderData(Object *obj) override;
};

#endif
