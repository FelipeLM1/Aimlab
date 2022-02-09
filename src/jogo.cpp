#include "GridAlvos.h"
#include <chrono>
#include <thread>
#include <random>
#include <iostream>
#include "jogo.h"


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void iniciarJogo(int numAlvos,int numLinha){
    GridAlvos g = GridAlvos::criarGrid(numAlvos,numLinha);
    iniciarRegras(g);

}

void iniciarRegras(GridAlvos gridAlvo){
     
        gerarAlvoAleatorio(gridAlvo);

}

void gerarAlvoAleatorio(GridAlvos gridAlvo){
    
    gridAlvo.ativaAlvo(2,2);
     
}


