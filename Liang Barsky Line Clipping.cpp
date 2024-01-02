#include<windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

float xwmin = 100, ywmin = 100, xwmax = 300, ywmax = 300;
float x1, y1, x2, y2;  //50,350,350,50

bool clipLine(float x1, float y1, float x2, float y2, float &x3, float &y3, float &x4, float &y4){
    float t1 = 0.0, t2 = 1.0;
    float dx = x2 - x1, dy = y2 - y1;
    float p[4], q[4];

    p[0] = -dx;
    q[0] = x1 - xwmin;
    p[1] = dx;
    q[1] = xwmax - x1;
    p[2] = -dy;
    q[2] = y1 - ywmin;
    p[3] = dy;
    q[3] = ywmax - y1;

    for (int i = 0; i < 4; i++){
        if (p[i] == 0 && q[i] < 0)
            return false;
        if (p[i] != 0){
            float t = q[i] / p[i];
            if (p[i] < 0 && t1 <= t)
                t1 = t;
            else if (p[i] > 0 && t2 > t)
                t2 = t;
        }
    }



    if (t1 < t2) {
        x3 = x1 + t1 * dx;
        y3 = y1 + t1 * dy;
        x4 = x1 + t2 * dx;
        y4 = y1 + t2 * dy;
        return true;
    }
    else
        return false;

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    float x3, y3, x4, y4;
    if (clipLine(x1, y1, x2, y2, x3, y3, x4, y4)){
        glBegin(GL_LINES);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv){
    cout<<"Enter the values of x1 and y1: "<<endl;
    cin>>x1>>y1;
    cout<<"Enter the values of x2 and y2: "<<endl;
    cin>>x2>>y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Liang-Barsky Algorithm");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
