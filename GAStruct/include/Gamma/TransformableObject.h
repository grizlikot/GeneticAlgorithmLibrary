//
// Created by Deiwid on 2017-04-14.
//

#ifndef GAMMA_TRANSFORMABLEOBJECT_H
#define GAMMA_TRANSFORMABLEOBJECT_H


#include "Object.h"

class GAMMA_LIB TransformableObject : public Object {
public:
    TransformableObject(ObjectType type = ObjectType::undefined);
    void setPosition(glm::vec3 pos);
    void addPosition(glm::vec3 dPos);
    void setRotation(glm::vec3 rot);
    void addRotation(glm::vec3 dRot);
    void setScale(glm::vec3 scale);
    void addScale(glm::vec3 dScale);
    glm::vec3 getPostion();
    glm::vec3 getRotation();
    glm::vec3 getScale();
    void persistTransform();
};


#endif //GAMMA_TRANSFORMABLEOBJECT_H
