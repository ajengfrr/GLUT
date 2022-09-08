#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void myInit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
 	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 900.0, 0.0, 400.0);
}
class GLintPoint
{
public:
		GLint x, y;
};
class Point2
{
public:
	float x,y;
	void set(float dx,float dy){
		x = dx;
		y = dy;
	}
	void set(Point2 &p){
		x = p.x;
		y = p.y;
	}
	Point2(float xx,float yy){
		x = xx;
		y = yy;
	}
	Point2(){
		x = y = 0;
	}
};
GLintPoint CP;
float lerp (float a, float b, float t){
	return a + (b - a) *t;
}
Point2 Tween(Point2 A, Point2 B ,float t){
		Point2 P;
		P.x = lerp(A.x,B.x,t);
		P.y = lerp(A.y,B.y,t);
		return P;
	}
void moveTo(GLint x ,GLint y){
	CP.x = x; CP.y = y;
}
void lineTo(GLint x ,GLint y){
	glBegin (GL_LINES);
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glutSwapBuffers();
	CP.x = x; CP.y = y;
}
void drawTween (Point2 A[], Point2 B[], int n, float t){
     for (int i = 0; i < n; i++){
        Point2 P;
        P = Tween (A[i], B[i], t);
        if (i == 0) moveTo (P.x, P.y);
        else lineTo (P.x, P.y);
       }
}
void myDisplay(void){
	int x;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);

	Point2 A[13];
		A [0].set(20,100);
		A [1].set(140,100);
		A [2].set(110,140);
		A [3].set(50,140);
		A [4].set(50,190);
		A [5].set(110,190);
		A [6].set(110,230);
		A [7].set(50,230);
		A [8].set(50,280);
		A [9].set(110,280);
		A [10].set(140,320);
		A [11].set(20,320);
		A [12].set(20,100);

	Point2 B[13];
		B [0].set (660,100);
		B [1].set (690,140);
		B [2].set (750,140);
		B [3].set (750,190);
		B [4].set (690,190);
		B [5].set (690,230);
		B [6].set (750,230);
		B [7].set (750,280);
		B [8].set (690,280);
		B [9].set (660,320);
		B [10].set (780,320);
		B [11].set (780,100);
		B [12].set (660,100);

	glColor3f(1,0,0);
	drawTween(A,B,13,0.0);
	glColor3f(1,1,0);
	drawTween(A,B,13,0.1);
	glColor3f(1,0,1);
	drawTween(A,B,13,0.2);
	glColor3f(0,1,0);
	drawTween(A,B,13,0.3);
	glColor3f(0,1,1);
	drawTween(A,B,13,0.4);
	glColor3f(0,0,1);
	drawTween(A,B,13,0.5);
	glColor3f(1,0.5,0);
	drawTween(A,B,13,0.6);
	glColor3f(1,0,0.5);
	drawTween(A,B,13,0.7);
	glColor3f(0.5,1,0);
	drawTween(A,B,13,0.8);
	glColor3f(0.5,0,1);
	drawTween(A,B,13,0.9);
	glColor3f(1,0,0.5);
	drawTween(A,B,13,1.0);
	glColor3f(0,1,0.5);
	drawTween(A,B,13,1.1);
	glFlush();
	glutSwapBuffers();
}
main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(900,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Eeee..");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
