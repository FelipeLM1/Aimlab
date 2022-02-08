#ifndef ALVO_H_INCLUDED
#define ALVO_H_INCLUDED
#include "Ponto.h"

class Alvo {       
  private:             
    double tamanho;        
    double corRgb[3] = {};  

    public:

        Alvo(double tamanho, double rgb[3]);
        
        void desenhaAlvo(Ponto& centro, double tamanho);
        double getTamanho();
        double getRed();
        double getGreen();
        double getBlue();
        void setRGB(double red, double green, double blue);
        void setTamanho(double tamanho);
        void setRed(double red);
        void setGreen(double green);
        void setBlue(double blue);


};
#endif