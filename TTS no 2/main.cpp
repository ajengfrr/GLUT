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

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>
void init(void);
void display(void);

main(int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First OpenGL Application");
	init(); //memanggil fungsi init
	glutDisplayFunc(display);//memanggil fungsi display
	glutMainLoop(); //untuk menjalankan program
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*glBegin(GL_LINES);
	glVertex3f(-3.0,-5.0,0.0);
	glVertex3f(3.0,-3.0,0.0);
	glVertex3f(3.0,3.0,0.0);
	glEnd();*/
	/*glRectf(-5,2.5,1,-3);
	glRectf(4,5,7,3);*/
	/*glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(-5, 2.5);
    glVertex2i(1, 2.5);
    glVertex2i(1, -3);
    glVertex2i(-5, -3);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(4, 5);
    glVertex2i(7, 5);
    glVertex2i(7, 3);
    glVertex2i(4, 3);
    glEnd();*/
    /*glBegin(GL_LINE_STRIP);
    glVertex2i(2,5);
    glVertex2i(5,5);
    glVertex2i(2,8);
    glEnd();*/
    /*glBegin(GL_LINE_LOOP);
    glVertex2i(2,5);
    glVertex2i(5,5);
    glVertex2i(2,8);
    glEnd();*/
    glBegin(GL_LINE_STRIP);
    glVertex2f()
    glEnd();
	glutSwapBuffers();
}
