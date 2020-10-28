#include <cstring>
#include <iostream>

#include "Classes.h"

using namespace std;

int totalKeys = 0;  

/*Métodos da classe TabelaDispersao*/
TabelaDispersao::TabelaDispersao(){             //construtor padrão
}

TabelaDispersao::~TabelaDispersao(){            //destrutor padrão
}

int TabelaDispersao::valor(char p[]){
    int tam = strlen(p);
    int value = 0;

    for(int i = 0; i < tam; i++)
        value = value + p[i];
    
    //printf("valor = %d\n", value);
    return value;
}

int TabelaDispersao::h(char p[]){
    int hash = (valor(p)%47);
    //printf("%d\n", hash);
    return hash;
}

void TabelaDispersao::novaOcorrencia(char p[], int linha){
    Palavra* pt;                               //(linha atual - contar na main, eu acho)
    int indice = h(p);
    ListaP *l = &tabela[indice];
    
    pt = l->busca(p);
    if(pt == NULL)                        //palavra nova - ListaP vazia
        pt = l->insere(p); 
        
    pt->insere(linha);                //nova ocorrência na ListaO    
}

void TabelaDispersao::escreve(){    
    int i = 0;
    ListaP *L;
    
    printf("%d:\n", i);
    for(i = 0; i < TAMANHO; i++){
        
        L = &tabela[i];             //chamar para cada i, a escrita da listaP -> escrita de Palavra
        printf("%d: ", i);
        L->escreve();
        printf("\n");
        
    }    
    printf("Fator de carga: %g\n", (double)totalKeys/TAMANHO);
}

/*Métodos da classe ListaP*/
ListaP::ListaP(){
    inicio = NULL;
    fim = NULL;
}

ListaP::~ListaP(){
    Palavra *p = inicio;
    Palavra *q;

    while (p != NULL){
        q = p->prox;
        delete p;
        p = q;
    }
}

Palavra* ListaP::busca(char p[]){
    int achou = 0;
    Palavra* aux = inicio;
       
    if (fim == NULL)
        return fim;

    else{

        do{
            if(strcmp(aux->p, p) == 0)
                achou = 1;
                
            else    
                aux = aux->prox;
                    
        }while((achou == 0) && (aux != NULL));

        return aux;
    }
}

Palavra* ListaP::insere(char p[]){
    Palavra *palavra = new Palavra(p);
    Palavra *pt;

    if(!fim){                       //ListaP vazia
        inicio = fim = palavra;     //1ª inserção
        totalKeys++;
        //ocorrencia: feita em novaOcorrencia
    }
    else{
        
        pt = inicio;
        while(pt->prox != NULL){
            pt = pt->prox;
        }
            pt->prox = palavra;
            fim = palavra;

            totalKeys++;
    }
    return palavra;
}

void ListaP::escreve(){
    Palavra *pt;

    for(pt = inicio; pt != NULL; pt = pt->prox){        
        pt->escreve();
    }
}

/*Métodos da classe Palavra*/
Palavra::Palavra(char p[]){
    strcpy(this->p, p);
    prox = NULL;    
}

Palavra::~Palavra(){
}

void Palavra::insere(int linha){
    this->ocorrencias.insere(linha);
}

void Palavra::escreve(){
    ListaO *O = &ocorrencias;
    
    printf("%s", this->p);
    O->escreve();
}

/*Métodos da classe ListaO*/
ListaO::ListaO(){
    inicio = NULL;
    fim = NULL;
}

ListaO::~ListaO(){
    Ocorrencia *p = inicio;
    Ocorrencia *q;

    while (p != NULL){
        q = p->prox;
        delete p;
        p = q;
    }
}

void ListaO::insere(int linha){
    Ocorrencia* nova = new Ocorrencia(linha);

    if(fim == NULL)                   //ListaO vazia
        inicio = fim = nova;          //1ª inserção     
    
    else{
        if (this->fim->linha != linha){         //evita duplicata 
            fim->prox = nova;
            fim = nova;   
        }     
    }    
}

void ListaO::escreve(){
    Ocorrencia* pt;

    printf("(");
    
    for(pt = inicio; pt != NULL; pt = pt->prox){
        printf("%d", pt->linha);

        if(pt->prox != NULL)
            printf(", ");
    }
    printf(") ");    
}

/*Métodos da classe Ocorrencia*/
Ocorrencia::Ocorrencia(int linha){
    this->linha = linha;
    prox = NULL;
}

Ocorrencia::~Ocorrencia(){
}