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
	//	glColor3f(1.0, 0.0, 0.0);
	}
	glEnd();
}

void display()
{


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-150, -100, 150, 150);//rect	
	DrawCircle(0, 140, 150, 50);//top circle
	DrawCircle(-120, -100, 30, 50);//bottom  circle left
	DrawCircle(0, -100, 30, 50);//bottom circle maiddle
	DrawCircle(120, -100, 30, 50);//bottom rigth circle 
	//eye left
	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(-70, 100, 35, 50);//white eye  
	glColor3f(0.0,0.0, 1.0);
	DrawCircle(-70, 100, 20, 50);//blue eye  

	//eye rghit
	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(70, 100, 35, 50);//white eye  
	glColor3f(0.0, 0.0, 1.0);
	DrawCircle(70, 100, 20, 50);//blue eye  
	glFlush();



}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game #5");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}
