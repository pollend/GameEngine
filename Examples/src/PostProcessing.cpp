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
#include <SmokeEngine/imgui.h>
#include "SceneImgui.h"


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

    _rgbDesyncProcedure = new RenderingProcedure(NULL, new Source("assets/rgb_desync.vs") , new Source("assets/rgb_desync.fs"));
    _grayScaleProcedure = new RenderingProcedure(NULL,new Source("assets/grayscale.vs"),new Source("assets/grayscale.fs"));
    _blurProcedure = new RenderingProcedure(NULL,new Source("assets/blur.vs"),new Source("assets/blur.fs"));
    _sobelProcedure = new RenderingProcedure(NULL,new Source("assets/sobel.vs"),new Source("assets/sobel.fs"));

    _frame = new Texture(1280,720,TEXTURE_RGBA);
    _buffer = new Framebuffer(mSmokeEngine,boost::array<Texture*,1>{_frame}, true);

    _rgbDesyncProcedure->GetShader()->SetTexture("in_BaseImage",_frame,0);
    _grayScaleProcedure->GetShader()->SetTexture("in_BaseImage",_frame,0);
    _blurProcedure->GetShader()->SetTexture("in_BaseImage",_frame,0);
    _sobelProcedure->GetShader()->SetTexture("in_BaseImage",_frame,0);

    {
        VertexBufferObjectWithSubData *lsubData = new VertexBufferObjectWithSubData();
        VertexElementBuffer *lVertexArray = WaveFrontLoad::Load("assets/Teapot.obj", lsubData);

        Model *lmodel = new Model(this, lsubData, lVertexArray, new Source("assets/basic.vs"),
                                  new Source("assets/phongshading.fs"));
        lmodel->mShader->SetTexture("in_BaseImage", new Texture("assets/color_map_1.png"), 0);

        _teapot = new ObjectNode("test_2");
        _teapot->SetRenderObject(lmodel,true);
    }

    {
//        VertexBufferObjectWithSubData *lsubData = new VertexBufferObjectWithSubData();
//        VertexElementBuffer *lVertexArray = WaveFrontLoad::Load("assets/drag.obj", lsubData);
//
//        Model *lmodel = new Model(this, lsubData, lVertexArray, new Source("assets/basic.vs"), new Source("assets/phongshading.fs"));
//        lmodel->mShader->SetTexture("in_BaseImage", new Texture("assets/test-pattern.png"), 0);
//
//        _testObject = new ObjectNode("test");
//        _testObject->SetRenderObject(lmodel,true);
    }

    _lightNode = new Node("Light");
    _camera = new Camera("Main",3.14f/2.0f,1,.5f,20);
}

void PostProcessing::UnLoad()
{
    SceneNode::UnLoad();

}


void PostProcessing::Initialize()
{
    _processingType = DESYNC;
    //_testObject->Position = Vector3f(-10,-3,-30);
    _teapot->Position = Vector3f(0,-3,-30);
    x = 0;
}

float clip( float n, float lower, float upper )
{
    n = ( n > lower ) * n + !( n > lower ) * lower;
    return ( n < upper ) * n + !( n < upper ) * upper;
}

