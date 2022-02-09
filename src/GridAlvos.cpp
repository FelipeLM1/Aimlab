#include "GridAlvos.h"
#include "Ponto.h"
#include <vector>
#include <stdio.h>

using namespace std;

namespace gridPadrao
{
    double TAMANHO_ALVO = 2.5;
    double RGB_ALVOS[] = {1, 0.8, 0.9, 0};
    double COORDENADAS_INICIAL[] = {-20.0, 1.0, -30.0};
}

GridAlvos::GridAlvos(vector<vector<Alvo>>alvos){
    this->alvos = alvos;
}

GridAlvos GridAlvos::criarGrid(int numAlvos, int numLinhas)
{
    int numColunas = numAlvos / numLinhas;
    vector<vector<Alvo>> matrizAlvos(numLinhas, vector<Alvo>(numColunas));
    

    Alvo *alvo = new Alvo(gridPadrao::TAMANHO_ALVO, gridPadrao::RGB_ALVOS);

    Ponto *ponto = new Ponto(gridPadrao::COORDENADAS_INICIAL[0],
                             gridPadrao::COORDENADAS_INICIAL[1],
                             gridPadrao::COORDENADAS_INICIAL[2]);

    double xInicio = ponto->getX();
    for (int i = 0; i < numLinhas; ++i)
    {
        ponto->setX(xInicio);

        for (int j = 0; j < numColunas; ++j)
        {
            if (j > 0)
            {
                ponto->setX(ponto->getX() + gridPadrao::TAMANHO_ALVO * 2);
            }
            alvo->setCentro(*ponto);
            alvo->desenhaAlvo(*ponto, gridPadrao::TAMANHO_ALVO);
            matrizAlvos[i][j] = *alvo;
        }
        ponto->setY(ponto->getY() + gridPadrao::TAMANHO_ALVO * 2);
    }
    GridAlvos gridAlvos = GridAlvos(matrizAlvos);
    gridAlvos.setNumColunas(numColunas);
    gridAlvos.setNumLinhas(numLinhas);
    return gridAlvos;
}


vector<vector<Alvo>> GridAlvos::getAlvos()
{
    return this->alvos;
}
void GridAlvos::setAlvos(vector<vector<Alvo>>alvos)
{
    this->alvos = alvos;
}

int GridAlvos::getNumLinhas(){
    return this->numLinhas;
}

int GridAlvos::getNumColunas(){
    return this->numColunas;
}

void GridAlvos::setNumLinhas(int numLinhas){
    this->numLinhas = numLinhas;
}

void GridAlvos::setNumColunas(int numColunas){
    this->numColunas = numColunas;
}

void GridAlvos::ativaAlvo(int i, int j){
    
    Alvo alvo = alvos[i][j];
    alvo.setAtivo(true);
    Ponto p = alvo.getCentro();
    alvo.desenhaAlvo(p,alvo.getTamanho());
    alvos[i][j] = alvo;
}

void GridAlvos::desativaAlvo(int i, int j){
    this->alvos[i][j].setAtivo(false);
}