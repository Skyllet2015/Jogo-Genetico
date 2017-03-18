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
    int opc;
    individuo* teste = new individuo();
    teste->inicializa(5);    
    teste->imprimir();
    cin>>opc;
    return 0;
}

