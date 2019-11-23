#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

void init(void)
{

	glClearColor(0.0, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300, 300, -300, 300);

}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 

	float x = r;//we start at angle = 0 

	float y = 0;

	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex 

		float tx = -y;
		float ty = x;
		x += tx * tangetial_factor;
		y += ty * tangetial_factor;
		x *= radial_factor;
		y *= radial_factor;

	}
	glEnd();
}

void display()
{


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);//sun
	DrawCircle(-200, 230, 50, 50);

	//cloud
	glColor3f(1, 1, 1);
	DrawCircle(200, 240, 50, 50);
	glColor3f(1, 1, 1);
	DrawCircle(180, 220, 50, 50);
	glColor3f(1, 1, 1);
	DrawCircle(200, 200, 50, 50);
	glColor3f(1, 1, 1);
	DrawCircle(220, 210, 50, 50);

	//tree
	glColor3f(0.0, 1.0, 0.0);
	glRectf(-600, -600, 600, -200);
	glColor3f(231 / 256, 224 / 256, 139 / 256);
	glRectf(-200, -200, -150, 30);
	glColor3f(0, 1, 0);
	DrawCircle(-175, 0, 50, 50);
	glColor3f(231 / 256, 224 / 256, 139 / 256);
	glRectf(200, -200, 150, 30);
	glColor3f(0, 1, 0);
	DrawCircle(175, 0, 50, 50);

	//house
	glColor3f(0.94, 0.84, 0.85);
	glRectf(-100, -200, 100, 0);

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex2f(-100, 0);
	glVertex2f(0, 50);
	glVertex2f(100, 0);
	glEnd();

	glColor3f(0, 1, 1);//window 1
	glRectf(-50, -70, -10, -30);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-30, -70);
	glVertex2f(-30, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-50, -50);
	glVertex2f(-10, -50);
	glEnd();

	glColor3f(0, 1, 1);//window 2
	glRectf(20, -70, 60, -30);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, -70);
	glVertex2f(40, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(20, -50);
	glVertex2f(60, -50);
	glEnd();

	glColor3f(0, 0, 0);//door
	glRectf(-10, -200, 30, -100);

	glColor3f(1, 1, 0);//circle door
	DrawCircle(25, -150, 5, 100);
	glFlush();



}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Draw");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}
