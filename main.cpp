/*****************************************
*
* Amanda Vieira Costa - 2018.1904042-9
* Trabalho 1 - Estruturas de Dados
* Professor: Diego Rubert
*
*******************************************/

#include<iostream>
#include<cstring>
#include<cctype>

#include "Classes.h"

#define MAX 20
#define MIN 3

using namespace std;

int main(int argc, char* argv[]){

    TabelaDispersao T;
    FILE *arquivo;
    char palavra[MAX];
    int linhaAtual = 1; //contador de linhas
    int c, tam;         //caractere de comparação/tamanho da palavra
    
    arquivo = fopen(argv[1], "r");

    if(!arquivo){
        cout << "Nao foi possivel abrir o arquivo" << endl;
        exit(0);
    }
    else{

        int i = 0;
        while (c != EOF){
            c = fgetc(arquivo);         //leitura por caractere

            
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){      //copiando apenas letras para a string a ser passada
                palavra[i] = tolower((char)c);
                i++;
            }
                        
            else{                           //exlcuindo pontuações
                palavra[i] = '\0';          //definindo a palavra
                tam = strlen(palavra);
                i = 0;

                if(tam >= MIN)
                    T.novaOcorrencia(palavra, linhaAtual);      //inserção da novaOcorrencia
            }

            if (c == '\n')
                linhaAtual++;           //contagem de linhas
        
        }

    }
    fclose(arquivo);
    
    T.escreve();
    
    return 0;
}   