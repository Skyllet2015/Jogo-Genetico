/* 
 * File:   individuo.hpp
 * Author: jsouza
 *
 * 
 */

#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

#include <vector>
#include <iostream>

using namespace std;

class individuo {
public:
    void inicializa(int);
    int getBalanceamento();
    int getTamanho();
    
    void setBalanceamento(int); 
    void imprimir();
    
    virtual ~individuo();
    
    friend class genetico;
private:
    int balanceamento;
    int tamanho;
    vector<vector<int> > matrix;
};

#endif /* INDIVIDUO_HPP */

