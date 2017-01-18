#include <GL/glew.h>
#include <GL/glut.h>
#include <SmokeEngine.h>
#include <TestScene/TestScene.h>

SmokeEngine * engine;


void display();
void init();
void reshape(GLint width, GLint height);

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize((GLint)800, (GLint)600);
	glutCreateWindow("Teapot");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


// Initialize the application.
void init() {
	glewInit();
	engine = new SmokeEngine();
	engine->mSceneManager->AppendScene("main",new TestScene(engine,new Camera(3.14f/2.0f,1,.5f,20)));
	engine->mSceneManager->SetActiveScene("main");

}




// Clears the window and draws the tetrahedron.
void display() {

	engine->Step();
	engine->Draw();
	glutSwapBuffers();
	glutPostRedisplay();
}



//reshape screen
void reshape(GLint width, GLint height)
{
	glViewport(0, 0, width, height);

}