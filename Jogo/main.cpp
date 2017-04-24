/* 
 * File:   main.cpp
 * Author: jsouza
 *
 * Created on 31 de Março de 2017, 22:50
 */

#include "inclu.hpp"
#include "Individuo.hpp"
#include "Genetico.hpp"

int main(int argc, char** argv) {
    cerr<<"Testando Início"<<endl;
    srand((unsigned) time(NULL));    
    
    int tamanho = 3;
    //Genetico(int matriz, int popInicial, int elite, int mutacao, int geracoes);
    Genetico* gen = new Genetico(tamanho, 100*tamanho, 30, 50, (tamanho*10000));
    
    /*
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

     */
    return 0;
}

