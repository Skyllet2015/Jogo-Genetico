/* 
 * File:   individuo.hpp
 * Author: jsouza
 *
 * 
 */

#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class individuo {
public:
    individuo();
    void inicializa(int);
    void preencher();
    
    int getBalanceamento();
    int getTamanho();
    
    void setBalanceamento(int); 
    void imprimir();
    
    bool operator<(individuo* i);
    
    virtual ~individuo();
    
    friend class genetico;
private:
    int balanceamento;
    int vermelhos;
    int clicados;
    int tamanho;
    vector<vector<int> > matrix;
};

#endif /* INDIVIDUO_HPP */

