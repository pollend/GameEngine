//
// Created by michaelpollind on 1/21/17.
//

#include "JulianSet.h"
#include <Render/Sprite.h>
#include "Render/Model.h"
#include "Utility/WaveFrontLoad.h"
#include "SmokeEngine.h"
#include <Eigen/Dense>
#include "Utility/Matrix/MatrixHelper.h"
#include "SceneImgui.h"
#include <boost/array.hpp>

using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Quaternionf;
JulianSet::JulianSet(SmokeEngine* smokeEngine) : SceneNode(smokeEngine)
{


}

JulianSet::~JulianSet(void)
{
}

void JulianSet::Load()
{
    SceneNode::Load();
    _procedure = new RenderingProcedure(NULL, new Source("assets/julianset.fs") , new Source("assets/julianset.vs"));


}
void JulianSet::Initialize() {

}
void JulianSet::UnLoad()
{
    SceneNode::UnLoad();
}



void JulianSet::Update(float deltaT)
{
    static float shift = -0.550f;
    ImGui::SliderFloat("index", &shift, -1.0f, 1.0f);
    _procedure->GetShader()->SetUniform1("in_shift",shift);
    SceneImgui::SceneSelect(this->mSmokeEngine);

}

void JulianSet::Draw(Renderer *renderer) {
    _procedure->Draw();

}

void JulianSet::Input(InputEvent* Event)
{

}
