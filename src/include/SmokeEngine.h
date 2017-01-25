#ifndef _SMOKEENGINE_H
#define _SMOKEENGINE_H

#include <GL/glew.h>
#include <time.h>
#include <ctime>
#include <Render/Renderer.h>
#include "SceneManager.h"
#include <GLFW/glfw3.h>

class SmokeEngine
{
private:
	GLFWwindow* _window;
	double _time;
	int _width;
	int _height;
public:
	SceneManager * mSceneManager;
	Renderer* mRenderer;

	void SetSize(int width, int height);
	void Step();
	void Draw();

	int GetWidth();
	int GetHeight();

	void CreateWindowContext();

	SmokeEngine();
	~SmokeEngine(void);
};
#endif
