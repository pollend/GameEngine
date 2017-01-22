//
// Created by michaelpollind on 1/20/17.
//

#include "PostProcessing.h"


#include <Render/Sprite.h>
#include "Render/Model.h"
#include "Utility/WaveFrontLoad.h"
#include "SmokeEngine.h"
#include <Eigen/Dense>
#include "Utility/Matrix/MatrixHelper.h"

#include <boost/array.hpp>

using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Quaternionf;
PostProcessing::PostProcessing(SmokeEngine* smokeEngine) : SceneNode(smokeEngine)
{


}

PostProcessing::~PostProcessing(void)
{
}

void PostProcessing::Load()
{
    SceneNode::Load();

    _procedure = new RenderingProcedure(NULL, new Source("assets/rgb_desync.vs") , new Source("assets/rgb_desync.fs"));

    _frame = new Texture(1280,720,TEXTURE_RGBA);
    _buffer = new Framebuffer(mSmokeEngine,boost::array<Texture*,1>{_frame}, true);
    _procedure->GetShader()->SetTexture("in_BaseImage",_frame,0);


    VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
    VertexElementBuffer * lVertexArray = WaveFrontLoad::Load("assets/drag.obj",lsubData);

    Model* lmodel = new Model(this,lsubData, lVertexArray, new Source("assets/basic.vs"), new Source("assets/phongshading.fs"));
    lmodel->mShader->SetTexture("in_BaseImage",new Texture("assets/test-pattern.png"),0);

    _lightNode = new Node("Light");
    _testObject = new ObjectNode("test");
    _testObject->SetRenderObject(lmodel,true);

    _camera = new Camera("Main",3.14f/2.0f,1,.5f,20);
}

void PostProcessing::UnLoad()
{
    SceneNode::UnLoad();

}


void PostProcessing::Initialize()
{
    _testObject->Position = Vector3f(0,-3,-30);
    x = 0;
}

void PostProcessing::Update(float deltaT)
{

    x += (deltaT);
    //this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
    _lightNode->Position = Vector3f( 100,0,0);
    _testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());
    _testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",_camera->GetTransformMatrixRelativeToNode(_lightNode));

}

void PostProcessing::Draw(Renderer *renderer) {


    renderer->ChangeRenderTarget(_buffer);
    renderer->DrawNode(_testObject,_camera);
    renderer->UnbindRenderTarget();
    _procedure->Draw();


}

void PostProcessing::Input(InputEvent* Event)
{

}
