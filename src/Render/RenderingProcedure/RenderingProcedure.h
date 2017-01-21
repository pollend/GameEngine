//
// Created by michaelpollind on 1/19/17.
//

#ifndef _RENDERINGPROCEDURE_H
#define _RENDERINGPROCEDURE_H

#include <Utility/Source.h>
#include <Render/Sprite.h>
#include <Utility/Shader.h>

class RenderingProcedure {
private:
    RenderingProcedure* _next;
    GLuint _quadVAO ;
    GLuint _quadVBO ;
protected:
    Shader _shader;
public:
    RenderingProcedure(RenderingProcedure* next,Source* fragment,Source* vertex);
    ~RenderingProcedure();

    Shader* GetShader();
    RenderingProcedure* GetNextProcedureInChain();
    virtual void Draw();

};
#endif
