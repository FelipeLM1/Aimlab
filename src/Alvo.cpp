#include "Alvo.h"
#include <stdio.h>
#include <GL/glut.h>
#include "Ponto.h"
#include <string>
using namespace std;

Alvo::Alvo(double tamanho, double rgb[3])
{
    this->tamanho = tamanho;
    this->corRgb[0] = rgb[0];
    this->corRgb[1] = rgb[1];
    this->corRgb[2] = rgb[2];
}

void Alvo::desenhaAlvo(Ponto& centro, double tamanho)
{
    glColor3f (this->getRed(),this->getGreen(),this->getBlue());
    glBegin(GL_POLYGON);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()-tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()+tamanho/2, centro.getY()-tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()+tamanho/2, centro.getY()+tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()+tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()-tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()-tamanho/2, centro.getZ()+tamanho/2);
        glVertex3f(centro.getX()+tamanho/2, centro.getY()-tamanho/2, centro.getZ()+tamanho/2);
        glVertex3f(centro.getX()+tamanho/2, centro.getY()+tamanho/2, centro.getZ()+tamanho/2);    
        glVertex3f(centro.getX()-tamanho/2, centro.getY()+tamanho/2, centro.getZ()+tamanho/2);  
        glVertex3f(centro.getX()-tamanho/2, centro.getY()-tamanho/2, centro.getZ()+tamanho/2); 
        glVertex3f(centro.getX()+tamanho/2, centro.getY()+tamanho/2, centro.getZ()-tamanho/2); 
        glVertex3f(centro.getX()+tamanho/2, centro.getY()+tamanho/2, centro.getZ()+tamanho/2); 
        glVertex3f(centro.getX()+tamanho/2, centro.getY()-tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()+tamanho/2, centro.getY()-tamanho/2, centro.getZ()+tamanho/2);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()+tamanho/2, centro.getZ()-tamanho/2);
        glVertex3f(centro.getX()-tamanho/2, centro.getY()+tamanho/2, centro.getZ()+tamanho/2);
    glEnd();

}

double Alvo::getTamanho()
{
    return this->tamanho;
}

double Alvo::getRed()
{
    return this->corRgb[0];
}

double Alvo::getGreen()
{
    return this->corRgb[1];
}

double Alvo::getBlue()
{
    return this->corRgb[2];
}

void Alvo::setRGB(double red, double green, double blue){
    this->setRed(red);
    this->setGreen(green);
    this->setBlue(blue);
}

void Alvo::setTamanho(double tamanho)
{
    this->tamanho = tamanho;
}

void Alvo::setRed(double red)
{
    if (red < 1 && red >= 0)
        this->corRgb[2] = red;
}

void Alvo::setGreen(double green)
{
    if (green < 1 && green >= 0)
        this->corRgb[2] = green;
}

void Alvo::setBlue(double blue)
{
    if (blue < 1 && blue >= 0)
        this->corRgb[2] = blue;
}
