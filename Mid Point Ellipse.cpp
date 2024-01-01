#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>

int width = 800;
int height = 600;

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void ellipseMidPoint(int rx, int ry, int xc, int yc) {
    int x = 0;
    int y = ry;

    float d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;

    while (dx < dy) {
        setPixel(x + xc, y + yc);
        setPixel(-x + xc, y + yc);
        setPixel(x + xc, -y + yc);
        setPixel(-x + xc, -y + yc);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    float d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        setPixel(x + xc, y + yc);
        setPixel(-x + xc, y + yc);
        setPixel(x + xc, -y + yc);
        setPixel(-x + xc, -y + yc);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int rx = 150;
    int ry = 100;
    int xc = width / 2;
    int yc = height / 2;

    ellipseMidPoint(rx, ry, xc, yc);

    glFlush();
}

void reshape(int w, int h) {
    width = w;
    height = h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Mid-Point Ellipse Drawing Algorithm");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(2.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
