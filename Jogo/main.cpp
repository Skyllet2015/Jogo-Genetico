/* 
 * File:   main.cpp
 * Author: jsouza
 *
 * 
 */

#include <iostream>
#include "Individuo.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {   
    Individuo* teste = new Individuo();
    teste->inicializar(10);
    teste->imprimir();

}

