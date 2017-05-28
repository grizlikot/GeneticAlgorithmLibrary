//
// Created by Deiwid on 2017-03-12.
//

#ifndef GAMMA_VULKANDEBUGEXTHANDLER_H
#define GAMMA_VULKANDEBUGEXTHANDLER_H


#include <vulkan/vulkan.h>
#include <vulkan/vulkan.hpp>

class VulkanDebugExtHandler {
    static PFN_vkCreateDebugReportCallbackEXT createDebugCallback;
    static PFN_vkDestroyDebugReportCallbackEXT destroyDebugCallback;
    VkDebugReportCallbackEXT debugReportCallback = VK_NULL_HANDLE;
public:
    void init(vk::Instance vkInstance);
    void destroy(vk::Instance vkInstance);
    static VKAPI_ATTR vk::Bool32 VKAPI_CALL vkDebugCallback(VkDebugReportFlagsEXT vkFlags, VkDebugReportObjectTypeEXT vkOType,
                                                            uint64_t src_obj, size_t location, int32_t msgCode,
                                                            const char *layerPrefix, const char* msg, void *userData);
    virtual ~VulkanDebugExtHandler() {}
};


#endif //GAMMA_VULKANDEBUGEXTHANDLER_H
