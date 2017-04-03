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

#include "Individuo.hpp"

using namespace std;
class Genetico {
public:
    Genetico(int matriz, int popInicial, int elite, int mutacao, int geracoes);
    void gerarPopulacao();
    bool avaliarPopulacao();
    void crossover();
    void mutacao();
    void eliminarNaoElite();
    void imprimirPopulacao();
    void ordenar();
    
    friend class Individuo;
private:
    int geracoes; //Quantidade de gerações limite
    int popInicial; //Tamanho da população inicial requerida
    int Matrix; //Tamanho da matriz quadrada
    int Elite; //Porcentagem considerada Elite
    int Mutation; //Porcentagem de mutação que deve ser adicionada
    vector<Individuo*> populacao; //Matriz de população
};

#endif /* GENETICO_HPP */