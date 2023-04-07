#include "house.hpp"

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D House");
    glutDisplayFunc(display);

    my_init(1280, 720);

    // glutFullScreen();
    glutMainLoop();
    return 0;
}
