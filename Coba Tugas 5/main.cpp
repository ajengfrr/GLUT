#include <windows.h>
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>

void init(void);
void display(void);
void display1(void);
void display2(void);
main(int argc, char *argv[]){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(-10,10);
	glutCreateWindow("LINES");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
}
void display(void){
    //garis AB
    float ax=2,ay=3,bx=1,by=5;
    //garis CD
    float cx=3,cy=3,dx=1,dy=1;
    float m1,c1,m2,c2,px1,py1;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
    glVertex2f(ax,ay);
    glVertex2f(bx,by);
    glColor3f(0,1,0);
    glVertex2f(cx,cy);
    glVertex2f(dx,dy);
	glEnd();
	//menentukan persamaan garis
	//AB
	m1=(by-ay)/(bx-ax);
	c1=ay-(m1*ax);
	//CD
    m2=(dy-cy)/(dx-cx);
    c2=cy-(m2*cx);
    //menentukan titik potong atas
    px1=(c2-c1)/(m1-m2);
    py1=(m1*px1)+c1;
    printf("%f,%f\n",px1,py1);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(px1,py1);
    glEnd();
	glutSwapBuffers();
}
