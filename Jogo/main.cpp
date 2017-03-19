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
    gn->cGenetico(5, 20, 30);
    
    /**
     * 
     * Dando erro de segmentação
     * 
     */
    //gn->imprimirPopulacao();
    return 0;
}

