#ifndef GRID_ALVOS_H_INCLUDED
#define GRID_ALVOS_H_INCLUDED
#include <vector>

#include "Alvo.h"

class GridAlvos
{
private:
    std::vector<std::vector<Alvo>> alvos;
    int numLinhas;
    int numColunas;

public:
    GridAlvos(std::vector<std::vector<Alvo>> alvos);
    int getNumLinhas();
    void setNumLinhas(int setNumLinhas);

    int getNumColunas();
    void setNumColunas(int numColunas);

    std::vector<std::vector<Alvo>> getAlvos();
    void setAlvos(std::vector<std::vector<Alvo>> alvos);
    static GridAlvos criarGrid(int numAlvos, int numLinhas);
    void ativaAlvo(int i, int j);
    void desativaAlvo(int i, int j);
};
#endif