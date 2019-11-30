#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL\freeglut.h>
#endif
#include <cstdlib>
#include <iostream>
using namespace std;

using namespace std;


float r = 0.0f;
float g = 0.0f;
float b = 0.0f;
float r1 = 0.0f;
float g1 = 0.0f;
float b1 = 0.0f;

void init(void) {

	glClearColor(0.83, 0.83, 0.83, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}

int random(int m) { return rand() % m; }

void MouseButton(int button, int action, int xPixel, int yPixel) {

	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		yPixel = glutGet(GLUT_WINDOW_HEIGHT) - yPixel;
		//cout << yPixel;
		int* index = new int[1];
		//Index1
		glReadPixels(xPixel, yPixel, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, index);// Read pixel under mouse's cursor and read information from stencil buffer to index when it rectangle index should be equal to 1


		if (index[0] == 1) {

			GLfloat lev = random(10) / 10.0; // random value, in range 0 to 1
			GLfloat lev1 = random(10) / 10.0;
			GLfloat lev2 = random(10) / 10.0;
			GLfloat lev10 = random(10) / 10.0; // random value, in range 0 to 1
			GLfloat lev100 = random(10) / 10.0;
			GLfloat lev200 = random(10) / 10.0;
			r1 = lev;
			g1 = lev1;
			b1 = lev2;
			glClearColor(lev10, lev100, lev200, 0.0f);
		}

		delete index;
	}

	glutPostRedisplay();
}

void Rectangles(void) {

	glStencilFunc(GL_ALWAYS, 1, -1);
	glColor3f(r1, g1, b1);
	glRectf(50, 200, 600, 400);


}
void Display(void) {
	glClearStencil(0); // specifies the index used by glClear to clear the stencil buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Rectangles();
	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_STENCIL); //Bit mask to select a window with a stencil buffer.
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Mouse");
	init();
	glutDisplayFunc(&Display);
	glutMouseFunc(&MouseButton);
	glutMainLoop();

	return EXIT_SUCCESS;
}