void PostProcessing::Update(float deltaT)
{
    SceneImgui::SceneSelect(this->mSmokeEngine);

    if(ImGui:: CollapsingHeader("Effects")) {
        if (ImGui::Button("RGB Desync")) _processingType = DESYNC;
        if (ImGui::Button("Grayscale")) _processingType = GRAYSCALE;
        if (ImGui::Button("Blur")) _processingType = BLUR;
        if (ImGui::Button("Sobel")) _processingType = SOBEL;
    }

        switch (_processingType) {
            case DESYNC: {

                static float rShiftx = 0.003f;
                static float rShifty = 0.0f;
                static float gShiftx = -0.003f;
                static float gShifty = 0.0f;
                static float bShiftx = 0.0f;
                static float bShifty = 0.003f;
                if(ImGui:: CollapsingHeader("Options")) {


                    ImGui::SliderFloat("red channel x", &rShiftx, -0.5f, 0.5f);
                    ImGui::SliderFloat("red channel y", &rShifty, -0.5f, 0.5f);

                    ImGui::SliderFloat("green channel x", &gShiftx, -0.5f, 0.5f);
                    ImGui::SliderFloat("green channel y", &gShifty, -0.5f, 0.5f);

                    ImGui::SliderFloat("blue channel x", &bShiftx, -0.5f, 0.5f);
                    ImGui::SliderFloat("blue channel y", &bShifty, -0.5f, 0.5f);

                }
                _rgbDesyncProcedure->GetShader()->SetUniform2("red_shift", Eigen::Vector2f(rShiftx, rShifty));
                _rgbDesyncProcedure->GetShader()->SetUniform2("green_shift", Eigen::Vector2f(gShiftx, gShifty));
                _rgbDesyncProcedure->GetShader()->SetUniform2("blue_shift", Eigen::Vector2f(bShiftx, bShifty));
                _teapot->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());



            }
                break;
            case GRAYSCALE: {
                static float red_channel = 1.0f;
                static float green_channel = 0.0f;
                static float blue_channel = 0.0f;
                static  bool color = false;

                float red_new_channel = red_channel;
                float green_new_channel = green_channel;
                float blue_new_channel = blue_channel;

                if(ImGui:: CollapsingHeader("Options")) {
                    if (ImGui::Button("color")) color = !color;
                    ImGui::SliderFloat("red channel", &red_new_channel, 0.0f, 1.0f);
                    ImGui::SliderFloat("green channel", &green_new_channel, 0.0f, 1.0f);
                    ImGui::SliderFloat("blue channel", &blue_new_channel, 0.0f, 1.0f);
                }

                if (red_new_channel - red_channel != 0) {
                    green_channel -= (red_new_channel - red_channel) / 2.0f;
                    blue_channel -= (red_new_channel - red_channel) / 2.0f;
                    red_channel = red_new_channel;
                } else if (green_new_channel - green_channel != 0) {
                    red_channel -= (green_new_channel - green_channel) / 2.0f;
                    blue_channel -= (green_new_channel - green_channel) / 2.0f;
                    green_channel = green_new_channel;
                } else if (blue_new_channel - blue_channel != 0) {
                    red_channel -= (blue_new_channel - blue_channel) / 2.0f;
                    green_channel -= (blue_new_channel - blue_channel) / 2.0f;
                    blue_channel = blue_new_channel;
                }
                red_channel = clip(red_channel, 0, 1);
                green_channel = clip(green_channel, 0, 1);
                blue_channel = clip(blue_channel, 0, 1);

                _grayScaleProcedure->GetShader()->SetUniform1("in_red_factor", red_channel);
                _grayScaleProcedure->GetShader()->SetUniform1("in_green_factor", green_channel);
                _grayScaleProcedure->GetShader()->SetUniform1("in_blue_factor", blue_channel);
                _grayScaleProcedure->GetShader()->SetUniform1("color", color);


            }
                break;
            case BLUR:
                static float blur_width = 0.002f;
                static float blur_height = 0.002f;
                if(ImGui:: CollapsingHeader("Options")) {
                    ImGui::SliderFloat("blur width", &blur_width, 0.0f, 0.5f);
                    ImGui::SliderFloat("blur height", &blur_height, 0.0f, 0.5f);
                }
                _blurProcedure->GetShader()->SetUniform1("in_xblur", blur_width);
                _blurProcedure->GetShader()->SetUniform1("in_yblur", blur_height);
                _teapot->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());
                break;
            case SOBEL:

                _teapot->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());
                break;
        }


    x += (deltaT);
    _teapot->GetRenderObject()->mShader->SetMatrix4x4("in_light", _camera->GetTransformMatrixRelativeToNode(_lightNode));
    _lightNode->Position = Vector3f( 100,0,0);
//    _testObject->Rotation = Eigen::AngleAxisf(x, Eigen::Vector3f::UnitY());
//    _testObject->GetRenderObject()->mShader->SetMatrix4x4("in_light",_camera->GetTransformMatrixRelativeToNode(_lightNode));



}

void PostProcessing::Draw(Renderer *renderer) {


    renderer->ChangeRenderTarget(_buffer);
    //renderer->DrawNode(_testObject,_camera);
    renderer->DrawNode(_teapot,_camera);
    renderer->UnbindRenderTarget();

    switch (_processingType) {
        case DESYNC:
            _rgbDesyncProcedure->Draw();
            break;
        case GRAYSCALE:
            _grayScaleProcedure->Draw();
            break;
        case BLUR:
            _blurProcedure->Draw();
            break;
        case SOBEL:
            _sobelProcedure->Draw();
            break;

    }
}

void PostProcessing::Input(InputEvent* Event)
{

}
