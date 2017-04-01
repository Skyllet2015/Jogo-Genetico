/* 
 * File:   main.cpp
 * Author: jsouza
 *
 * Created on 31 de Março de 2017, 22:50
 */

#include "Individuo.hpp"

int main(int argc, char** argv) {
    srand((unsigned) time(nullptr));
    
    cout<<endl<<endl<<"Criando Primeiro Individuo!";
    Individuo* ind0 = new Individuo(5);
    ind0->preencher();
    ind0->imprimirAtributos();

    cout<<endl<<endl<<"Criando Segundo Individuo!";
    Individuo* ind1 = new Individuo(5);
    ind1->preencher();
    ind1->imprimirAtributos();
    
    cout<<endl<<endl<<"Criando Primeiro Filho!";
    Individuo* filho0 = ind0->cruzar(ind1);
    filho0->imprimirAtributos();
    
    cout<<endl<<endl<<"Criando Segundo Filho!";
    Individuo* filho1 = ind1->cruzar(ind0);
    filho1->imprimirAtributos();

    return 0;
}

