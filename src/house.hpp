#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define COS_30 cos(30 * M_PI / 180)
#define SIN_30 sin(30 * M_PI / 180)
#define COS_60 cos(60 * M_PI / 180)
#define SIN_60 cos(60 * M_PI / 180)

void reshape(int w, int h);
void display(void);
void my_init(int w, int h);
void test(void);
