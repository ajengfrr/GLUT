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

void init(void);
void display(void);

main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Rumah Impianku");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 450, 0, 450);
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //atap
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex2i(100, 375);
    glVertex2i(250, 375);
    glVertex2i(300, 300);
    glVertex2i(150, 300);
    glEnd();
    //segitiga atap
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 375);
    glVertex2i(150, 300);
    glVertex2i(50, 300);
    glEnd();
    //dinding kecil
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 1.0);
    glVertex2i(150, 300);
    glVertex2i(50, 300);
    glVertex2i(50, 100);
    glVertex2i(150, 100);
    glEnd();
    //pintu
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(75, 225);
    glVertex2i(75, 100);
    glVertex2i(125, 100);
    glVertex2i(125, 225);
    glEnd();
    //gagang pintu
    glPointSize(15);
    glBegin(GL_POINTS);
    glColor3f(2.0, 0.5, 1.0);
    glVertex2i(80, 160);
    glEnd();
    //dinding besar
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3);
    glVertex2i(150, 300);
    glVertex2i(150, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 300);
    glEnd();
    //jendela
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.4, 0.3);
    glVertex2i(175, 250);
    glVertex2i(175, 175);
    glVertex2i(275, 175);
    glVertex2i(275, 250);
    glEnd();
    //garis jendela
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.1, 0.7, 0.5);
    glVertex2i(225, 250);
    glVertex2i(225, 175);
    glVertex2i(175, 213);
    glVertex2i(275, 213);
    glEnd();
    //jalan
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(50, 0);
    glVertex2i(75, 100);
    glVertex2i(125, 100);
    glVertex2i(125, 0);
    glEnd();
    //matahari
    glPointSize(110);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2i(300, 425);
    glEnd();
    //rumput
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(310, 100);
    glVertex2i(310, 130);
    glVertex2i(330, 115);
    glVertex2i(350, 130);
    glVertex2i(375, 115);
    glVertex2i(390, 130);
    glVertex2i(390, 100);
    glEnd();
    //corong asap
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.4);
    glVertex2i(180, 375);
    glVertex2i(180, 420);
    glVertex2i(225, 420);
    glVertex2i(225, 375);
    glEnd();
    //batu
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(150, 50);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(200, 75);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(250, 90);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(230, 60);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(170, 40);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(300, 60);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(250, 30);
    glEnd();
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2i(210, 40);
    glEnd();
    glutSwapBuffers();
}

