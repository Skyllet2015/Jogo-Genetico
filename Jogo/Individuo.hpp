
/* 
 * File:   Individuo.hpp
 * Author: jsouza
 *
 */

#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Individuo {
public:
    void inicializar(int tamanho);
    void preencher();
    void imprimir();
    
    int getTamanho();
    int getBalanceamento();
    
    void setBalanceamento(int novo);
    
    bool operator<(Individuo* i);
private:
    int balanceamento;
    int clicados;
    int tamanho;
    int vermelhos;
    vector<vector<int> > matriz;

};

#endif /* INDIVIDUO_HPP */

