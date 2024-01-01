#include <windows.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void dda(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    if(dy<dx){
        int p0 = 2*dy - dx;
            int pk;
        for(int i=0;i<dx;i++){
            glBegin(GL_POINTS);
            if(pk<0){
                pk = p0 + 2*dy;
                x1++;
                glBegin(GL_POINTS);
                glVertex2d(x1, y1);
                glEnd();
                p0 = pk;
            }
            else{
                pk = p0 + 2*dy - 2*dx;
                x1++;
                y1++;
                glBegin(GL_POINTS);
                glVertex2d(x1, y1);
                glEnd();
                p0 = pk;
            }
            glEnd();
        }
    }
    else{
        int p0 = 2*dx - dy;
        for(int i=0;i<dy;i++){
            int pk;
            if(pk<0){
                pk = p0 + 2*dx;
                y1++;
                glBegin(GL_POINTS);
                glVertex2d(x1, y1);
                glEnd();
                p0 = pk;
            }
            else{
                pk = p0 + 2*dx - 2*dy;
                x1++;
                y1++;
                glBegin(GL_POINTS);
                glVertex2d(x1, y1);
                glEnd();
                p0 = pk;
            }
        }
    }
    glFlush();
}
void line(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    dda(100,120,600,300);
}
int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(640,480);
    glutCreateWindow("Bresenham’s Line Drawing Algorithm ");
    glutDisplayFunc(line);
    init();
    glutMainLoop();
    return 1;
}
