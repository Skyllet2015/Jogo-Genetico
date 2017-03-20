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
    individuo* inicializa(int);
    void preencher(int);
    
    int getBalanceamento();
    int getTamanho();
    
    void setBalanceamento(int); 
    
    bool operator<(individuo* i);
    
    virtual ~individuo();
    
    friend class genetico;
private:
    int balanceamento;
    int vermelhos;
    int clicados;
    int tamanho;
    vector<vector<int>> matrix = vector<vector<int>> (getTamanho());
};

#endif /* INDIVIDUO_HPP */

