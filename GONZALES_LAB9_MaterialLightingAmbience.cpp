#include <GL/glut.h>
#include <cmath>

// Window size
int width = 800;
int height = 600;

// Camera position
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 5.0f;

// Rotation angles
float angleX = 0.0f;
float angleY = 0.0f;

// Zoom factor
float zoom = 1.0f;

// Pan offsets
float panX = 0.0f;
float panY = 0.0f;

void init()
{
    // Set the clear color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Enable depth testing for 3D rendering
    glEnable(GL_DEPTH_TEST);

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Set ambient light color to black
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // Enable color material
    glEnable(GL_COLOR_MATERIAL);
}

void drawIcosahedron()
{
    // Define the vertices of an icosahedron
    static const GLfloat X = 0.525731112119133606;
    static const GLfloat Z = 0.850650808352039932;

    static const GLfloat vertices[][3] =
    {
        {-X, 0.0f, Z}, {X, 0.0f, Z}, {-X, 0.0f, -Z}, {X, 0.0f, -Z},
        {0.0f, Z, X}, {0.0f, Z, -X}, {0.0f, -Z, X}, {0.0f, -Z, -X},
        {Z, X, 0.0f}, {-Z, X, 0.0f}, {Z, -X, 0.0f}, {-Z, -X, 0.0f}
    };

    // Define the faces of the icosahedron
    static const GLuint faces[][3] =
    {
        {1, 4, 0}, {4, 9, 0}, {4, 5, 9}, {8, 5, 4}, {1, 8, 4},
        {1, 10, 8}, {10, 3, 8}, {8, 3, 5}, {3, 2, 5}, {3, 7, 2},
        {3, 10, 7}, {10, 6, 7}, {6, 11, 7}, {6, 0, 11}, {6, 1, 0},
        {10, 1, 6}, {11, 0, 9}, {2, 11, 9}, {5, 2, 9}, {11, 2, 7}
    };

    // Draw the icosahedron with rainbow colors
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 20; ++i)
    {
        glColor3f(0.6f, 0.2f, 0.9f);
        for (int j = 0; j < 3; ++j)
        {
            glNormal3fv(vertices[faces[i][j]]);
            glVertex3fv(vertices[faces[i][j]]);
        }
    }
    glEnd();
}

void display()
{
    // Clear the color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the camera position and orientation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Apply zoom and pan transformations
    glTranslatef(panX, panY, 0.0f);
    glScalef(zoom, zoom, zoom);

    // Enable lighting
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    // Set up the first spotlight
    GLfloat lightPos0[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightDir0[] = {-1.0f, -1.0f, -1.0f};
    GLfloat lightColor0[] = {1.0f, 0.843f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDir0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0f);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0f);

    // Set up the second spotlight
    GLfloat lightPos1[] = {-1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightDir1[] = {1.0f, -1.0f, -1.0f};
    GLfloat lightColor1[] = {1.0f, 0.843f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDir1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0f);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0f);

    // Set up the third spotlight
    GLfloat lightPos2[] = {0.0f, -1.0f, 1.0f, 1.0f};
    GLfloat lightDir2[] = {0.0f, 1.0f, -1.0f};
    GLfloat lightColor2[] = {1.0f, 0.843f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightDir2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightColor2);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0f);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0f);

    // Draw the icosahedron
    glPushMatrix();
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    drawIcosahedron();
    glPopMatrix();

    // Swap the buffers
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    // Set the viewport size
    glViewport(0, 0, w, h);

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<float>(w) / static_cast<float>(h), 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w': // Pan up
        panY += 0.1f;
        break;
    case 's': // Pan down
        panY -= 0.1f;
        break;
    case 'a': // Pan left
        panX -= 0.1f;
        break;
    case 'd': // Pan right
        panX += 0.1f;
        break;
    case 'q': // Zoom in
        zoom += 0.1f;
        break;
    case 'e': // Zoom out
        zoom -= 0.1f;
        if (zoom < 0.1f)
            zoom = 0.1f;
        break;
    }
    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP: // Rotate camera up
        angleX -= 5.0f;
        break;
    case GLUT_KEY_DOWN: // Rotate camera down
        angleX += 5.0f;
        break;
    case GLUT_KEY_LEFT: // Rotate camera left
        angleY -= 5.0f;
        break;
    case GLUT_KEY_RIGHT: // Rotate camera right
        angleY += 5.0f;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("LAB9-GONZALES");

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);

    // Initialize OpenGL settings
    init();

    // Start the main loop
    glutMainLoop();

    return 0;
}

