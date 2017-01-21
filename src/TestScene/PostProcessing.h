//
// Created by michaelpollind on 1/20/17.
//

#include <Node/ObjectNode.h>
#include <Render/RenderingProcedure/RenderingProcedure.h>
#include "Node/SceneNode.h"
#include <Render/Framebuffers/Framebuffer.h>
#include <Render/Model.h>

#ifndef _POSTPROCESSING_H
#define _POSTPROCESSING_H


class PostProcessing  : public SceneNode
{
private:
    ObjectNode * _testObject;
    Node * _lightNode;
    RenderingProcedure* _procedure;
    Texture* _frame;
    Framebuffer* _buffer;
    Model* _model;
    float x;
public:


    PostProcessing(SmokeEngine* smokeEngine,Camera * camera);
    ~PostProcessing(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;

    virtual void Load();
    virtual void UnLoad();
    virtual void Inintalize();
    virtual void InintalizeScene();
    virtual void Draw(Renderer* renderer);

};


#endif //ASSIGMENT_3_POSTPROCESSING_H
