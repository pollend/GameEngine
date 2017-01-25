#include <Render/Sprite.h>
#include "Render/Model.h"
#include "Utility/WaveFrontLoad.h"
#include "SmokeEngine.h"
#include <Eigen/Dense>
#include "Utility/Matrix/MatrixHelper.h"
#include "SceneImgui.h"
#include "VertexBallon.h"


VertexBallon::VertexBallon(SmokeEngine* smokeEngine) : SceneNode(smokeEngine)
{

}
VertexBallon::~VertexBallon()
{

}

void VertexBallon::Input(InputEvent* Event)
{

}

void VertexBallon::Load()
{
    SceneNode::Load();
    VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
    VertexElementBuffer * lVertexArray = WaveFrontLoad::Load("assets/drag.obj",lsubData);

    Model* lmodel = new Model(this,lsubData, lVertexArray, new Source("assets/ballon.vs"), new Source("assets/phongshading.fs"));
    lmodel->mShader->SetTexture("in_BaseImage",new Texture("assets/test-pattern.png"),0);

    _lightNode = new Node("Light");
    _testObject = new ObjectNode("test");
    _testObject->SetRenderObject(lmodel,true);


    _camera = new Camera("Main",3.14f/2.0f,1,.5f,20);
}
void VertexBallon::UnLoad()
{
    SceneNode::UnLoad();
}
void VertexBallon::Initialize()
{
    _testObject->Position = Vector3f(0,-3,-30);
    x = 0;
}
void VertexBallon::Update(float deltaT)
{
    SceneImgui::SceneSelect(this->mSmokeEngine);

    static float ballon = -0.0f;
    ImGui::SliderFloat("ballon factor", &ballon, -1.0f, 1.0f);
    _testObject->GetRenderObject()->mShader->SetUniform1("in_ballon_factor",ballon);

    _testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",_camera->GetTransformMatrixRelativeToNode(_lightNode));

    Matrix4f t = _camera->GetTransformMatrixRelativeToNode(_lightNode);
    x += (deltaT);
    //this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
    _lightNode->Position = Vector3f( 100,0,0);

    _testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());
}

void VertexBallon::Draw(Renderer* renderer)
{
    renderer->DrawNode(_testObject,_camera);
}