#include <stdlib.h>
#include <math.h>
#include "triangulo.h"

// Definição da estrutura oculta
struct triangulo {
    Ponto p1;
    Ponto p2;
    Ponto p3;
};

// Função para criar o triângulo
Triangulo* triangulo_cria(Ponto p1, Ponto p2, Ponto p3) {
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    if (t != NULL) {
        t->p1 = p1;
        t->p2 = p2;
        t->p3 = p3;
    }
    return t;
}

// Função para liberar a memória do triângulo
void triangulo_libera(Triangulo* t) {
    if (t != NULL) {
        free(t);
    }
}

// Função auxiliar (interna) para calcular a distância entre dois pontos
static float distancia(Ponto pa, Ponto pb) {
    float dx = pb.x - pa.x;
    float dy = pb.y - pa.y;
    return sqrt(dx * dx + dy * dy);
}

// Implementação da função de perímetro solicitada
float triangulo_perimetro(Triangulo* t) {
    if (t == NULL) return 0.0;
    
    float a = distancia(t->p1, t->p2);
    float b = distancia(t->p2, t->p3);
    float c = distancia(t->p3, t->p1);
    
    return a + b + c;
}

// Implementação da função extra de escolha (Alterar os pontos do triângulo)
void triangulo_altera_pontos(Triangulo* t, Ponto p1, Ponto p2, Ponto p3) {
    if (t != NULL) {
        t->p1 = p1;
        t->p2 = p2;
        t->p3 = p3;
    }
}

// Função para acessar os atributos
void triangulo_acessa(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3) {
    if (t != NULL) {
        *p1 = t->p1;
        *p2 = t->p2;
        *p3 = t->p3;
    }
}
