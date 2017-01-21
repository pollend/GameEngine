//
// Created by michaelpollind on 1/19/17.
//

#ifndef _FRAMEBUFFER_H
#define _FRAMEBUFFER_H


#include <Utility/Texture.h>
#include <boost/array.hpp>
#include <boost/log/trivial.hpp>
#include <SmokeEngine.h>

class Framebuffer {
private:
    GLuint _frameBuffer;
    GLuint _depthRenderBuffer;
protected:
    Framebuffer();

public:
    template <long unsigned size>
    Framebuffer(SmokeEngine* smokeEngine, boost::array<Texture*,size> textures, bool useDepth)
    {
        glGenFramebuffers(1,&_frameBuffer);
        glBindFramebuffer(GL_FRAMEBUFFER,_frameBuffer);
        GLuint attachments[size];
        for(int i = 0; i < size; i++)
        {
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D + i,textures[i]->GetResourceID(), 0);
            attachments[i] = GL_COLOR_ATTACHMENT0 + i;
        }

       glDrawBuffers(size,attachments);
        if(useDepth)
        {
            glGenRenderbuffers(1,&_depthRenderBuffer);
            glBindRenderbuffer(GL_RENDERBUFFER, _depthRenderBuffer);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, smokeEngine->GetWidth(),  smokeEngine->GetHeight());
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _depthRenderBuffer);

        }
        else _depthRenderBuffer = 0;

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            BOOST_LOG_TRIVIAL(error) <<  "Framebuffer not complete!";

        glBindFramebuffer(GL_FRAMEBUFFER,0);
    }

    void Bind();

    static  void Unbind();
};


#endif
