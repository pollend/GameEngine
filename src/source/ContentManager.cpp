//
// Created by michaelpollind on 1/21/17.
//

#include "ContentManager.h"

std::shared_ptr<Model> ContentManager::LoadModel(const char *path) {
    return std::shared_ptr<Model>();
}

std::shared_ptr<Texture> ContentManager::LoadTexture(const char *path) {
    return std::make_shared<Texture>(path);
}

std::shared_ptr<Source> ContentManager::LoadSourceFromRaw(const char *src, GLenum type) {
    return std::shared_ptr<Source>();
}

std::shared_ptr<Source> ContentManager::LoadSource(const char *path) {
    return std::shared_ptr<Source>();
}
