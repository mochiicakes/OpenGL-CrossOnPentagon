#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

void display();
void triangle();
void init();
void specialInput(int key, int x, int y);

bool triangleUpdate = false;
GLfloat *mappedVertices = NULL;
float px = 0, py = 0;
GLuint VBOid;
	
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("GONZALES - LAB#8");
    glutDisplayFunc(display);
	glutSpecialFunc(specialInput);
    
    GLenum err = glewInit();
    if (err == GLEW_OK) {
        glutMainLoop();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2f(px,py);
    triangle();
    glFlush();
}

void triangle() {
	if(!triangleUpdate) {
	    GLfloat trianglevertices[] = {
	        -0.5f, 0.0f,
	        -0.2f, -0.3f,
	        0.0f, 0.0f,
	
	        -0.2f, -0.3f,
	        0.2f, -0.3f,
	        0.0f, 0.0f,
	
	        0.5f, 0.0f,
	        0.2f, -0.3f,
	        0.0f, 0.0f,
	
	        0.5f, 0.0f,
	        0.2f, 0.3f,
	        0.0f, 0.0f,
	
	        -0.2f, 0.3f,
	        0.2f, 0.3f,
	        0.0f, 0.0f,
	
	        -0.5f, 0.0f,
	        -0.2f, 0.3f,
	        0.0f, 0.0f
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
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*36, trianglevertices, GL_STATIC_DRAW);
		
		GLuint VBOindex; 
		glGenBuffers(1, &VBOindex);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBOindex);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte)*18, indices, GL_STATIC_DRAW);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		
		glVertexPointer(2, GL_FLOAT, 0, 0);
		glColorPointer(3, GL_UNSIGNED_BYTE,7,0);
		
		glDrawArrays(GL_TRIANGLES,0,18);
	}
	else{
		glVertexPointer(2, GL_FLOAT, 0, 0);
		glColorPointer(3, GL_UNSIGNED_BYTE,7,0);
		
		glDrawArrays(GL_TRIANGLES,0,18);
    }
}

void specialInput(int key, int x, int y){
	triangleUpdate = true;
	mappedVertices = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
	switch(key){
		case GLUT_KEY_LEFT:
			px = mappedVertices[0] -= .01f;
			px = mappedVertices[2] -= .01f;
			px = mappedVertices[4] -= .01f;
			px = mappedVertices[6] -= .01f;
			px = mappedVertices[8] -= .01f;
			px = mappedVertices[10] -= .01f;
			px = mappedVertices[12] -= .01f;
			px = mappedVertices[14] -= .01f;
			px = mappedVertices[16] -= .01f;
			px = mappedVertices[18] -= .01f;
			px = mappedVertices[20] -= .01f;
			px = mappedVertices[22] -= .01f;
			px = mappedVertices[24] -= .01f;
			px = mappedVertices[26] -= .01f;
			px = mappedVertices[28] -= .01f;
			px = mappedVertices[30] -= .01f;
			px = mappedVertices[32] -= .01f;
			px = mappedVertices[34] -= .01f;
			px = mappedVertices[36] -= .01f;
			break;
		case GLUT_KEY_RIGHT:
			px = mappedVertices[0] += .01f;
			px = mappedVertices[2] += .01f;
			px = mappedVertices[4] += .01f;
			px = mappedVertices[6] += .01f;
			px = mappedVertices[8] += .01f;
			px = mappedVertices[10] += .01f;
			px = mappedVertices[12] += .01f;
			px = mappedVertices[14] += .01f;
			px = mappedVertices[16] += .01f;
			px = mappedVertices[18] += .01f;
			px = mappedVertices[20] += .01f;
			px = mappedVertices[22] += .01f;
			px = mappedVertices[24] += .01f;
			px = mappedVertices[26] += .01f;
			px = mappedVertices[28] += .01f;
			px = mappedVertices[30] += .01f;
			px = mappedVertices[32] += .01f;
			px = mappedVertices[34] += .01f;
			px = mappedVertices[36] += .01f;
			break;
		case GLUT_KEY_UP:
			py = mappedVertices[1] += .01f;
			py = mappedVertices[3] += .01f;
			py = mappedVertices[5] += .01f;
			py = mappedVertices[7] += .01f;
			py = mappedVertices[9] += .01f;
			py = mappedVertices[11] += .01f;
			py = mappedVertices[13] += .01f;
			py = mappedVertices[15] += .01f;
			py = mappedVertices[17] += .01f;
			py = mappedVertices[19] += .01f;
			py = mappedVertices[21] += .01f;
			py = mappedVertices[23] += .01f;
			py = mappedVertices[25] += .01f;
			py = mappedVertices[27] += .01f;
			py = mappedVertices[29] += .01f;
			py = mappedVertices[31] += .01f;
			py = mappedVertices[33] += .01f;
			py = mappedVertices[35] += .01f;
			py = mappedVertices[37] += .01f;
			break;
		case GLUT_KEY_DOWN:
			py = mappedVertices[1] -= .01f;
			py = mappedVertices[3] -= .01f;
			py = mappedVertices[5] -= .01f;
			py = mappedVertices[7] -= .01f;
			py = mappedVertices[9] -= .01f;
			py = mappedVertices[11] -= .01f;
			py = mappedVertices[13] -= .01f;
			py = mappedVertices[15] -= .01f;
			py = mappedVertices[17] -= .01f;
			py = mappedVertices[19] -= .01f;
			py = mappedVertices[21] -= .01f;
			py = mappedVertices[23] -= .01f;
			py = mappedVertices[25] -= .01f;
			py = mappedVertices[27] -= .01f;
			py = mappedVertices[29] -= .01f;
			py = mappedVertices[31] -= .01f;
			py = mappedVertices[33] -= .01f;
			py = mappedVertices[35] -= .01f;
			py = mappedVertices[37] -= .01f;
			break;
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glutPostRedisplay();
}
