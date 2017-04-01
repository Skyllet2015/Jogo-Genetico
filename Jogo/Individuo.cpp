/* 
 * File:   Individuo.cpp
 * Author: jsouza
 * 
 * Created on 31 de Março de 2017, 22:50
 */

#include "Individuo.hpp"

Individuo::Individuo(int tam) {
    this->clicados = 0;
    this->tamanho = tam;
    this->vermelhos = 0;
    this->matrizClic = vector<vector<int>> (tam, vector<int>(tam));
    this->matrizCores = vector<vector<int>> (tam, vector<int>(tam));
}

void Individuo::preencher() {
    for (int cont = 0; cont < tamanho;) {
        int add = clicar(rand() % tamanho, rand() % tamanho);
        if (add == true) cont++;
    }
    this->balancear();
}

bool Individuo::clicar(int linha, int coluna) {
    if (linha >= 0 and coluna >= 0 and linha < tamanho and coluna < tamanho) {

        if (this->matrizClic[linha][coluna] == 0) {
            this->matrizClic[linha][coluna] = 1;

            // Modificando a cor da celula clicada
            if (this->matrizCores[linha][coluna] == 0) {
                this->matrizCores[linha][coluna] = 1;
            } else {
                this->matrizCores[linha][coluna] = 0;
            }

            //Modificando a cor da celula de cima da clicada
            if ((linha - 1 >= 0) and (this->matrizCores[linha - 1][coluna] == 0)) {
                this->matrizCores[linha - 1][coluna] = 1;
            } else if (linha - 1 >= 0) {
                this->matrizCores[linha - 1][coluna] = 0;
            }

            //Modificando a cor da celula de baixo da clicada
            if ((linha + 1 < this->tamanho) and (this->matrizCores[linha + 1][coluna] == 0)) {
                this->matrizCores[linha + 1][coluna] = 1;
            } else if (linha + 1 < this->tamanho) {
                this->matrizCores[linha + 1][coluna] = 0;
            }

            //Modificando a cor da celula esquerda da clicada
            if ((coluna - 1 >= 0) and (this->matrizCores[linha][coluna - 1] == 0)) {
                this->matrizCores[linha][coluna - 1] = 1;
            } else if (coluna - 1 >= 0) {
                this->matrizCores[linha][coluna - 1] = 0;
            }

            //Modificando a cor da celula direita da clicada
            if ((coluna + 1 < this->tamanho) and (this->matrizCores[linha][coluna + 1] == 0)) {
                this->matrizCores[linha][coluna + 1] = 1;
            } else if (coluna + 1 < this->tamanho) {
                this->matrizCores[linha][coluna + 1] = 0;
            }
        }
        return true;
    }
    return false;

}

void Individuo::balancear() {
    int auxClic = 0, auxVer = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matrizCores[i][j] == 0) {
                auxVer++;
            }
            if (matrizClic[i][j] == 1) {
                auxClic++;
            }
        }
    }
    this->vermelhos = auxVer;
    this->clicados = auxClic;
    this->balanceamento = ((auxVer * 5) + (auxClic));
}

Individuo* Individuo::cruzar(Individuo* ind) {
    Individuo* filho = new Individuo(this->tamanho);
    int val = 0, cont = 0;
    cerr << "" << endl;
    for (int i = 0; i < this->tamanho; i++) {
        for (int j = 0; j < this->tamanho; j++) {
            if ((val == 0 and (this->matrizClic[i][j] == 1 or this->matrizClic[i][j] == 3)) and (filho->matrizClic[i][j] != 1 or filho->matrizClic[i][j] != 3)) {
                filho->clicar(i, j);
                val = 1;
                cont++;
            } else if ((val == 1 and (ind->matrizClic[i][j] == 1 or ind->matrizClic[i][j] == 3)) and (filho->matrizClic[i][j] != 1 or filho->matrizClic[i][j] != 3)) {
                filho->clicar(i, j);
                val = 0;
                cont++;
            }
        }
    }
    filho->balancear();
    return filho;
}

void Individuo::imprimirAtributos() {
    cout << "\nClicados: " << this->clicados << endl;
    cout << "Vermelhos: " << this->vermelhos << endl;
    cout << "Tamanho: " << this->tamanho << endl;
    cout << "Balanceamento: " << this->balanceamento << endl;
    this->imprimirMatriz();
}

void Individuo::imprimirMatriz() {
    cout << endl << "Imprimindo matriz de Clicados" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << endl;
        for (int j = 0; j < tamanho; j++) {
            cout << "[" << this->matrizClic[i][j] << "]";

        }
    }
    cout << "\n\nImprimindo matriz de Cores" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << endl;
        for (int j = 0; j < tamanho; j++) {
            cout << "[" << this->matrizCores[i][j] << "]";
        }
    }
}