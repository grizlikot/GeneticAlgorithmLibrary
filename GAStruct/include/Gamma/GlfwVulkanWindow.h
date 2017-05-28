#ifndef GLFW_VULKAN_WINDOW_H
#define GLFW_VULKAN_WINDOW_H

#include <GLFW/glfw3.h>
#include <vector>
#include <vulkan/vulkan.hpp>

#include "VulkanWindow.h"

class GlfwVulkanWindow : public VulkanWindow {
private:

    GLFWwindow *window = nullptr;
    GLFWmonitor *monitor = nullptr;
    std::string title;
    int width;
    int height;
public:
    GlfwVulkanWindow(const int width = 640, const int height = 480, const std::string &title = "Gamma", const  bool fullscreen = false);
    void setTitle(const std::string title) override;
    void setFullscreen(const bool fullscreen) override;
    void setSize(const int width, const int height) override;
    void setVisible(const bool visible) override;
    void pollEvents() override;
    bool shouldClose() override;
    void destroy() override;
    void create() override;
    std::set<const char *> getRequiredExtensions() override;
    vk::SurfaceKHR createSurface(vk::Instance instance) override;
    virtual ~GlfwVulkanWindow();
};

#endif
