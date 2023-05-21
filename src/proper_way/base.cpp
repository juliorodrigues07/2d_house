#include "base.hpp"

GLfloat windowWidth;
GLfloat windowHeight;

void drawSquare() {

    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

void drawTriangle() {

    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

void drawCircle() {

    glBegin(GL_POLYGON);
        for (int i = 0; i < 30; i++)
            glVertex2f(cos(i), sin(i));
    glEnd();
}

void skewX(GLfloat rads) {

    GLfloat angle = rads * M_PI / 180;
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };

    glMultMatrixf(m);
}

void skewY(GLfloat rads) {

    GLfloat angle = rads * M_PI / 180;
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0, 
        0, 0, 0, 1
    };

    glMultMatrixf(m);
}

void draw(void) {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    // Aqui entra seu código da casa 2D.
    //Vocês só pode usar as funções de desenho:
        // desenhaQuadrado, desenhaTriangulo, desenhaCirculo
    // as transformações geométricas:
        // glTranslatef, glRotatef, glScalef, skewX, skewY
    // e as funções de cor:
        // glColor3f
    // Não desenhe nenhuma primitiva utilizando glBegin/glEnd diretamente aqui.

    // Front of the house (with shadow)
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
        glTranslatef(175, 100, 0);
        glScalef(100, 50, 1);
        skewY(-30);
        drawSquare();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(176, 158, 0);
        skewX(-20);
        glRotatef(-18, 0, 0, 1);
        glScalef(100, 75, 1);
        drawTriangle();
    glPopMatrix();

    // Side of the house (lighter)
    glColor3f(1.0f, 1.0f, 1.0f);
        glPushMatrix();
        glTranslatef(300, 100, 0);
        glScalef(150, 50, 1);
        skewY(30);
        drawSquare();
    glPopMatrix();

    // Left portion of the roof (with shadow)
    glColor3f(0.197059f, 0.164706f, 0.164706f);
    glPushMatrix();
        glTranslatef(149, 168, 0);
        glRotatef(48, 0, 0, 1);
        glScalef(80, 3, 1);
        drawSquare();
    glPopMatrix();

    // Right portion of the roof (lighter)
    glColor3f(0.347059f, 0.164706f, 0.164706f);
    glPushMatrix();
        glTranslatef(279, 169, 0);
        skewX(-20);
        glRotatef(10, 0, 0, 1);
        glScalef(180, 90, 1);
        drawSquare();
    glPopMatrix();

    glutSwapBuffers();
}

void myInit (void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void changeWindowSize(GLsizei w, GLsizei h) {

    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
    	windowHeight = 250.0f * h / w;
		windowWidth = 250.0f;
    } else {
		windowWidth = 250.0f * w / h;
		windowHeight = 250.0f;
    }

    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
