#include "SmokeEngine.h"
#include <boost/log/trivial.hpp>
#include <imgui_impl_glfw_gl3.h>
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
	_width = 1280;
	_height = 720;

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	_window = glfwCreateWindow(_width, _height, "Simple example", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//glfwSetKeyCallback(_window, key_callback);
	glfwMakeContextCurrent(_window);
    glewInit();
    ImGui_ImplGlfw_Init(_window, true);
	glfwSwapInterval(1);

}


void SmokeEngine::Step()
{

	while (!glfwWindowShouldClose(_window)) {
        glfwPollEvents();
        ImGui_ImplGlfw_NewFrame();

		struct timespec d;
		clock_gettime(CLOCK_MONOTONIC, &d);
		double ldiff = ((double) ((d.tv_sec + (d.tv_nsec / 1000000000.0)) - _time));
		_time = (double) (d.tv_sec + (d.tv_nsec / 1000000000.0));
		mSceneManager->Update(ldiff);

		glfwGetFramebufferSize(_window, &_width, &_height);
		glViewport(0, 0, _width, _height);
		glClear(GL_COLOR_BUFFER_BIT);


		Draw();
		glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        glUseProgram(0);
        ImGui::Render();
        glfwSwapBuffers(_window);

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

