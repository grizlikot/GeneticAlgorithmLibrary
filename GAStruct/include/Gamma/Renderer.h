#ifndef RENDERER_H
#define RENDERER_H

#include "Object.h"
#include "Scene.h"

class Renderer {
public:
    virtual void init() = 0;
    virtual void drawFrame(std::shared_ptr<Scene> scene) = 0;
    virtual void deinitRenderData(Object *obj) = 0;
    /// \brief Prepares the renderer for a graceful exit
    virtual void deinit() = 0;
    virtual void onObjectChange(Object *obj) = 0;
    virtual void onSceneChange(Scene *scene) = 0;
    virtual ~Renderer() {}
};

#endif
