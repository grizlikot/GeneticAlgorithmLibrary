//
// Created by Deiwid on 2017-04-11.
//

#ifndef GAMMA_TEXTUREDOBJECT_H
#define GAMMA_TEXTUREDOBJECT_H

#include <gli/gli.hpp>
#include "TransformableObject.h"

class GAMMA_LIB TexturedObject : public TransformableObject {
private:
    gli::texture2d texture;
    std::vector<TexturedVertex> texturedVertices;
protected:
    void loadTexture(std::string texturePath);
    void loadMesh(std::vector<TexturedVertex> vertices, std::vector<uint32_t> indices);
public:
    TexturedObject(std::string texturePath);
    TexturedObject();
    virtual ~TexturedObject() {}
    friend class VulkanRenderer;
};


#endif //GAMMA_TEXTUREDOBJECT_H
