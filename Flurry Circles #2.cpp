#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>
#include <iostream>

float R = 0.2;
float G = .7;
float B = 0.5;

int random(int a) {
	return (rand() % a);
}

float random2(int a) {
	return (rand() % a);
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(4.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}

void DrawCircle()
{
	float cx;
	float cy;
	float r;
	int num_segments = 500;
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i< 50; i++)
	{
		R = (random2(10) / 10.0);
		G = (random2(10) /10.0);
		B = (random2(10)  /10.0);

		float cx = rand() % 640;
		float cy = rand() % 480;
		float r = rand() % 80;

		glBegin(GL_POINTS);
		glColor3f(R, G, B);
		for (float ii = 0; ii < num_segments; ii += .5)
		{
			GLfloat angle = ii * 0.0174533;

			glVertex2d(cx + (cos(angle)  *r), cy + (sin(angle) * r));

		}
		glEnd();
		glFlush();
	}
	for (int i = 0; i< 50; i++)
	{
		R = (random2(10) /10.0);
		G = (random2(10) / 10.0);
		B = (random2(10) / 10.0);

		float cx = rand() % 640;
		float cy = rand() % 480;
		float r = rand() % 80;

		glBegin(GL_LINE_LOOP);
		glColor3f(R, G, B);
		for (float ii = 0; ii <num_segments; ii += .5)
		{
			GLfloat angle = ii * 0.0174533;
			glVertex2f(cx, cy); 
			glVertex2d(cx + (cos(angle) * r), cy + (sin(angle) * r));

		}
		glEnd();
		glFlush();
	}
}

void flurry()
{
	for (size_t i = 0; i <100; i++)
	{

		GLint x = random(640);
		GLint y = random(480);
		GLint lingth = random(200);

		R = (random2(100) * 100.0);
		G = (random2(100) * 100.0);
		B = (random2(100) * 100.0);

		glBegin(GL_POLYGON);

		glColor3f(R, G, B);

		glVertex2i(x - lingth, y);
		glVertex2i(x, y - lingth);
		glVertex2i(x + lingth, y);
		glVertex2i(x, y + lingth);
		glEnd();
		glFlush();
	}

}




void main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("flurry Circle");
	glutDisplayFunc(DrawCircle);

	myInit();
	glutMainLoop();

}