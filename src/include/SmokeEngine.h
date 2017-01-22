#ifndef _SMOKEENGINE_H
#define _SMOKEENGINE_H

#include <GL/glew.h>
#include <time.h>
#include <ctime>
#include <Render/Renderer.h>
#include "SceneManager.h"

class SmokeEngine
{
private:
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

	SmokeEngine();
	~SmokeEngine(void);
};
#endif
