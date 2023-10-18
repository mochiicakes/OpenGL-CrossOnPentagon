#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <random>
using namespace std;

void displayShape();
void mouseMonitor(int button, int state, int x, int y);
void keyboardMonitor(unsigned char, int x, int y);
void specialKeyMonitor(int key, int x, int y);

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<unsigned int> distribution(0, 255);
unsigned int r1 = 255, g1 = 255, b1 = 255;
unsigned int r2 = 255, g2 = 255, b2 = 255;
float shapePosX = 0.0f;
float shapePosY = 0.0f;


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("LAB #5_GONZALES");
	glutDisplayFunc(displayShape);
	glutMouseFunc(mouseMonitor);
	glutKeyboardFunc(keyboardMonitor);
	glutSpecialFunc(specialKeyMonitor);
	glutMainLoop();
	return 0;
}

void displayShape(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(shapePosX, shapePosY, 0.0f);
	
	glBegin(GL_TRIANGLES); // left triangle
	glColor3ub(r1, g1, b1);
	glVertex2f(-1.0f, 0);
	glVertex2f(-0.6f, 0.4f);
	glVertex2f(-0.6f, -0.4f);
	glEnd();
	
	glBegin(GL_TRIANGLES); // right triangle
	glColor3ub(r2, g2, b2);
	glVertex2f(1.0f, 0);
	glVertex2f(0.6f, 0.4f);
	glVertex2f(0.6f, -0.4f);
	glEnd();
	
	glBegin(GL_QUADS); // rectangle
	glColor3ub(255,255,255);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(-0.6f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.6f, -0.2f);
	glEnd();
	
	glFlush();
}

void mouseMonitor(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		r1 = distribution(generator);
		g1 = distribution(generator);
		b1 = distribution(generator);
	} else if (button == GLUT_RIGHT_BUTTON){
		r2 = distribution(generator);
		g2 = distribution(generator);
		b2 = distribution(generator);
	}
	
	glutPostRedisplay();
}

void keyboardMonitor(unsigned char key, int x, int y){
	switch (key) {
        case 27: // ASCII value of ESC key is 27
            exit(0); // Exit the program
            break;
        case 'w':
        	shapePosY += 0.1f;
        	break;
        case 'a':
        	shapePosX -= 0.1f;
        	break;
        case 's':
        	shapePosY -= 0.1f;
        	break;
        case 'd':
        	shapePosX += 0.1f;
        	break;
    }
    
    glutPostRedisplay();
}

void specialKeyMonitor(int key, int x, int y){
	switch (key) {
        case GLUT_KEY_UP:
        	shapePosY += 0.1f;
        	break;
        case GLUT_KEY_DOWN:
        	shapePosY -= 0.1f;
        	break;
        case GLUT_KEY_RIGHT:
        	shapePosX += 0.1f;
        	break;
		case GLUT_KEY_LEFT:
        	shapePosX -= 0.1f;
        	break;
               
    }
    
    glutPostRedisplay();
}

