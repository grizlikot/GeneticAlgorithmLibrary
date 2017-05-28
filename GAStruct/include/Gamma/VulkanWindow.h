#ifndef VULKAN_WINDOW_H
#define VULKAN_WINDOW_H

#include <vector>
#include <set>

#include "Window.h"


class VulkanWindow : public Window {
public:
    virtual std::set<const char *> getRequiredExtensions() = 0;
    virtual vk::SurfaceKHR createSurface(vk::Instance instance) = 0;
    virtual ~VulkanWindow() {}
};

#endif