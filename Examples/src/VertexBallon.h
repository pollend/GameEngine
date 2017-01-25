//
// Created by michaelpollind on 1/25/17.
//

#ifndef _VERTEXBALLON_H
#define _VERTEXBALLON_H

#include <Node/ObjectNode.h>
#include "Node/SceneNode.h"


class VertexBallon : public SceneNode
{
private:
    ObjectNode * _testObject;
    Node * _lightNode;
    Camera* _camera;
    float x;
public:


    VertexBallon(SmokeEngine* smokeEngine);
    ~VertexBallon();

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;

    virtual void Load();
    virtual void UnLoad();
    virtual void Initialize();
    virtual void Draw(Renderer* renderer);
};


#endif //SMOKEENGINE_VERTEXBALLON_H
