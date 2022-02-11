#ifndef REGRAS_H_INCLUDED
#define REGRAS_H_INCLUDED

#include "GridAlvos.h"

GridAlvos *iniciarJogo(int numLinha, int numAlvos);
void rodarJogo(GridAlvos gridAlvos);
void iniciarRegras(GridAlvos gridAlvo);
void click(int b, int estado, int x, int y);
void atirar(int x, int y);
void ativaNovoAlvo(int iAntes, int jAntes);
void atingirAlvo();

#endif