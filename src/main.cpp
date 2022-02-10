#include <GL/glut.h>
#include "ambiente.h"
#include "Alvo.h"
#include "Ponto.h"
#include "camera.h"
#include "iluminacao.h"
#include "jogo.h"
#include <iostream>

const int width = 16 * 50;
const int height = 9 * 50;

int exec = 0;
GridAlvos *g;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    camera();
    desenharPiso();

    gerarIluminacao();
    rodarJogo(*g);
    glutSwapBuffers();
}

void init(void)
{
    /* select clearing color 	*/
    glClearColor(0.0, 0.0, 0.0, 0.0);
    g = iniciarJogo(50, 5);
    /* initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 16.0 / 9.0, 1, 75);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Aimlab");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(click);
    glutKeyboardUpFunc(keyboard_up);
    glutMainLoop();
    return 0;
}
