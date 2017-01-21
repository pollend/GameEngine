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
PostProcessing::PostProcessing(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{


}

PostProcessing::~PostProcessing(void)
{
}

void PostProcessing::Load()
{
    SceneNode::Load();

    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("PhongShading",GL_FRAGMENT_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("PhongShading",new Source("assets/phongshading.fs"));
    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("BasicVertex",GL_VERTEX_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("BasicVertex",new Source("assets/basic.vs"));


    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("RGBDesync",GL_FRAGMENT_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("RGBDesync",new Source("assets/rgb_desync.fs"));
    if(!this->mSmokeEngine->mShaderSourceStorage->IsSourceUsed("RGBDesync",GL_VERTEX_SHADER))
        this->mSmokeEngine->mShaderSourceStorage->AppendSource("RGBDesync",new Source("assets/rgb_desync.vs"));

    if(!this->mSmokeEngine->mVertexBufferStorage->IsVertexArrayObjectExist("Teapot") || !this->mSmokeEngine->mVertexBufferStorage->IsVertexObjectWithSubDataExist("Teapot"))
    {
        VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
        VertexElementBuffer * lVertexArray = WaveFrontLoad::Load("assets/Teapot.obj",lsubData);
        this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lsubData);
        this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lVertexArray);
    }

    _procedure = new RenderingProcedure(NULL,
            this->mSmokeEngine->mShaderSourceStorage->GetSource("RGBDesync",GL_VERTEX_SHADER) ,
            this->mSmokeEngine->mShaderSourceStorage->GetSource("RGBDesync",GL_FRAGMENT_SHADER));

    if(!this->mSmokeEngine->mTextureStorage->IsTextureUsed("assets/test-pattern.png"))
        this->mSmokeEngine->mTextureStorage->AppendTexture( new Texture("assets/test-pattern.png"));

    _frame = new Texture(mSmokeEngine->Width,mSmokeEngine->Height,TEXTURE_RGBA);
    _buffer = new Framebuffer(mSmokeEngine,boost::array<Texture*,1>{_frame}, false);

    _procedure->GetShader()->SetTexture("in_BaseImage",_frame,0);

}

void PostProcessing::UnLoad()
{
    SceneNode::UnLoad();

    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("RGBDesync",GL_FRAGMENT_SHADER);
    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("RGBDesync",GL_VERTEX_SHADER);

    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("PhongShading",GL_FRAGMENT_SHADER);
    this->mSmokeEngine->mShaderSourceStorage->DeleteSource("BasicVertex",GL_VERTEX_SHADER);

    this->mSmokeEngine->mVertexBufferStorage->DeleteVertexArryObject("Teapot");
    this->mSmokeEngine->mVertexBufferStorage->DeleteVertexObjectWithSubData("Teapot");

    this->mSmokeEngine->mTextureStorage->DeleteTexture("test-pattern.png");
}

void PostProcessing::InintalizeScene()
{
    Model* lmodel = new Model(this,
                              this->mSmokeEngine->mVertexBufferStorage->GetVertexObjectWithSubData("Teapot"),
                              this->mSmokeEngine->mVertexBufferStorage->GetVertexArryObject("Teapot"),
                              this->mSmokeEngine->mShaderSourceStorage->GetSource("BasicVertex",GL_VERTEX_SHADER) ,
                              this->mSmokeEngine->mShaderSourceStorage->GetSource("PhongShading",GL_FRAGMENT_SHADER));
    lmodel->mShader->SetTexture("in_BaseImage",this->mSmokeEngine->mTextureStorage->GetTexture("assets/test-pattern.png"),0);
    Sprite* sp = new Sprite(this,this->mSmokeEngine->mTextureStorage->GetTexture("assets/test-pattern.png"));
    _model = lmodel;
    _testObject->SetRenderObject(lmodel,true);


}

void PostProcessing::Inintalize()
{
    _lightNode = new Node("Light");

    _testObject = new ObjectNode("test");
    this->mRootSceneNode->AppendNode(_testObject);
    this->mRootSceneNode->AppendNode(_lightNode);
    _testObject->Position = Vector3f(0,-3,-30);

    x = 0;
}

void PostProcessing::Update(float deltaT)
{
    _testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode));

    Matrix4f t = this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode);
    x += (deltaT);
    //this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
    _lightNode->Position = Vector3f( 100,0,0);

    _testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());

}

void PostProcessing::Draw(Renderer *renderer) {
    renderer->ChangeRenderTarget(_buffer);
    glClearColor(0.1f, 0.1f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderer->DrawNode(_testObject,mMainCamera);

    renderer->UnbindRenderTarget();
    glClearColor(1.0f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    _procedure->Draw();




}

void PostProcessing::Input(InputEvent* Event)
{

}
