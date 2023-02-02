//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void init();

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);


    glutCreateWindow("Section: PC-F");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //we will draw here
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glLineWidth(5);
    for(int i=1; i<20; i++){

    glLineWidth(i);
    glBegin(GL_LINES);

     glVertex2f(10, i);
     glVertex2f(20, i);
     glEnd();
    }
    //display the frame buffer
    glFlush();

}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
