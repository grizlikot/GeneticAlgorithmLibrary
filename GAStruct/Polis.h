#ifndef GAMMA_POLIS_H
#define GAMMA_POLIS_H


#include <Gamma/LoadableObject.h>

class Polis : public LoadableObject {
public:
    Polis(glm::vec2 startingPos);
    void init() override;

    void update(double deltaTime) override;
};


#endif 
