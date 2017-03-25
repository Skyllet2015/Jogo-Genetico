/* 
 * File:   Individuo.cpp
 * Author: jsouza
 * 
 * Created on 25 de Março de 2017, 00:23
 */

#include "Individuo.hpp"

void Individuo::inicializar(int tamanho) {
    this->tamanho = tamanho;
    this->clicados = 0;
    vector< vector<int> > aux(tamanho, vector<int>(tamanho));
    this->matriz = aux;
    preencher(tamanho);
}

void Individuo::preencher(int tam) {
    int cont = 0;
    while (cont < tam) {
        srand((unsigned int) time((time_t *) NULL));
        if (clicar(rand() % tam, rand() % tam) == true) {
            cont++;
        }
    }
}

bool Individuo::clicar(int linha, int coluna) {
    if (matriz[linha][coluna] == 0) {
        matriz[linha][coluna] = 1;

        if ((linha - 1 >= 0 and linha - 1 < tamanho)) {
            if ((matriz[linha - 1][coluna] == 1) or matriz[linha - 1][coluna] == 3) {
                if (matriz[linha - 1][coluna] == 1) {
                    matriz[linha - 1][coluna] = 3;
                } else {
                    matriz[linha - 1][coluna] = 1;
                }
            } else if ((matriz[linha - 1][coluna] == 0) or matriz[linha - 1][coluna] == 2) {
                if (matriz[linha - 1][coluna] == 0) {
                    matriz[linha - 1][coluna] = 2;
                } else {
                    matriz[linha - 1][coluna] = 0;
                }
            }
        }

        if ((linha + 1 >= 0 and linha + 1 < tamanho)) {
            if ((matriz[linha + 1][coluna] == 1) or matriz[linha + 1][coluna] == 3) {
                if (matriz[linha + 1][coluna] == 1) {
                    matriz[linha + 1][coluna] = 3;
                } else {
                    matriz[linha + 1][coluna] = 1;
                }
            } else if ((matriz[linha + 1][coluna] == 0) or matriz[linha + 1][coluna] == 2) {
                if (matriz[linha + 1][coluna] == 0) {
                    matriz[linha + 1][coluna] = 2;
                } else {
                    matriz[linha + 1][coluna] = 0;
                }
            }
        }

        if ((coluna - 1 >= 0 and coluna - 1 < tamanho)) {
            if ((matriz[linha][coluna - 1] == 1) or matriz[linha][coluna - 1] == 3) {
                if (matriz[linha][coluna - 1] == 1) {
                    matriz[linha][coluna - 1] = 3;
                } else {
                    matriz[linha][coluna - 1] = 1;
                }
            } else if ((matriz[linha][coluna - 1] == 0) or matriz[linha][coluna - 1] == 2) {
                if (matriz[linha][coluna - 1] == 0) {
                    matriz[linha][coluna - 1] = 2;
                } else {
                    matriz[linha][coluna - 1] = 0;
                }
            }
        }

        if ((coluna + 1 >= 0 and coluna + 1 < tamanho)) {
            if ((matriz[linha][coluna + 1] == 1) or matriz[linha][coluna + 1] == 3) {
                if (matriz[linha][coluna + 1] == 1) {
                    matriz[linha][coluna + 1] = 3;
                } else {
                    matriz[linha][coluna + 1] = 1;
                }
            } else if ((matriz[linha][coluna + 1] == 0) or matriz[linha][coluna + 1] == 2) {
                if (matriz[linha][coluna + 1] == 0) {
                    matriz[linha][coluna + 1] = 2;
                } else {
                    matriz[linha][coluna + 1] = 0;
                }
            }
        }
        return true;
    }
}

void Individuo::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        cout << endl;
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] == 1) {
                cout << "[X]";
            } else if (matriz[i][j] == 2) {
                cout << "[V]";
            } else if (matriz[i][j] == 3) {
                cout << "[.]";
            } else {
                cout << "[ ]";
            }
        }
    }
}

int Individuo::getBalanceamento() {
    return this->balanceamento;
}

int Individuo::getTamanho() {
    return this->tamanho;
}

void Individuo::setBalanceamento(int novo) {
    this->balanceamento = novo;
}

bool Individuo::operator<(Individuo* i) {
    if (this->vermelhos < i->vermelhos) {
        return true;
    } else if (this->vermelhos == i->vermelhos) {
        return (this->clicados < i->clicados);
    } else {
        return false;
    }
}