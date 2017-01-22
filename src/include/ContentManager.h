//
// Created by michaelpollind on 1/21/17.
//

#ifndef _CONTENTMANAGER_H
#define _CONTENTMANAGER_H

#include <memory>
#include <Utility/Source.h>
#include <Utility/Texture.h>
#include <Render/Model.h>

class ContentManager {
public:
    std::shared_ptr<Source> LoadSource(const char* path);
    std::shared_ptr<Source> LoadSourceFromRaw(const char* src,GLenum type);
    std::shared_ptr<Texture> LoadTexture(const char* path);
    std::shared_ptr<Model> LoadModel(const char* path);


};


#endif //ASSIGMENT_3_CONTENTMANAGER_H
