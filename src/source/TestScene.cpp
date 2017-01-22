#include <Render/Sprite.h>
#include "TestScene/TestScene.h"
#include "Render/Model.h"
#include "Utility/WaveFrontLoad.h"
#include "SmokeEngine.h"
#include <Eigen/Dense>
#include "Utility/Matrix/MatrixHelper.h"

using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Quaternionf;
TestScene::TestScene(SmokeEngine* smokeEngine) : SceneNode(smokeEngine)
{


}

TestScene::~TestScene(void)
{
}

void TestScene::Load()
{
	SceneNode::Load();
	VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
	VertexElementBuffer * lVertexArray = WaveFrontLoad::Load("assets/Teapot.obj",lsubData);

	Model* lmodel = new Model(this,lsubData, lVertexArray, new Source("assets/basic.vs"), new Source("assets/phongshading.fs"));
	lmodel->mShader->SetTexture("in_BaseImage",new Texture("assets/test-pattern.png"),0);

	_lightNode = new Node("Light");
	_testObject = new ObjectNode("test");
	_testObject->SetRenderObject(lmodel,true);


	_camera = new Camera("Main",3.14f/2.0f,1,.5f,20);
}

void TestScene::UnLoad()
{
	SceneNode::UnLoad();
}

void TestScene::Initialize()
{
	_testObject->Position = Vector3f(0,-3,-30);
	x = 0;
}

void TestScene::Update(float deltaT) 
{
	_testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",_camera->GetTransformMatrixRelativeToNode(_lightNode));

	Matrix4f t = _camera->GetTransformMatrixRelativeToNode(_lightNode);
	x += (deltaT);
	//this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
	_lightNode->Position = Vector3f( 100,0,0);

	_testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());

}

void TestScene::Draw(Renderer *renderer) {
	renderer->DrawNode(_testObject,_camera);

}

void TestScene::Input(InputEvent* Event)
{

}
