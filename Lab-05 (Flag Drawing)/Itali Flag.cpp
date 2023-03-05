#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>

void makeRectangle(int x1, int y1, int x2, int y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 150.0, 0.0, 90.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //draw the flag
    makeRectangle(0, 0, 50, 90, 0.0, 0.5, 0.0); //green
    makeRectangle(50, 0, 100, 90, 1.0, 1.0, 1.0); //white
    makeRectangle(100, 0, 150, 90, 1.0, 0.0, 0.0); //red

    //display the frame buffer
    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(750, 450);

    glutCreateWindow("Italian Flag");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
