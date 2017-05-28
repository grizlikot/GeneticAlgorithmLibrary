//
// Created by Deiwid on 2017-04-04.
//

#ifndef GAMMA_OBJECT_H
#define GAMMA_OBJECT_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <memory>
#include <atomic>
#include "BuildOptions.h"
#include "ObjectRendererData.h"
#include "Transform.h"
#include "ColoredVertex.h"
#include "Scene.h"
#include "ObjectType.h"
#include "TexturedVertex.h"

class Scene;

class GAMMA_LIB Object {
private:
    std::unique_ptr<ObjectRendererData> rendererData;
    uint64_t id;
protected:
    std::vector<ColoredVertex> coloredVertices;
    std::vector<uint32_t> indices;
    ObjectType objectType;
    Scene *scene = nullptr;
    Transform transform;
    std::string name;
    void loadMesh(std::vector<ColoredVertex> vertices, std::vector<uint32_t> indices);
    std::atomic<bool> ready = {false};
    void setReady(bool isReady);
public:
    Object(ObjectType type = ObjectType::undefined);
    std::string getName();
    void setScene(Scene *newScene);
    virtual bool operator==(Object& other);
    virtual void init() = 0;
    virtual void update(double deltaTime) = 0;
    virtual ~Object() {};
    friend class VulkanRenderer;
    friend class Scene;
};


#endif //GAMMA_OBJECT_H
