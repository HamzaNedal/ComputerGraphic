#include <GL\glut.h>

class GLintPoint {
  public:
	  GLint  x , y;
};
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // set the background to white
	glColor3f(0.0f, 0.0f, 0.0f); // set the drawing color to black

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void parameterizedHouse(GLintPoint peak, GLint width, GLint height)
{

	glBegin(GL_LINE_LOOP); // draw shell of house 
	glVertex2i(peak.x, peak.y);   
	glVertex2i(peak.x + width / 2, peak.y - 3 * height / 8);
	glVertex2i(peak.x + width / 2 , peak.y - height);
	glVertex2i(peak.x - width / 2, peak.y - height);
	glVertex2i(peak.x - width / 2, peak.y - 3 * height / 8);

	//Chimeney of the house
	glVertex2i(peak.x - width / 3, peak.y - height / 4.5);
	glVertex2i(peak.x - width / 3, peak.y);
	glVertex2i(peak.x - width / 5, peak.y);
	glVertex2i(peak.x - width / 5, peak.y - height/6);
	glEnd();

	glBegin(GL_LINE_LOOP); //draw the door
	glVertex2i(peak.x - width / 3, peak.y - 5 * height / 8);
	glVertex2i(peak.x - width / 3, peak.y - height);
	glVertex2i(peak.x - width / 5, peak.y - height);
	glVertex2i(peak.x - width /5, peak.y - 5 * height / 8);
    glEnd();

	glBegin(GL_LINE_LOOP); //draw the window
	glVertex2i(peak.x + width / 3, peak.y - 5 * height / 8);
	glVertex2i(peak.x + width / 3, peak.y - height / 2);
	glVertex2i(peak.x + width /5 , peak.y - height / 2);
	glVertex2i(peak.x + width / 5, peak.y - 5 * height /8);
	glEnd();

}
//-------------------------------------------------------------------
void myDisplay(void)
{
	GLintPoint p;
	p.x = 250;
	p.y = 350;
	glClear(GL_COLOR_BUFFER_BIT);
	parameterizedHouse(p, 250, 250);
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my house");

	glutDisplayFunc(myDisplay);

	myInit();

	glutMainLoop();
}