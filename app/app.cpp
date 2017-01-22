#include <GL/glew.h>
#include <GL/glut.h>
#include <include/SmokeEngine.h>
#include "../Examples/PostProcessing/src/TestScene.h"
#include "../Examples/PostProcessing/src/JulianSet.h"
#include "../Examples/PostProcessing/src/PostProcessing.h"


SmokeEngine * engine;


void display();
void reshape(GLint width, GLint height);
void updateGame();
// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize((GLint)1280, (GLint)720);
	glutCreateWindow("Teapot");

	glewInit();
	engine = new SmokeEngine();
	engine->SetSize(1280,720);

	//engine->mSceneManager->AppendScene("main",new PostProcessing(engine));
    engine->mSceneManager->AppendScene("main",new TestScene(engine));

    engine->mSceneManager->SetActiveScene("main");

	glutReshapeFunc(reshape);
	glutIdleFunc(updateGame);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void updateGame()
{
	engine->Step();
}



// Clears the window and draws the tetrahedron.
void display() {

	engine->Draw();

	glutSwapBuffers();
	glutPostRedisplay();
}



//reshape screen
void reshape(GLint width, GLint height)
{
    glutReshapeWindow( 1280, 720);

}