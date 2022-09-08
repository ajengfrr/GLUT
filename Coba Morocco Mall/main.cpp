#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <vector>
#include <cmath>

void init(void);
void tampil(void);
void ukuran(int, int);
void ornamen_pagar(int cx);

// mouse
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

// keyboard
void keyboard(unsigned char, int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(250,80);
    glutCreateWindow("MOROCCO MALL");
    init();

    // transparan
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(62/255.f,185/255.f,255/255.f,1.0);
    glMatrixMode(GL_PROJECTION);

    // lighting
    // glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
    is_depth=1;

    glMatrixMode(GL_MODELVIEW);

    glPointSize(9.0);
    glLineWidth(6.0f);
}

void eskalator(float aDasar, float bDasar,float tinggiDasar,float aTegak,float bTegak,
               float tinggiTegak,float aMashok,float bMashok,int aCover,
               int bCover,int yCover,float z1, float z2)
{
    //ESKALATOR
    //PERULANGAN TANGGA ALAS

    while(aDasar>=-190 && tinggiDasar<=-10){
        glBegin(GL_QUADS);
        glColor3f(127/255.f,127/255.f,127/255.f);
        glVertex3f(aDasar,tinggiDasar,z1);
        glVertex3f(aDasar,tinggiDasar,z2);
        glVertex3f(bDasar,tinggiDasar,z2);
        glVertex3f(bDasar,tinggiDasar,z1);
        glEnd();
        aDasar-=5;
        bDasar-=5;
        tinggiDasar+=5;
    }

    //PERULANGAN TANGGA TEGAK/KOTAK
    while(aTegak<=-150 && aTegak>=-190){
        glBegin(GL_QUADS);
        glColor3f(89/255.f,89/255.f,89/255.f);
        glVertex3f(aTegak,tinggiTegak,z1);
        glVertex3f(bTegak,tinggiTegak,z1);
        glVertex3f(bTegak,tinggiTegak+5,z1);
        glVertex3f(aTegak,tinggiTegak+5,z1);
        glEnd();
        aTegak-=5;
        bTegak-=5;
        tinggiTegak+=5;
    }

    //PERULANGAN TANGGA TEGAK/KOTAK
    while(aTegak<=-150 && aTegak>=-190){
        glBegin(GL_QUADS);
        glColor3f(89/255.f,89/255.f,89/255.f);
        glVertex3f(aTegak,tinggiTegak,z2);
        glVertex3f(bTegak,tinggiTegak,z2);
        glVertex3f(bTegak,tinggiTegak+5,z2);
        glVertex3f(aTegak,tinggiTegak+5,z2);
        glEnd();
        aTegak-=5;
        bTegak-=5;
        tinggiTegak+=5;
    }

    //PERULANGAN TANGGA MASHOK
    while(aMashok>=-190 && bMashok<-10){
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aMashok,bMashok,z1);
        glVertex3f(aMashok,bMashok,z2);
        glVertex3f(aMashok,bMashok+5,z2);
        glVertex3f(aMashok,bMashok+5,z1);
        glEnd();
        aMashok-=5;
        bMashok+=5;
    }

    //COVER TANGGA DEPAN
    while(aCover>=-190 && yCover<-10){
       glBegin(GL_QUADS);
        glColor3f(89/255.f,89/255.f,89/255.f);
        glVertex3f(aCover,-50,z1);
        glVertex3f(bCover,-50,z1);
        glVertex3f(bCover,yCover,z1);
        glVertex3f(aCover,yCover,z1);
        glEnd();
        aCover-=5;
        bCover-=5;
        yCover+=5;
    }

    //COVER TANGGA BELAKANG
    while(aCover>=-190 && yCover<-10){
       glBegin(GL_QUADS);
        glColor3f(89/255.f,89/255.f,89/255.f);
        glVertex3f(aCover,-50,z2);
        glVertex3f(bCover,-50,z2);
        glVertex3f(bCover,yCover,z2);
        glVertex3f(aCover,yCover,z2);
        glEnd();
        aCover-=5;
        bCover-=5;
        yCover+=5;
    }
}

void lingkaran(float x, float y,float z,float r){
    float theta;
    for(int i = 0; i < 360; i++){
            theta = i* 3.14285714/180;
            glVertex3f(x+r*cos(theta), y+r*sin(theta),z);
        }
}
void awan(float x1,float x2, float y1, float y2, float z){
    float batas = x1+20;
    for(float i = x1; i<=batas;i+=10){
        glPushMatrix();
            glColor3f(1.0,1.0,1.0);
            glTranslated(i,y1,z);
            glutSolidSphere(10,20,20);
        glPopMatrix();
    }
    glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslated(x2,y2,z);
        glutSolidSphere(10,20,20);
    glPopMatrix();
}
void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // mouse
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex3f(-350, -50, -140);
        glVertex3f(350, -50, -140);
        glVertex3f(350, -50, 100);
        glVertex3f(-350, -50, 100);
    glEnd();
