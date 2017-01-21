//
// Created by michaelpollind on 1/19/17.
//

#include <cstdio>
#include "RenderingProcedure.h"

RenderingProcedure::RenderingProcedure(RenderingProcedure* next,Source* fragment,Source* vertex) {
    _next = next;

    GLfloat quadVertices[] = {
            // Positions        // Texture Coords
            -1.0f, 1.0f,  0.0f, 1.0f,
            -1.0f, -1.0f,0.0f, 0.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, -1.0f, 1.0f, 0.0f,
    };

    glGenVertexArrays(1,&_quadVAO);
    glGenBuffers(1,&_quadVBO);
    glBindVertexArray(_quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, _quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4* sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    _shader.AttachSource(vertex);
    _shader.AttachSource(fragment);
    _shader.SetAttrib(0,"in_Verts");
    _shader.SetAttrib(1,"in_Texcoords");
    _shader.IntalizeShader();
}


RenderingProcedure::~RenderingProcedure() {
}

RenderingProcedure* RenderingProcedure::GetNextProcedureInChain() {
    return _next;
}

Shader* RenderingProcedure::GetShader() {
    return  &_shader;
}

void RenderingProcedure::Draw() {
    _shader.BindShader();
    glBindBuffer(GL_ARRAY_BUFFER, _quadVBO);

    glBindVertexArray(_quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4* sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));



    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}
