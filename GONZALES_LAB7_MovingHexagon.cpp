#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

void display();
void triangles();
void init();

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 460);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GONZALES - LAB #7");
	glutDisplayFunc(display);
	
	GLenum err = glewInit();
		if(err == GLEW_OK) {
			glutMainLoop();
		}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0,1.0);
	triangles();
	glFlush();
}

void triangles(){
GLfloat trianglevertices[] = {
0.0f, 0.0f, 0.0f,
-0.35f, 0.0f, 0.0f,
-0.2f, -0.3f, 0.0f,

0.0f, 0.0f, 0.0f,
-0.2f, -0.3f, 0.0f,
.2f, -0.3f, 0.0f,

0.0f, 0.0f, 0.0f,
.2f, -0.3f, 0.0f,
0.35f, 0.0f, 0.0f,

0.0f, 0.0f, 0.0f,
0.35f, 0.0f, 0.0f,
0.2f, 0.3f, 0.0f,

0.0f, 0.0f, 0.0f,
0.2f, 0.3f, 0.0f,
-0.2f, 0.3f, 0.0f,

0.0f, 0.0f, 0.0f,
-0.2f, 0.3f, 0.0f,
-0.35f, 0.0f, 0.0f
};

GLubyte indices[] = {
0,1,2,
3,4,5,
6,7,8,
9,10,11,
12,13,14,
15,16,17
};

GLuint VBOid;
glGenBuffers(1, &VBOid);
glBindBuffer(GL_ARRAY_BUFFER, VBOid);
glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*54, trianglevertices, 
GL_STATIC_DRAW);

GLuint VBOindex; 
glGenBuffers(1, &VBOindex);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBOindex);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte)*18, indices, GL_STATIC_DRAW);

glEnableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_NORMAL_ARRAY);

glVertexPointer(3, GL_FLOAT, 0, 0);
glNormalPointer(GL_UNSIGNED_BYTE,0, 0);

glDrawArrays(GL_TRIANGLES,0,18);
glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_BYTE, 0);

glDisableClientState(GL_VERTEX_ARRAY);
glDisableClientState(GL_NORMAL_ARRAY);

glBindBuffer(GL_ARRAY_BUFFER, 0);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
glDeleteBuffers(1, &VBOid);
glDeleteBuffers(1, &VBOindex);
}
