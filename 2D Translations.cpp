#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

float polygonVertices[][2] = {{-0.4, -0.4}, {0.4, -0.4}, {0.4, 0.4}, {-0.4, 0.4}};
int numVertices = 4;
float tx = 0.0, ty = 0.0;
float angle = 0.0;
float sx = 1.0, sy = 1.0;
float shearX = 0.0, shearY = 0.0;

void drawPolygon(){
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++){
        glVertex2f(polygonVertices[i][0], polygonVertices[i][1]);
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(tx, ty, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(sx, sy, 1.0);
    glMultMatrixf(new GLfloat[16] {
        1.0, shearX, 0.0, 0.0,
        shearY, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    });
    glColor3f(1.0, 1.0, 1.0);
    drawPolygon();
    glFlush();
}
void menu(int choice){
    switch (choice){
        case 1:
            cout << "Enter translation values (dx dy): ";
            cin >> tx >> ty;
            break;
        case 2:
            cout << "Enter rotation angle (degrees): ";
            cin >> angle;
            break;
        case 3:
            cout << "Enter scaling factors (sx sy): ";
            cin >> sx >> sy;
            break;
        case 4:
            cout << "Enter shear factors (ShearX ShearY): ";
            cin >> shearX >> shearY;
            break;
        case 5:
            tx = ty = angle = 0.0;
            sx = sy = 1.0;
            shearX = shearY = 0.0;
            break;
        case 6:
            exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Polygon Transformation");
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Shear", 4);
    glutAddMenuEntry("Reset", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
