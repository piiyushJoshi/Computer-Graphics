#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int xmin, ymin, xmax, ymax;

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void drawLine(int x1, int y1, int x2, int y2){
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void Algo(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax){
    float t1 = 0.0, t2 = 1.0;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};
    for (int i = 0; i < 4; i++){
        if (p[i] == 0){
            if (q[i] < 0)
                return;
        }
        else{
            float t = q[i] / p[i];
            if (p[i] < 0){
                if (t > t2)
                    return;
                if (t > t1)
                    t1 = t;
            }
            else{
                if (t < t1)
                    return;
                if (t < t2)
                    t2 = t;
            }
        }
    }

    int x1c = x1 + t1 * dx;
    int y1c = y1 + t1 * dy;
    int x2c = x1 + t2 * dx;
    int y2c = y1 + t2 * dy;
    drawLine(x1c, y1c, x2c, y2c);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawLine(x1, y1, x2, y2);
    glColor3f(1.0, 0.0, 0.0);
    Algo(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    glFlush();

}

int main(int argc, char** argv){
    cout << "Enter coordinates of the line (x1 y1 x2 y2): "<<endl;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter coordinates of the clipping window (xmin ymin xmax ymax): "<<endl;
    cin >> xmin >> ymin >> xmax >> ymax;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("N-L-N Line Clipping Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
