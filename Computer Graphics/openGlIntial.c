#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x, y;
float i, j;

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{
    for (j = 0; j < 10000; j += 0.01)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        for (i = 0;i < 6.29;i += 0.001)
        {
            x = 200 * cos(i);
            y = 200 * sin(i);
            glVertex2i(x/1.5, y/1.5);
            glVertex2i(x/4 - 200  * cos(j), y/4 - 200 * sin(j));
            glVertex2i(x/3 - 350  * cos(-j), y/3 - 350 * sin(-j));
            glVertex2i(x/4 - 470  * cos(j), y/4 - 470 * sin(j));
            glVertex2i(x/5 - 570  * cos(-j), y/5 - 570 * sin(-j));
        }
        glEnd();
        glFlush();
    }
}


int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1360, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Revolution");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
