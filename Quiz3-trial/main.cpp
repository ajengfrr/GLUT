#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void display(void);
int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Quiz3-Transformasi");
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
void init(void){
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
void display(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3b(0,0,0);
   glBegin(GL_LINES);
   glVertex2d(10,20);
   glVertex2d(50,70);
   glVertex2d(13,20);
   glVertex2d(15,80);
   glVertex2d(29,90);
   glEnd();
   /*
   glBegin(GL_QUADS);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2f(-10, 0);
      glVertex2f(0, 0);
      glVertex2f(0, 10);
      glVertex2f(-10, 10);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2f(-8, -1);
      glVertex2f(2, -1);
      glVertex2f(2, -11);
      glVertex2f(-8, -11);
      glColor3f(0.2, 0.2, 0.2);
      glVertex2f(-11, -14);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(-5, -14);
      glColor3f(0.2, 0.2, 0.2);
      glVertex2f(-5, -8);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(-11, -8);
   glEnd();
   glBegin(GL_TRIANGLES);
      glColor3f(0.0, 0.0, 1.0);
      glVertex2f(7, -9);
      glVertex2f(18, -9);
      glVertex2f(13, -1);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2f(11, -6);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2f(22, -6);
      glColor3f(0.0, 0.0, 1.0);
      glVertex2f(17, -13);
   glEnd();
   glBegin(GL_POLYGON);
      glColor3f(1.0, 1.0, 0.0);
      glVertex2f(15, 8);
      glVertex2f(13, 8);
      glVertex2f(11, 5);
      glVertex2f(13, 2);
      glVertex2f(15, 2);
      glVertex2f(17, 5);*/
   glEnd();
   glFlush();
}
