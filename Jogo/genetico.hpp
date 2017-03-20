/* 
 * File:   genetico.hpp
 * Author: jsouza
 *
 * 
 */

#ifndef GENETICO_HPP
#define GENETICO_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "individuo.hpp"

using namespace std;
class genetico {
public:
    void cGenetico(int tamMatriz, int popInicial, int porcentMelhores);
    void popular(int tamMatriz, int popInicial);
    void selecao(int porcentMelhores);
    void imprimirPopulacao(); 
    int getTamPopulacao();
    
    virtual ~genetico();
    
    friend class individuo;
private:
    int tamMatriz;
    int porcentMelhores;
    int popInicial;
    vector<individuo*> populacao;
};

#endif /* GENETICO_HPP */