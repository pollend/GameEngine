//
// Created by michaelpollind on 1/20/17.
//
#ifndef _DEFERREDSCENE_H
#define _DEFERREDSCENE_H

#include <Node/ObjectNode.h>
#include "Node/SceneNode.h"
#include "Render/RenderingProcedure/RenderingProcedure.h"

class DeferredScene : public SceneNode
{
private:
    Texture* _position;
    Texture* _normals;
    Texture* _albedo;

    RenderingProcedure* renderProcedure;

    ObjectNode * _testObject;
    Node * _lightNode;

    float x;
public:


    DeferredScene(SmokeEngine* smokeEngine,Camera * camera);
    ~DeferredScene(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;

    virtual void Load();
    virtual void UnLoad();
    virtual void Inintalize();
    virtual void InintalizeScene();
    virtual void Draw(Renderer* renderer);

};

#endif //ASSIGMENT_3_DEFERREDSCENE_H
