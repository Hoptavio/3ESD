#include <stdio.h>
#include <stdlib.h>
#include "TAD_Peso.h"

struct peso{
    float kg;
    float g;
};
//Função para criar peso
Peso * criaPeso(float kg,float g){
    Peso *p = (Peso*)malloc(sizeof(Peso));
    if(p != NULL){
        p->kg = kg;
        p->g = g;
    }
    return p;
}
//Função para liberar peso
void liberaPeso(Peso*p){
    free(p);    
}
//Função para exibir peso
void exibePeso(Peso*p){
    printf("Peso: %.2f kg %.2f g\n",p->kg,p->g);
}
//Função para acessar peso e retornar os valores de kg e g
void acessaPeso(Peso*p, float*kg, float*g){
    *kg = p->kg;
    *g = p->g;
}
//Função para atribuir novos valores de peso
void atribuiPeso(Peso*p, float kg, float g){
    p->kg = kg;
    p->g = g;
}
//Função para comparar pesos
int comparaPeso(Peso*p1, Peso*p2){
    float peso1 = p1->kg + (p1->g/1000.0);
    float peso2 = p2->kg + (p2->g/1000.0);
    if(peso1 > peso2){
        return 1;
    }else if(peso1 < peso2){
        return -1;
    }else{
        return 0;
    }
}
//Função para somar peso em gramas
Peso *somaPeso(Peso*p, float g){
    Peso *novoPeso = (Peso*)malloc(sizeof(Peso));
    novoPeso->kg = p->kg;
    novoPeso->g = p->g + g;
   if (novoPeso->g >= 1000.0f) {
    int extraKg = (int)(novoPeso->g / 1000.0f);
    novoPeso->kg += extraKg;
    novoPeso->g -= extraKg * 1000.0f;
    }
    return novoPeso;
}
//Função para copiar peso
Peso *copiaPeso(Peso*p){
    Peso *novoPeso = (Peso*)malloc(sizeof(Peso));
    novoPeso->kg = p->kg;
    novoPeso->g = p->g;
    return novoPeso;
}
//Função para retornar uma string com os valores de peso no formato kg,g
char *getPeso(Peso*p){
    char *str = (char*)malloc(sizeof(char)*20);
    sprintf(str,"%.2f kg %.2f g",p->kg,p->g);
    return str;
}