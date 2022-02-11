#include <GL/glut.h>
#include "ambiente.h"
#include "Alvo.h"
#include "Ponto.h"

/**
 * @brief Desenha o piso do cenario.
 * 
 */
void desenharPiso()
{
    glEnable(GL_TEXTURE_2D);
    GLuint texture;
    glGenTextures(1,&texture);

    unsigned char texture_data[2][2][4] =
                    {
                        0,0,0,255,  255,255,255,255,
                        255,255,255,255,    0,0,0,255
                    };

    glBindTexture(GL_TEXTURE_2D,texture);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,texture_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0,0.0);  glVertex3f(-50.0,-5.0,-50.0);
    glTexCoord2f(25.0,0.0);  glVertex3f(50.0,-5.0,-50.0);
    glTexCoord2f(25.0,25.0);  glVertex3f(50.0,-5.0,50.0);
    glTexCoord2f(0.0,25.0);  glVertex3f(-50.0,-5.0,50.0);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

