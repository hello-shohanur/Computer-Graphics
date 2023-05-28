#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

int red= 172;
int green= 91;
int blue= 54;

int x_inc=0;
int y_inc=0;

double l=0, m=0;

void keyboard(unsigned char key, int w, int h)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
    case 'A':
        l-=1;
        glutPostRedisplay();
        break;
    case 'd':
    case 'D':
        l+=1;
        glutPostRedisplay();
        break;
    case 'w':
    case 'W':
        m+=1;
        glutPostRedisplay();
        break;
    case 's':
    case 'S':
        m-=1;
        glutPostRedisplay();
        break;
    }
}

void init();

#define NUM_SEGMENTS 100

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for(int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //we will draw here

   glBegin(GL_POLYGON);
   glColor3ub(green, blue, red);
  glVertex3i(3+l, 5+m, 0);
  glVertex3i(3+l, 8+m, 0);
  glVertex3i(7+l, 15+m, 0);
  glVertex3i(25+l, 15+m, 0);
  glVertex3i(29+l, 9+m, 0);
  glVertex3i(32+l, 9+m, 0);
  glVertex3i(32+l, 5+m, 0);

  glEnd();

   glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3i(7+l , 9+m, 0);
  glVertex3i(7+l, 13+m, 0);
  glVertex3i(14+l, 13+m, 0);
  glVertex3i(14+l, 9+m, 0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3i(16+l, 9+m, 0);
  glVertex3i(16+l, 13+m, 0);
  glVertex3i(23+l, 13+m, 0);
  glVertex3i(23+l, 9+m, 0);
  glEnd();

    glColor3f(0.f, 0.f, 0.f);
    glLineWidth(2.0f);
    drawCircle(6+l, 5+m, 2.0f, NUM_SEGMENTS);
    drawCircle(25+l, 5+m, 2.0f, NUM_SEGMENTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(6+l, 5+m, 1.0f, NUM_SEGMENTS);
    drawCircle(25+l, 5+m, 1.0f, NUM_SEGMENTS);

    //display the frame buffer
    glFlush();

}

void reshape(int w, int h){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float h2wRatio = (float)h/(float)w;
    float w2hRatio = (float)w/(float)h;

    if(w<=h)
        gluOrtho2D(0.0, 50.0, 0.0, 50.0*h2wRatio);

    else
        gluOrtho2D(0.0*w2hRatio, 50.0, 0.0, 50.0);


    glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 600);


    glutCreateWindow("car");
    glutDisplayFunc(display);
    //init();
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();



    return 0;

}