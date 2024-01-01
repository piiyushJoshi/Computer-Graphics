#include <bits/stdc++.h>
#include <GL/glut.h>

void init (void){
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
void lineSegment (void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
    glVertex3f(0.25,0.20,0.0);
    glVertex3f(0.25,0.70,0.0);
    glVertex3f(0.5,0.95,0.0);
    glVertex3f(0.75,0.70,0.0);
    glVertex3f(0.75,0.20,0.0);

    glEnd ( );
    glFlush ( );
}
int main (int argc, char** argv){
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (1000, 600);
    glutCreateWindow ("211397 Computer Graphics Lab 1");
    init ( );
    glutDisplayFunc (lineSegment);
    glutMainLoop ( );
    return 0;
}
