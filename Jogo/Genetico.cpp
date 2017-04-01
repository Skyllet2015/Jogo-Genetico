/* 
 * File:   genetico.cpp
 * Author: jsouza
 * 
 */

#include "Genetico.hpp"
#include "Individuo.hpp"

Genetico::Genetico(int matriz, int popInicial, int elite, int mutacao, int geracoes) {
    cerr << "Iniciando Genético" << endl;
    this->Matrix = matriz;
    this->Elite = elite;
    this->Mutation = mutacao;
    this->popInicial = popInicial;
    this->geracoes = geracoes;
    int ger = 0;
    bool stop = false;
    while (ger < geracoes) {
        cerr<<"Geração: "<<ger<<endl;
        this->gerarPopulacao();
        this->crossover();
        this->mutacao();        
        stop = this->avaliarPopulacao();
        this->eliminarNaoElite();
        if(stop == true){
            break;
        }
        ger++;
        sort(this->populacao.begin(), this->populacao.end());
    }
    this->populacao[0]->imprimirAtributos();
}

void Genetico::gerarPopulacao() {
    if (this->populacao.size() < this->popInicial) {
        for (int i = this->populacao.size(); i < this->popInicial; i++) {
            Individuo* ind = new Individuo(this->Matrix);
            ind->preencher();
            this->populacao.push_back(ind);
        }
    }
}

bool Genetico::avaliarPopulacao() {
    sort(this->populacao.begin(), this->populacao.end());
    Individuo* aux = this->populacao[0];
    if (aux->vermelhos == 0) {
        return true;
    } else {
        return false;
    }
}

void Genetico::crossover() {
    int i = this->populacao.size();
    for (; i < this->populacao.size();) {
        Individuo* pai = this->populacao[i];
        Individuo* mae = this->populacao[i + 1];
        this->populacao.push_back(pai->cruzar(mae));
        this->populacao.push_back(mae->cruzar(pai));
        i++;
        i++;
    }
}

void Genetico::mutacao() {
    int i = this->populacao.size();
    for (; i < ((this->populacao.size() * this->Mutation) / 100); ) {
        Individuo* pai = this->populacao[i];
        Individuo* mae = this->populacao[i + 1];
        this->populacao.push_back(pai->cruzar(mae));
        this->populacao.push_back(mae->cruzar(pai));
        i++;
        i++;
    }
}

void Genetico::eliminarNaoElite() {
    int i = this->populacao.size();
    int tam = this->populacao.size();
    for (; i >= ((tam * this->Elite) / 100); i--) {
        this->populacao.pop_back();
    }
}

