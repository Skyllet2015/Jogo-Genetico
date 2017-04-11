/* 
 * File:   genetico.cpp
 * Author: jsouza
 * 
 */

#include "Genetico.hpp"
#include "Individuo.hpp"

Genetico::Genetico(int matriz, int popInicial, int elite, int mutacao, int geracoes) {
    this->Matrix = matriz;
    this->Elite = elite;
    this->Mutation = mutacao;
    this->popInicial = popInicial;
    this->geracoes = geracoes;
    int ger = 0;
    bool stop = false;
    this->gerarPopulacao();
    while (!stop) {
        this->crossover();
        if (this->avaliarPopulacao() == true or ger >= geracoes) {
            stop = true;
        }
        this->eliminarNaoElite();
        ger++;
    }
    cout<<"Tamanho: "<<Matrix<<endl;
    cout << "Geração: " << ger << endl;
    this->populacao[0]->imprimirAtributos();
}

void Genetico::gerarPopulacao() {
    if (this->populacao.size() < this->popInicial) {
        int i = this->populacao.size();
        for (; i < this->popInicial; i++) {
            Individuo* ind = new Individuo(this->Matrix, geracoes);
            ind->preencher();
            this->populacao.push_back(ind);
        }
    }
}

bool Genetico::avaliarPopulacao() {
    this->ordenar();
    Individuo* aux = this->populacao[0];
    if (aux->vermelhos == 0) {
        return true;
    } else {
        return false;
    }
}

void Genetico::crossover() {
    if (this->populacao.size() < this->popInicial) {
        this->gerarPopulacao();
    }
    int aux = this->populacao.size();
    for (int i = 0; i < aux;) {
        int pai = rand()%aux;
        int mae = rand()%aux;
        Individuo* filho1 = this->populacao[pai]->cruzar(this->populacao[mae]);
        Individuo* filho2 = this->populacao[mae]->cruzar(this->populacao[pai]);        
        if(rand()%100 < ((this->populacao.size() * this->Mutation) / 100)) filho1->clicar(rand()%this->Matrix, rand()%this->Matrix);
        if(rand()%100 < ((this->populacao.size() * this->Mutation) / 100)) filho2->clicar(rand()%this->Matrix, rand()%this->Matrix);
        filho1->balancear();
        filho2->balancear();
        this->populacao.push_back(filho1);
        this->populacao.push_back(filho2);
        i += 2;
    }
}

void Genetico::eliminarNaoElite() {
    
    for(int i = populacao.size(); i > ((this->populacao.size() * this->Elite) / 100); i--){
        delete populacao[i];
    }
    this->populacao.resize(((this->populacao.size() * this->Elite) / 100));
}

void Genetico::imprimirPopulacao() {
    for(int i = 0; i < populacao.size(); i++){
        populacao[i]->imprimirAtributos();
    }
}

void Genetico::ordenar() {
    for (int i = 0; i < this->populacao.size(); i++) {
        for (int j = 0; j < this->populacao.size(); j++) {
            if (this->populacao[i]->vermelhos < this->populacao[j]->vermelhos) {
                Individuo* aux = this->populacao[i];
                this->populacao[i] = this->populacao[j];
                this->populacao[j] = aux;
            }
            if (this->populacao[i]->vermelhos == this->populacao[j]->vermelhos) {
                if (this->populacao[i]->clicados < this->populacao[j]->clicados) {
                    Individuo* aux = this->populacao[i];
                    this->populacao[i] = this->populacao[j];
                    this->populacao[j] = aux;
                }
            }
        }
    }
}