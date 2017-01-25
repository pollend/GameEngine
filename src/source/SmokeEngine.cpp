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

void SmokeEngine::CreateWindowContext()
{
	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	_window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//glfwSetKeyCallback(_window, key_callback);
	glfwMakeContextCurrent(_window);
    glewInit();
	glfwSwapInterval(1);


}


void SmokeEngine::Step()
{
    _width = 1280;
    _height = 720;
	while (!glfwWindowShouldClose(_window)) {

        glfwGetFramebufferSize(_window, &_width, &_height);

		struct timespec d;
		clock_gettime(CLOCK_MONOTONIC, &d);
		double ldiff = ((double) ((d.tv_sec + (d.tv_nsec / 1000000000.0)) - _time));
		_time = (double) (d.tv_sec + (d.tv_nsec / 1000000000.0));
		mSceneManager->Update(ldiff);
		Draw();

        glfwSwapBuffers(_window);
        glfwPollEvents();
	}


    glfwDestroyWindow(_window);
    glfwTerminate();

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

