#include "house.h"

void reshape(int w, int h) {

    if (w == 0)
        w = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -10, 10);

    glMatrixMode(GL_MODELVIEW);
}

void display(void) {

    // glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float twice_pi = 2 * M_PI;

    // Edge bewtween house's right side and its front
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(800.0f * COS_30, 380.0f * SIN_30, 0.0f);
        glVertex3f(800.0f * COS_30, 670.0f * SIN_30, 0.0f);
    glEnd();

    // Windows' inner delimiters
    glBegin(GL_LINES);
        glVertex3f(900.0f * COS_30, 520.0f * SIN_30, 0.0f);
        glVertex3f(900.0f * COS_30, 630.0f * SIN_30, 0.0f);
        glVertex3f(1100.0f * COS_30, 585.0f * SIN_30, 0.0f);
        glVertex3f(1100.0f * COS_30, 695.0f * SIN_30, 0.0f);
    glEnd();

    // Windows' contours
    glBegin(GL_LINE_LOOP);
        glVertex3f(850.0f * COS_30, 505.0f * SIN_30, 0.0f);
        glVertex3f(950.0f * COS_30, 535.0f * SIN_30, 0.0f);
        glVertex3f(950.0f * COS_30, 645.0f * SIN_30, 0.0f);
        glVertex3f(850.0f * COS_30, 615.0f * SIN_30, 0.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex3f(1050.0f * COS_30, 570.0f * SIN_30, 0.0f);
        glVertex3f(1150.0f * COS_30, 600.0f * SIN_30, 0.0f);
        glVertex3f(1150.0f * COS_30, 710.0f * SIN_30, 0.0f);
        glVertex3f(1050.0f * COS_30, 680.0f * SIN_30, 0.0f);
    glEnd();

    // Rectangular windows
    glBegin(GL_QUADS);
        glColor3f(0.439216f, 0.858824f, 0.8f);
        glVertex3f(850.0f * COS_30, 505.0f * SIN_30, 0.0f);
        glVertex3f(950.0f * COS_30, 535.0f * SIN_30, 0.0f);
        glVertex3f(950.0f * COS_30, 645.0f * SIN_30, 0.0f);
        glVertex3f(850.0f * COS_30, 615.0f * SIN_30, 0.0f);

        glVertex3f(1050.0f * COS_30, 570.0f * SIN_30, 0.0f);
        glVertex3f(1150.0f * COS_30, 600.0f * SIN_30, 0.0f);
        glVertex3f(1150.0f * COS_30, 710.0f * SIN_30, 0.0f);
        glVertex3f(1050.0f * COS_30, 680.0f * SIN_30, 0.0f);
    glEnd();

    // Radius and roundness level of the door knob
    float r = 4;
    int roundness = 16;

    glBegin(GL_TRIANGLE_FAN);
        // Door knob center
        glVertex3f(540.0f, 270.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        for (int i = 0; i <= roundness; i++)
            glVertex3f(540.0f + r * cos(i * twice_pi / roundness), 270.0f + r * sin(i * twice_pi / roundness), 0.0f);
    glEnd();

    // Front door
    glBegin(GL_QUADS);
        glColor3f(0.197059f, 0.164706f, 0.164706f);
        glVertex3f(610.0f * COS_30, 455.0f * SIN_30, 0.0f);
        glVertex3f(610.0f * COS_30, 655.0f * SIN_30, 0.0f);
        glColor3f(0.247059f, 0.164706f, 0.164706f);
        glVertex3f(660.0f * COS_30, 635.0f * SIN_30, 0.0f);
        glVertex3f(660.0f * COS_30, 435.0f * SIN_30, 0.0f);
    glEnd();

    // House's roof
    glBegin(GL_POLYGON);

        // Left side
        glColor3f(0.197059f, 0.164706f, 0.164706f);
        glVertex3f(1100.0f * COS_60, 1000.0f * SIN_60, 0.0f);
        glVertex3f(855.0f * COS_60, 790.0f * SIN_60, 0.0f);
        glVertex3f(845.0f * COS_60, 800.0f * SIN_60, 0.0f);
        glVertex3f(1100.0f * COS_60, 1020.0f * SIN_60, 0.0f);

        // Right side (lighter)
        glColor3f(0.347059f, 0.164706f, 0.164706f);
        glVertex3f(1780.0f * COS_60, 1110.0f * SIN_60, 0.0f);
        glVertex3f(1210.0f * COS_30, 770.0f * SIN_30, 0.0f);
        glVertex3f(810.0f * COS_30, 650.0f * SIN_30, 0.0f);
    glEnd();

    // Chimney attempt
    glBegin(GL_POLYGON);
        glColor3f(0.197059f, 0.164706f, 0.164706f);
        glVertex3f(950.0f * COS_60, 880.0f * SIN_60, 0.0f);
        glVertex3f(950.0f * COS_60, 1000.0f * SIN_60, 0.0f);
        glVertex3f(1000.0f * COS_60, 1050.0f * SIN_60, 0.0f);
        glVertex3f(1000.0f * COS_60, 930.0f * SIN_60, 0.0f);
    glEnd();

    // Radius and roundness level of the circular front window
    r = 25;
    roundness = 50;

    glBegin(GL_TRIANGLE_FAN);
        // Circular window center
        glVertex3f(550.0f, 420.0f, 0.0f);
        glColor3f(0.5f, 0.0f, 1.0f);
        for (int i = 0; i <= roundness; i++)
            glVertex3f(550.0f + r * cos(i * twice_pi / roundness), 420.0f + r * sin(i * twice_pi / roundness), 0.0f);
    glEnd();

    // Right side and front of the house
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(800.0f  * COS_30, 380.0f  * SIN_30, 0.0f);
        glVertex3f(1190.0f * COS_30, 500.0f * SIN_30, 0.0f);
        glVertex3f(1190.0f * COS_30, 800.0f * SIN_30, 0.0f);
        glVertex3f(800.0f * COS_30, 680.0f * SIN_30, 0.0f);

        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(1100.0f * COS_60, 1000.0f * SIN_60, 0.0f);
        glVertex3f(865.0f * COS_60, 800.0f * SIN_60, 0.0f);
        glVertex3f(500.0f * COS_30, 500.0f * SIN_30, 0.0f);
    glEnd();

    glutSwapBuffers();
}

void my_init(int w, int h) {

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -10, 10);

    glMatrixMode(GL_MODELVIEW);
}
