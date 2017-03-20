/* 
 * File:   main.cpp
 * Author: jsouza
 *
 * 
 */

#include <iostream>
#include "genetico.hpp"
#include "individuo.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {   
    genetico* gn = new genetico();
    gn->cGenetico(5, 25, 30);    
    cerr<<"Quantidade: "<<gn->getTamPopulacao()<<endl;
    
    /**
     * 
     * Dando erro de segmentação
     * 
     */
    gn->imprimirPopulacao();
    return 0;
}

