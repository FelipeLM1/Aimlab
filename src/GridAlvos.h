#ifndef GRID_ALVOS_H_INCLUDED
#define GRID_ALVOS_H_INCLUDED
#include <vector>

#include "Alvo.h"

class GridAlvos
{
private:
    std::vector<std::vector<Alvo>> alvos;
    Ponto posicaoAlvoAtivo;
    int numLinhas;
    int numColunas;

public:
    GridAlvos();
    GridAlvos(std::vector<std::vector<Alvo>> alvos);
    int getNumLinhas();
    void setNumLinhas(int setNumLinhas);

    void setAlvoPosicao(Alvo *alvo, int i, int j);

    int getNumColunas();
    void setNumColunas(int numColunas);

    Ponto getPosicaoAlvoAtivo();
    void setPosicaoAlvoAtivo(Ponto alvo);

    std::vector<std::vector<Alvo>> getAlvos();
    void setAlvos(std::vector<std::vector<Alvo>> alvos);
    GridAlvos criarGrid(int numAlvos, int numLinhas);
    void atualizaGrid();
    GridAlvos ativaAlvo(int i, int j);
    GridAlvos desativaAlvo(int i, int j);
};
#endif