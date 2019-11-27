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
	DrawCircle(-310, 280,65, 50);
	


	//cloud3
	glColor3f(1, 1, 1);
	DrawCircle(160, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(200, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(240, 200, 35, 50);
	//cloud2
	glColor3f(1, 1, 1);
	DrawCircle(-10, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(30, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(70, 200, 35, 50);
	//cloud1
	glColor3f(1, 1, 1);
	DrawCircle(-170, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(-140, 200, 35, 50);
	glColor3f(1, 1, 1);
	DrawCircle(-100, 200, 35, 50);


	//ground
	glColor3f(0.72, 0.83, 0.19);
	glRectf(-600, -600, 600, -200);
	//ground2
	glColor3f(0.50, 0.52, 0.50);
	glRectf(-600, -50, 600, -180);
	int x = -300;
	int y = -180;
	int x2 = -200;
	int y2 = -200;
	int y12 = -50;
	int y22 = -30;
	for (int i = 0; i < 6; i++)
	{
		if (i%2==0)
		{
			glColor3f(1, 0, 0);
			glRectf(x, y, x2, y2);
			glRectf(x, -50, x2, -30);
			glColor3f(1, 1, 0);
			glRectf(x, -130, x2-10, -110);
		}
		else {
			glColor3f(1,1, 1);
			glRectf(x, y, x2, y2);
			glRectf(x, -50, x2, -30);
			glColor3f(1, 1, 1);
			glRectf(x, -130, x2-10, -110);
		}
		x  += 100;
		x2 +=100;
	
		
	}
	


	//tree
	int xtreeponit1 = -200;
	int xtreeponit2 = -180;
	int xtree1 = -230;
	int xtree2 = -190;
	int xtree3 = -150;
	int space = 130;

	for (int i = 0; i < 4; i++)
	{
		glColor3f(0.54, 0.09, 0.11);
		glRectf(xtreeponit1, -30, xtreeponit2, 80);
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 0);
		glVertex2f(xtree1, 80);
		glVertex2f(xtree2, 120);
		glVertex2f(xtree3, 80);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 0);
		glVertex2f(xtree1, 100);
		glVertex2f(xtree2, 150);
		glVertex2f(xtree3, 100);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 0);
		glVertex2f(xtree1, 120);
		glVertex2f(xtree2, 190);
		glVertex2f(xtree3, 120);
		glEnd();
		xtreeponit1 += space;
		xtreeponit2 += space;
		xtree1 += space;
		xtree2 += space;
		xtree3 += space;

	}
	int xShapePonit1 = -200;
	int xShapePonit2 = -160;
	int xShapePonit3 = -150;
	int xShapePonit4 = -180;
	int xShapePonit5 = -210;
	int ChangePostion = 60;
	for (int i = 0; i < 7; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f(xShapePonit1, -300);
		glVertex2f(xShapePonit2, -300);
		glVertex2f(xShapePonit3, -270);
		glVertex2f(xShapePonit4, -250);
		glVertex2f(xShapePonit5, -270);
		glEnd();

		xShapePonit1 += ChangePostion;
		xShapePonit2 += ChangePostion;
		xShapePonit3 += ChangePostion;
		xShapePonit4 += ChangePostion;
		xShapePonit5 += ChangePostion;
	}
	
	
	

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
	//glutKeyboardFunc(mykey);
	init();
	glutMainLoop();

	return 0;
}