/*
    // dinding pele
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, 40);
        glVertex3f(-200, -50, 55);
        glVertex3f(-200, 70, 55);
        glVertex3f(-280, 70, 40);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-180, -50, 55);
        glVertex3f(-50, -50, 55);
        glVertex3f(-50, 70, 55);
        glVertex3f(-180, 70, 55);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, 40);
        glVertex3f(-280, -50, -60);
        glVertex3f(-280, 70, -60);
        glVertex3f(-280, 70, 40);
    glEnd();


    //dinding deva
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(120, -50, 50);
        glVertex3f(220, -50, 25);
        glVertex3f(220, 70, 25);
        glVertex3f(120, 70, 50);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-30, -50, 55);
        glVertex3f(120, -50, 50);
        glVertex3f(120, 70, 50);
        glVertex3f(-30, 70, 55);
    glEnd();
        glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, -60);
        glVertex3f(-190, -50, -60);
        glVertex3f(-190, 70, -60);
        glVertex3f(-280, 70, -60);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-170, -50, -60);
        glVertex3f(-130, -50, -60);
        glVertex3f(-130, 70, -60);
        glVertex3f(-170, 70, -60);
    glEnd();

    // dinding jek
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(220, -50, -30);
        glVertex3f(120, -50, -50);
        glVertex3f(120, 70, -50);
        glVertex3f(220, 70, -30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(120, -50, -50);
        glVertex3f(-30, -50, -50);
        glVertex3f(-30, 70, -50);
        glVertex3f(120, 70, -50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(-50, -50, -50);
        glVertex3f(-130, -50, -60);
        glVertex3f(-130, 70, -60);
        glVertex3f(-50, 70, -50);
    glEnd();


    // atap
    glColor3f(0.85,0.85,0.85);
    glBegin(GL_POLYGON);
        glVertex3d(220, 70, 25);
        glVertex3d(120, 70, 50);
        glVertex3d(-30, 70, 55);
        glVertex3d(-50, 70, 55);
        glVertex3d(-180, 70, 55);
        glVertex3d(-200, 70, 55);
        glVertex3d(-280, 70, 40);
        glVertex3d(-280, 70, -60);
        glVertex3d(-130, 70, -60);
        glVertex3d(-50, 70, -50);
        glVertex3d(120, 70, -50);
        glVertex3d(220, 70, -30);
    glEnd();

    // lantai
    glColor3f(0.85,0.85,0.85);
    glBegin(GL_POLYGON);
        glVertex3f(220, -49.8, 25);
        glVertex3f(120, -49.8, 50);
        glVertex3f(-30, -49.8, 55);
        glVertex3f(-50, -49.8, 55);
        glVertex3f(-180, -49.8, 55);
        glVertex3f(-200, -49.8, 55);
        glVertex3f(-280, -49.8, 40);
        glVertex3f(-280, -49.8, -60);
        glVertex3f(-130, -49.8, -60);
        glVertex3f(-50, -49.8, -50);
        glVertex3f(120, -49.8, -50);
        glVertex3f(220, -49.8, -30);
    glEnd();

    // Awal Pele 24/6/2021
    // trotoar
    glColor3f(229/255.f, 148/255.f, 148/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-280,-49.9,-80);
        glVertex3f(220,-49.9,-80);
        glVertex3f(220,-49.9,75);
        glVertex3f(-280,-49.9,75);
    glEnd();

    // rumput
    glColor3f(15/255.f, 154/255.f, 3/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-280,-49.9,-140);
        glVertex3f(220,-49.9,-140);
        glVertex3f(220,-49.9,-80);
        glVertex3f(-280,-49.9,-80);
    glEnd();

    // kolam
    glColor3f(22/255.f, 111/255.f, 194/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-120, -49.8, -110);
        glVertex3f(-75, -49.8, -125);
        glVertex3f(-30, -49.8, -130);
        glVertex3f(30, -49.8, -130);
        glVertex3f(75, -49.8, -125);
        glVertex3f(120, -49.8, -110);
        glVertex3f(75, -49.8, -95);
        glVertex3f(30, -49.8, -90);
        glVertex3f(-30, -49.8, -90);
        glVertex3f(-75, -49.8, -95);
    glEnd();

    // Cafe
    for(int i=0; i<3; i++){
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_QUADS); // dinding
            glVertex3f(-10+(i*40),-50,-50.1);
            glVertex3f(20+(i*40),-50,-50.1);
            glVertex3f(20+(i*40),-20,-50.1);
            glVertex3f(-10+(i*40),-20,-50.1);
        glEnd();
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_QUADS); // kanopi
            glVertex3f(-10+(i*40),-20,-50.1);
            glVertex3f(20+(i*40),-20,-50.1);
            glVertex3f(20+(i*40),-23,-70);
            glVertex3f(-10+(i*40),-23,-70);
        glEnd();
        glBegin(GL_QUADS); // tiang kanopi
            glVertex3f(-10+(i*40),-50,-70);
            glVertex3f(-8+(i*40),-50,-70);
            glVertex3f(-8+(i*40),-23,-70);
            glVertex3f(-10+(i*40),-23,-70);
        glEnd();
        glBegin(GL_QUADS); // tiang kanopi
            glVertex3f(18+(i*40),-50,-70);
            glVertex3f(20+(i*40),-50,-70);
            glVertex3f(20+(i*40),-23,-70);
            glVertex3f(18+(i*40),-23,-70);
        glEnd();
        glColor3f(80/255.f, 80/255.f, 80/255.f);
        glBegin(GL_QUADS); // pintu
            glVertex3f(2+(i*40),-50,-50.2);
            glVertex3f(8+(i*40),-50,-50.2);
            glVertex3f(8+(i*40),-30,-50.2);
            glVertex3f(2+(i*40),-30,-50.2);
        glEnd();
        glColor3f(215/255.f, 255/255.f, 253/255.f);
        glBegin(GL_QUADS); // jendela 1
            glVertex3f(-8+(i*40),-48,-50.2);
            glVertex3f(1+(i*40),-48,-50.2);
            glVertex3f(1+(i*40),-32,-50.2);
            glVertex3f(-8+(i*40),-32,-50.2);
        glEnd();
        glBegin(GL_QUADS); // jendela 2
            glVertex3f(9+(i*40),-48,-50.2);
            glVertex3f(18+(i*40),-48,-50.2);
            glVertex3f(18+(i*40),-32,-50.2);
            glVertex3f(9+(i*40),-32,-50.2);
        glEnd();
        glColor3f(230/255.f, 230/255.f, 230/255.f);
        glBegin(GL_QUADS); // papan iklan bawah
            glVertex3f(-12+(i*40),-20,-55);
            glVertex3f(22+(i*40),-20,-55);
            glVertex3f(22+(i*40),-10,-55);
            glVertex3f(-12+(i*40),-10,-55);
        glEnd();
        glBegin(GL_QUADS); // papan iklan bawah
            glVertex3f(-12+(i*40),-10,-55);
            glVertex3f(-12+(i*40),-10,-50);
            glVertex3f(22+(i*40),-10,-50);
            glVertex3f(22+(i*40),-10,-55);
        glEnd();
        glColor3f(220/255.f, 220/255.f, 220/255.f);
        glBegin(GL_QUADS); // papan iklan bawah
            glVertex3f(-12+(i*40),-20,-55);
            glVertex3f(-12+(i*40),-20,-50);
            glVertex3f(-12+(i*40),-10,-50);
            glVertex3f(-12+(i*40),-10,-55);
        glEnd();
        glBegin(GL_QUADS); // papan iklan bawah
            glVertex3f(22+(i*40),-20,-55);
            glVertex3f(22+(i*40),-20,-50);
            glVertex3f(22+(i*40),-10,-50);
            glVertex3f(22+(i*40),-10,-55);
        glEnd();
        glColor3f(221/255.f, 208/255.f, 141/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(-10+(i*40),-20,-52);
            glVertex3f(20+(i*40),-20,-52);
            glVertex3f(20+(i*40),30,-52);
            glVertex3f(-10+(i*40),30,-52);
        glEnd();
        glColor3f(202/255.f, 189/255.f, 124/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(-10+(i*40),-20,-52);
            glVertex3f(-10+(i*40),-20,-50);
            glVertex3f(-10+(i*40),30,-50);
            glVertex3f(-10+(i*40),30,-52);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(20+(i*40),-20,-52);
            glVertex3f(20+(i*40),-20,-50);
            glVertex3f(20+(i*40),30,-50);
            glVertex3f(20+(i*40),30,-52);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(-10+(i*40),30,-52);
            glVertex3f(-10+(i*40),30,-50);
            glVertex3f(20+(i*40),30,-50);
            glVertex3f(20+(i*40),30,-52);
        glEnd();
    }

    // balkon lurus kiri
    glColor3f(180/255.f, 180/255.f, 180/255.f);
    glBegin(GL_QUADS); // lantai
        glVertex3f(-160,-10,-60);
        glVertex3f(-140,-10,-60);
        glVertex3f(-140,-10,-70);
        glVertex3f(-160,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-160,-12,-60);
        glVertex3f(-140,-12,-60);
        glVertex3f(-140,-12,-70);
        glVertex3f(-160,-12,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-160,-10,-70);
        glVertex3f(-140,-10,-70);
        glVertex3f(-140,-12,-70);
        glVertex3f(-160,-12,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-160,-12,-70);
        glVertex3f(-160,-12,-60);
        glVertex3f(-160,-10,-60);
        glVertex3f(-160,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-140,-12,-70);
        glVertex3f(-140,-12,-60);
        glVertex3f(-140,-10,-60);
        glVertex3f(-140,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-160,30,-60);
        glVertex3f(-140,30,-60);
        glVertex3f(-140,30,-70);
        glVertex3f(-160,30,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-160,28,-60);
        glVertex3f(-140,28,-60);
        glVertex3f(-140,28,-70);
        glVertex3f(-160,28,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-160,30,-70);
        glVertex3f(-140,30,-70);
        glVertex3f(-140,28,-70);
        glVertex3f(-160,28,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-160,28,-70);
        glVertex3f(-160,28,-60);
        glVertex3f(-160,30,-60);
        glVertex3f(-160,30,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-140,28,-70);
        glVertex3f(-140,28,-60);
        glVertex3f(-140,30,-60);
        glVertex3f(-140,30,-70);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-160,-10,-70);
        glVertex3f(-159,-10,-70);
        glVertex3f(-159,5,-70);
        glVertex3f(-160,5,-70);
    glEnd();
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-141,-10,-70);
        glVertex3f(-140,-10,-70);
        glVertex3f(-140,5,-70);
        glVertex3f(-141,5,-70);
    glEnd();
    glColor3f(80/255.f, 80/255.f, 80/255.f);
    glBegin(GL_QUADS); // pintu
        glVertex3f(-155,-10,-60.1);
        glVertex3f(-145,-10,-60.1);
        glVertex3f(-145,10,-60.1);
        glVertex3f(-155,10,-60.1);
    glEnd();
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-159,-9,-70);
        glVertex3f(-141,-9,-70);
        glVertex3f(-141,4,-70);
        glVertex3f(-159,4,-70);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-160,-9,-70);
        glVertex3f(-160,-9,-60);
        glVertex3f(-160,4,-60);
        glVertex3f(-160,4,-70);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-140,-9,-70);
        glVertex3f(-140,-9,-60);
        glVertex3f(-140,4,-60);
        glVertex3f(-140,4,-70);
    glEnd();

    // balkon lurus kanan
    glColor3f(180/255.f, 180/255.f, 180/255.f);
    glBegin(GL_QUADS); // lantai
        glVertex3f(-270,-10,-60);
        glVertex3f(-200,-10,-60);
        glVertex3f(-200,-10,-70);
        glVertex3f(-270,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-270,-12,-60);
        glVertex3f(-200,-12,-60);
        glVertex3f(-200,-12,-70);
        glVertex3f(-270,-12,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-270,-10,-70);
        glVertex3f(-200,-10,-70);
        glVertex3f(-200,-12,-70);
        glVertex3f(-270,-12,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-270,-12,-70);
        glVertex3f(-270,-12,-60);
        glVertex3f(-270,-10,-60);
        glVertex3f(-270,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-200,-12,-70);
        glVertex3f(-200,-12,-60);
        glVertex3f(-200,-10,-60);
        glVertex3f(-200,-10,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-270,30,-60);
        glVertex3f(-200,30,-60);
        glVertex3f(-200,30,-70);
        glVertex3f(-270,30,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-270,28,-60);
        glVertex3f(-200,28,-60);
        glVertex3f(-200,28,-70);
        glVertex3f(-270,28,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-270,30,-70);
        glVertex3f(-200,30,-70);
        glVertex3f(-200,28,-70);
        glVertex3f(-270,28,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-270,28,-70);
        glVertex3f(-270,28,-60);
        glVertex3f(-270,30,-60);
        glVertex3f(-270,30,-70);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-200,28,-70);
        glVertex3f(-200,28,-60);
        glVertex3f(-200,30,-60);
        glVertex3f(-200,30,-70);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-270,-10,-70);
        glVertex3f(-269,-10,-70);
        glVertex3f(-269,5,-70);
        glVertex3f(-270,5,-70);
    glEnd();
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-201,-10,-70);
        glVertex3f(-200,-10,-70);
        glVertex3f(-200,5,-70);
        glVertex3f(-201,5,-70);
    glEnd();
    glColor3f(80/255.f, 80/255.f, 80/255.f);
    for(int i=0; i<3; i++){
        glBegin(GL_QUADS); // pintu
            glVertex3f(-260+(i*20),-10,-60.1);
            glVertex3f(-250+(i*20),-10,-60.1);
            glVertex3f(-250+(i*20),10,-60.1);
            glVertex3f(-260+(i*20),10,-60.1);
        glEnd();
    }
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-269,-9,-70);
        glVertex3f(-201,-9,-70);
        glVertex3f(-201,4,-70);
        glVertex3f(-269,4,-70);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-270,-9,-70);
        glVertex3f(-270,-9,-60);
        glVertex3f(-270,4,-60);
        glVertex3f(-270,4,-70);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-200,-9,-70);
        glVertex3f(-200,-9,-60);
        glVertex3f(-200,4,-60);
        glVertex3f(-200,4,-70);
    glEnd();

    // balkon miring
    glColor3f(180/255.f, 180/255.f, 180/255.f);
    glBegin(GL_QUADS); // lantai
        glVertex3f(-120,-10,-58.75);
        glVertex3f(-60,-10,-51.25);
        glVertex3f(-60,-10,-61.25);
        glVertex3f(-120,-10,-68.75);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-120,-12,-58.75);
        glVertex3f(-60,-12,-51.25);
        glVertex3f(-60,-12,-61.25);
        glVertex3f(-120,-12,-68.75);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-120,-10,-68.75);
        glVertex3f(-60,-10,-61.25);
        glVertex3f(-60,-12,-61.25);
        glVertex3f(-120,-12,-68.75);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-120,-12,-58.75);
        glVertex3f(-120,-12,-68.75);
        glVertex3f(-120,-10,-68.75);
        glVertex3f(-120,-10,-58.75);
    glEnd();
    glBegin(GL_QUADS); // lantai
        glVertex3f(-60,-12,-51.25);
        glVertex3f(-60,-12,-61.25);
        glVertex3f(-60,-10,-61.25);
        glVertex3f(-60,-10,-51.25);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-120,30,-58.75);
        glVertex3f(-60,30,-51.25);
        glVertex3f(-60,30,-61.25);
        glVertex3f(-120,30,-68.75);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-120,28,-58.75);
        glVertex3f(-60,28,-51.25);
        glVertex3f(-60,28,-61.25);
        glVertex3f(-120,28,-68.75);
    glEnd();
        glBegin(GL_QUADS); // atap
        glVertex3f(-120,30,-68.75);
        glVertex3f(-60,30,-61.25);
        glVertex3f(-60,28,-61.25);
        glVertex3f(-120,28,-68.75);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-120,28,-58.75);
        glVertex3f(-120,28,-68.75);
        glVertex3f(-120,30,-68.75);
        glVertex3f(-120,30,-58.75);
    glEnd();
    glBegin(GL_QUADS); // atap
        glVertex3f(-60,28,-51.25);
        glVertex3f(-60,28,-61.25);
        glVertex3f(-60,30,-61.25);
        glVertex3f(-60,30,-51.25);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-120,-10,-68.75);
        glVertex3f(-119,-10,-68.75);
        glVertex3f(-119,5,-68.75);
        glVertex3f(-120,5,-68.75);
    glEnd();
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-61,-10,-61.25);
        glVertex3f(-60,-10,-61.25);
        glVertex3f(-60,5,-61.25);
        glVertex3f(-61,5,-61.25);
    glEnd();
    glColor3f(80/255.f, 80/255.f, 80/255.f);
    glBegin(GL_QUADS); // pintu
        glVertex3f(-80,-10,-53.76);
        glVertex3f(-70,-10,-52.51);
        glVertex3f(-70,10,-52.51);
        glVertex3f(-80,10,-53.76);
    glEnd();
    glBegin(GL_QUADS); // pintu
        glVertex3f(-95,-10,-55.76);
        glVertex3f(-85,-10,-54.51);
        glVertex3f(-85,10,-54.51);
        glVertex3f(-95,10,-55.76);
    glEnd();
    glBegin(GL_QUADS); // pintu
        glVertex3f(-110,-10,-57.51);
        glVertex3f(-100,-10,-56.26);
        glVertex3f(-100,10,-56.26);
        glVertex3f(-110,10,-57.51);
    glEnd();
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-119,-9,-68.75);
        glVertex3f(-61,-9,-61.25);
        glVertex3f(-61,4,-61.25);
        glVertex3f(-119,4,-68.75);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-120,-9,-58.75);
        glVertex3f(-120,-9,-68.75);
        glVertex3f(-120,4,-68.75);
        glVertex3f(-120,4,-58.75);
    glEnd();
    glBegin(GL_QUADS); // kaca
        glVertex3f(-60,-9,-51.25);
        glVertex3f(-60,-9,-61.25);
        glVertex3f(-60,4,-61.25);
        glVertex3f(-60,4,-51.25);
    glEnd();
    // Akhir Pele 24/6/2021

     //LANTAI 2 DEKET
    //LANTAI 2 1
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(210,-10,27);
        glVertex3f(210,-10,10);
        glVertex3f(160,-10,10);
        glVertex3f(160,-10,40);
    glEnd();

    //LANTAI 2 2
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(160,-10,40);
        glVertex3f(160,-10,10);
        glVertex3f(100,-10,30);
        glVertex3f(90,-10,30);
        glVertex3f(90,-10,50);
    glEnd();

    //LANTAI 2 3
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(90,-10,50);
        glVertex3f(90,-10,30);
        glVertex3f(10,-10,10);
        glVertex3f(10,-10,50);
    glEnd();

    //LANTAI 2 4
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(10,-10,50);
        glVertex3f(10,-10,10);
        glVertex3f(-100,-10,30);
        glVertex3f(-100,-10,55);
        glVertex3f(-50,-10,55);
        glVertex3f(-30,-10,50);
    glEnd();

    //LANTAI 2 5
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-100,-10,55);
        glVertex3f(-100,-10,30);
        glVertex3f(-160,-10,20);
        glVertex3f(-190,-10,20);
        glVertex3f(-190,-10,50);
    glEnd();
    //LANTAI 2 6
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-190,-10,50);
        glVertex3f(-190,-10,0);
        glVertex3f(-280,-10,0);
        glVertex3f(-280,-10,40);
    glEnd();

    //LANTAI 2 JAUH
    //LANTAI 2 7
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-280,-10,0);
        glVertex3f(-190,-10,0);
        glVertex3f(-190,-10,-60);
        glVertex3f(-280,-10,-60);
    glEnd();


     //sofa lantai 2
    //pinggir kiri
    glBegin(GL_QUADS);
    glColor3ub(0,9,41);
    glVertex3f(-279,1,17.9);
    glColor3ub(0,19,87);
    glVertex3f(-279,-10,17.9);
    glVertex3f(-271,-10,17.9);
    glColor3ub(0,9,41);
    glVertex3f(-271,1,17.9);
    glEnd();
    //pinggir kanan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,-10,-30.1);
    glVertex3f(-271,1,-30.1);
    glVertex3f(-279,1,-30.1);
    glVertex3f(-279,-10,-30.1);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,-10,-30);
    glVertex3f(-271,-3,-30);
    glColor3ub(0,9,41);
    glVertex3f(-271,-3,18);
    glVertex3f(-271,-10,18);
    glEnd();
    //dudukan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,-3,-30);
    glColor3ub(88,117,224);
    glVertex3f(-277,-3,-30);
    glVertex3f(-277,-3,18);
    glColor3ub(0,5,23);
    glVertex3f(-271,-3,18);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-279,9,-30);
    glVertex3f(-279,-10,-30);
    glColor3ub(0,9,41);
    glVertex3f(-279,-10,18);
    glVertex3f(-279,9,18);
    glEnd();
    //senderan
    glBegin(GL_QUADS);
    glColor3ub(88,117,224);
    glVertex3f(-277,-3,-30);
    glColor3ub(0,5,23);
    glVertex3f(-279,9,-30);
    glVertex3f(-279,9,18);
    glColor3ub(88,117,224);
    glVertex3f(-277,-3,18);
    glEnd();
    //segitiga penutup kiri
    glBegin(GL_POLYGON);
    glColor3ub(88,117,224);
    glVertex3f(-277,-3,18);
    glVertex3f(-279,9,18);
    glVertex3f(-279,-3,18);
    glEnd();
    //segitiga penutup kanan
    glBegin(GL_POLYGON);
    glColor3ub(88,117,224);
    glVertex3f(-277,-3,-30);
    glVertex3f(-279,9,-30);
    glVertex3f(-279,-3,-30);
    glEnd();
/*
    //LANTAI 2 8
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-190,-10,-20);
        glVertex3f(-140,-10,-20);
        glVertex3f(-90,-10,-30);
        glVertex3f(-50,-10,-30);
        glVertex3f(-50,-10,-50);
        glVertex3f(-130,-10,-60);
        glVertex3f(-190,-10,-60);
    glEnd();

    //LANTAI 2 9
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-50,-10,-30);
        glVertex3f(10,-10,-10);
        glVertex3f(90,-10,-30);
        glVertex3f(100,-10,-30);
        glVertex3f(120,-10,-25);
        glVertex3f(120,-10,-50);
        glVertex3f(-50,-10,-50);
    glEnd();

    //LANTAI 2 10
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(120,-10,-25);
        glVertex3f(170,-10,-10);
        glVertex3f(200,-10,-10);
        glVertex3f(200,-10,-30);
        glVertex3f(120,-10,-50);
    glEnd();

    //pagar lantai 2 1
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(209,-10,10);
        glVertex3f(160,-10,10);
        glVertex3f(160,0,10);
        glVertex3f(209,0,10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(159,-10,10);
        glVertex3f(160,-10,10);
        glVertex3f(160,0,10);
        glVertex3f(159,0,10);
        glVertex3f(210,-10,10);
        glVertex3f(209,-10,10);
        glVertex3f(209,0,10);
        glVertex3f(210,0,10);
    glEnd();

    //pagar lantai 2 2
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(160,-10,10);
        glVertex3f(100,-10,30);
        glVertex3f(100,0,30);
        glVertex3f(160,0,10);
        glVertex3f(90,0,30);
        glVertex3f(90,-10,30);
        glVertex3f(100,-10,30);
        glVertex3f(100,0,30);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(90,-10,30);
        glVertex3f(89,-10,30);
        glVertex3f(89,0,30);
        glVertex3f(90,0,30);
    glEnd();

    //pagar lantai 2 3
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(89,-10,30);
        glVertex3f(10,-10,10);
        glVertex3f(10,0,10);
        glVertex3f(89,0,30);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(10,-10,10);
        glVertex3f(9,-10,10);
        glVertex3f(9,0,10);
        glVertex3f(10,0,10);
    glEnd();

    //pagar lantai 2 4
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(9,-10,10);
        glVertex3f(-100,-10,30);
        glVertex3f(-100,0,30);
        glVertex3f(9,0,10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-100,-10,30);
        glVertex3f(-101,-10,30);
        glVertex3f(-101,0,30);
        glVertex3f(-100,0,30);
    glEnd();

    //pagar lantai 2 5
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-101,-10,30);
        glVertex3f(-160,-10,20);
        glVertex3f(-160,0,20);
        glVertex3f(-101,0,30);
        glVertex3f(-160,-10,20);
        glVertex3f(-160,0,20);
        glVertex3f(-189,0,20);
        glVertex3f(-189,-10,20);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-189,-10,20);
        glVertex3f(-190,-10,20);
        glVertex3f(-190,0,20);
        glVertex3f(-189,0,20);
    glEnd();

    //pagar lantai 2 6,7
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-190,-10,20);
        glVertex3f(-190,-10,-20);
        glVertex3f(-190,0,-20);
        glVertex3f(-190,0,20);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-189,-10,-20);
        glVertex3f(-190,-10,-20);
        glVertex3f(-190,0,-20);
        glVertex3f(-189,0,-20);

    //pagar lantai 2 8
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-189,-10,-20);
        glVertex3f(-140,-10,-20);
        glVertex3f(-140,0,-20);
        glVertex3f(-189,0,-20);
        glVertex3f(-140,-10,-20);
        glVertex3f(-115,-10,-25);
        glVertex3f(-115,0,-25);
        glVertex3f(-140,0,-20);
        glVertex3f(-114,-10,-25);
        glVertex3f(-50,-10,-30);
        glVertex3f(-50,0,-30);
        glVertex3f(-114,0,-25);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-50,-10,-30);
        glVertex3f(-49,-10,-30);
        glVertex3f(-49,0,-30);
        glVertex3f(-50,0,-30);
        glVertex3f(-140,-10,-20);
        glVertex3f(-139,-10,-20);
        glVertex3f(-139,0,-20);
        glVertex3f(-140,0,-20);
        glVertex3f(-115,-10,-25);
        glVertex3f(-114,-10,-25);
        glVertex3f(-114,0,-25);
        glVertex3f(-115,0,-25);
    glEnd();

    //pagar lantai 2 9
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-49,-10,-30);
        glVertex3f(10,-10,-10);
        glVertex3f(10,0,-10);
        glVertex3f(-49,0,-30);
        glVertex3f(10,-10,-10);
        glVertex3f(75,-10,-25);
        glVertex3f(75,0,-25);
        glVertex3f(10,0,-10);
        glVertex3f(75,-10,-25);
        glVertex3f(119,-10,-25);
        glVertex3f(119,0,-25);
        glVertex3f(75,0,-25);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(10,-10,-10);
        glVertex3f(9,-10,-10);
        glVertex3f(9,0,-10);
        glVertex3f(10,0,-10);
        glVertex3f(75,-10,-25);
        glVertex3f(76,-10,-25);
        glVertex3f(76,0,-25);
        glVertex3f(75,0,-25);
        glVertex3f(119,-10,-25);
        glVertex3f(120,-10,-25);
        glVertex3f(120,0,-25);
        glVertex3f(119,0,-25);
    glEnd();

    //pagar lantai 2 10
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(121,-10,-25);
        glVertex3f(170,-10,-10);
        glVertex3f(170,0,-10);
        glVertex3f(121,0,-25);
        glVertex3f(170,-10,-10);
        glVertex3f(199,-10,-10);
        glVertex3f(199,0,-10);
        glVertex3f(170,0,-10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(170,-10,-10);
        glVertex3f(171,-10,-10);
        glVertex3f(171,0,-10);
        glVertex3f(170,0,-10);
        glVertex3f(199,-10,-10);
        glVertex3f(200,-10,-10);
        glVertex3f(200,0,-10);
        glVertex3f(199,0,-10);
    glEnd();




    //LANTAI 3 DEKET
    //LANTAI 3 1
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(210,30,27);
        glVertex3f(210,30,10);
        glVertex3f(160,30,10);
        glVertex3f(160,30,40);
    glEnd();

    //LANTAI 3 2
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(160,30,40);
        glVertex3f(160,30,10);
        glVertex3f(100,30,30);
        glVertex3f(90,30,30);
        glVertex3f(90,30,50);
    glEnd();

    //LANTAI 3 3
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(90,30,50);
        glVertex3f(90,30,30);
        glVertex3f(10,30,10);
        glVertex3f(10,30,50);
    glEnd();

    //LANTAI 3 4
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(10,30,50);
        glVertex3f(10,30,10);
        glVertex3f(-100,30,30);
        glVertex3f(-100,30,55);
        glVertex3f(-50,30,55);
        glVertex3f(-30,30,50);
    glEnd();

    //LANTAI 3 5
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-100,30,55);
        glVertex3f(-100,30,30);
        glVertex3f(-160,30,20);
        glVertex3f(-190,30,20);
        glVertex3f(-190,30,50);
    glEnd();
*/
    //LANTAI 3 6
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-190,30,50);
        glVertex3f(-190,30,0);
        glVertex3f(-280,30,0);
        glVertex3f(-280,30,40);
    glEnd();

    //LANTAI 3 JAUH
    //LANTAI 3 7
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-280,30,0);
        glVertex3f(-190,30,0);
        glVertex3f(-190,30,-60);
        glVertex3f(-280,30,-60);
    glEnd();

    //sofa lantai 3
    //pinggir kiri
    glBegin(GL_QUADS);
    glColor3ub(0,9,41);
    glVertex3f(-279,41,17.9);
    glColor3ub(0,19,87);
    glVertex3f(-279,30,17.9);
    glVertex3f(-271,30,17.9);
    glColor3ub(0,9,41);
    glVertex3f(-271,41,17.9);
    glEnd();
    //pinggir kanan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,30,-30.1);
    glVertex3f(-271,41,-30.1);
    glVertex3f(-279,41,-30.1);
    glVertex3f(-279,30,-30.1);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,30,-30);
    glVertex3f(-271,37,-30);
    glColor3ub(0,9,41);
    glVertex3f(-271,37,18);
    glVertex3f(-271,30,18);
    glEnd();
    //dudukan
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-271,37,-30);
    glColor3ub(88,117,224);
    glVertex3f(-277,37,-30);
    glVertex3f(-277,37,18);
    glColor3ub(0,5,23);
    glVertex3f(-271,37,18);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(0,5,23);
    glVertex3f(-279,49,-30);
    glVertex3f(-279,30,-30);
    glColor3ub(0,9,41);
    glVertex3f(-279,30,18);
    glVertex3f(-279,49,18);
    glEnd();
    //senderan
    glBegin(GL_QUADS);
    glColor3ub(88,117,224);
    glVertex3f(-277,37,-30);
    glColor3ub(0,5,23);
    glVertex3f(-279,49,-30);
    glVertex3f(-279,49,18);
    glColor3ub(88,117,224);
    glVertex3f(-277,37,18);
    glEnd();
    //segitiga penutup kiri
    glBegin(GL_POLYGON);
    glColor3ub(88,117,224);
    glVertex3f(-277,37,18);
    glVertex3f(-279,49,18);
    glVertex3f(-279,37,18);
    glEnd();
    //segitiga penutup kanan
    glBegin(GL_POLYGON);
    glColor3ub(88,117,224);
    glVertex3f(-277,37,-30);
    glVertex3f(-279,49,-30);
    glVertex3f(-279,37,-30);
    glEnd();
