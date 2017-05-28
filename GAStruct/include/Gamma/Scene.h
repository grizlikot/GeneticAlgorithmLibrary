//
// Created by Deiwid on 2017-04-04.
//

#ifndef GAMMA_SCENE_H
#define GAMMA_SCENE_H

#include <set>
#include <list>
#include "Gamma.h"
#include "SceneUpdate.h"
#include "Camera.h"

class Object;
class Gamma;

class GAMMA_LIB Scene {
private:
    std::set<std::shared_ptr<Object>> objects;
    std::list<std::shared_ptr<Object>> readyObjects;
    Gamma *gamma;
    SceneUpdate sceneUpdate;
    void removeFromObjects(uint64_t objId);
    void removeFromActiveObjects(uint64_t objId);
    Timer updateTimer;
    std::atomic<bool> run = { false };
    std::atomic<bool> paused = { false };
    std::thread updateThread;
    void updateFunction();
public:
    Camera camera;
    Scene(Gamma *gamma);
    void addObject(std::shared_ptr<Object> obj);
    void addObjects(std::vector<std::shared_ptr<Object>> objs);
    void removeObject(uint64_t objId);
    void start();
    void pause();
    void unpause();
    void stop();
    void destroy();
    void onReadyChange(Object *obj, bool isReady);
    void meshChanged(Object *obj);
    std::list<std::shared_ptr<Object>> getReadyObjects();
    std::set<std::shared_ptr<Object>> getAllObjects();
    virtual ~Scene();
};


#endif //GAMMA_SCENE_H
