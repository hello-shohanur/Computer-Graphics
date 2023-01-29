/**
 * Lab-01
 * Drawing a straight line
 * Author: @shohan
 * GitHub: https://github.com/shohan-cse/Computer-Graphics
 */

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display(){
//clear the frame buffer
glClear(GL_COLOR_BUFFER_BIT);

//Draw line
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
    glVertex2i(5,5);
    glVertex2i(15,10);
glEnd();

//display the content of frame buffer
glFlush();
}

void init(){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); //to avoid transformation rotation
        gluOrtho2D(0.0f,20.0f,0.0f,20.0f);
        glClearColor(0.39f, 0.19f, 0.0f, 0.0f);
        glMatrixMode(GL_MODELVIEW);
    }

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100,200);
    glutInitWindowSize(500,500);

    glutCreateWindow("PC-F");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}
