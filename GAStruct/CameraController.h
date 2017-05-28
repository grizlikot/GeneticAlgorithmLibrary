#ifndef GAMMA_CAMERACONTROLLER_H
#define GAMMA_CAMERACONTROLLER_H


#include <Gamma\Object.h>

class CameraController : public Object {
    float rot = 0;
    void init() override;

    void update(double deltaTime) override;
};


#endif 
