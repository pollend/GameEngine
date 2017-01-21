#ifndef _SMOKEENGINE_H
#define _SMOKEENGINE_H

#include <GL/glew.h>
#include <time.h>
#include <ctime>
#include <Storage/ShaderSourceStorage.h>
#include <Storage/TextureStorage.h>
#include <Storage/VertexBufferStorage.h>
#include <Render/Renderer.h>
#include "SceneManager.h"

class SmokeEngine
{
private:
	 double _time;

public:

	int Width;
	int Height;

	ShaderSourceStorage * mShaderSourceStorage;
	TextureStorage * mTextureStorage;
	VertexBufferStorage * mVertexBufferStorage;

	SceneManager * mSceneManager;
	Renderer* mRenderer;
	
	void Step();
	void Draw();

	SmokeEngine();
	~SmokeEngine(void);
};
#endif
