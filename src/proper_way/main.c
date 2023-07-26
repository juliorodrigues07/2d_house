#include "base.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D House");
    glutDisplayFunc(draw);

    glutReshapeFunc(changeWindowSize);
    myInit();

    glutMainLoop();
    return 0;
}
