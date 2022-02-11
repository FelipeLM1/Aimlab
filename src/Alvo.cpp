#include "Alvo.h"
#include <GL/glut.h>
#include "Ponto.h"
using namespace std;

Alvo::Alvo(double tamanho, double rgb[3])
{
    this->tamanho = tamanho;
    this->corRgb[0] = rgb[0];
    this->corRgb[1] = rgb[1];
    this->corRgb[2] = rgb[2];
    this->corRgb[3] = rgb[3];
    this->centro = centro;
    this->ativo = false;
}
Alvo::Alvo() {}
Alvo::~Alvo(){}; 

Alvo::Alvo(double tamanho, double rgb[3], Ponto centro)
{
    this->tamanho = tamanho;
    this->corRgb[0] = rgb[0];
    this->corRgb[1] = rgb[1];
    this->corRgb[2] = rgb[2];
    this->corRgb[3] = 0;
    this->centro = centro;
    this->ativo = false;
}
/**
 * @brief desenha um cubo com posição e tamanho definido nos parametros.
 * 
 * @param centro posicao do centro do alvo
 * @param tamanho tamanho do alvo
 */
void Alvo::desenhaAlvo(Ponto &centro, double tamanho)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(this->getRed(), this->getGreen(), this->getBlue(), this->getAlfa());
    glBegin(GL_POLYGON);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() + tamanho / 2, centro.getY() - tamanho / 2, centro.getZ() + tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() - tamanho / 2);
    glVertex3f(centro.getX() - tamanho / 2, centro.getY() + tamanho / 2, centro.getZ() + tamanho / 2);
    glEnd();

    glDisable(GL_BLEND);
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

double Alvo::getAlfa()
{
    return this->corRgb[3];
}

Ponto Alvo::getCentro()
{
    return this->centro;
}

bool Alvo::isAtivo()
{
    return this->ativo;
}

void Alvo::setRGB(double red, double green, double blue)
{
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

void Alvo::setAlfa(double alfa)
{
    this->corRgb[3] = alfa;
}

void Alvo::setCentro(Ponto centro)
{
    this->centro = centro;
}

void Alvo::setAtivo(bool ativo)
{
    this->ativo = ativo;
    ativo ? this->setAlfa(1.0) : this->setAlfa(0);
}
