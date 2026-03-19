#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "unidade.h"

struct produto {
    char identificacao[100];
    char codigoBarras[50];
    float preco;
    int qt_unidades;
    int max_unidades;
    tUnidade** unidades;
};

tProduto* criaProduto(char* identificacao, char* codigoBarras, float preco, int max_unidades) {
    tProduto* p = (tProduto*)malloc(sizeof(tProduto));
    
    if (identificacao != NULL && strlen(identificacao) > 0) {
        strcpy(p->identificacao, identificacao);
    } else {
        strcpy(p->identificacao, "Produto");
    }
    
    if (codigoBarras != NULL) {
        strcpy(p->codigoBarras, codigoBarras);
    } else {
        strcpy(p->codigoBarras, "");
    }
    
    p->preco = preco > 0 ? preco : 0.0f;
    p->max_unidades = max_unidades > 0 ? max_unidades : 10;
    p->qt_unidades = 0;
    p->unidades = (tUnidade**)malloc(sizeof(tUnidade*) * p->max_unidades);
    
    return p;
}

void liberaProduto(tProduto* p) {
    if (p != NULL) {
        for (int i = 0; i < p->qt_unidades; i++) {
            liberaUnidade(p->unidades[i]);
        }
        free(p->unidades);
        free(p);
    }
}

void exibirProduto(tProduto* p) {
    if (p == NULL) return;
    printf("Produto: %s | Codigo: %s | Preco: R$%.2f | Unidades: %d\n", 
            p->identificacao, p->codigoBarras, p->preco, p->qt_unidades);
    for (int i = 0; i < p->qt_unidades; i++) {
        printf("  - ");
        exibirUnidade(p->unidades[i]);
        printf("\n");
    }
}

int ehSemelhante(tProduto* p1, tProduto* p2) {
    if (p1 == NULL || p2 == NULL) return 0;
    return strcmp(p1->identificacao, p2->identificacao) == 0;
}

void reajuste(tProduto* p, float x) {
    if (p == NULL) return;
    p->preco = p->preco * (1.0f + (x / 100.0f));
}

char* getIdentificacao(tProduto* p) {
    return p->identificacao;
}

void setIdentificacao(tProduto* p, char* id) {
    if (p != NULL && id != NULL) {
        strcpy(p->identificacao, id);
    }
}

char* getCodigoBarras(tProduto* p) {
    return p->codigoBarras;
}

void setCodigoBarras(tProduto* p, char* codigo) {
    if (p != NULL && codigo != NULL) {
        strcpy(p->codigoBarras, codigo);
    }
}

float getPrecoProduto(tProduto* p) {
    return p ? p->preco : 0.0f;
}

void setPrecoProduto(tProduto* p, float preco) {
    if (p != NULL) {
        p->preco = preco;
    }
}

int getQtUnidadesProduto(tProduto* p) {
    return p ? p->qt_unidades : 0;
}

void setQtUnidadesProduto(tProduto* p, int qt) {
    if (p != NULL) {
        p->qt_unidades = qt;
    }
}

tUnidade* getUnidadeProduto(tProduto* p, int indice) {
    if (p != NULL && indice >= 0 && indice < p->qt_unidades) {
        return p->unidades[indice];
    }
    return NULL;
}

void setUnidadeProduto(tProduto* p, int indice, tUnidade* u) {
    if (p != NULL && indice >= 0 && indice < p->qt_unidades) {
        p->unidades[indice] = u;
    }
}

int adicionaUnidade(tProduto* p, tUnidade* u) {
    if (p != NULL && p->qt_unidades < p->max_unidades && u != NULL) {
        p->unidades[p->qt_unidades] = u;
        p->qt_unidades++;
        return 1;
    }
    return 0;
}

char* getProdutoReq(tProduto* p) {
    char* str = (char*)malloc(256);
    if (p != NULL) {
        sprintf(str, "Info [%s], EAN [%s], Preco [%.2f], Qtd [%d]", 
                p->identificacao, p->codigoBarras, p->preco, p->qt_unidades);
    } else {
        strcpy(str, "");
    }
    return str;
}

int produtosIguais(tProduto* p1, tProduto* p2) {
    if (p1 == NULL || p2 == NULL) return 0;
    if (strcmp(p1->identificacao, p2->identificacao) != 0) return 0;
    if (strcmp(p1->codigoBarras, p2->codigoBarras) != 0) return 0;
    if (p1->preco != p2->preco) return 0;
    if (p1->qt_unidades != p2->qt_unidades) return 0;
    return 1;
}
