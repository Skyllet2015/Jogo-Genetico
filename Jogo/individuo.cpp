/* 
 * File:   individuo.cpp
 * Author: jsouza
 * 
 * 
 */

#include "individuo.hpp"

individuo* individuo::inicializa(int tam) {
    individuo* novo = new individuo();
    novo->balanceamento = 0;
    novo->tamanho = tam;

    vector<vector<int> > aux(tamanho);
    srand(time(NULL));
    int cont = 0;
    int linha;
    int coluna;

    while (cont < tamanho) {
        linha = rand() % tamanho;
        coluna = rand() % tamanho;
        if (aux[linha][coluna] == 0) {
            aux[linha][coluna] = 1;
            cont++;
        }
    }
    novo->matrix = aux;
    return novo;
};


int individuo::getBalanceamento() {
    return this->balanceamento;
}

int individuo::getTamanho() {
    return this->tamanho;
}

void individuo::setBalanceamento(int novoBalanceamento) {
    this->balanceamento = novoBalanceamento;
}

bool individuo::operator<(individuo* i) {
    if (this->vermelhos < i->vermelhos) {
        return true;
    } else if (this->vermelhos == i->vermelhos) {
        return (this->clicados < i->clicados);
    } else {
        return false;
    }
}

individuo::~individuo() {
    this->balanceamento = 0;
    this->tamanho = 0;
    this->matrix.clear();
}