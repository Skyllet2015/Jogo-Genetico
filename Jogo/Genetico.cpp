/* 
 * File:   genetico.cpp
 * Author: jsouza
 * 
 */

#include "Genetico.hpp"

void Genetico::cGenetico(int tamMatriz, int popInicial, int porcentMelhores) {
    this->popInicial = popInicial;
    this->tamMatriz = tamMatriz;
    this->porcentMelhores = porcentMelhores;
}

void Genetico::popular(int tamMatriz, int popInicial) {
    for (int i = 0; i < tamMatriz; i++) {
        Individuo* ind = new Individuo();
        ind->inicializar(tamMatriz);
        cout<<endl<<endl<<endl<<endl;
        cout<<"-------------Nova matriz-------------";
        ind->imprimir();
        this->populacao.push_back(ind);        
    }
    cout<<endl<<endl<<endl<<endl;
}

void Genetico::solver(){    
    popular(tamMatriz, popInicial);
        
}

void Genetico::imprimirPopulacao(){
    for(Individuo* ind: this->populacao){
        ind->imprimir();
        cout<<endl<<endl;
    }        
}

int Genetico::getTamPopulacao() {
    return populacao.size();
}