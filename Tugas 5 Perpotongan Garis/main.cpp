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
    float ax=1,ay=7,bx=-5,by=-3;
    //garis CD
    float cx=-1,cy=7,dx=5,dy=-3;
    //garis EF
    float ex=-4,ey=1,fx=4,fy=1;
    float m1,c1,m2,c2,m3,c3,px1,py1,px2,py2,px3,py3;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
    glVertex2f(ax,ay);
    glVertex2f(bx,by);
    glColor3f(0,1,0);
    glVertex2f(cx,cy);
    glVertex2f(dx,dy);
    glColor3f(0,0,1);
    glVertex2f(ex,ey);
    glVertex2f(fx,fy);
	glEnd();
	//menentukan persamaan garis
	//AB
	m1=(by-ay)/(bx-ax);
	c1=ay-(m1*ax);
	//CD
    m2=(dy-cy)/(dx-cx);
    c2=cy-(m2*cx);
    //EF
    m3=(fy-ey)/(fx-ex);
    c3=ey-(m3*ex);
    //menentukan titik potong atas
    px1=(c2-c1)/(m1-m2);
    py1=(m1*px1)+c1;
    //menentukan titik potong kanan
    px2=(c3-c2)/(m2-m3);
    py2=(m2*px2)+c2;
    //menentukan titik potong kiri
    px3=(c3-c1)/(m1-m3);
    py3=(m3*px3)+c3;
    printf("Titik potong garis ABCD (%.3f,%.3f)\n",px1,py1);
    printf("Titik potong garis CDEF (%.3f,%.3f)\n",px2,py2);
    printf("Titik potong garis ABEF (%.3f,%.3f)\n",px3,py3);
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(px1,py1);
    glColor3f(0,1,0);
    glVertex2f(px2,py2);
    glColor3f(0,0,1);
    glVertex2f(px3,py3);
    glEnd();
	glutSwapBuffers();
}
