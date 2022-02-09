#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED


class Ponto
{
private:
    double x;
    double y;
    double z;

public:
    Ponto();
    Ponto(double x, double y, double z);

    double getX();
    double getY();
    double getZ();
    void setXYZ(double x,double y,double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
};
#endif