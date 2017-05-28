#ifndef GAMMA_FUNDAMENTAS_H
#define GAMMA_FUNDAMENTAS_H


#include <Gamma/LoadableObject.h>

class Fundamentas : public LoadableObject {
public:
    Fundamentas(glm::vec2 topLeft, glm::vec2 bottomRight);
    void init() override;

    void update(double deltaTime) override;
};


#endif 
