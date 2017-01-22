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

#include <boost/array.hpp>

using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Quaternionf;
JulianSet::JulianSet(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{


}

JulianSet::~JulianSet(void)
{
}

void JulianSet::Load()
{
    SceneNode::Load();
    _procedure = new RenderingProcedure(NULL, new Source("assets/fractals/julianset.fs") , new Source("assets/fractals/julianset.vs"));


}
void JulianSet::Initialize() {

}
void JulianSet::UnLoad()
{
    SceneNode::UnLoad();

}



void JulianSet::Update(float deltaT)
{


}

void JulianSet::Draw(Renderer *renderer) {
    _procedure->Draw();

}

void JulianSet::Input(InputEvent* Event)
{

}
