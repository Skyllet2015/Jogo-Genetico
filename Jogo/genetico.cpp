/* 
 * File:   genetico.cpp
 * Author: jsouza
 * 
 * 
 */

#include "genetico.hpp"
#include "individuo.hpp"

void genetico::cGenetico(int tamMatriz, int popInicial, int porcentMelhores) {
    this->populacao =  vector<individuo*> (popInicial);
    this->popular(tamMatriz, popInicial);
    /**
     * implantar algoritmo genetico
     */


    sort(populacao.begin(), populacao.end());
}

void genetico::popular(int tamMatriz, int popInicial) {
    if (this->populacao.size() < popInicial) {
        for (int i = this->populacao.size(); i < popInicial; i++) {
            individuo* ind = new individuo();
            ind->inicializa(tamMatriz);
            populacao.push_back(ind);
        }
    }
}

void genetico::selecao(int porcentMelhores) {
    int porcent = ((this->populacao.size() / porcentMelhores) * 100);
    this->populacao.erase(this->populacao.begin() + porcent, this->populacao.end());
}

void genetico::imprimirPopulacao(){
    for(int i = 0; i < this->populacao.size(); i++){
        this->populacao[i]->imprimir();
    }
}

genetico::~genetico() {
}

