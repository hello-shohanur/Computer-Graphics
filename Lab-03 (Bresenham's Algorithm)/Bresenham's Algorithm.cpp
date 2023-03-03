#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>

float x1, x2, y1, y2, p;
int dx, dy;

void display();
void init();

int main(int argc, char** argv){

    printf("Enter first point (coordinate): \n");
    scanf("%f", &x1);
    scanf("%f", &y1);

    printf("Enter second point (coordinate): \n");
    scanf("%f", &x2);
    scanf("%f", &y2);
    dy = y2 - y1;
    dx = x2 - x1;

    p = 2 * dy -dx;

    printf("P\tX\tY\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Lab-3: implementation of Bresenham's algorithm ");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}


void display(){

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //we will draw here
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(3);
    glBegin(GL_POINTS);
    while(x1 <= x2){
        glVertex2f(x1,y1);
        printf("%.2f\t%.2f\t%.2f\n", p, x1, y1);
        x1+=.5;
        if(p < 0 ){
            p = p + 2 * dy;
        }
        else{
            p = p + 2 * dy - 2 * dx;
            y1+=.5;
        }
    }
    glEnd();
    //display the frame buffer
    glFlush();

}


void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 60.0, 0.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
}
