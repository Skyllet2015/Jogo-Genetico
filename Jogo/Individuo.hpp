/* 
 * File:   Individuo.hpp
 * Author: jsouza
 *
 * Created on 31 de Março de 2017, 22:50
 */

#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Individuo {
public:
    Individuo(int tam, int ger);
    void preencher();
    bool clicar(int linha, int coluna);
    void balancear();
    Individuo* cruzar(Individuo* ind);    
    
    bool operator<(Individuo* ind);
    
    void imprimirAtributos();
    void imprimirMatriz();
    
    virtual ~Individuo();
    
    friend class Genetico;
private:
    int vermelhos;
    int clicados;
    int tamanho;
    int balanceamento;
    int geracao;
    vector<vector<int> > matrizClic;
    vector<vector<int> > matrizCores;
    
};

#endif /* INDIVIDUO_HPP */

