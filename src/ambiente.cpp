#include <GL/glut.h>
#include "ambiente.h"
#include "Alvo.h"
#include "Ponto.h"

namespace gridPadrao
{
    double TAMANHO_ALVO = 2.5;
    double RGB_ALVOS[] = {1, 0.8, 0.9};
    double COORDENADAS_INICIAL[] = {-20.0,1.0,-30.0};
}

// criar classe ambiente e salvar as posições dos alvos para depois conseguir desativa-los

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

void gerarGridDeAlvos(int numAlvos, int numLinhas)
{
    Alvo *alvo = new Alvo(gridPadrao::TAMANHO_ALVO, gridPadrao::RGB_ALVOS);
    
    Ponto *ponto = new Ponto(gridPadrao::COORDENADAS_INICIAL[0],
    gridPadrao::COORDENADAS_INICIAL[1],gridPadrao::COORDENADAS_INICIAL[2]);
    
    double xInicio = ponto->getX();
    int numAlvosPorLinha = (numAlvos / numLinhas);
    for (int i = 0; i < numLinhas; i++)
    {
        ponto->setX(xInicio);
        for (int j = 0; j < numAlvosPorLinha; j++)
        {
            if(j>0){
                ponto->setX(ponto->getX() + gridPadrao::TAMANHO_ALVO*2);
            } 
        
            alvo->desenhaAlvo(*ponto, gridPadrao::TAMANHO_ALVO);
        }
        ponto->setY(ponto->getY() + gridPadrao::TAMANHO_ALVO*2);
    }
}