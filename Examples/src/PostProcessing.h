//
// Created by michaelpollind on 1/20/17.
//
#ifndef _POSTPROCESSING_H
#define _POSTPROCESSING_H
#include <Node/ObjectNode.h>
#include <Render/RenderingProcedure/RenderingProcedure.h>
#include <Node/SceneNode.h>
#include <Render/Framebuffers/Framebuffer.h>
#include <Render/Model.h>

enum ProcessingType{
    DESYNC,
    GRAYSCALE,
    GRAYSCALE_1
};

class PostProcessing  : public SceneNode
{
private:
    Camera* _camera;
    ObjectNode * _testObject;
    ObjectNode* _teapot;
    Node * _lightNode;
    RenderingProcedure* _rgbDesyncProcedure;
    RenderingProcedure* _grayScaleProcedure;
    Texture* _frame;
    Framebuffer* _buffer;
    Model* _model;
    ProcessingType _processingType;
    float x;
public:


    PostProcessing(SmokeEngine* smokeEngine);
    ~PostProcessing(void);

    virtual void Update(float deltaT);
    virtual void Input(InputEvent* Event) ;
    virtual void Initialize();
    virtual void Load();
    virtual void UnLoad();
    virtual void Draw(Renderer* renderer);

};


#endif //ASSIGMENT_3_POSTPROCESSING_H
