#ifndef TRIANGULO_H
#define TRIANGULO_H

// Estrutura para representar um ponto 2D
typedef struct {
    float x;
    float y;
} Ponto;

// Tipo encapsulado para o Triângulo
typedef struct triangulo Triangulo;

// Cria um triângulo a partir de 3 pontos
Triangulo* triangulo_cria(Ponto p1, Ponto p2, Ponto p3);

// Libera a memória alocada pelo triângulo
void triangulo_libera(Triangulo* t);

// Calcula o perímetro do triângulo
float triangulo_perimetro(Triangulo* t);

// Altera os vértices do triângulo para novos pontos (Função de escolha livre)
void triangulo_altera_pontos(Triangulo* t, Ponto p1, Ponto p2, Ponto p3);

// Recupera os pontos dos vértices do triângulo
void triangulo_acessa(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3);

#endif
