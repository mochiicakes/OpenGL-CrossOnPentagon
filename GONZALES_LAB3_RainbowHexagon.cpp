#include <iostream>
#include <GL/glut.h>
using namespace std;

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	
	glColor3ub(255,105,97); //red
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0, 0.5);
	glVertex2f(0.4, 0.5);
	glEnd();
	glFlush();
	
	glColor3ub(255,180,128); //orange
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0.4, 0.5);
	glVertex2f(0.7,0);
	glEnd();
	glFlush();
	
	glColor3ub(248,243,141); //yellow
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0.7,0);
	glVertex2f(0.4, -0.5);
	glEnd();
	glFlush();
	
	glColor3ub(66,214,164); //green
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0.4, -0.5);
	glVertex2f(0,-0.5);
	glEnd();
	glFlush();
	
	glColor3ub(8,202,209); //bluegreen
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(-0.4, -0.5);
	glVertex2f(0,-0.5);
	glEnd();
	glFlush();
	
	glColor3ub(89, 173, 246); //blue
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(-0.7,0);
	glVertex2f(-0.4, -0.5);
	glEnd();
	glFlush();
	
	glColor3ub(157,148,255); //violet
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(-0.7,0);
	glVertex2f(-0.4, 0.5);
	glEnd();
	glFlush();
	
	glColor3ub(199,128,232); //pink
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(-0.4,0.5);
	glVertex2f(0, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutCreateWindow("Lab3");
	glutDisplayFunc(display);
	glutMainLoop();
}

