
#include <stdio.h>
#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}

int random(int m) { return rand() % m; }

void drawFlurry(int num, int xCenter ,int yCenter)
// draw num random rectangles in a Width by Height rectangle
{

	for (int i = 0; i < num; i++)
	{
		GLfloat xCenter1 = random(xCenter);
		GLfloat yCenter2 = random(yCenter);
		
		GLfloat lev = random(10) / 10.0; // random value, in range 0 to 1
		GLfloat lev1 = random(10) / 10.0;
		GLfloat lev2 = random(10) / 10.0;

		glBegin(GL_POLYGON);
		glColor3f(lev, lev1, lev2); // set the gray level
		glVertex2f(xCenter1, yCenter2 + 100);
		glVertex2f(xCenter1 + 100, yCenter2);
		glVertex2f(xCenter1, yCenter2 - 100);
		glVertex2f(xCenter1 - 100, yCenter2);
		glEnd();

	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//100,100
	drawFlurry(200, 1000, 1000);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Test");
	glutDisplayFunc(myDisplay);
	//glutMouseFunc(myMouse);
//	glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop();
	return 0;
}

