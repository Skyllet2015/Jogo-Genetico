/* 
 * File:   Individuo.cpp
 * Author: jsouza
 * 
 * Created on 25 de Março de 2017, 00:23
 */

#include "Individuo.hpp"

void Individuo::inicializar(int tamanho) {
    this->tamanho = tamanho;
    this->clicados = 0;
    vector< vector<int> > aux(tamanho, vector<int>(tamanho));
    this->matriz = aux;
    preencher();
}

void Individuo::preencher() {
    srand(time(NULL));
    int linha, coluna, cont = 0;
    while (cont < tamanho) {
        linha = rand() % tamanho;
        coluna = rand() % tamanho;
        if (matriz[linha][coluna] == 0) {
            matriz[linha][coluna] = 1;
            cont++;
        }
    }
}

void Individuo::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        cout << endl;
        for (int j = 0; j < tamanho; j++) {
            if(matriz[i][j] == 1){
                cout<<"[X]";
            }else{
                cout<<"[ ]";
            }
        }
    }
}

int Individuo::getBalanceamento() {
    return this->balanceamento;
}

int Individuo::getTamanho() {
    return this->tamanho;
}

void Individuo::setBalanceamento(int novo) {
    this->balanceamento = novo;
}

bool Individuo::operator<(Individuo* i) {
    if (this->vermelhos < i->vermelhos) {
        return true;
    } else if (this->vermelhos == i->vermelhos) {
        return (this->clicados < i->clicados);
    } else {
        return false;
    }
}