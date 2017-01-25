//
// Created by michaelpollind on 1/22/17.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include <SmokeEngine.h>
#include "src/JulianSet.h"
#include "src/PostProcessing.h"
#include "src/TestScene.h"



SmokeEngine * engine;


void display();
void reshape(GLint width, GLint height);
void updateGame();
// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    engine = new SmokeEngine();
    engine->CreateWindowContext();
    engine->mSceneManager->AppendScene("post_processing",new PostProcessing(engine));
    engine->mSceneManager->AppendScene("julian_set",new JulianSet(engine));
    engine->mSceneManager->AppendScene("texture_mapping",new TestScene(engine));
    engine->mSceneManager->SetActiveScene("texture_mapping");
    engine->Step();
    return 0;
}
