//
// Created by michaelpollind on 1/19/17.
//

#ifndef _RENDERINGPROCEDURE_H
#define _RENDERINGPROCEDURE_H

class RenderingProcedure {
private:
    RenderingProcedure* _next;
public:
    RenderingProcedure(RenderingProcedure* next);
    ~RenderingProcedure();

    RenderingProcedure* GetNextProcedureInChain();
    virtual void Draw() = 0;

};
#endif
