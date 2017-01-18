#include "SmokeEngine.h"
#include <boost/log/trivial.hpp>

SmokeEngine::SmokeEngine()
{
	

	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();

	mRenderer = new Renderer();
	mSceneManager = new SceneManager(this);
	_time = clock();

	struct timespec d;
    clock_gettime(CLOCK_MONOTONIC, &d);
	_time = (double)( d.tv_sec+ (d.tv_nsec / 1000000000.0));

}



SmokeEngine::~SmokeEngine(void)
{

}


void SmokeEngine::Step()
{
	
	struct timespec d;
    clock_gettime(CLOCK_MONOTONIC, &d);
	double ldiff = ((double)(( d.tv_sec + (d.tv_nsec / 1000000000.0)) - _time));
	_time = (double)( d.tv_sec+ (d.tv_nsec / 1000000000.0));
	mSceneManager->Update(ldiff);
	Draw();

}

void SmokeEngine::Draw()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	if(mSceneManager->GetActiveSceneNode()->IsLoad())
		mRenderer->Draw(mSceneManager->GetActiveSceneNode());


	GLenum err;
	while((err = glGetError()) != GL_NO_ERROR)
	{
		BOOST_LOG_TRIVIAL(error) <<"GL_ERROR:"<< err;
	}
}

