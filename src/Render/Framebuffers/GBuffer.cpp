//
// Created by michaelpollind on 1/20/17.
//

#include <SmokeEngine.h>
#include "GBuffer.h"

GBuffer::GBuffer(SmokeEngine *smokeEngine) : Framebuffer::Framebuffer(smokeEngine,boost::array<Texture*,3>{
        smokeEngine->mTextureStorage->AppendTexture(new Texture((int) smokeEngine->Width, (int) smokeEngine->Height, TEXTURE_RGB)),
        smokeEngine->mTextureStorage->AppendTexture(new Texture((int) smokeEngine->Width, (int) smokeEngine->Height, TEXTURE_RGB)),
        smokeEngine->mTextureStorage->AppendTexture(new Texture((int) smokeEngine->Width, (int) smokeEngine->Height, TEXTURE_RGBA))
},true) {



}
