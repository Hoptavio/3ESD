#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"

int main() {
    // Definindo 3 pontos para formar um triângulo retângulo (lados 3, 4 e 5)
    // Pontos: (0,0), (3,0), e (0,4)
    Ponto p1 = {0.0, 0.0};
    Ponto p2 = {3.0, 0.0};
    Ponto p3 = {0.0, 4.0};

    printf("Criando Triangulo com os pontos: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", 
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

    // Cria o triângulo
    Triangulo* t = triangulo_cria(p1, p2, p3);

    if (t == NULL) {
        printf("Erro ao alocar memória para o triângulo.\n");
        return 1;
    }

    // Testa a função perímetro
    // Distâncias:
    // (0,0) a (3,0) = 3
    // (3,0) a (0,4) = 5
    // (0,4) a (0,0) = 4
    // Perímetro esperado: 3 + 4 + 5 = 12
    float perimetro = triangulo_perimetro(t);
    printf("Perimetro do triangulo = %.2f (esperado: 12.00)\n", perimetro);

    // Testa a função de escolha livre: alterar pontos
    // Vamos dobrar o tamanho do triângulo alterando os pontos
    Ponto p4 = {0.0, 0.0};
    Ponto p5 = {6.0, 0.0};
    Ponto p6 = {0.0, 8.0};
    
    printf("Alterando os pontos para: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", 
           p4.x, p4.y, p5.x, p5.y, p6.x, p6.y);
           
    triangulo_altera_pontos(t, p4, p5, p6);
    
    // Testa o novo perímetro (lados serão 6, 8 e 10 -> perímetro 24)
    perimetro = triangulo_perimetro(t);
    printf("Novo perimetro do triangulo = %.2f (esperado: 24.00)\n", perimetro);

    // Libera a memória
    triangulo_libera(t);
    
    printf("Teste concluido com sucesso.\n");
    return 0;
}
