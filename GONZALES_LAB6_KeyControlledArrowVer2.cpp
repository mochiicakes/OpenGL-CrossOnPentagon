#include <GL/glut.h>
#include <GL/freeglut_ext.h>
using namespace std;

// Initial Colors of Both Triangle
int lr = 255, lg = 255, lb = 255;
int rr = 255, rg = 255, rb = 255;
float shapePosX = 0.0f;
float shapePosY = 0.0f;

// Returns random number between 0 and 255
int randomNumberGenerator(){
	return rand() % 256;
}

// Triangle 1
GLfloat triangle1Vertices[] = {
	-1.0f, 0.0f,
	-0.6f, 0.4f,
	-0.6f, -0.4f
};

// Triangle 2
GLfloat triangle2Vertices[] = {
	1.0f, 0.0f,
	0.6f, 0.4f,
	0.6f, -0.4f
};

// Rectangle
GLfloat rectangleVertices[] = {
	-0.6f, -0.2f,
	-0.6f, 0.2f,
	0.6f, 0.2f,
	0.6f, -0.2f
};

void displayShape(){
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(shapePosX, shapePosY, 0.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	
	// Triangle 1
	glColor3ub(lr, lg, lb);
	glVertexPointer(2, GL_FLOAT, 0, triangle1Vertices);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Triangle 2
	glColor3ub(rr, rg, rb);
	glVertexPointer(2, GL_FLOAT, 0, triangle2Vertices);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Rectangle
	glColor3ub(255, 255, 255);
	glVertexPointer(2, GL_FLOAT, 0, rectangleVertices);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);

	glFlush();
}

void mouseMonitor(int button, int state, int x, int y){
	// Generates random number for each color value
	int tempColor[3];
	
	for(int i = 0; i < 3; i++){
		tempColor[i] = randomNumberGenerator();
	}
	
	// Checks the mouse state
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		// Changes Color
		lr = tempColor[0];
		lg = tempColor[1];
		lb = tempColor[2];
	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		// Changes Color
		rr = tempColor[0];
		rg = tempColor[1];
		rb = tempColor[2];
	}
	
	glutPostRedisplay();
}

void keyboardMonitor(unsigned char key, int x, int y){
	switch (key) {
        case 27:
            exit(0);
            break;
        case 'w ':
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

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(2000, 1000);
	glutCreateWindow("LAB #6_GONZALES");
	glutDisplayFunc(displayShape);
	glutMouseFunc(mouseMonitor);
	glutKeyboardFunc(keyboardMonitor);
	glutMainLoop();
	return 0;
}
