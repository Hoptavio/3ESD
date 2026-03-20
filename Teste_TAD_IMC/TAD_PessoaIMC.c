#include "TAD_PessoaIMC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Peso.h"
#include "TAD_Altura.h"
//Definição da struct PessoaIMC
struct pessoaIMC{
    Peso *peso;
    Altura *altura;
};
//Função que cria uma pessoaIMC
PessoaIMC *criaPessoaIMC(Peso *peso, Altura *altura){
    PessoaIMC *p = (PessoaIMC*)malloc(sizeof(PessoaIMC));
    if(p != NULL){
        p->peso = peso;
        p->altura = altura;
    }
    return p;
}
//Função que libera a memória alocada para uma pessoaIMC
void liberaPessoaIMC(PessoaIMC*p){
    free(p);
}
//Função que exibe uma pessoaIMC
void exibePessoaIMC(PessoaIMC*p){
    float kg, g;
    int m, cm;
    acessaPeso(p->peso, &kg, &g);
    alt_acessa(p->altura, &m, &cm);
    printf("Peso: %.2f kg %.2f g, Altura: %d,%02dm\n", kg, g, m, cm);
}
//Função que acessa os dados de uma pessoaIMC
void acessaPessoaIMC(PessoaIMC*p, Peso **peso, Altura **altura){
    *peso = p->peso;
    *altura = p->altura;
}
//Função que atribui os dados de uma pessoaIMC
void atribuiPessoaIMC(PessoaIMC*p, Peso *peso, Altura *altura){
    p->peso = peso;
    p->altura = altura;
}
//Função que compara duas pessoasIMC
int comparaPessoaIMC(PessoaIMC*p1, PessoaIMC*p2){
    float imc1 = calculaIMC(p1);
    float imc2 = calculaIMC(p2);
    if(imc1 > imc2){
        return 1;
    }else if(imc1 < imc2){
        return -1;
    }else{
        return 0;
    }
}
//Função que retorna uma string com os dados de uma pessoaIMC
char *getPessoaIMC(PessoaIMC*p){
    char *str = (char*)malloc(sizeof(char)*100);
    float kg, g;
    int m, cm;
    acessaPeso(p->peso, &kg, &g);
    alt_acessa(p->altura, &m, &cm);
    sprintf(str,"Peso: %.2f kg %.2f g, Altura: %d,%02dm", kg, g, m, cm);
    return str;
}
//Função que calcula o IMC de uma pessoaIMC
float calculaIMC(PessoaIMC*p){
    float kg, g, pesoTotal;
    int m, cm;
    float altTotal;
    
    acessaPeso(p->peso, &kg, &g);
    pesoTotal = kg + (g / 1000.0);
    
    alt_acessa(p->altura, &m, &cm);
    altTotal = m + (cm / 100.0);
    
    return pesoTotal / (altTotal * altTotal);
}
//Função que classifica o IMC de uma pessoaIMC
int *classificaIMC(float imc){
    int *classificacao = (int*)malloc(sizeof(int));
    if(imc < 18.5){
        *classificacao = 1;
    }else if(imc < 25){
        *classificacao = 2;
    }else if(imc < 30){
        *classificacao = 3;
    }else{
        *classificacao = 4;
    }
    return classificacao;
}