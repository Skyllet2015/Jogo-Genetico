/* 
 * File:   individuo.cpp
 * Author: jsouza
 * 
 * 
 */

#include "individuo.hpp"

using namespace std;

void individuo::inicializa(int tam) {
    individuo* novo = new individuo();
    novo->balanceamento = 0;
    novo->tamanho = tam;
    vector<vector<int> > matrix(tam);
    novo->matrix = matrix;
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

void individuo::imprimir() {
    for (int i = 0; i< this->tamanho; i++) {
        cout<<endl;
        for (int j = 0; j< this->tamanho; j++) {
            cout<<this->matrix[i][j]<<" ";
        }
    }
}

individuo::~individuo() {

}

