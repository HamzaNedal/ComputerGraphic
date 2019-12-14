#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL\freeglut.h>
#endif
#include <cstdlib>
#include <iostream>
using namespace std;

using namespace std;

float xWorldCoordinate = 0.0f;
float yWorldCoordinate = 0.0f;
float r = 0.0f;
float g = 0.0f;
float b = 0.0f;
float r1 = 0.0f;
float g1 = 0.0f;
float b1 = 0.0f;
bool isRed = false;
bool isBlue = false;
void init(void) {

	glClearColor(0.83, 0.83, 0.83, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}

void MouseButton(int button, int action, int xPixel, int yPixel) {

	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		yPixel = glutGet(GLUT_WINDOW_HEIGHT) - yPixel;
		//cout << yPixel;
		int* index = new int[1];
		//Index1
		glReadPixels(xPixel, yPixel, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, index);// Read pixel under mouse's cursor and read information from stencil buffer to index when it rectangle index should be equal to 1
	

		if (index[0] == 1) {
			r1 = 0.0f;
			g1 = 0.0f;
			b1 = 0.0f;
		}
		 if (index[0] == 2) {
				r1 = 1.0f;
				g1 = 0.0f;
				b1 = 0.0f;
		}
		 if (index[0] == 3) {
				r1 = 1.0f;
				g1 = 0.0f;
				b1 = 1.0f;
				
		}
		 if (index[0] == 4) {
			 r1 = 1.0f;
			 g1 = 1.0f;
			 b1 = 1.0f;
			
		 }
		 if (index[0] == 5) {
			 r1 = 1.0f;
			 g1 = 1.0f;
			 b1 = 0.0f;
			
		 }
		 if (index[0] == 6) {
			 r1 = 0.0f;
			 g1 = 1.0f;
			 b1 = 1.0f;
			 
		 }
		 if (index[0] == 7) {
			 r1 = 0.0f;
			 g1 = 0.0f;
			 b1 = 1.0f;

		 }
		 if (index[0] == 8) {
			 r1 = 0.0f;
			 g1 = 1.0f;
			 b1 = 0.0f;

		 }
		delete index;
	}

	glutPostRedisplay();
}

void Rectangles(void) {

	glStencilFunc(GL_ALWAYS, 99, -1);
	glColor3f(r1, g1, b1);
	glRectf(50, 200, 600, 400);

	glStencilFunc(GL_ALWAYS, 1, -1); //set front and back function and reference value for stencil testing
	glColor3f(r, g, b);
	glRectf(50, 50, 100, 100);

	glStencilFunc(GL_ALWAYS, 2, -1);
	glColor3f(1, 0, 0);
	glRectf(110, 50, 160, 100);

	glStencilFunc(GL_ALWAYS, 3, -1);
	glColor3f(1, 0, 1);
	glRectf(170, 50, 220, 100);

	glStencilFunc(GL_ALWAYS, 4, -1);
	glColor3f(1, 1, 1);
	glRectf(230, 50, 280, 100);

	glStencilFunc(GL_ALWAYS, 5, -1);
	glColor3f(1, 1, 0);
	glRectf(290, 50, 340, 100);

	glStencilFunc(GL_ALWAYS, 6, -1);
	glColor3f(0, 0.89,1);
	glRectf(350, 50, 400, 100);

	glStencilFunc(GL_ALWAYS, 7, -1);
	glColor3f(0, 0, 1);
	glRectf(410, 50, 460, 100);

	glStencilFunc(GL_ALWAYS, 8, -1);
	glColor3f(0, 1, 0);
	glRectf(470, 50, 520, 100);
	
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