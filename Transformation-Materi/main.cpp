/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void myInit(void) {
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}
void myDisplay(void) {
    glColor3f(1.0, 0.0, 0.0);
    glRectf(-10.0, 0.0, 0.10, -10.10);
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(2,-12,0);
    glRectf(-10.0, 0.0, 0.10, -10.10);
    glPopMatrix();
    glFlush();

}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("transformasi");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
