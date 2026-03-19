#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "unidade.h"
#include "Data.h"

// Funcao auxiliar para verificar se d1 >= d2
int data_maior_ou_igual(tData* d1, tData* d2) {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    dta_acessa(d1, &dia1, &mes1, &ano1);
    dta_acessa(d2, &dia2, &mes2, &ano2);
    
    if (ano1 > ano2) return 1;
    if (ano1 == ano2 && mes1 > mes2) return 1;
    if (ano1 == ano2 && mes1 == mes2 && dia1 >= dia2) return 1;
    return 0;
}

// Funcao auxiliar para verificar se d1 == d2
int data_igual(tData* d1, tData* d2) {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    dta_acessa(d1, &dia1, &mes1, &ano1);
    dta_acessa(d2, &dia2, &mes2, &ano2);
    
    return (ano1 == ano2 && mes1 == mes2 && dia1 == dia2);
}

int main() {
    int total_produtos = 3;
    tProduto* produtos[3];

    produtos[0] = criaProduto("Leite", "12345", 5.50, 5);
    produtos[1] = criaProduto("Pao", "67890", 4.00, 5);
    produtos[2] = criaProduto("Manteiga", "11121", 10.00, 5);

    // Adicionando unidades (dados exemplos) // lote default 1, 2, 3...
    // Supondo que a data de fabricacao seja a data usada para validade (conforme enunciado)
    adicionaUnidade(produtos[0], criaUnidade(dta_cria(20, 3, 2026), 1));
    adicionaUnidade(produtos[0], criaUnidade(dta_cria(25, 3, 2026), 2));
    
    adicionaUnidade(produtos[1], criaUnidade(dta_cria(23, 3, 2026), 3));
    
    adicionaUnidade(produtos[2], criaUnidade(dta_cria(20, 3, 2026), 4));

    int d, m, a;
    printf("Informe a data alvo (dd mm aaaa): ");

    if (scanf("%d %d %d", &d, &m, &a) != 3) {
        d = 20; m = 3; a = 2026;
        printf("%02d/%02d/%04d (Padrao assumido)\n", d, m, a);
    }
    
    tData* data_alvo = dta_cria(d, m, a);

    printf("\n=== UNIDADES QUE VENCEM NA DATA ALVO ===\n");
    for (int i = 0; i < total_produtos; i++) {
        int qtd_unidades = getQtUnidadesProduto(produtos[i]);
        for (int j = 0; j < qtd_unidades; j++) {
            tUnidade* uni = getUnidadeProduto(produtos[i], j);
            tData* data_fab = getDataFabricacao(uni); // usando dataFab como data
            
            if (data_igual(data_fab, data_alvo)) {
                printf("Produto: %s | Lote: %d | Data: ", getIdentificacao(produtos[i]), getLote(uni));
                dta_exibe(data_fab);
                printf("\n");
            }
        }
    }

    printf("\n=== DESCONTO DE 25%% (Vencimento em ate 3 dias da data alvo) ===\n");
    for (int i = 0; i < total_produtos; i++) {
        int aplica = 0;
        int qtd_unidades = getQtUnidadesProduto(produtos[i]);
        
        for (int j = 0; j < qtd_unidades; j++) {
            tUnidade* uni = getUnidadeProduto(produtos[i], j);
            tData* data_fab = getDataFabricacao(uni);
            
            if (data_maior_ou_igual(data_fab, data_alvo)) {
                // dta_diferenca retorna diferenca absoluta em dias + 1
                int dif = dta_diferenca(data_fab, data_alvo);
                if (dif <= 4) { // ate 3 dias
                    aplica = 1;
                    break;
                }
            }
        }
        
        if (aplica) {
            float preco_antigo = getPrecoProduto(produtos[i]);
            // reajuste aplica percentual, entao -25.0 eh 25% de desconto
            reajuste(produtos[i], -25.0);
            printf("Produto: %s descontado! Preco antigo: R$%.2f | Novo Preco: R$%.2f\n", 
                    getIdentificacao(produtos[i]), preco_antigo, getPrecoProduto(produtos[i]));
        }
    }

    // Liberando memoria
    dta_libera(data_alvo);
    for (int i = 0; i < total_produtos; i++) {
        liberaProduto(produtos[i]);
    }

    printf("\nFim do programa.\n");
    return 0;
}
