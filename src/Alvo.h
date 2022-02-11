#ifndef ALVO_H_INCLUDED
#define ALVO_H_INCLUDED
#include "Ponto.h"

class Alvo
{
private:
  double tamanho;
  double corRgb[4] = {};
  Ponto centro;
  bool ativo;

  void setAlfa(double alfa);

public:
  // construtor
  Alvo();
  Alvo(double tamanho, double rgb[3]);
  Alvo(double tamanho, double rgb[3], Ponto centro);
  ~Alvo();
  void desenhaAlvo(Ponto &centro, double tamanho);

  // getters
  double getTamanho();
  double getRed();
  double getGreen();
  double getBlue();
  double getAlfa();
  Ponto getCentro();
  bool isAtivo();

  // setters
  void setRGB(double red, double green, double blue);
  void setTamanho(double tamanho);
  void setRed(double red);
  void setGreen(double green);
  void setBlue(double blue);
  void setCentro(Ponto centro);
  void setAtivo(bool ativo);
};
#endif