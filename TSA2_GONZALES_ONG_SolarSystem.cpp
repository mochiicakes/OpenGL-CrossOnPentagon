/* Technical Summative # 2
   SOLAR SYSTEM by:
   Michaella Gonzales
   Maria Evangelicalyn Ong
 */

#define GLEW_STATIC

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Constants for planet orbits and rotation
const float MercuryOrbitRadius = 7.0f;
const float VenusOrbitRadius = 10.0f;
const float EarthOrbitRadius = 20.0f;
const float MarsOrbitRadius = 30.0f;
const float JupiterOrbitRadius = 35.0f;
const float SaturnOrbitRadius = 40.0f;
const float UranusOrbitRadius = 45.5f;
const float NeptuneOrbitRadius = 50.0f;

const float MercuryRotationSpeed = 0.1f;
const float VenusRotationSpeed = 0.075f;
const float EarthRotationSpeed = 0.05f;
const float MarsRotationSpeed = 0.04f;
const float JupiterRotationSpeed = 0.025f;
const float SaturnRotationSpeed = 0.02f;
const float UranusRotationSpeed = 0.015f;
const float NeptuneRotationSpeed = 0.01f;
const int TimerInterval = 100;

// Global variables for rotation angles
float mercuryAngle = 120.0f;
float venusAngle = 44.0f;
float earthAngle = 102.0f;
float marsAngle = 30.0f;
float jupiterAngle = 500.0f;
float saturnAngle = 780.0f;
float uranusAngle = 200.0f;
float neptuneAngle = 360.0f;

float sunScale = 1.0f; // Scale factor for the sun

float object1Position = 0.0f; // Initial position of object 1
bool object1Moving = false;   // Indicates if object 1 is currently moving

GLuint vbo; // Vertex Buffer Object ID

void moveObject(int value)
{
    if (object1Moving)
    {
        // Update object 1 position
        object1Position += 0.1f; // Adjust the translation speed as needed

        // Wrap object 1 position within a certain range if desired
        if (object1Position > 10.0f)
        {
            object1Position = -10.0f; // Reset the position
        }

        // Translate object 1 along the x-axis
        glTranslatef(object1Position, 0.0f, 0.0f);

        // Redraw the scene
        glutPostRedisplay();

        // Restart the timer
        glutTimerFunc(TimerInterval, moveObject, 150);
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Rotate the Earth by 45 degrees on left mouse button click
        earthAngle += 45.0f;
    }
    else if (button == 3)
    {
        // Scroll up, increase the sun's scale factor
        sunScale += 0.1f;
    }
    else if (button == 4)
    {
        // Scroll down, decrease the sun's scale factor
        sunScale *= 0.9f;
    }

    // Redraw the scene
    glutPostRedisplay();
}




void drawPlanet(float orbitRadius, float& rotationAngle, float planetRadius, float red, float green, float blue)
{
    glPushMatrix();
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(orbitRadius, 0.0f, 0.0f);

    glColor3f(red, green, blue);
    glutSolidSphere(planetRadius, 20, 20);

    glPopMatrix();

    // Randomize the rotation angle for the next frame
    rotationAngle += static_cast<float>(rand() % 10) / 100.0f; // Adjust the randomization range as desired
}

void drawOrbit(float orbitRadius)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 0.3f);
    for (int i = 0; i < 360; ++i)
    {
        float angle = static_cast<float>(i) * 3.14159f / 180.0f;
        float x = orbitRadius * cos(angle);
        float z = -orbitRadius * sin(angle);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
}

