#pragma once

#include <Node/ObjectNode.h>
#include "Node/SceneNode.h"


class TestScene : public SceneNode
{
private:
    ObjectNode * _testObject;
    Node * _lightNode;

    float x;
public:


    TestScene(SmokeEngine* smokeEngine,Camera * camera);
    ~TestScene(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;

    virtual void Load();
    virtual void UnLoad();
    virtual void Initialize();
    virtual void Draw(Renderer* renderer);

};