/*
    //LANTAI 3 8
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-190,30,-20);
        glVertex3f(-140,30,-20);
        glVertex3f(-90,30,-30);
        glVertex3f(-50,30,-30);
        glVertex3f(-50,30,-50);
        glVertex3f(-130,30,-60);
        glVertex3f(-190,30,-60);
    glEnd();

    //LANTAI 3 9
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(-50,30,-30);
        glVertex3f(10,30,-10);
        glVertex3f(90,30,-30);
        glVertex3f(100,30,-30);
        glVertex3f(120,30,-25);
        glVertex3f(120,30,-50);
        glVertex3f(-50,30,-50);
    glEnd();

    //LANTAI 3 10
    glColor3f(255/255.f,251/255.f,231/255.f);
    glBegin(GL_POLYGON);
        glVertex3f(120,30,-25);
        glVertex3f(170,30,-10);
        glVertex3f(200,30,-10);
        glVertex3f(200,30,-30);
        glVertex3f(120,30,-50);
    glEnd();

    //pagar lantai 3 1
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(209,30,10);
        glVertex3f(160,30,10);
        glVertex3f(160,40,10);
        glVertex3f(209,40,10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(159,30,10);
        glVertex3f(160,30,10);
        glVertex3f(160,40,10);
        glVertex3f(159,40,10);
        glVertex3f(210,30,10);
        glVertex3f(209,30,10);
        glVertex3f(209,40,10);
        glVertex3f(210,40,10);
    glEnd();

    //pagar lantai 3 2
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(160,30,10);
        glVertex3f(100,30,30);
        glVertex3f(100,40,30);
        glVertex3f(160,40,10);
        glVertex3f(90,40,30);
        glVertex3f(90,30,30);
        glVertex3f(100,30,30);
        glVertex3f(100,40,30);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(90,30,30);
        glVertex3f(89,30,30);
        glVertex3f(89,40,30);
        glVertex3f(90,40,30);
    glEnd();

    //pagar lantai 3 3
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(89,30,30);
        glVertex3f(10,30,10);
        glVertex3f(10,40,10);
        glVertex3f(89,40,30);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(10,30,10);
        glVertex3f(9,30,10);
        glVertex3f(9,40,10);
        glVertex3f(10,40,10);
    glEnd();

    //pagar lantai 3 4
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(9,30,10);
        glVertex3f(-100,30,30);
        glVertex3f(-100,40,30);
        glVertex3f(9,40,10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-100,30,30);
        glVertex3f(-101,30,30);
        glVertex3f(-101,40,30);
        glVertex3f(-100,40,30);
    glEnd();

    //pagar lantai 3 5
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-101,30,30);
        glVertex3f(-160,30,20);
        glVertex3f(-160,40,20);
        glVertex3f(-101,40,30);
        glVertex3f(-160,30,20);
        glVertex3f(-160,40,20);
        glVertex3f(-189,40,20);
        glVertex3f(-189,30,20);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-189,30,20);
        glVertex3f(-190,30,20);
        glVertex3f(-190,40,20);
        glVertex3f(-189,40,20);
    glEnd();

    //pagar lantai 3 6,7
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-190,30,20);
        glVertex3f(-190,30,-20);
        glVertex3f(-190,40,-20);
        glVertex3f(-190,40,20);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-189,30,-20);
        glVertex3f(-190,30,-20);
        glVertex3f(-190,40,-20);
        glVertex3f(-189,40,-20);

    //pagar lantai 3 8
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-189,30,-20);
        glVertex3f(-140,30,-20);
        glVertex3f(-140,40,-20);
        glVertex3f(-189,40,-20);
        glVertex3f(-140,30,-20);
        glVertex3f(-115,30,-25);
        glVertex3f(-115,40,-25);
        glVertex3f(-140,40,-20);
        glVertex3f(-114,30,-25);
        glVertex3f(-50,30,-30);
        glVertex3f(-50,40,-30);
        glVertex3f(-114,40,-25);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(-50,30,-30);
        glVertex3f(-49,30,-30);
        glVertex3f(-49,40,-30);
        glVertex3f(-50,40,-30);
        glVertex3f(-140,30,-20);
        glVertex3f(-139,30,-20);
        glVertex3f(-139,40,-20);
        glVertex3f(-140,40,-20);
        glVertex3f(-115,30,-25);
        glVertex3f(-114,30,-25);
        glVertex3f(-114,40,-25);
        glVertex3f(-115,40,-25);
    glEnd();

    //pagar lantai 3 9
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(-49,30,-30);
        glVertex3f(10,30,-10);
        glVertex3f(10,40,-10);
        glVertex3f(-49,40,-30);
        glVertex3f(10,30,-10);
        glVertex3f(75,30,-25);
        glVertex3f(75,40,-25);
        glVertex3f(10,40,-10);
        glVertex3f(75,30,-25);
        glVertex3f(119,30,-25);
        glVertex3f(119,40,-25);
        glVertex3f(75,40,-25);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(10,30,-10);
        glVertex3f(9,30,-10);
        glVertex3f(9,40,-10);
        glVertex3f(10,40,-10);
        glVertex3f(75,30,-25);
        glVertex3f(76,30,-25);
        glVertex3f(76,40,-25);
        glVertex3f(75,40,-25);
        glVertex3f(119,30,-25);
        glVertex3f(120,30,-25);
        glVertex3f(120,40,-25);
        glVertex3f(119,40,-25);
    glEnd();

    //pagar lantai 3 10
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS); // kaca
        glVertex3f(121,30,-25);
        glVertex3f(170,30,-10);
        glVertex3f(170,40,-10);
        glVertex3f(121,40,-25);
        glVertex3f(170,30,-10);
        glVertex3f(199,30,-10);
        glVertex3f(199,40,-10);
        glVertex3f(170,40,-10);
    glEnd();
    glColor3f(228/255.f, 228/255.f, 228/255.f);
    glBegin(GL_QUADS); // tiang pagar
        glVertex3f(170,30,-10);
        glVertex3f(171,30,-10);
        glVertex3f(171,40,-10);
        glVertex3f(170,40,-10);
        glVertex3f(199,30,-10);
        glVertex3f(200,30,-10);
        glVertex3f(200,40,-10);
        glVertex3f(199,40,-10);
    glEnd();




/*
    // pele 25/6/2021
    // jalan raya
    glColor3f(111/255.f,111/255.f,111/255.f);
    glBegin(GL_QUADS);
        glVertex3d(-350,-49.9,75);
        glVertex3d(350,-49.9,75);
        glVertex3d(350,-49.9,150);
        glVertex3d(-350,-49.9,150);
    glEnd();
    // bahu jalan
    glColor3f(210/255.f,210/255.f,210/255.f);
    glBegin(GL_QUADS);
        glVertex3d(-350,-45,105);
        glVertex3d(350,-45,105);
        glVertex3d(350,-45,120);
        glVertex3d(-350,-45,120);
    glEnd();
    glColor3f(58/255.f,58/255.f,58/255.f);
    glBegin(GL_QUADS);
        glVertex3d(-350,-49.9,120);
        glVertex3d(350,-49.9,120);
        glVertex3d(350,-45,120);
        glVertex3d(-350,-45,120);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3d(-350,-49.9,105);
        glVertex3d(350,-49.9,105);
        glVertex3d(350,-45,105);
        glVertex3d(-350,-45,105);
    glEnd();
    glColor3f(0.95,0.95,0.95);
    for(int i=0; i<70; i++){
        glBegin(GL_QUADS);
            glVertex3d(-350+(i*10),-49.9,120.1);
            glVertex3d(-345+(i*10),-49.9,120.1);
            glVertex3d(-345+(i*10),-45,120.1);
            glVertex3d(-350+(i*10),-45,120.1);
        glEnd();
        glBegin(GL_QUADS);
            glVertex3d(-350+(i*10),-49.9,104.9);
            glVertex3d(-345+(i*10),-49.9,104.9);
            glVertex3d(-345+(i*10),-45,104.9);
            glVertex3d(-350+(i*10),-45,104.9);
        glEnd();
    }
    glColor3f(1,1,1);
    for(int i=0; i<35; i++){
        glBegin(GL_QUADS);
            glVertex3d(-350+(i*20),-49.8,135.5);
            glVertex3d(-340+(i*20),-49.8,135.5);
            glVertex3d(-340+(i*20),-49.8,134.5);
            glVertex3d(-350+(i*20),-49.8,134.5);
        glEnd();
        glBegin(GL_QUADS);
            glVertex3d(-350+(i*20),-49.8,90.5);
            glVertex3d(-340+(i*20),-49.8,90.5);
            glVertex3d(-340+(i*20),-49.8,89.5);
            glVertex3d(-350+(i*20),-49.8,89.5);
        glEnd();
    }

    // IMAX
    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslated(300,-10,-20);
        glutSolidSphere(55,20,20);
    glPopMatrix();

    // AQUARIUM
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,-10);
        glVertex3f(-40,-50,-4);
        glVertex3f(-40,70,-4);
        glVertex3f(-50,70,-10);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-40,-50,-4);
        glVertex3f(-40,-50,4);
        glVertex3f(-40,70,4);
        glVertex3f(-40,70,-4);
    glEnd();
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,10);
        glVertex3f(-40,-50,4);
        glVertex3f(-40,70,4);
        glVertex3f(-50,70,10);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,10);
        glVertex3f(-60,-50,4);
        glVertex3f(-60,70,4);
        glVertex3f(-50,70,10);
    glEnd();
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-60,-50,-4);
        glVertex3f(-60,-50,4);
        glVertex3f(-60,70,4);
        glVertex3f(-60,70,-4);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,-10);
        glVertex3f(-60,-50,-4);
        glVertex3f(-60,70,-4);
        glVertex3f(-50,70,-10);
    glEnd();


    //ESKALATOR
    eskalator(-150,-145,-50,-155,-150,-50,-150,-50,-155,-160,-45,15,0);
    eskalator(-150,-145,-50,-155,-150,-50,-150,-50,-155,-160,-45,-10,-25);

    // ATAP KIRI ATAS
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-140,80,-15);
        glVertex3f(-100,80,-25);
        glVertex3f(-100,80,-15);
        glVertex3f(-140,80,-5);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(-140,70,-5);
        glVertex3f(-140,70,-15);
        glVertex3f(-140,80,-15);
        glVertex3f(-140,80,-5);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(-100,70,-15);
        glVertex3f(-100,70,-25);
        glVertex3f(-100,80,-25);
        glVertex3f(-100,80,-15);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(-140,70,-15);
        glVertex3f(-100,70,-25);
        glVertex3f(-100,80,-25);
        glVertex3f(-140,80,-15);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(-140,70,-5);
        glVertex3f(-100,70,-15);
        glVertex3f(-100,80,-15);
        glVertex3f(-140,80,-5);
    glEnd();

    // ATAP KIRI BAWAH
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-140,80,15);
        glVertex3f(-100,80,25);
        glVertex3f(-100,80,15);
        glVertex3f(-140,80,5);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(-140,70,5);
        glVertex3f(-140,70,15);
        glVertex3f(-140,80,15);
        glVertex3f(-140,80,5);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(-100,70,15);
        glVertex3f(-100,70,25);
        glVertex3f(-100,80,25);
        glVertex3f(-100,80,15);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(-140,70,15);
        glVertex3f(-100,70,25);
        glVertex3f(-100,80,25);
        glVertex3f(-140,80,15);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(-140,70,5);
        glVertex3f(-100,70,15);
        glVertex3f(-100,80,15);
        glVertex3f(-140,80,5);
    glEnd();

    // AC
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            glColor3f(0.95,0.95,0.95);
            glBegin(GL_QUADS); // belakang
                glVertex3f(-270+(i*20),70,-40+(j*25));
                glVertex3f(-260+(i*20),70,-40+(j*25));
                glVertex3f(-260+(i*20),77,-40+(j*25));
                glVertex3f(-270+(i*20),77,-40+(j*25));
            glEnd();
            glBegin(GL_QUADS); // depan
                glVertex3f(-270+(i*20),70,-35+(j*25));
                glVertex3f(-260+(i*20),70,-35+(j*25));
                glVertex3f(-260+(i*20),77,-35+(j*25));
                glVertex3f(-270+(i*20),77,-35+(j*25));
            glEnd(); // kanan
            glColor3f(0.9,0.9,0.9);
            glBegin(GL_QUADS);
                glVertex3f(-270+(i*20),70,-40+(j*25));
                glVertex3f(-270+(i*20),70,-35+(j*25));
                glVertex3f(-270+(i*20),77,-35+(j*25));
                glVertex3f(-270+(i*20),77,-40+(j*25));
            glEnd(); // kiri
            glColor3f(0.98,0.98,0.98);
            glBegin(GL_QUADS);
                glVertex3f(-260+(i*20),70,-40+(j*25));
                glVertex3f(-260+(i*20),70,-35+(j*25));
                glVertex3f(-260+(i*20),77,-35+(j*25));
                glVertex3f(-260+(i*20),77,-40+(j*25));
            glEnd();// atas
            glBegin(GL_QUADS);
                glVertex3f(-260+(i*20),77,-40+(j*25));
                glVertex3f(-270+(i*20),77,-40+(j*25));
                glVertex3f(-270+(i*20),77,-35+(j*25));
                glVertex3f(-260+(i*20),77,-35+(j*25));
            glEnd();
            glColor3f(0.6,0.6,0.6);
            glBegin(GL_POLYGON);
                lingkaran(-263+(i*20),73.5,-34.9+(j*25),2);
            glEnd();
        }
    }


    // ATAP TENGAH
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
        glVertex3d(-70,80,-25);
        glVertex3d(-30,80,-20);
        glVertex3d(-10,80,-10);
        glVertex3d(0,80,0);
        glVertex3d(-10,80,10);
        glVertex3d(-30,80,20);
        glVertex3d(-70,80,25);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(-70,70,-25);
        glVertex3f(-70,70,25);
        glVertex3f(-70,80,25);
        glVertex3f(-70,80,-25);
    glEnd(); //depan 1
    glBegin(GL_QUADS);
        glVertex3f(-70,70,25);
        glVertex3f(-30,70,20);
        glVertex3f(-30,80,20);
        glVertex3f(-70,80,25);
    glEnd(); //depan 2
    glBegin(GL_QUADS);
        glVertex3f(-30,70,20);
        glVertex3f(-10,70,10);
        glVertex3f(-10,80,10);
        glVertex3f(-30,80,20);
    glEnd(); //depan 3
    glBegin(GL_QUADS);
        glVertex3f(-10,70,10);
        glVertex3f(0,70,0);
        glVertex3f(0,80,0);
        glVertex3f(-10,80,10);
    glEnd(); //belakang 1
    glBegin(GL_QUADS);
        glVertex3f(-70,70,-25);
        glVertex3f(-30,70,-20);
        glVertex3f(-30,80,-20);
        glVertex3f(-70,80,-25);
    glEnd(); //belakang 2
    glBegin(GL_QUADS);
        glVertex3f(-30,70,-20);
        glVertex3f(-10,70,-10);
        glVertex3f(-10,80,-10);
        glVertex3f(-30,80,-20);
    glEnd(); //belakang 3
    glBegin(GL_QUADS);
        glVertex3f(-10,70,-10);
        glVertex3f(0,70,0);
        glVertex3f(0,80,0);
        glVertex3f(-10,80,-10);
    glEnd();

    // ATAP KANAN (ATAS KIRI)
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(40,80,-3);
        glVertex3f(80,80,-13);
        glVertex3f(80,80,-20);
        glVertex3f(40,80,-10);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(40,70,-3);
        glVertex3f(40,70,-10);
        glVertex3f(40,80,-10);
        glVertex3f(40,80,-3);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(80,70,-13);
        glVertex3f(80,70,-20);
        glVertex3f(80,80,-20);
        glVertex3f(80,80,-13);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(40,70,-3);
        glVertex3f(80,70,-13);
        glVertex3f(80,80,-13);
        glVertex3f(40,80,-3);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(40,70,-10);
        glVertex3f(80,70,-20);
        glVertex3f(80,80,-20);
        glVertex3f(40,80,-10);
    glEnd();

    // ATAP KANAN (BAWAH KIRI)
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(40,80,3);
        glVertex3f(80,80,13);
        glVertex3f(80,80,20);
        glVertex3f(40,80,10);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(40,70,3);
        glVertex3f(40,70,10);
        glVertex3f(40,80,10);
        glVertex3f(40,80,3);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(80,70,13);
        glVertex3f(80,70,20);
        glVertex3f(80,80,20);
        glVertex3f(80,80,13);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(40,70,3);
        glVertex3f(80,70,13);
        glVertex3f(80,80,13);
        glVertex3f(40,80,3);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(40,70,10);
        glVertex3f(80,70,20);
        glVertex3f(80,80,20);
        glVertex3f(40,80,10);
    glEnd();

    // ATAP KANAN (ATAS KANAN)
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(110,80,20);
        glVertex3f(150,80,10);
        glVertex3f(150,80,3);
        glVertex3f(110,80,13);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(110,70,13);
        glVertex3f(110,70,20);
        glVertex3f(110,80,20);
        glVertex3f(110,80,13);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(150,70,3);
        glVertex3f(150,70,10);
        glVertex3f(150,80,10);
        glVertex3f(150,80,3);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(110,70,13);
        glVertex3f(150,70,3);
        glVertex3f(150,80,3);
        glVertex3f(110,80,13);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(110,70,20);
        glVertex3f(150,70,10);
        glVertex3f(150,80,10);
        glVertex3f(110,80,20);
    glEnd();

    // ATAP KANAN (BAWAH KANAN)
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(110,80,-20);
        glVertex3f(150,80,-10);
        glVertex3f(150,80,-3);
        glVertex3f(110,80,-13);
    glEnd(); // kiri
    glColor4f(215/255.f, 255/255.f, 253/255.f, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(110,70,-13);
        glVertex3f(110,70,-20);
        glVertex3f(110,80,-20);
        glVertex3f(110,80,-13);
    glEnd(); // kanan
    glBegin(GL_QUADS);
        glVertex3f(150,70,-3);
        glVertex3f(150,70,-10);
        glVertex3f(150,80,-10);
        glVertex3f(150,80,-3);
    glEnd(); //depan
    glBegin(GL_QUADS);
        glVertex3f(110,70,-13);
        glVertex3f(150,70,-3);
        glVertex3f(150,80,-3);
        glVertex3f(110,80,-13);
    glEnd(); //belakang
    glBegin(GL_QUADS);
        glVertex3f(110,70,-20);
        glVertex3f(150,70,-10);
        glVertex3f(150,80,-10);
        glVertex3f(110,80,-20);
    glEnd();


    //papan iklan
    for(int i=0; i<2; i++){
        glColor3f(221/255.f, 208/255.f, 141/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(20+(i*40),-30,55);
            glColor3f(214/255.f,21/255.f,15/255.f);
            glVertex3f(50+(i*40),-30,55);
            glColor3f(21/255.f,24/255.f,0/255.f);
            glVertex3f(50+(i*40),40,55);
            glColor3f(231/255.f,24/255.f,536/255.f);
            glVertex3f(20+(i*40),40,55);
        glEnd();
        glColor3f(255/255.f, 255/255.f, 255/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(20+(i*40),-30,55);
            glVertex3f(20+(i*40),-30,53);
            glVertex3f(20+(i*40),40,53);
            glVertex3f(20+(i*40),40,55);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(50+(i*40),-30,55);
            glVertex3f(50+(i*40),-30,53);
            glVertex3f(50+(i*40),40,53);
            glVertex3f(50+(i*40),40,55);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(20+(i*40),40,55);
            glVertex3f(20+(i*40),40,53);
            glVertex3f(50+(i*40),40,53);
            glVertex3f(50+(i*40),40,55);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(20+(i*40),-30,55);
            glVertex3f(20+(i*40),-30,53);
            glVertex3f(50+(i*40),-30,53);
            glVertex3f(50+(i*40),-30,55);
        glEnd();
    }
    for(int i=0; i<3; i++){
        glColor3f(221/255.f, 208/255.f, 141/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(-170+(i*40),-30,58);
            glColor3f(25/255.f,21/255.f,15/255.f);
            glVertex3f(-140+(i*40),-30,58);
            glColor3f(21/255.f,24/255.f,0/255.f);
            glVertex3f(-140+(i*40),40,58);
            glColor3f(341/255.f,24/255.f,12/255.f);
            glVertex3f(-170+(i*40),40,58);
        glEnd();
        glColor3f(255/255.f, 255/255.f, 255/255.f);
        glBegin(GL_QUADS); // banner
            glVertex3f(-170+(i*40),-30,58);
            glVertex3f(-170+(i*40),-30,56);
            glVertex3f(-170+(i*40),40,58);
            glVertex3f(-170+(i*40),40,56);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(-140+(i*40),-30,58);
            glVertex3f(-140+(i*40),-30,56);
            glVertex3f(-140+(i*40),40,56);
            glVertex3f(-140+(i*40),40,58);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(-170+(i*40),40,58);
            glVertex3f(-170+(i*40),40,56);
            glVertex3f(-140+(i*40),40,56);
            glVertex3f(-140+(i*40),40,58);
        glEnd();
        glBegin(GL_QUADS); // banner
            glVertex3f(-170+(i*40),-30,58);
            glVertex3f(-170+(i*40),-30,56);
            glVertex3f(-140+(i*40),-30,56);
            glVertex3f(-140+(i*40),-30,58);
        glEnd();
    }

//KACA KIRI KOLAM RENANG
    for(int i= -50;i< -30;i+=4)
    {
        for(int j= -20;j<70;j+=10)
        {
            int x = i+4;
            int y = j+10;
            int z = -50;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }

    //KACA KANAN KOLAM RENANG
    for(int i= -190;i< -170;i+=4)
    {
        for(int j= -20;j<70;j+=10)
        {
            int x = i+4;
            int y = j+10;
            int z = -60;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }

    //KACA KANAN
    for(int i= -50;i< -30;i+=4)
    {
        for(int j= -20;j<70;j+=10)
        {
            int x = i+4;
            int y = j+10;
            int z = 55;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }

    //KACA KIRI
    for(int i= -200;i< -180;i+=4)
    {
        for(int j= -20;j<70;j+=10)
        {
            int x = i+4;
            int y = j+10;
            int z = 55;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }

    //PINTU KIRI
    //depan
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-200,-25,75);
    glVertex3f(-180,-25,75);
    glVertex3f(-180,-20,75);
    glVertex3f(-200,-20,75);
    glEnd();

    for(int i= -200;i< -180;i+=10)
    {
        for(int j= -50;j<-25;j+=25)
        {
            int x = i+10;
            int y = j+25;
            int z = 70;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-200,-20,55);
    glVertex3f(-180,-20,55);
    glVertex3f(-180,-20,75);
    glVertex3f(-200,-20,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-200,-25,70);
    glVertex3f(-180,-25,70);
    glVertex3f(-180,-25,75);
    glVertex3f(-200,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-200,-25,55);
    glVertex3f(-200,-20,55);
    glVertex3f(-200,-20,75);
    glVertex3f(-200,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-180,-25,55);
    glVertex3f(-180,-20,55);
    glVertex3f(-180,-20,75);
    glVertex3f(-180,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-180,-25,55);
    glVertex3f(-180,-50,55);
    glVertex3f(-180,-50,70);
    glVertex3f(-180,-25,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-180,-25,55);
    glVertex3f(-180,-50,55);
    glVertex3f(-180,-50,70);
    glVertex3f(-180,-25,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-200,-25,55);
    glVertex3f(-200,-50,55);
    glVertex3f(-200,-50,70);
    glVertex3f(-200,-25,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-200,-25,55);
    glVertex3f(-200,-50,55);
    glVertex3f(-200,-50,70);
    glVertex3f(-200,-25,70);
    glEnd();

    //KANAN
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,75);
    glVertex3f(-30,-25,75);
    glVertex3f(-30,-20,75);
    glVertex3f(-50,-20,75);
    glEnd();

    for(int i= -50;i< -30;i+=10)
    {
        for(int j= -50;j<-25;j+=25)
        {
            int x = i+10;
            int y = j+25;
            int z = 70;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-20,55);
    glVertex3f(-30,-20,55);
    glVertex3f(-30,-20,75);
    glVertex3f(-50,-20,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,70);
    glVertex3f(-30,-25,70);
    glVertex3f(-30,-25,75);
    glVertex3f(-50,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,55);
    glVertex3f(-50,-20,55);
    glVertex3f(-50,-20,75);
    glVertex3f(-50,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-30,-25,55);
    glVertex3f(-30,-20,55);
    glVertex3f(-30,-20,75);
    glVertex3f(-30,-25,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-30,-25,55);
    glVertex3f(-30,-50,55);
    glVertex3f(-30,-50,70);
    glVertex3f(-30,-25,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-30,-25,55);
    glVertex3f(-30,-50,55);
    glVertex3f(-30,-50,70);
    glVertex3f(-30,-25,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-50,-25,55);
    glVertex3f(-50,-50,55);
    glVertex3f(-50,-50,70);
    glVertex3f(-50,-25,70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-50,-25,55);
    glVertex3f(-50,-50,55);
    glVertex3f(-50,-50,70);
    glVertex3f(-50,-25,70);
    glEnd();

    //KANAN KOLAM
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-190,-25,-80);
    glVertex3f(-170,-25,-80);
    glVertex3f(-170,-20,-80);
    glVertex3f(-190,-20,-80);
    glEnd();

    for(int i= -190;i< -170;i+=10)
    {
        for(int j= -50;j<-25;j+=25)
        {
            int x = i+10;
            int y = j+25;
            int z = -75;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-190,-20,-60);
    glVertex3f(-170,-20,-60);
    glVertex3f(-170,-20,-80);
    glVertex3f(-190,-20,-80);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-190,-25,-75);
    glVertex3f(-170,-25,-75);
    glVertex3f(-170,-25,-80);
    glVertex3f(-190,-25,-80);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-190,-25,-60);
    glVertex3f(-190,-20,-60);
    glVertex3f(-190,-20,-80);
    glVertex3f(-190,-25,-80);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-170,-25,-60);
    glVertex3f(-170,-20,-60);
    glVertex3f(-170,-20,-80);
    glVertex3f(-170,-25,-80);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-170,-25,-60);
    glVertex3f(-170,-50,-60);
    glVertex3f(-170,-50,-75);
    glVertex3f(-170,-25,-75);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-170,-25,-60);
    glVertex3f(-170,-50,-60);
    glVertex3f(-170,-50,-75);
    glVertex3f(-170,-25,-75);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-190,-25,-60);
    glVertex3f(-190,-50,-60);
    glVertex3f(-190,-50,-75);
    glVertex3f(-190,-25,-75);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-190,-25,-60);
    glVertex3f(-190,-50,-60);
    glVertex3f(-190,-50,-75);
    glVertex3f(-190,-25,-75);
    glEnd();

    //KIRI KOLAM
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,-70);
    glVertex3f(-30,-25,-70);
    glVertex3f(-30,-20,-70);
    glVertex3f(-50,-20,-70);
    glEnd();

    for(int i= -50;i< -30;i+=10)
    {
        for(int j= -50;j<-25;j+=25)
        {
            int x = i+10;
            int y = j+25;
            int z = -65;
        glBegin(GL_QUADS);
        glColor4f(255/255.f,251/255.f,231/255.f,0.5);
            glVertex3f(i,y,z);
            glVertex3f(x,y,z);
            glVertex3f(x,j,z);
            glVertex3f(i,j,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(0/255.f,0/255.f,0/255.f,0.1);
            glVertex3f(i,y,z);
            glVertex3f(i,j,z);
            glVertex3f(x,j,z);
            glVertex3f(x,y,z);
        glEnd();
        }
    }
    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-20,-50);
    glVertex3f(-30,-20,-50);
    glVertex3f(-30,-20,-70);
    glVertex3f(-50,-20,-70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,-65);
    glVertex3f(-30,-25,-65);
    glVertex3f(-30,-25,-70);
    glVertex3f(-50,-25,-70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-50,-25,-50);
    glVertex3f(-50,-20,-50);
    glVertex3f(-50,-20,-70);
    glVertex3f(-50,-25,-70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(163/255.f,23/255.f,23/255.f,1);
    glVertex3f(-30,-25,-50);
    glVertex3f(-30,-20,-50);
    glVertex3f(-30,-20,-70);
    glVertex3f(-30,-25,-70);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-30,-25,-50);
    glVertex3f(-30,-50,-50);
    glVertex3f(-30,-50,-65);
    glVertex3f(-30,-25,-65);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-30,-25,-50);
    glVertex3f(-30,-50,-50);
    glVertex3f(-30,-50,-65);
    glVertex3f(-30,-25,-65);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(255/255.f,251/255.f,231/255.f,0.5);
    glVertex3f(-50,-25,-50);
    glVertex3f(-50,-50,-50);
    glVertex3f(-50,-50,-65);
    glVertex3f(-50,-25,-65);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0/255.f,0/255.f,0/255.f,0.1);
    glVertex3f(-50,-25,-50);
    glVertex3f(-50,-50,-50);
    glVertex3f(-50,-50,-65);
    glVertex3f(-50,-25,-65);
    glEnd();


float aLampu=-300;
    float bLampu=-295;

    while(aLampu<=300 && bLampu<=295){
        //LAMPU JALAN
        //ALAS SISI HADEP DEPAN
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu,-50,115);
        glVertex3f(bLampu,-50,115);
        glVertex3f(bLampu-1,-40,114);
        glVertex3f(aLampu+1,-40,114);
        glEnd();

        //ALAS SISI HADEP BELAKANG
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu,-50,110);
        glVertex3f(bLampu,-50,110);
        glVertex3f(bLampu-1,-40,111);
        glVertex3f(aLampu+1,-40,111);
        glEnd();

        //ALAS SISI HADEP KIRI
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu,-50,115);
        glVertex3f(aLampu,-50,110);
        glVertex3f(aLampu+1,-40,111);
        glVertex3f(aLampu+1,-40,114);
        glEnd();

        //ALAS SISI HADEP KIRI
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(bLampu,-50,115);
        glVertex3f(bLampu,-50,110);
        glVertex3f(bLampu-1,-40,111);
        glVertex3f(bLampu-1,-40,114);
        glEnd();

        //ALAS SISI HADEP ATAS
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu+1,-40,114);
        glVertex3f(bLampu-1,-40,114);
        glVertex3f(bLampu-1,-40,111);
        glVertex3f(aLampu+1,-40,111);
        glEnd();

        //TIANG TEGAK DEPAN
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu+2,-40,113);
        glVertex3f(bLampu-2,-40,113);
        glVertex3f(bLampu-2,0,113);
        glVertex3f(aLampu+2,0,113);
        glEnd();

        //TIANG TEGAK BELAKANG
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu+2,-40,112);
        glVertex3f(bLampu-2,-40,112);
        glVertex3f(bLampu-2,0,112);
        glVertex3f(aLampu+2,0,112);
        glEnd();

        //TIANG TEGAK KIRI
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(aLampu+2,-40,113);
        glVertex3f(aLampu+2,-40,112);
        glVertex3f(aLampu+2,0,112);
        glVertex3f(aLampu+2,0,113);
        glEnd();

        //TIANG TEGAK KANAN
        glBegin(GL_QUADS);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(bLampu-2,-40,113);
        glVertex3f(bLampu-2,-40,112);
        glVertex3f(bLampu-2,0,112);
        glVertex3f(bLampu-2,0,113);
        glEnd();

        //CAGAK LAMPU
        glBegin(GL_LINES);
        glColor3f(64/255.f,64/255.f,64/255.f);
        glVertex3f(bLampu-2.5,-2,112.5);
        glVertex3f(bLampu-2.5,3,116);

        glVertex3f(bLampu-2.5,-2,112.5);
        glVertex3f(bLampu-2.5,3,109);

        glVertex3f(bLampu-2.5,3,116);
        glVertex3f(bLampu-2.5,3,119);

        glVertex3f(bLampu-2.5,3,109);
        glVertex3f(bLampu-2.5,3,106);
        glEnd();

        //LAMPU JALAN
        glPushMatrix();
            glColor3f(1.0,1.0,0.0);
            glTranslated(bLampu-2.5,1,118);
            glutSolidSphere(2,10,10);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1.0,1.0,0.0);
            glTranslated(bLampu-2.5,1,107);
            glutSolidSphere(2,10,10);
        glPopMatrix();

        float x1=228.0;
        float x2=270.0;

        while(x1>=-228 && x2>=-270){
            //MOBIL
            //BODY SAMPING DEKET
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1,-43,133);
                glVertex3f(x2,-43,133);
                glVertex3f(x2,-33,133);
                glVertex3f(x1,-33,133);
            glEnd();

            //BODY SAMPING JAUH
            glColor3f(134/255.f,3/255.f,3/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1,-43,123);
                glVertex3f(x2,-43,123);
                glVertex3f(x2,-33,123);
                glVertex3f(x1,-33,123);
            glEnd();

            //BODY DEPAN
            glColor3f(186/255.f,14/255.f,14/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1,-33,133);
                glVertex3f(x1,-43,133);
                glVertex3f(x1,-43,123);
                glVertex3f(x1,-33,123);
            glEnd();

            //BODY BELAKANG
            glColor3f(186/255.f,14/255.f,14/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x2,-33,133);
                glVertex3f(x2,-43,133);
                glVertex3f(x2,-43,123);
                glVertex3f(x2,-33,123);
            glEnd();

            //BODY ATAS
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1+15.0,-23,133);
                glVertex3f(x2-8.0,-23,133);
                glVertex3f(x2-8.0,-23,123);
                glVertex3f(x1+15.0,-23,123);
            glEnd();

            //KAP MOBIL DEPAN
            glColor3f(186/255.f,14/255.f,14/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1,-33,133);
                glVertex3f(x1+7,-33,133);
                glVertex3f(x1+7,-33,123);
                glVertex3f(x1,-33,123);
            glEnd();

            //BODY KACA DEPAN
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1+7,-33,133);
                glVertex3f(x1+15,-23,133);
                glVertex3f(x1+15,-23,123);
                glVertex3f(x1+7,-33,123);
            glEnd();

            //KACA BELAKANG
            glBegin(GL_QUADS);
            glColor3f(134/255.f,232/255.f,238/255.f);
                glVertex3f(x2-8,-23,133);
                glVertex3f(x2-8,-23,123);
                glColor3f(255/255.f,255/255.f,255/255.f);
                glVertex3f(x2,-33,123);
                glVertex3f(x2,-33,133);


            glEnd();

            //BODY KACA SAMPING DEKET
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1+7,-33,133);
                glVertex3f(x2,-33,133);
                glVertex3f(x2-8,-23,133);
                glVertex3f(x1+15,-23,133);
            glEnd();

            //BODY KACA SAMPING JAUH
            glColor3f(134/255.f,3/255.f,3/255.f);
            glBegin(GL_QUADS);
                glVertex3f(x1+7,-33,123);
                glVertex3f(x2,-33,123);
                glVertex3f(x2-8,-23,123);
                glVertex3f(x1+15,-23,123);
            glEnd();

            //KACA DEPAN
            glBegin(GL_QUADS);
                glColor3f(134/255.f,232/255.f,238/255.f);
                glVertex3f(x1+14,-24,132.5);
                glVertex3f(x1+14,-24,123.5);
                glColor3f(255/255.f,255/255.f,255/255.f);
                glVertex3f(x1+7.5,-32,123.5);
                glVertex3f(x1+7.5,-32,132.5);
            glEnd();

            //KACA SAMPING DEKET
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glColor3f(255/255.f,255/255.f,255/255.f);
                glVertex3f(x1+8,-32.5,133.1);
                glVertex3f(x2-1,-32.5,133.1);
                glColor3f(134/255.f,232/255.f,238/255.f);
                glVertex3f(x2-9,-23.5,133.1);
                glVertex3f(x1+16,-23.5,133.1);
            glEnd();

            //KACA SAMPING JAUH
            glColor3f(232/255.f,21/255.f,21/255.f);
            glBegin(GL_QUADS);
                glColor3f(255/255.f,255/255.f,255/255.f);
                glVertex3f(x1+8,-32.5,122.9);
                glVertex3f(x2-1,-32.5,122.9);
                glColor3f(134/255.f,232/255.f,238/255.f);
                glVertex3f(x2-9,-23.5,122.9);
                glVertex3f(x1+16,-23.5,122.9);
            glEnd();

            //BAN DEPAN DEKET
            glColor3f(14/255.f,13/255.f,13/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x1+8,-44,133.1,5);
            glEnd();

            //BAN BELAKANG DEKET
            glColor3f(14/255.f,13/255.f,13/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x2-8,-44,133.1,5);
            glEnd();

            //BAN DEPAN JAUH
            glColor3f(14/255.f,13/255.f,13/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x1+8,-44,122.9,5);
            glEnd();

            //BAN BELAKANG JAUH
            glColor3f(14/255.f,13/255.f,13/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x2-8,-44,122.9,5);
            glEnd();

            //BAN KECIL DEPAN DEKET
            glColor3f(134/255.f,125/255.f,125/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x1+8,-44,133.2,3);
            glEnd();

            //BAN KECIL BELAKANG DEKET
            glColor3f(134/255.f,125/255.f,125/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x2-8,-44,133.2,3);
            glEnd();

            //BAN KECIL DEPAN JAUH
            glColor3f(134/255.f,125/255.f,125/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x1+8,-44,122.8,3);
            glEnd();

            //BAN KECIL BELAKANG JAUH
            glColor3f(134/255.f,125/255.f,125/255.f);
            glBegin(GL_POLYGON);
                lingkaran(x2-8,-44,122.8,3);
            glEnd();

            x1-=100;
            x2-=100;
        }
        aLampu+=70;
        bLampu+=70;
    }
    //AWAN
    awan(90,100,110,120,-60);
    awan(-170,-160,130,140,-90);
    awan(0,10,150,160,-80);
    awan(-10,0,140,150,80);
    awan(-200,-190,120,130,50);
    awan(150,160,140,150,0);

    //dinding belakang imax
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(220, -50, -30);
        glVertex3f(220, -50, -15);
        glVertex3f(220, 70, -15);
        glVertex3f(220, 70, -30);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(220, -50, 10);
        glVertex3f(220, -50, 25);
        glVertex3f(220, 70, 25);
        glVertex3f(220, 70, 10);
    glEnd();

    // AQUARIUM
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,-10);
        glVertex3f(-40,-50,-4);
        glVertex3f(-40,70,-4);
        glVertex3f(-50,70,-10);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-40,-50,-4);
        glVertex3f(-40,-50,4);
        glVertex3f(-40,70,4);
        glVertex3f(-40,70,-4);
    glEnd();
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,10);
        glVertex3f(-40,-50,4);
        glVertex3f(-40,70,4);
        glVertex3f(-50,70,10);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,10);
        glVertex3f(-60,-50,4);
        glVertex3f(-60,70,4);
        glVertex3f(-50,70,10);
    glEnd();
    glColor4f(36/255.f,117/255.f,182/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-60,-50,-4);
        glVertex3f(-60,-50,4);
        glVertex3f(-60,70,4);
        glVertex3f(-60,70,-4);
    glEnd();
    glColor4f(19/255.f,107/255.f,165/255.f,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-50,-50,-10);
        glVertex3f(-60,-50,-4);
        glVertex3f(-60,70,-4);
        glVertex3f(-50,70,-10);
    glEnd();

    //pintu tabung
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex3f(220,-50,-21);
        glVertex3f(230,-50,-15);
        glVertex3f(230,70,-15);
        glVertex3f(220,70,-21);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex3f(230,-50,-15);
        glVertex3f(230,-50,21);
        glVertex3f(230,70,21);
        glVertex3f(230,70,-15);
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glVertex3f(220,-50,21);
        glVertex3f(230,-50,10);
        glVertex3f(230,70,10);
        glVertex3f(220,70,21);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex3f(225,-50,25);
        glVertex3f(235,-50,10);
        glVertex3f(235,70,10);
        glVertex3f(225,70,25);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(235,-50,-15);
        glVertex3f(235,-50,10);
        glVertex3f(235,70,10);
        glVertex3f(235,70,-15);
    glEnd();
    glColor3f(0,1,1);
    glBegin(GL_QUADS);
        glVertex3f(225,-50,-21);
        glVertex3f(235,-50,-15);
        glVertex3f(235,70,-15);
        glVertex3f(225,70,-21);
    glEnd();*/

    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'W':
            glTranslatef(0.0,0.0,3.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(3.0,0.0,0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0,0.0,-3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0,0.0,0.0);
            break;
        case '7':
            glTranslatef(0.0,3.0,0.0);
            break;
        case '9':
            glTranslatef(0.0,-3.0,0.0);
            break;
        case '2':
            glRotatef(2.0,1.0,0.0,0.0);
            break;
        case '8':
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
        case '6':
            glRotatef(2.0,0.0,1.0,0.0);
            break;
        case '4':
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
        case '1':
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        case '3':
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        case '5':
            if(is_depth){
                is_depth=0;
                glDisable(GL_DEPTH_TEST);
            } else{
                is_depth=1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    } else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x-xdiff;
        xrot = y+ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(130.0, lebar/tinggi,5.0,1000.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
