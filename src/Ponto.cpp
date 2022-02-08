#include "Ponto.h"
#include <GL/glut.h>

Ponto::Ponto(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
double Ponto::getX()
{
    return this->x;
}
double Ponto::getY()
{
    return this->y;
}
double Ponto::getZ()
{
    return this->z;
}

void Ponto::setXYZ(double x,double y,double z){
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}
void Ponto::setX(double x)
{
    this->x = x;
}
void Ponto::setY(double y)
{
    this->y = y;
}
void Ponto::setZ(double z)
{
    this->z = z;
}