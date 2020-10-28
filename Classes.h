#ifndef CLASSES_H
#define CLASSES_H

#include <cstdio>
#include <cctype>
#include <cstring>

#define MIN 3
#define MAX 20

using namespace std;

extern int totalKeys;      //calcula o nº total chaves

/* Célula de uma lista encadeada de ocorrências, armazena um inteiro */
class Ocorrencia {
  friend class ListaO;

  public:
    Ocorrencia(int linha); // Construtor padrão   - OK
    ~Ocorrencia();         // Destrutor padrão    - OK

  private:
    int linha;
    Ocorrencia *prox;      //ponteiro
};


/* Lista encadeada de ocorrências, inserção realizada no fim da lista.
   Tenha o cuidado de não inserir duplicatas */
class ListaO {
  public:
    ListaO();               // Construtor padrão                      - OK
    ~ListaO();              // Destrutor padrão                       - OK
    void insere(int linha); // Recebe um inteiro e insere na lista    - OK
    void escreve();         // Escreve os elementos da lista          - OK

  private:
    Ocorrencia *inicio; // Início da lista
    Ocorrencia *fim;    // Fim da lista
};


/* Célula de uma lista encadeada de palavras, armazena uma cadeia de caracteres */
class Palavra {
  friend class ListaP;        //recebe acesso aos membros privados da classe ListaP

  public:
    Palavra(char p[]);        // Construtor padrão recebe uma palavra           - OK
    ~Palavra();               // Destrutor padrão                               - OK
    void insere(int linha);   // Insere uma ocorrência na lista de ocorrências  - OK
    void escreve();           // Escreve a palavra e suas ocorrências           - OK
    
  private:
    char p[MAX];              // A palavra em si
    ListaO ocorrencias;       // Lista de ocorrências
    Palavra *prox;            // Próxima Palavra na lista - ponteiro
};


/* Lista encadeada de palavras, inserção realizada no fim da lista.
   Tenha o cuidado de não inserir duplicatas */
class ListaP {
  
  public:
    ListaP();                  // Construtor padrão           - OK
    ~ListaP();                 // Destrutor padrão            - OK
    Palavra *insere(char p[]); // Recebe uma palavra e insere na lista, devolvendo um ponteiro para o objeto inserido - OK
    Palavra *busca(char p[]);  // Busca e devolve o ponteiro do objeto de uma palavra na lista                        - OK
    void escreve();            // Escreve os elementos da lista                                                       - OK
    
  private:
    Palavra *inicio;           // Início da ListaP
    Palavra *fim;              // Fim da ListaP
};


/* Tabela de dispersão que guarda um índice de palavras */
class TabelaDispersao {
  public:
    TabelaDispersao();  // Construtor padrão                                                 - OK
    ~TabelaDispersao(); // Destrutor padrão                                                  - OK
    void escreve();     // Escreve a tabela (incluindo fator de carga) - (Nº chaves/TAMANHO) - OK
    void novaOcorrencia(char p[], int linha); // Registra uma nova ocorrência de uma palavra - OK    

  private:
    static const int TAMANHO = 47; // Tamanho da tabela
    ListaP tabela[TAMANHO];        // Listas da tabela

    int valor(char p[]); // Valor da palavra p -> soma dos valores ASCII                     - OK
    int h(char p[]);     // Função de hash -> determina a posição na tabela hash             - OK
};


#endif
