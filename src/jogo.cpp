#include "GridAlvos.h"
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

/**
 * @brief inicia o jogo criando uma grid de alvos
 * 
 * @param numAlvos numero de alvos na grid
 * @param numLinha numero de linhas da grid
 * @return GridAlvos* 
 */
GridAlvos *iniciarJogo(int numAlvos, int numLinha)
{
    gridAlvos = gridAlvos.criarGrid(numAlvos, numLinha);
    return &gridAlvos;
}

/**
 * @brief atualiza o jogo redesenhando a grid
 * 
 * @param grid 
 */
void rodarJogo(GridAlvos grid)
{
    gridAlvos = grid;
    gridAlvos.atualizaGrid();
}
/**
 * @brief verifica se o clique dado foi no botao esquerdo, nesse caso
 * , chama a função atirar
 * 
 * @param b botão acionado
 * @param estado 
 * @param x posicao x
 * @param y posicao y
 */
void click(int b, int estado, int x, int y)
{

    if (b == botaoMouse::BOTAO_ESQUERDO)
    {
        atirar(x, y);
    }
}

/**
 * @brief verifica se o tiro dado acertou algum alvo, se acertar , chama a funcao
 * atingir alvo.
 * 
 * @param x 
 * @param y 
 */
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

/**
 * @brief desativa o alvo atingido e ativa um alvo aleatorio
 * 
 */
void atingirAlvo()
{
    Ponto posicaoAlvoAtingido = gridAlvos.getPosicaoAlvoAtivo();

    gridAlvos.desativaAlvo(posicaoAlvoAtingido.getX(), posicaoAlvoAtingido.getY());
    ativaNovoAlvo(posicaoAlvoAtingido.getX(), posicaoAlvoAtingido.getY());
}

/**
 * @brief sorteia um alvo do grid para ativá-lo, o novo alvo é diferente do 
 * que acabou de ser atingido
 * 
 * @param iAntes linha do alvo que acabou de ser atingido
 * @param jAntes coluna do alvo que acabou de ser atingido
 */
void ativaNovoAlvo(int iAntes, int jAntes)
{
    int i = rand() % gridAlvos.getNumLinhas();
    int j = rand() % gridAlvos.getNumColunas();
    while (i == iAntes && j == jAntes)
    {
        int i = rand() % gridAlvos.getNumLinhas();
        int j = rand() % gridAlvos.getNumColunas();
    }

    Alvo novoAlvo = gridAlvos.getAlvos()[i][j];
    novoAlvo.setAtivo(true);
    gridAlvos.setAlvoPosicao(&novoAlvo, i, j);
    gridAlvos.setPosicaoAlvoAtivo(Ponto(i, j, 0));
}
