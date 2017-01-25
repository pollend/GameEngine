//
// Created by michaelpollind on 1/25/17.
//

#ifndef _SCENEIMGUI_H
#define _SCENEIMGUI_H

#include "SmokeEngine/SmokeEngine.h"
#include "SmokeEngine/imgui.h"

class SceneImgui{
public:
    static void SceneSelect(SmokeEngine* smokeEngine)
    {
        ImGui::TreePush("Scenes");
        if(ImGui::Button("Texture Mapping")) smokeEngine->mSceneManager->SetActiveScene("texture_mapping");
        if(ImGui::Button("Julian Set")) smokeEngine->mSceneManager->SetActiveScene("julian_set");
        if(ImGui::Button("Post Processing")) smokeEngine->mSceneManager->SetActiveScene("post_processing");
        ImGui::TreePop();

    }

};

#endif //SMOKEENGINE_SCENEIMGUI_H
