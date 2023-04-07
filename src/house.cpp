#include "house.hpp"

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

    // Division
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(800.0f  * COS_30, 380.0f  * SIN_30, 0.0f);
        glVertex3f(800.0f * COS_30, 680.0f * SIN_30, 0.0f);
    glEnd();

    // Right side of the house
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(800.0f  * COS_30, 380.0f  * SIN_30, 0.0f);
        glVertex3f(1200.0f * COS_30, 500.0f * SIN_30, 0.0f);
        glVertex3f(1200.0f * COS_30, 800.0f * SIN_30, 0.0f);
        glVertex3f(800.0f  * COS_30, 680.0f  * SIN_30, 0.0f);
    glEnd();

    // Front of the house (shaded)
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(800.0f  * COS_30, 680.0f  * SIN_30, 0.0f);
        glVertex3f(500.0f  * COS_30, 800.0f  * SIN_30, 0.0f);
        glVertex3f(500.0f  * COS_30, 500.0f  * SIN_30, 0.0f);
        glVertex3f(800.0f  * COS_30, 380.0f  * SIN_30, 0.0f);
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
