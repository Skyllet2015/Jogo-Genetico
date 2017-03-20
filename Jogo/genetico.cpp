/* 
 * File:   genetico.cpp
 * Author: jsouza
 * 
 * 
 */

#include "genetico.hpp"
#include "individuo.hpp"

void genetico::cGenetico(int tamMatriz, int popInicial, int porcentMelhores) {
    this->tamMatriz = tamMatriz;
    this->popInicial = popInicial;
    this->porcentMelhores = porcentMelhores;
    this->popular(tamMatriz, popInicial);
    /**
     * implantar algoritmo genetico
     */
    sort(populacao.begin(), populacao.end());
}

int genetico::getTamPopulacao() {
    return this->populacao.size();
}

void genetico::popular(int tamMatriz, int popInicial) {
    individuo* ind = new individuo();
    if (this->populacao.size() < popInicial) {
        for (int i = this->populacao.size(); i < popInicial; i++) {
            populacao.push_back(ind->inicializa(tamMatriz));
        }
    }
}

void genetico::selecao(int porcentMelhores) {
    int porcent = ((this->populacao.size() / porcentMelhores) * 100);
    this->populacao.erase(this->populacao.begin() + porcent, this->populacao.end());
}

void genetico::imprimirPopulacao() {
    cerr << "Imprimindo População!" << endl;
    for (individuo* ind : this->populacao) {
        for (int i = 0; i < this->tamMatriz; i++) {
            for (int j = 0; j < this->tamMatriz; j++) {
                cerr << ind->matrix[i][j] << " ";
            }
        }
    }
}


genetico::~genetico() {
}

