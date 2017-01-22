//
// Created by michaelpollind on 1/21/17.
//

#ifndef _JULIANSET_H
#define _JULIANSET_H

#include <Node/ObjectNode.h>
#include <Render/RenderingProcedure/RenderingProcedure.h>
#include "Node/SceneNode.h"
#include <Render/Framebuffers/Framebuffer.h>
#include <Render/Model.h>

class JulianSet : public SceneNode
{
private:

    RenderingProcedure* _procedure;
public:


    JulianSet(SmokeEngine* smokeEngine,Camera * camera);
    ~JulianSet(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;
    virtual void Initialize();
    virtual void Load();
    virtual void UnLoad();
    virtual void Draw(Renderer* renderer);

};


#endif //ASSIGMENT_3_JULIANSET_H
