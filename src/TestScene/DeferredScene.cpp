//
// Created by michaelpollind on 1/20/17.
//

#include "DeferredScene.h"

#include <Render/Sprite.h>
#include "Render/Model.h"
#include "Utility/WaveFrontLoad.h"
#include "SmokeEngine.h"
#include <Eigen/Dense>
#include "Utility/Matrix/MatrixHelper.h"

using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Quaternionf;
DeferredScene::DeferredScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{


}

DeferredScene::~DeferredScene(void)
{
}

void DeferredScene::Load()
{
    SceneNode::Load();

    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("PhongShading",GL_FRAGMENT_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("PhongShading",new Source("assets/phongshading.fs"));
    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("BasicVertex",GL_VERTEX_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("BasicVertex",new Source("assets/basic.vs"));

    if(!this->mSmokeEngine->mVertexBufferStorage->IsVertexArrayObjectExist("Teapot") || !this->mSmokeEngine->mVertexBufferStorage->IsVertexObjectWithSubDataExist("Teapot"))
    {
        VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
        VertexElementBuffer * lVertexArray = WaveFrontLoad::Load("assets/Teapot.obj",lsubData);
        this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lsubData);
        this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lVertexArray);
    }


    if(!this->mSmokeEngine->mTextureStorage->IsTextureUsed("assets/test-pattern.png"))
        this->mSmokeEngine->mTextureStorage->AppendTexture( new Texture("assets/test-pattern.png"));


}

void DeferredScene::UnLoad()
{
    SceneNode::UnLoad();

    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("PhongShading",GL_FRAGMENT_SHADER);
    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("BasicVertex",GL_VERTEX_SHADER);

    this->mSmokeEngine->mVertexBufferStorage->DeleteVertexArryObject("Teapot");
    this->mSmokeEngine->mVertexBufferStorage->DeleteVertexObjectWithSubData("Teapot");

    this->mSmokeEngine->mTextureStorage->DeleteTexture("test-pattern.png");
}

void DeferredScene::InintalizeScene()
{
    Model* lmodel = new Model(this,
                              this->mSmokeEngine->mVertexBufferStorage->GetVertexObjectWithSubData("Teapot"),
                              this->mSmokeEngine->mVertexBufferStorage->GetVertexArryObject("Teapot"),
                              this->mSmokeEngine->mShaderSourceStorage->GetSource("BasicVertex",GL_VERTEX_SHADER) ,
                              this->mSmokeEngine->mShaderSourceStorage->GetSource("PhongShading",GL_FRAGMENT_SHADER));
    lmodel->mShader->SetTexture("in_BaseImage",this->mSmokeEngine->mTextureStorage->GetTexture("assets/test-pattern.png"),0);

    Sprite* sp = new Sprite(this,this->mSmokeEngine->mTextureStorage->GetTexture("assets/test-pattern.png"));

    _testObject->SetRenderObject(lmodel,true);

}

void DeferredScene::Inintalize()
{
    _lightNode = new Node("Light");

    _testObject = new ObjectNode("test");
    this->mRootSceneNode->AppendNode(_testObject);
    this->mRootSceneNode->AppendNode(_lightNode);
    _testObject->Position = Vector3f(0,-3,-30);

    x = 0;
}

void DeferredScene::Update(float deltaT)
{
    _testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode));

    Matrix4f t = this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode);
    x += (deltaT);
    //this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
    _lightNode->Position = Vector3f( 100,0,0);

    _testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());

}

void DeferredScene::Draw(Renderer *renderer) {
    //renderer->ChangeRenderTarget()
    renderer->DrawNode(_testObject,mMainCamera);

}

void DeferredScene::Input(InputEvent* Event)
{

}