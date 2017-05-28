//
// Created by Deiwid on 2017-04-14.
//

#ifndef GAMMA_LOADABLEOBJECT_H
#define GAMMA_LOADABLEOBJECT_H


#include "TexturedObject.h"

class GAMMA_LIB LoadableObject : public TexturedObject {
protected:
    void loadObject(std::string modelPath, std::string texturePath);
};


#endif //GAMMA_LOADABLEOBJECT_H
