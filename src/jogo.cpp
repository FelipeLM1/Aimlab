#include "GridAlvos.h"
#include <chrono>
#include <thread>
#include <random>
#include <iostream>
#include "jogo.h"
#include <GL/glut.h>

enum botaoMouse
{
    BOTAO_ESQUERDO = 0,
    BOTAO_MEIO = 1,
    BOTAO_DIREITO = 2
};

GridAlvos gridAlvos = GridAlvos();

GridAlvos *iniciarJogo(int numAlvos, int numLinha)
{
    gridAlvos = gridAlvos.criarGrid(numAlvos, numLinha);

    iniciarRegras(gridAlvos);
    return &gridAlvos;
}

void rodarJogo(GridAlvos grid)
{
    gridAlvos = grid;
    gridAlvos.atualizaGrid();
}

void iniciarRegras(GridAlvos gridAlvo)
{
    gerarAlvoAleatorio(gridAlvo);
}

void click(int b, int estado, int x, int y)
{

    if (b == botaoMouse::BOTAO_ESQUERDO)
    {
        atirar(x, y);
    }
}

void atirar(int x, int y)
{
    float pixel[4] = {0};
    glReadPixels(x, y, 1, 1, GL_RGBA, GL_FLOAT, pixel);
    float r = pixel[0];
    float g = pixel[1];
    float b = pixel[2];
    float a = pixel[3];

    bool rAlvo = r > 0.5;
    bool gAlvo = g > 0.5;
    bool bAlvo = b == 0;

    if (rAlvo && gAlvo && bAlvo)
    {
        std::cout << "Alvo atingido!\n";
        atingirAlvo();
    }
}

void atingirAlvo()
{   
    Ponto posicaoAlvoAtingido = gridAlvos.getPosicaoAlvoAtivo();
    
    gridAlvos.desativaAlvo(posicaoAlvoAtingido.getX(), posicaoAlvoAtingido.getY());
    ativaNovoAlvo(posicaoAlvoAtingido.getX(), posicaoAlvoAtingido.getY());
}

void ativaNovoAlvo(int iAntes, int jAntes)
{
    int i = rand() % gridAlvos.getNumLinhas();
    int j = rand() % gridAlvos.getNumColunas();
    Alvo novoAlvo = gridAlvos.getAlvos()[i][j];
    novoAlvo.setAtivo(true);
    gridAlvos.setAlvoPosicao(&novoAlvo, i, j);
    gridAlvos.setPosicaoAlvoAtivo(Ponto(i, j, 0));
}

void gerarAlvoAleatorio(GridAlvos gridAlvo)
{
    Alvo alvo = gridAlvo.getAlvos()[2][2];
    gridAlvo.setAlvoPosicao(&alvo, 2, 2);
}
