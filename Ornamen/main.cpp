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
#include<math.h>

void init(void);
void display(void);

main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Ornament Homemade");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
}
void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;
    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    }
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0);
	int segi=8;
    for(int a=150;a>=30;a-=10){
        if(segi%2==0){
            glBegin(GL_POLYGON);
                glColor3f(1.0, 1.0, 0.0);   //yellow
                ngon(segi,0,0,a,60);
            glEnd();
        }
        else{
            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 1.0);   //magenta
                ngon(segi,0,0,a,60);
            glEnd();
        }
        segi++;
    }
    int data[5][4]={{-21,-34},{2,47},{40,-14},{-37,25}};
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    for(int s=0;s<0;s++){
            glVertex2i(data[s][0],data[s][1]);
        }
    int cx=0;
    for(int a=70;a>=20;a-=10){
        if(cx%2==0){
            glBegin(GL_POLYGON);
                glColor3f(0.0, 0.0, 1.0);      //blue
                ngon(6,cx,0,a,60);
            glEnd();
        }
        else{
            glBegin(GL_POLYGON);
                glColor3f(1.0, 1.0, 0.0);   //yellow
                ngon(6,cx,0,a,60);
            glEnd();
        }
        segi--;
    }
    for(int a=50;a>=10;a-=5){
        if(cx%2==0){
            glBegin(GL_POLYGON);
                glColor3f(0.0, 1.0, 1.0);   //cyan
                ngon(6,cx,0,a,60);
            glEnd();
        }
        else{
            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);   //red
                ngon(6,cx,0,a,60);
            glEnd();
        }
        cx++;
    }
	glutSwapBuffers();
}
