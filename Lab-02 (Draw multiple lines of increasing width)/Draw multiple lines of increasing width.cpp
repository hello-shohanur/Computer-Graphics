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


    glutCreateWindow("PC-F Section");
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
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(5);

/*
    //==>> Using GL Lines:

    glBegin(GL_LINES);
        glVertex2f(5, 5);
        glVertex2f(15, 10);

        //glColor3ub(31, 138, 112); // For long project we should use this color system
        //glColor3f(0.52f, 0.37f, 0.26f); //Changing colors of straight line;
        //glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(7, 7);
        glVertex2f(17, 12);

        glColor3f(1.0f, 1.0f, 1.0f);
//        glVertex2f(7, 7);
//        glVertex2f(17, 8);

*/

/*
    //==>> Using GL Strip:

    glBegin(GL_LINE_STRIP);

        glVertex2f(10, 10);
        glVertex2f(15, 15);
         glVertex2f(15, 20);
        glVertex2f(15, 25);
         glColor3f(0.40f, 0.30f, 0.0f);
        glVertex2f(7, 7);
        glVertex2f(17, 12);

*/

/*
    //==>> Using GL Points:

    for(int i=0; i < 15; ++i){

    glPointSize(i);
    glBegin(GL_POINTS);

        glVertex2f(10, i);

         glColor3f(0.40f, 0.30f, 0.0f);
//        glVertex2f(7, 7);
//        glVertex2f(17, 12);

*/


/*
    //==>> Using GL Lines (Increment):

    for(int i=1; i < 15; ++i){

    glLineWidth(i);
    glBegin(GL_LINES);

        glVertex2f(10, i);
        glVertex2f(30, i);

         glColor3f(0.50f, 0.60f, 0.0f);
//        glVertex2f(7, 7);
//        glVertex2f(17, 12);

*/

    glBegin(GL_TRIANGLES);
    glVertex2i(10, 10);
    glVertex2i(30, 10);
    glVertex2i(15, 20);


    glEnd();

    //display the frame buffer
    glFlush();

}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}
