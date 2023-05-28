#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int r = 171;
int g = 81;
int b = 54;
int x_inc = 0, y_inc = 0;

//void init() {
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0.0, 40.0, 0.0, 40.0);
//    glMatrixMode(GL_MODELVIEW);
//}

void reshape(int w, int h) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float h2wRatio = (float)h/(float)w;
    float w2hRatio = (float)w/(float)h;
    if(w <= h)
        gluOrtho2D(0, 40, 0, 40*h2wRatio);
    else
        gluOrtho2D(0, 40*w2hRatio, 0, 40);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int w, int h) {
    switch(key) {
        case 27:
            exit(0);
            break;
        case 'F':
        case 'f':
            glutFullScreen();
            break;
        case 'm':
        case 'M':
            glutPositionWindow(700, 100);
            glutReshapeWindow(600, 600);
            break;
        case 'r':
        case 'R':
            r = 255;
            g = 0;
            b = 0;
            glutPostRedisplay();
            break;
        case 'g':
        case 'G':
            r = 0;
            g = 255;
            b = 0;
            glutPostRedisplay();
            break;
        case 'b':
        case 'B':
            r = 0;
            g = 0;
            b = 255;
            glutPostRedisplay();
            break;

            case 'c':
            case 'C':
                x_inc = 7;
                y_inc = -7;
                glutPostRedisplay();
                break;
    }
    if(key == 27) exit(0);

}
void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glColor3ub(95, 86, 79);
    glBegin(GL_TRIANGLES);
        glVertex2i(4+x_inc, 12+y_inc);
        glVertex2i(10+x_inc, 17+y_inc);
        glVertex2i(16+x_inc, 12+y_inc);
    glEnd();

    glColor3ub(r, g, b);
    glRecti(6, 4, 14, 12);

    glColor3ub(29, 43, 82);
    glRecti(8, 4, 12, 8);
    //display the frame buffer
    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 600);


    glutCreateWindow("Reshape");
    glutDisplayFunc(display);
    //init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}