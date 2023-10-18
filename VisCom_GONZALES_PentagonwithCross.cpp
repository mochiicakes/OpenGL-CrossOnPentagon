#include <iostream>
#include <GL/glut.h>
using namespace std;

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(92,181,100);

	glPointSize(2.0);
	glBegin(GL_LINES);

	glVertex2f(0, 0.5);
	glVertex2f(0.5, 0.2);

	glVertex2f(0.5, 0.2);
	glVertex2f(0.25, -0.5);

	glVertex2f(0.25, -0.5);
	glVertex2f(-0.25, -0.5);

	glVertex2f(-0.25, -0.5);
	glVertex2f(-0.5, 0.2);

	glVertex2f(-0.5, 0.2);
	glVertex2f(0, 0.5);

	glVertex2f(0, 0.5);
	glVertex2f(0, -0.5);

	glVertex2f(-0.5, 0.2);
	glVertex2f(0.5, 0.2);
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutCreateWindow("LAB1_GONZALES");
	glutDisplayFunc(display);
	glutMainLoop();
}
