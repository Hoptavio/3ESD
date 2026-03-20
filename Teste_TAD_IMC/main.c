#include <stdio.h>
#include <stdlib.h>
#include "TAD_PessoaIMC.h"
#include "TAD_Peso.h"
#include "TAD_Altura.h"

int main() {
    // Vetor para 4 pessoas
    PessoaIMC *pessoas[4];
    
    // Pessoa 1 (Abaixo do peso)
    Peso *peso1 = criaPeso(50.0, 0.0);
    Altura *altura1 = alt_cria(1, 80);
    pessoas[0] = criaPessoaIMC(peso1, altura1);
    
    // Pessoa 2 (Peso normal)
    Peso *peso2 = criaPeso(70.0, 0.0);
    Altura *altura2 = alt_cria(1, 75);
    pessoas[1] = criaPessoaIMC(peso2, altura2);
    
    // Pessoa 3 (Sobrepeso)
    Peso *peso3 = criaPeso(85.0, 0.0);
    Altura *altura3 = alt_cria(1, 70);
    pessoas[2] = criaPessoaIMC(peso3, altura3);
    
    // Pessoa 4 (Obeso)
    Peso *peso4 = criaPeso(120.0, 0.0);
    Altura *altura4 = alt_cria(1, 60);
    pessoas[3] = criaPessoaIMC(peso4, altura4);
    
    printf("==== AVALIACAO DE CANDIDATOS ====\n\n");
    
    // Avaliar cada pessoa para ver se esta apta
    int i = 0;
    for(i = 0; i < 4; i++) {
        printf("Candidato %d:\n", i + 1);
        exibePessoaIMC(pessoas[i]);
        
        float imc = calculaIMC(pessoas[i]);
        int *classificacao = classificaIMC(imc);
        
        printf("IMC Calculado: %.2f\n", imc);
        
        // Apenas normais (2) ou sobrepeso (3) sao aceitos
        if(*classificacao == 2 || *classificacao == 3) {
            printf(" === RESULTADO: APTO PARA O EMPREGO ===\n\n");
        } else {
            printf(" === RESULTADO: INAPTO PARA O EMPREGO ===\n");
            if(*classificacao == 1) {
                printf("Motivo: Abaixo do peso.\n\n");
            } else {
                printf("Motivo: Obesidade.\n\n");
            }
        }
        
        free(classificacao); // Libera o ponteiro retornado pela funcao
    }
    
    // Libera toda a memoria alocada
    liberaPeso(peso1); alt_libera(altura1); liberaPessoaIMC(pessoas[0]);
    liberaPeso(peso2); alt_libera(altura2); liberaPessoaIMC(pessoas[1]);
    liberaPeso(peso3); alt_libera(altura3); liberaPessoaIMC(pessoas[2]);
    liberaPeso(peso4); alt_libera(altura4); liberaPessoaIMC(pessoas[3]);
    
    printf("Memoria liberada com sucesso.\n");
    return 0;
}
