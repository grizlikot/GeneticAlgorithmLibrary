#ifndef GAMMA_H
#define GAMMA_H

#include <vulkan/vulkan.hpp>

#include "BuildOptions.h"
#include "Global.h"
#include "Window.h"
#include "Timer.h"
#include "Object.h"
#include "Scene.h"

#define GAMMA_CONFIG_DIR "./conf/"
#define GAMMA_CONFIG_PATH GAMMA_CONFIG_DIR"config.json"
#define GAMMA_DEFAULT_CONFIG_PATH GAMMA_CONFIG_DIR"default_config.json"

class Renderer;
class Scene;
class Object;

class GAMMA_LIB Gamma {
private:
    std::shared_ptr<Window> window;
    std::shared_ptr<Renderer> renderer;
    json ovrride;
    void loadConfig();
    void onSceneChange(Scene *scene);
    void onNewObject(Object *obj);
    std::shared_ptr<Scene> scene;
public:
    Gamma();
    void init();
    void overrideConfig(json ovrride);
    void startMainLoop();
    std::shared_ptr<Scene> getScene();
    virtual ~Gamma();
    friend class Scene;
};

#endif