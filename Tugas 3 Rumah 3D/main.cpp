#include <windows.h>
#include<stdlib.h>
#include <gl/glut.h>
void init(void); void ukuran(int,int);
void tampil(void); void hilang(void); void display(void);
void rumahmain(void); void balkon(void); void depan(void); void dasar(void); void objekdalam(void);
void keyboard(unsigned char, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Ajeng Febriana Rahmawati - 672019323");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}
void objekdalam(void){
    //alas teras
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, 10.0);
    glVertex3f(17.0, -10.0, 10.0);
    glVertex3f(17.0, -10.0, 19.0);
    glVertex3f(-11.0, -10.0, 19.0);
    glEnd();
    //step depan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, 19.0);
    glVertex3f(17.0, -10.0, 19.0);
    glVertex3f(17.0, -12.0, 19.0);
    glVertex3f(-11.0, -12.0, 19.0);
    glEnd();
    //step kanan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(17.01, -10.0, 18.9);
    glVertex3f(17.01, -10.0, -28.0);
    glVertex3f(17.01, -12.0, -28.0);
    glVertex3f(17.01, -12.0, 18.9);
    glEnd();
    //step kiri
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.01, -10.0, 18.9);
    glVertex3f(-11.01, -10.0, -28.0);
    glVertex3f(-11.01, -12.0, -28.0);
    glVertex3f(-11.01, -12.0, 18.9);
    glEnd();
    //step belakang
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, -28.1);
    glVertex3f(17.0, -10.0, -28.1);
    glVertex3f(17.0, -12.0, -28.1);
    glVertex3f(-11.0, -12.0, -28.1);
    glEnd();

    //tembok rg tamu
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, 6.0, 10.0);
    glVertex3f(17.0, 6.0, 10.0);
    glVertex3f(17.0, -12.0, 10.0);
    glVertex3f(-11.0, -12.0, 10.0);
    glEnd();
    //pintu rg tamu
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(9.0, 0.0, 10.1);
    glVertex3f(13.0, 0.0, 10.1);
    glVertex3f(13.0, -12.0, 10.1);
    glVertex3f(9.0, -12.0, 10.1);
    glEnd();
    //gagang pintu rg tamu
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(12, -5, 10.2);
    glEnd();

    //sofa
    //pinggir kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 9, 41);
    glVertex3f(-4.0, -4.0, 18.9);
    glColor3ub(0, 19, 87);
    glVertex3f(-4.0, -10.0, 18.9);
    glVertex3f(-8.0, -10.0, 18.9);
    glColor3ub(0, 9, 41);
    glVertex3f(-8.0, -4.0, 18.9);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(0, 5, 23);
    glVertex3f(-8.0, -4.0, 12.0);
    glVertex3f(-8.0, -10.0, 12.0);
    glColor3ub(0, 9, 41);
    glVertex3f(-8.0, -10.0, 18.9);
    glVertex3f(-8.0, -4.0, 18.9);
    glEnd();
    //pinggir kiri
    glBegin(GL_QUADS);
    glColor3ub(0, 5, 23);
    glVertex3f(-8.0, -10.0, 12.0);
    glVertex3f(-8.0, -4.0, 12.0);
    glVertex3f(-4.0, -4.0, 12.0);
    glVertex3f(-4.0, -10.0, 12.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(0, 5, 23);
    glVertex3f(-4.0, -10.0, 12.0);
    glVertex3f(-4.0, -7.0, 12.0);
    glColor3ub(0, 9, 41);
    glVertex3f(-4.0, -7.0, 18.9);
    glVertex3f(-4.0, -10.0, 18.9);
    glEnd();
    //dudukan
    glBegin(GL_QUADS);
    glColor3ub(0, 5, 23);
    glVertex3f(-4.0, -7.0, 12.0);
    glColor3ub(88, 117, 224);
    glVertex3f(-7.0, -7.0, 12.0);
    glVertex3f(-7.0, -7.0, 18.9);
    glColor3ub(0, 5, 23);
    glVertex3f(-4.0, -7.0, 18.9);
    glEnd();
    //senderan
    glBegin(GL_QUADS);
    glColor3ub(88, 117, 224);
    glVertex3f(-7.0, -7.0, 12.0);
    glColor3ub(0, 5, 23);
    glVertex3f(-8.0, -2.0, 12.0);
    glVertex3f(-8.0, -2.0, 18.9);
    glColor3ub(88, 117, 224);
    glVertex3f(-7.0, -7.0, 18.9);
    glEnd();
    //s3penutup kanan
    glBegin(GL_POLYGON);
    glColor3ub(88, 117, 224);
    glVertex3f(-7.0, -7.0, 18.8);
    glVertex3f(-8.0, -2.0, 18.8);
    glVertex3f(-8.0, -7.0, 18.8);
    glEnd();

    //meja
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(151, 89, 74);
    glVertex3f(3.0, -6.0, 12.1);
    glVertex3f(-2.0, -6.0, 12.1);
    glVertex3f(-2.0, -10.0, 12.1);
    glVertex3f(3.0, -10.0, 12.1);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(151, 89, 74);
    glVertex3f(3.0, -6.0, 17.6);
    glVertex3f(-2.0, -6.0, 17.6);
    glColor3ub(95, 63, 52);
    glVertex3f(-2.0, -10.0, 17.6);
    glVertex3f(3.0, -10.0, 17.6);
    glEnd();
    //samping kiri
    glBegin(GL_QUADS);
    glColor3ub(151, 89, 74);
    glVertex3f(-2.0, -6.0, 12.5);
    glVertex3f(-2.0, -10.0, 12.5);
    glColor3ub(95, 63, 52);
    glVertex3f(-2.0, -10.0, 17.6);
    glVertex3f(-2.0, -6.0, 17.6);
    glEnd();
    //samping kanan
    glBegin(GL_QUADS);
    glColor3ub(151, 89, 74);
    glVertex3f(3.0, -6.0, 12.5);
    glVertex3f(3.0, -10.0, 12.5);
    glColor3ub(95, 63, 52);
    glVertex3f(3.0, -10.0, 17.6);
    glVertex3f(3.0, -6.0, 17.6);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(220, 191, 184);
    glVertex3f(3.0, -6.0, 12.0);
    glColor3ub(234, 220, 215);
    glVertex3f(-2.0, -6.0, 12.0);
    glVertex3f(-2.0, -6.0, 18.1);
    glColor3ub(181, 135, 119);
    glVertex3f(3.0, -6.0, 18.1);
    glEnd();

    //pigura
    glBegin(GL_QUADS);
    glColor3ub(315, 24, 4);
    glVertex3f(-1.0, 1.0, 10.2);
    glColor3ub(111, 210, 12);
    glVertex3f(5.0, 1.0, 10.2);
    glColor3ub(548, 12, 122);
    glVertex3f(5.0, -4.0, 10.2);
    glColor3ub(212, 475, 42);
    glVertex3f(-1.0, -4.0, 10.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 236, 134);
    glVertex3f(-2.0, 2.0, 10.1);
    glVertex3f(6.0, 2.0, 10.1);
    glVertex3f(6.0, -5.0, 10.1);
    glVertex3f(-2.0, -5.0, 10.1);
    glEnd();
}
void depan(void){
    //tembok depan
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, 6.0, 19.0);
    glVertex3f(17.0, 6.0, 19.0);
    glVertex3f(17.0, -12.0, 19.0);
    glVertex3f(-11.0, -12.0, 19.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(6.0, 0.0, 19.1);
    glVertex3f(10.0, 0.0, 19.1);
    glVertex3f(10.0, -10.0, 19.1);
    glVertex3f(6.0, -10.0, 19.1);
    glEnd();
    //gagang pintu depan
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(9, -4.5, 19.2);
    glEnd();
    //jendela kanan
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(10.0, 0.0, 19.1);
    glVertex3f(14.0, 0.0, 19.1);
    glVertex3f(14.0, -5.0, 19.1);
    glVertex3f(10.0, -5.0, 19.1);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glVertex3f(10.0, 0.0, 19.2);
    glVertex3f(14.0, 0.0, 19.2);
    glVertex3f(14.0, -5.0, 19.2);
    glVertex3f(10.0, -5.0, 19.2);
    glVertex3f(12.0, 0.0, 19.2);
    glVertex3f(12.0, -5.0, 19.2);
    glVertex3f(12.0, -1.0, 19.2);
    glVertex3f(14.0, -1.0, 19.2);
    glVertex3f(12.0, -2.0, 19.2);
    glVertex3f(14.0, -2.0, 19.2);
    glVertex3f(12.0, -3.0, 19.2);
    glVertex3f(14.0, -3.0, 19.2);
    glVertex3f(12.0, -4.0, 19.2);
    glVertex3f(14.0, -4.0, 19.2);
    glEnd();
    //jendela kiri
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(1.0, 0.0, 19.1);
    glVertex3f(-5.0, 0.0, 19.1);
    glVertex3f(-5.0, -5.0, 19.1);
    glVertex3f(1.0, -5.0, 19.1);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(1.0, 0.0, 19.2);
    glVertex3f(-5.0, 0.0, 19.2);
    glVertex3f(-5.0, -5.0, 19.2);
    glVertex3f(1.0, -5.0, 19.2);
    glVertex3f(-3.0, 0.0, 19.2);
    glVertex3f(-3.0, -5.0, 19.2);
    glVertex3f(-1.0, 0.0, 19.2);
    glVertex3f(-1.0, -5.0, 19.2);
    glVertex3f(1.0, -1.0, 19.2);
    glVertex3f(-1.0, -1.0, 19.2);
    glVertex3f(1.0, -2.0, 19.2);
    glVertex3f(-1.0, -2.0, 19.2);
    glVertex3f(1.0, -3.0, 19.2);
    glVertex3f(-1.0, -3.0, 19.2);
    glVertex3f(1.0, -4.0, 19.2);
    glVertex3f(-1.0, -4.0, 19.2);
    glVertex3f(-3.0, -1.0, 19.2);
    glVertex3f(-5.0, -1.0, 19.2);
    glVertex3f(-3.0, -2.0, 19.2);
    glVertex3f(-5.0, -2.0, 19.2);
    glVertex3f(-3.0, -3.0, 19.2);
    glVertex3f(-5.0, -3.0, 19.2);
    glVertex3f(-3.0, -4.0, 19.2);
    glVertex3f(-5.0, -4.0, 19.2);
    glEnd();
}
void rumahmain(void){
    //genteng kanan
    glBegin(GL_QUADS);
    glColor3ub(97, 70, 32);
    glVertex3f(2.8, 15.2, 21.0);
    glVertex3f(18.0, 5.5, 21.0);
    glColor3ub(51, 39, 15);
    glVertex3f(18.0, 5.5, -30.0);
    glVertex3f(2.8, 15.2, -30.0);
    glEnd();
    //genteng kiri
    glBegin(GL_QUADS);
    glColor3ub(97, 70, 32);
    glVertex3f(2.8, 15.2, 21.0);
    glVertex3f(-12.0, 5.5, 21.0);
    glColor3ub(51, 39, 15);
    glVertex3f(-12.0, 5.5, -30.0);
    glVertex3f(2.8, 15.2, -30.0);
    glEnd();
    //atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-10.9, 6.0, 20.0);
    glVertex3f(16.9, 6.0, 20.0);
    glVertex3f(16.9, 6.0, -28.0);
    glVertex3f(-10.9, 6.0, -28.0);
    glEnd();
    //segitiga atap depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex3f(-11.0, 6.0, 20.0);
    glVertex3f(3.0, 15.0, 20.0);
    glVertex3f(17.0, 6.0, 20.0);
    glEnd();
    //segitiga atap belakang
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex3f(-11.0, 6.0, -28.0);
    glVertex3f(3.0, 15.0, -28.0);
    glVertex3f(17.0, 6.0, -28.0);
    glEnd();

    //tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, 6.0, -28.0);
    glVertex3f(-11.0, 6.0, 19.0);
    glVertex3f(-11.0, -12.0, 19.0);
    glVertex3f(-11.0, -12.0, -28.0);
    glEnd();
    //jendela tembok kiri 1
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(-11.1, 0.0, 12.0);
    glVertex3f(-11.1, 0.0, 16.0);
    glVertex3f(-11.1, -5.0, 16.0);
    glVertex3f(-11.1, -5.0, 12.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-11.1, 0.0, 12.0);
    glVertex3f(-11.1, 0.0, 16.0);
    glVertex3f(-11.1, -5.0, 16.0);
    glVertex3f(-11.1, -5.0, 12.0);
    glVertex3f(-11.1, -1.0, 16.0);
    glVertex3f(-11.1, -1.0, 12.0);
    glVertex3f(-11.1, -2.0, 16.0);
    glVertex3f(-11.1, -2.0, 12.0);
    glVertex3f(-11.1, -3.0, 16.0);
    glVertex3f(-11.1, -3.0, 12.0);
    glVertex3f(-11.1, -4.0, 16.0);
    glVertex3f(-11.1, -4.0, 12.0);
    glEnd();
    //jendela tembok kiri 2
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(-11.1, 0.0, 4.0);
    glVertex3f(-11.1, 0.0, 8.0);
    glVertex3f(-11.1, -5.0, 8.0);
    glVertex3f(-11.1, -5.0, 4.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-11.1, 0.0, 4.0);
    glVertex3f(-11.1, 0.0, 8.0);
    glVertex3f(-11.1, -5.0, 8.0);
    glVertex3f(-11.1, -5.0, 4.0);
    glVertex3f(-11.1, -1.0, 4.0);
    glVertex3f(-11.1, -1.0, 8.0);
    glVertex3f(-11.1, -2.0, 4.0);
    glVertex3f(-11.1, -2.0, 8.0);
    glVertex3f(-11.1, -3.0, 4.0);
    glVertex3f(-11.1, -3.0, 8.0);
    glVertex3f(-11.1, -4.0, 4.0);
    glVertex3f(-11.1, -4.0, 8.0);
    glEnd();
    //jendela tembok kiri 3
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(-11.1, 0.0, 0.0);
    glVertex3f(-11.1, 0.0, -4.0);
    glVertex3f(-11.1, -5.0, -4.0);
    glVertex3f(-11.1, -5.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-11.1, 0.0, 0.0);
    glVertex3f(-11.1, 0.0, -4.0);
    glVertex3f(-11.1, -5.0, -4.0);
    glVertex3f(-11.1, -5.0, 0.0);
    glVertex3f(-11.1, -1.0, -4.0);
    glVertex3f(-11.1, -1.0, 0.0);
    glVertex3f(-11.1, -2.0, -4.0);
    glVertex3f(-11.1, -2.0, 0.0);
    glVertex3f(-11.1, -3.0, -4.0);
    glVertex3f(-11.1, -3.0, 0.0);
    glVertex3f(-11.1, -4.0, -4.0);
    glVertex3f(-11.1, -4.0, 0.0);
    glEnd();
    //jendela tembok kiri 4
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(-11.1, 0.0, -8.0);
    glVertex3f(-11.1, 0.0, -12.0);
    glVertex3f(-11.1, -5.0, -12.0);
    glVertex3f(-11.1, -5.0, -8.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-11.1, 0.0, -8.0);
    glVertex3f(-11.1, 0.0, -12.0);
    glVertex3f(-11.1, -5.0, -12.0);
    glVertex3f(-11.1, -5.0, -8.0);
    glVertex3f(-11.1, -1.0, -12.0);
    glVertex3f(-11.1, -1.0, -8.0);
    glVertex3f(-11.1, -2.0, -12.0);
    glVertex3f(-11.1, -2.0, -8.0);
    glVertex3f(-11.1, -3.0, -12.0);
    glVertex3f(-11.1, -3.0, -8.0);
    glVertex3f(-11.1, -4.0, -12.0);
    glVertex3f(-11.1, -4.0, -8.0);
    glEnd();
    //tembok kanan
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(17.0, 6.0, -28.0);
    glVertex3f(17.0, 6.0, 19.0);
    glVertex3f(17.0, -12.0, 19.0);
    glVertex3f(17.0, -12.0, -28.0);
    //jendela kanan 1
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(17.1, 0.0, 12.0);
    glVertex3f(17.1, 0.0, 16.0);
    glVertex3f(17.1, -5.0, 16.0);
    glVertex3f(17.1, -5.0, 12.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(17.1, 0.0, 12.0);
    glVertex3f(17.1, 0.0, 16.0);
    glVertex3f(17.1, -5.0, 16.0);
    glVertex3f(17.1, -5.0, 12.0);
    glVertex3f(17.1, -1.0, 12.0);
    glVertex3f(17.1, -1.0, 16.0);
    glVertex3f(17.1, -2.0, 12.0);
    glVertex3f(17.1, -2.0, 16.0);
    glVertex3f(17.1, -3.0, 12.0);
    glVertex3f(17.1, -3.0, 16.0);
    glVertex3f(17.1, -4.0, 12.0);
    glVertex3f(17.1, -4.0, 16.0);
    glEnd();
    //jendela kanan 2
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3f(17.1, 0.0, 5.0);
    glVertex3f(17.1, 0.0, 9.0);
    glVertex3f(17.1, -5.0, 9.0);
    glVertex3f(17.1, -5.0, 5.0);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0, 0, 0);
    glVertex3f(17.1, 0.0, 5.0);
    glVertex3f(17.1, 0.0, 9.0);
    glVertex3f(17.1, -5.0, 9.0);
    glVertex3f(17.1, -5.0, 5.0);
    glVertex3f(17.1, -1.0, 5.0);
    glVertex3f(17.1, -1.0, 9.0);
    glVertex3f(17.1, -2.0, 5.0);
    glVertex3f(17.1, -2.0, 9.0);
    glVertex3f(17.1, -3.0, 5.0);
    glVertex3f(17.1, -3.0, 9.0);
    glVertex3f(17.1, -4.0, 5.0);
    glVertex3f(17.1, -4.0, 9.0);
    glEnd();
    //pintu kanan 1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(17.1, 0.0, 3.0);
    glVertex3f(17.1, 0.0, -1.0);
    glVertex3f(17.1, -10.0, -1.0);
    glVertex3f(17.1, -10.0, 3.0);
    glEnd();
    //gagang pintu kanan 1
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(17.2, -5, 0.0);
    glEnd();
    //pintu kanan 2
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(17.1, 0.0, -20.0);
    glVertex3f(17.1, 0.0, -16.0);
    glVertex3f(17.1, -10.0, -16.0);
    glVertex3f(17.1, -10.0, -20.0);
    glEnd();
    //gagang pintu kanan 2
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(17.2, -5, -19.0);
    glEnd();
    //tembok belakang
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, 6.0, -28.0);
    glVertex3f(17.0, 6.0, -28.0);
    glVertex3f(17.0, -12.0, -28.0);
    glVertex3f(-11.0, -12.0, -28.0);
    glEnd();

    //pintu belakang
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(9.0, 0.0, -28.1);
    glVertex3f(13.0, 0.0, -28.1);
    glVertex3f(13.0, -10.0, -28.1);
    glVertex3f(9.0, -10.0, -28.1);
    glEnd();
    //gagang pintu belakang
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3ub(192, 192, 192);
    glVertex3f(10, -5, -28.2);
    glEnd();
}
void teras(void){
    //alas teras
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, 19.0);
    glVertex3f(17.0, -10.0, 19.0);
    glVertex3f(17.0, -10.0, 30.0);
    glVertex3f(-11.0, -10.0, 30.0);
    glEnd();
    //step depan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, 30.0);
    glVertex3f(17.0, -10.0, 30.0);
    glVertex3f(17.0, -12.0, 30.0);
    glVertex3f(-11.0, -12.0, 30.0);
    glEnd();
    //step kanan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(17.0, -10.0, 30.0);
    glVertex3f(17.0, -10.0, 19.0);
    glVertex3f(17.0, -12.0, 19.0);
    glVertex3f(17.0, -12.0, 30.0);
    glEnd();
    //step kiri
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, -10.0, 30.0);
    glVertex3f(-11.0, -10.0, 19.0);
    glVertex3f(-11.0, -12.0, 19.0);
    glVertex3f(-11.0, -12.0, 30.0);
    glEnd();

    //buk depan
    //step atas buk panjang
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, -5.0, 28.0);
    glVertex3f(10.0, -5.0, 28.0);
    glVertex3f(10.0, -5.0, 30.0);
    glVertex3f(-11.0, -5.0, 30.0);
    glEnd();
    //step atas buk kanan
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(15.0, -5.0, 19.0);
    glVertex3f(17.0, -5.0, 19.0);
    glVertex3f(17.0, -5.0, 30.0);
    glVertex3f(15.0, -5.0, 30.0);
    glEnd();
    //step atas buk kiri
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, -5.0, 19.0);
    glVertex3f(-9.0, -5.0, 19.0);
    glVertex3f(-9.0, -5.0, 30.0);
    glVertex3f(-11.0, -5.0, 30.0);
    glEnd();
    //step depan
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, -5.0, 30.0);
    glVertex3f(10.0, -5.0, 30.0);
    glVertex3f(10.0, -10.0, 30.0);
    glVertex3f(-11.0, -10.0, 30.0);
    glEnd();
    //step depan buk kecil
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(15.0, -5.0, 30.0);
    glVertex3f(17.0, -5.0, 30.0);
    glVertex3f(17.0, -10.0, 30.0);
    glVertex3f(15.0, -10.0, 30.0);
    glEnd();
    //step kanan
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(17.0, -5.0, 30.0);
    glVertex3f(17.0, -5.0, 19.0);
    glVertex3f(17.0, -10.0, 19.0);
    glVertex3f(17.0, -10.0, 30.0);
    glEnd();
    //step kanan buk panjang
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(10.0, -5.0, 30.0);
    glVertex3f(10.0, -5.0, 28.0);
    glVertex3f(10.0, -10.0, 28.0);
    glVertex3f(10.0, -10.0, 30.0);
    glEnd();
    //step kanan buk kiri
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-9.0, -5.0, 30.0);
    glVertex3f(-9.0, -5.0, 19.0);
    glVertex3f(-9.0, -10.0, 19.0);
    glVertex3f(-9.0, -10.0, 30.0);
    glEnd();
    //step kiri
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(-11.0, -5.0, 30.0);
    glVertex3f(-11.0, -5.0, 19.0);
    glVertex3f(-11.0, -10.0, 19.0);
    glVertex3f(-11.0, -10.0, 30.0);
    glEnd();
    //step kiri buk kecil
    glBegin(GL_QUADS);
    glColor3ub(30, 234, 188);
    glVertex3f(15.0, -5.0, 30.0);
    glVertex3f(15.0, -5.0, 19.0);
    glVertex3f(15.0, -10.0, 19.0);
    glVertex3f(15.0, -10.0, 30.0);
    glEnd();

    //buk depan
    //step atas buk panjang
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(-9.0, -5.0, 28.1);
    glVertex3f(10.0, -5.0, 28.1);
    glVertex3f(10.0, -5.0, 30.1);
    glVertex3f(-9.0, -5.0, 30.1);
    glEnd();
    //step atas buk kanan
    glBegin(GL_LINES);
    glLineWidth(3.0);
    glColor3ub(0,0,0);
    glVertex3f(15.0, -5.0, 19.1);
    glVertex3f(17.0, -5.0, 19.1);
    glVertex3f(17.0, -5.0, 30.1);
    glVertex3f(15.0, -5.0, 30.1);
    glEnd();
    //step atas buk kiri
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(-11.0, -5.0, 19.1);
    glVertex3f(-9.0, -5.0, 19.1);
    glVertex3f(-9.0, -5.0, 30.1);
    glVertex3f(-11.0, -5.0, 30.1);
    glEnd();
    //step depan
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(10.0);
    glVertex3f(-11.0, -5.0, 30.1);
    glVertex3f(10.0, -5.0, 30.1);
    glVertex3f(10.0, -10.0, 30.1);
    glVertex3f(-11.0, -10.0, 30.1);
    glEnd();
    //step depan buk kecil
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(15.0, -5.0, 30.1);
    glVertex3f(17.0, -5.0, 30.1);
    glVertex3f(17.0, -10.0, 30.1);
    glVertex3f(15.0, -10.0, 30.1);
    glEnd();
    //step kanan
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(17.0, -5.0, 30.1);
    glVertex3f(17.0, -5.0, 19.1);
    glVertex3f(17.0, -10.0, 19.1);
    glVertex3f(17.0, -10.0, 30.1);
    glEnd();
    //step kanan buk panjang
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex3f(10.0, -5.0, 30.0);
    glVertex3f(10.0, -5.0, 28.0);
    glVertex3f(10.0, -10.0, 28.0);
    glVertex3f(10.0, -10.0, 30.0);
    glEnd();
    //step kanan buk kiri
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(-9.0, -5.0, 30.1);
    glVertex3f(-9.0, -5.0, 19.1);
    glVertex3f(-9.0, -10.0, 19.1);
    glVertex3f(-9.0, -10.0, 30.1);
    glEnd();
    //step kiri
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(-11.0, -5.0, 30.1);
    glVertex3f(-11.0, -5.0, 19.1);
    glVertex3f(-11.0, -10.0, 19.1);
    glVertex3f(-11.0, -10.0, 30.1);
    glEnd();
    //step kiri buk kecil
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glVertex3f(15.0, -5.0, 30.1);
    glVertex3f(15.0, -5.0, 19.1);
    glVertex3f(15.0, -10.0, 19.1);
    glVertex3f(15.0, -10.0, 30.1);
    glEnd();
    //alas atap
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, 6.0, 19.0);
    glVertex3f(17.0, 6.0, 19.0);
    glVertex3f(17.0, 6.0, 30.0);
    glVertex3f(-11.0, 6.0, 30.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, 4.0, 19.0);
    glVertex3f(17.0, 4.0, 19.0);
    glVertex3f(17.0, 4.0, 30.0);
    glVertex3f(-11.0, 4.0, 30.0);
    glEnd();
    //step depan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, 4.0, 30.0);
    glVertex3f(17.0, 4.0, 30.0);
    glVertex3f(17.0, 6.0, 30.0);
    glVertex3f(-11.0, 6.0, 30.0);
    glEnd();
    //step kanan
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(17.0, 4.0, 30.0);
    glVertex3f(17.0, 4.0, 19.0);
    glVertex3f(17.0, 6.0, 19.0);
    glVertex3f(17.0, 6.0, 30.0);
    glEnd();
    //step kiri
    glBegin(GL_QUADS);
    glColor3ub(95, 95, 95);
    glVertex3f(-11.0, 4.0, 30.0);
    glVertex3f(-11.0, 4.0, 19.0);
    glVertex3f(-11.0, 6.0, 19.0);
    glVertex3f(-11.0, 6.0, 30.0);
    glEnd();

    //segitiga atap
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex3f(-11.0, 6.0, 20.0);
    glVertex3f(3.0, 15.0, 20.0);
    glVertex3f(17.0, 6.0, 20.0);
    glEnd();

    //depan tiang kiri1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-1.5, -5.0, 29.0);
    glVertex3f(-1.5, 6.0, 29.0);
    glVertex3f(-0.5, 6.0, 29.0);
    glVertex3f(-0.5, -5.0, 29.0);
    glEnd();
    //kanan tiang kiri1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-0.5, -5.0, 29.0);
    glVertex3f(-0.5, 6.0, 29.0);
    glVertex3f(-0.5, 6.0, 28.0);
    glVertex3f(-0.5, -5.0, 28.0);
    glEnd();
    //belakang tiang kiri1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-1.5, -5.0, 28.0);
    glVertex3f(-1.5, 6.0, 28.0);
    glVertex3f(-0.5, 6.0, 28.0);
    glVertex3f(-0.5, -5.0, 28.0);
    glEnd();
    //kiri tiang kiri1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-1.5, -5.0, 28.0);
    glVertex3f(-1.5, 6.0, 28.0);
    glVertex3f(-1.5, 6.0, 29.0);
    glVertex3f(-1.5, -5.0, 29.0);
    glEnd();

    //depan tiang kiri
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-10.5, -5.0, 29.0);
    glVertex3f(-10.5, 6.0, 29.0);
    glVertex3f(-9.5, 6.0, 29.0);
    glVertex3f(-9.5, -5.0, 29.0);
    glEnd();
    //kanan tiang kiri
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-9.5, -5.0, 29.0);
    glVertex3f(-9.5, 6.0, 29.0);
    glVertex3f(-9.5, 6.0, 28.0);
    glVertex3f(-9.5, -5.0, 28.0);
    glEnd();
    //belakang tiang kiri
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-10.5, -5.0, 28.0);
    glVertex3f(-10.5, 6.0, 28.0);
    glVertex3f(-9.5, 6.0, 28.0);
    glVertex3f(-9.5, -5.0, 28.0);
    glEnd();
    //kiri tiang kiri
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(-10.5, -5.0, 28.0);
    glVertex3f(-10.5, 6.0, 28.0);
    glVertex3f(-10.5, 6.0, 29.0);
    glVertex3f(-10.5, -5.0, 29.0);
    glEnd();

    //depan tiang kanan1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(7.5, -5.0, 29.0);
    glVertex3f(7.5, 6.0, 29.0);
    glVertex3f(6.5, 6.0, 29.0);
    glVertex3f(6.5, -5.0, 29.0);
    glEnd();
    //kanan tiang kanan1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(6.5, -5.0, 29.0);
    glVertex3f(6.5, 6.0, 29.0);
    glVertex3f(6.5, 6.0, 28.0);
    glVertex3f(6.5, -5.0, 28.0);
    glEnd();
    //belakang tiang kanan1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(7.5, -5.0, 28.0);
    glVertex3f(7.5, 6.0, 28.0);
    glVertex3f(7.5, 6.0, 28.0);
    glVertex3f(7.5, -5.0, 28.0);
    glEnd();
    //kiri tiang kanan1
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(7.5, -5.0, 28.0);
    glVertex3f(7.5, 6.0, 28.0);
    glVertex3f(7.5, 6.0, 29.0);
    glVertex3f(7.5, -5.0, 29.0);
    glEnd();

    //depan tiang kanan
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(16.5, -5.0, 29.0);
    glVertex3f(16.5, 6.0, 29.0);
    glVertex3f(15.5, 6.0, 29.0);
    glVertex3f(15.5, -5.0, 29.0);
    glEnd();
    //kanan tiang kanan
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(15.5, -5.0, 29.0);
    glVertex3f(15.5, 6.0, 29.0);
    glVertex3f(15.5, 6.0, 28.0);
    glVertex3f(15.5, -5.0, 28.0);
    glEnd();
    //belakang tiang kanan
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(16.5, -5.0, 28.0);
    glVertex3f(16.5, 6.0, 28.0);
    glVertex3f(16.5, 6.0, 28.0);
    glVertex3f(16.5, -5.0, 28.0);
    glEnd();
    //kiri tiang kanan
    glBegin(GL_QUADS);
    glColor3ub(74, 0, 0);
    glVertex3f(16.5, -5.0, 28.0);
    glVertex3f(16.5, 6.0, 28.0);
    glVertex3f(16.5, 6.0, 29.0);
    glVertex3f(16.5, -5.0, 29.0);
    glEnd();
}
void dasar(void){
    glBegin(GL_QUADS);
    glColor3ub(98, 232, 77);
    glVertex3f(-18.0, -12.0, 35.0);
    glVertex3f(26.0, -12.0, 35.0);
    glVertex3f(26.0, -12.0, -35.0);
    glVertex3f(-18.0, -12.0, -35.0);
    glEnd();
}
void hilang(void){
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    rumahmain();
    dasar();
    objekdalam();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    rumahmain();
    depan();
    teras();
    dasar();
    objekdalam();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void display(void){
    if (is_depth)
        tampil();
    else
        hilang();
}
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case'w':
        case'W':
            glTranslatef(0.0, 0.0, 3.0);
            break;
        case'd':
        case'D':
            glTranslatef(-3.0, 0.0, 0.0);
            break;
        case's':
        case'S':
            glTranslatef(0.0, 0.0, -3.0);
            break;
        case'a':
        case'A':
            glTranslatef(3.0, 0.0, 0.0);
            break;
        case'7':
            glTranslatef(0.0, 3.0, 0.0);
            break;
        case'9':
            glTranslatef(0.0, -3.0, 0.0);
            break;
        case'2':
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case'8':
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case'6':
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case'4':
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        case'1':
            glRotatef(2.0, 0.0, 0.0, 1.0);
            break;
        case'3':
            glRotatef(-2.0, 0.0, 0.0, 1.0);
            break;
        case'5':
            if(is_depth){
                is_depth = 0;
                tampil();
            }
            else{
                is_depth = 1;
                hilang();
            }
            break;
    }
    display();
}
void idle(){
    if (!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown=false;
}
void putar(){
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y){
    putar();
    if (mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void ukuran(int lebar, int tinggi){
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
    glTranslatef(-3.5, -15.0, -100.0);
    glMatrixMode(GL_MODELVIEW);
}
