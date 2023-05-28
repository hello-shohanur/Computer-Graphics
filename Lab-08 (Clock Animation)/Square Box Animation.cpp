#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define FORWARD 1
#define BACKWARD -1

float x_inc = 0;

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'W':
        case 'w':
            //some action
            glutPostRedisplay();
            break;

        case 'A':
        case 'a':
            x_inc--;
            glutPostRedisplay();
            break;

        case 'S':
        case 's':
            //some action
            glutPostRedisplay();
            break;

        case 'D':
        case 'd':
            x_inc++;
            glutPostRedisplay();
            break;

        default:
            //default task
            break;
    }
}

int state = FORWARD;
void timer(int value) {
    switch(state) {
        case FORWARD:
            if(x_inc < 60) x_inc++;
            else state = BACKWARD;
            break;
        case BACKWARD:
            if(x_inc > -10) x_inc--;
            else state = FORWARD;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //Square Box
    glColor3ub(255, 255, 0);
    glPushMatrix();
    glTranslatef(x_inc, 0, 0);
    glRectd(10, 10, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 80, 0, 60);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Square Box");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}