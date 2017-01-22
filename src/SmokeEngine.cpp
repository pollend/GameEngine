#include "SmokeEngine.h"
#include <boost/log/trivial.hpp>

SmokeEngine::SmokeEngine()
{
	


	mRenderer = new Renderer();
	mSceneManager = new SceneManager(this);
	_time = clock();

	struct timespec d;
    clock_gettime(CLOCK_MONOTONIC, &d);
	_time = (double)( d.tv_sec+ (d.tv_nsec / 1000000000.0));

}

void SmokeEngine::SetSize(int width, int height) {
    _width = width;
    _height = height;
}

SmokeEngine::~SmokeEngine(void)
{

}


int SmokeEngine::GetWidth()
{
    return  _width;
}
int SmokeEngine::GetHeight()
{
    return _height;
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

    mRenderer->Clear();
	mSceneManager->GetActiveSceneNode()->Draw(mRenderer);


	GLenum err;
	while((err = glGetError()) != GL_NO_ERROR)
	{
		BOOST_LOG_TRIVIAL(error) <<"GL_ERROR:"<< err << "("<< gluErrorString(err) << ")";
	}
}

