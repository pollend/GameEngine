#pragma once

#include <Node/ObjectNode.h>
#include "Node/SceneNode.h"


class TestScene : public SceneNode
{
private:
    ObjectNode * _testObject;
    Node * _lightNode;
    Camera* _camera;
    float x;
public:


    TestScene(SmokeEngine* smokeEngine);
    ~TestScene(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;

    virtual void Load();
    virtual void UnLoad();
    virtual void Initialize();
    virtual void Draw(Renderer* renderer);

};