void createVBO()
{
    // Vertex data
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f, // Vertex 1
        1.0f, -1.0f, 0.0f,  // Vertex 2
        0.0f, 1.0f, 0.0f    // Vertex 3
    };

    // Generate and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Set the data of the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void drawTriangle()
{
    // Enable vertex array
    glEnableClientState(GL_VERTEX_ARRAY);

    // Set the pointer to the vertex data
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Disable vertex array
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawSolarSystem()
{
    // Draw stars
    glPointSize(2.5f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 500; ++i)
    {
        float x = static_cast<float>(rand() % 200) - 50.0f;
        float y = static_cast<float>(rand() % 200) - 75.0f;
        float z = static_cast<float>(rand() % 200) - 50.0f;

        float intensity = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        glColor3f(intensity, 100, 255);
        glVertex3f(x, y, -z);
    }
    glEnd();

    // Draw the sun
    glColor3f(1.0f, 0.875f, 0.0f);
    glutSolidSphere(5.0f, 20, 20);

    // Draw the orbits of each planet
    drawOrbit(MercuryOrbitRadius);
    drawOrbit(VenusOrbitRadius);
    drawOrbit(EarthOrbitRadius);
    drawOrbit(MarsOrbitRadius);
    drawOrbit(JupiterOrbitRadius);
    drawOrbit(SaturnOrbitRadius);
    drawOrbit(UranusOrbitRadius);
    drawOrbit(NeptuneOrbitRadius);
    
    // Draw the planets
    // Draw the planets with randomized positions
    drawPlanet(MercuryOrbitRadius, mercuryAngle, 1.0f, 1.0f, 0.651f, 0.0f);
    drawPlanet(VenusOrbitRadius, venusAngle, 1.5f, 1.0f, 0.569f, 0.306f);
    drawPlanet(EarthOrbitRadius, earthAngle, 2.0f, 1.0f, 0.518f, 0.518f);
    drawPlanet(MarsOrbitRadius, marsAngle, 1.8f, 1.0f, 0.525f, 0.71f);
    drawPlanet(JupiterOrbitRadius, jupiterAngle, 4.0f, 1.0f, 0.58f, 0.875f);
    drawPlanet(SaturnOrbitRadius, saturnAngle, 3.5f, 0.882f, 0.647f, 0.98f);
    drawPlanet(UranusOrbitRadius, uranusAngle, 2.5f, 0.706f, 0.706f, 1.0f);
    drawPlanet(NeptuneOrbitRadius, neptuneAngle, 2.3f, 0.561f, 0.749f, 1.0f);


    
    // Draw the sun with the adjusted scale factor
        glPushMatrix();
        glScalef(sunScale, sunScale, sunScale);
        glColor3f(1.0f, 0.875f, 0.0f);
        glutSolidSphere(5.0f, 20, 20);
        glPopMatrix();

    // Update rotation angles
    mercuryAngle += MercuryRotationSpeed;
    venusAngle += VenusRotationSpeed;
    earthAngle += EarthRotationSpeed;
    marsAngle += MarsRotationSpeed;
    jupiterAngle += JupiterRotationSpeed;
    saturnAngle += SaturnRotationSpeed;
    uranusAngle += UranusRotationSpeed;
    neptuneAngle += NeptuneRotationSpeed;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0f, 90.0f, 0.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 0.0f, -5.0f);

    drawSolarSystem();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<float>(width) / static_cast<float>(height), 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')
    {
        object1Moving = !object1Moving; // Toggle the object 1 movement
        if (object1Moving)
        {
            // Start the timer for moving the object
            glutTimerFunc(TimerInterval, moveObject, 0);
        }
    }
    else if (key == 27)
    {
        // Exit the program when 'q' or 'Q' is pressed
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Solar System: GONZALES and ONG");
    
    glutFullScreen(); // Set the window to full screen

    glewExperimental = GL_TRUE; // Enable GLEW experimental features
    GLenum glewInitResult = glewInit();
    if (glewInitResult != GLEW_OK) {
        std::cerr << "GLEW initialization error: " << glewGetErrorString(glewInitResult) << std::endl;
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
        // Remove the idle function as it will no longer be used
        // glutIdleFunc(moveObject);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutKeyboardFunc(keyboard);

        glutMainLoop();


    return 0;
}
