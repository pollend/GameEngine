//
// Created by michaelpollind on 1/19/17.
//
#include <GL/glew.h>
#include "Render/Framebuffers/Framebuffer.h"


Framebuffer::Framebuffer() {

}

void Framebuffer::Bind() {
    glBindFramebuffer(GL_FRAMEBUFFER,_frameBuffer);
}
void Framebuffer::Unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER,0);
}

