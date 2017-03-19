/* 
 * File:   individuo.cpp
 * Author: jsouza
 * 
 * 
 */

#include "individuo.hpp"

individuo::individuo(){};

void individuo::inicializa(int tam) {
    individuo* novo = new individuo();
    novo->balanceamento = 0;
    novo->tamanho = tam;
    vector<vector<int> > matri(tam);
    novo->matrix = matri;
    novo->preencher();
};

void individuo::preencher() {
    srand((unsigned)time(0));
    int linha = rand() % this->tamanho;
    int coluna = rand() % this->tamanho;
    int pc = 30;
    int quantidade = 0;
    int porcent = (((this->tamanho * this->tamanho) / pc) * 100);

    do {
        if (this->matrix[linha][coluna] == 0) {
            this->matrix[linha][coluna] = 1;
            quantidade++;
        }
    } while (quantidade < porcent);

}

int individuo::getBalanceamento() {
    return this->balanceamento;
}

int individuo::getTamanho() {
    return this->tamanho;
}

void individuo::setBalanceamento(int novoBalanceamento) {
    this->balanceamento = novoBalanceamento;
}

void individuo::imprimir() {
    for (int i = 0; i< this->tamanho; i++) {
        cout << endl;
        for (int j = 0; j< this->tamanho; j++) {
            cout << this->matrix[i][j] << " ";
        }
    }
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