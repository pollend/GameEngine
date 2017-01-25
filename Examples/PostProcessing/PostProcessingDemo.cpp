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
    engine->mSceneManager->AppendScene("main",new PostProcessing(engine));
    engine->mSceneManager->SetActiveScene("main");
    engine->Step();
    return 0;
}
