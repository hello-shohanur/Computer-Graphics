#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define FORWARD 1
#define BACKWARD -1

float angle = 0;

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'W':
        case 'w':
            //some action
            glutPostRedisplay();
            break;

        case 'A':
        case 'a':
            angle++;
            glutPostRedisplay();
            break;

        case 'S':
        case 's':
            //some action
            glutPostRedisplay();
            break;

        case 'D':
        case 'd':
            angle--;
            glutPostRedisplay();
            break;

        default:
            //nothing
            break;
    }
}

void drawGrid(double x_min, double x_max, double y_min, double y_max) {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_LINES);
    for (double i = x_min; i <= x_max; ++i) {
        glVertex2d(i, y_min);
        glVertex2d(i, y_max);
    }

    for (double j = y_min; j <= y_max; ++j) {
        glVertex2d(x_min, j);
        glVertex2d(x_max, j);
    }
    glEnd();
}

void drawCircle(double r, double x_center, double y_center, int fillValue) {
    double deg = 0, theta, x, y;
    glPointSize(2);
    if(fillValue == 1) {
        glBegin(GL_TRIANGLE_FAN) ;
        glVertex2d(x_center, y_center);
    } else {
        glBegin(GL_POINTS);
    }
    while (deg < 360) {
        // theta values in radian
        theta = (deg * M_PI) / 180;
        x = x_center + r * cos(theta);
        y = y_center + r * sin(theta);
        glVertex2d(x, y);
        deg += 0.5;
    }
    glEnd();
}

int state = FORWARD;
void timer(int value) {
    switch(state) {
        case FORWARD:
            if(angle < 30) angle++;
            else state = BACKWARD;
            break;
        case BACKWARD:
            if(angle > -30) angle--;
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
    glLineWidth(1);
    drawGrid(0, 40, 0, 30);
    glLineWidth(0.5);
    //drawGrid(0, 160, 0, 120);
    glColor3ub(38, 242, 167);
    drawCircle(3, 20, 18, 0);
    glColor3ub(0, 0, 0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2d(20, 18);
    glVertex2d(20, 20.5);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2d(20, 18);
    glVertex2d(22.5, 18);
    glEnd();
    glColor3ub(198, 181, 25);
    glLineWidth(3);
    glPushMatrix();
    glTranslatef(20, 15, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-20, -15, 0);
    glBegin(GL_LINES);
    glVertex2d(20, 15);
    glVertex2d(20, 11);
    glEnd();
    drawCircle(0.5, 20, 10.5, 1);
    glPopMatrix();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 40, 0, 30);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Clock");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    init();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}