#ifndef PRODUTO_H
#define PRODUTO_H

#include "unidade.h"

typedef struct produto tProduto;


tProduto* criaProduto(char* identificacao, char* codigoBarras, float preco, int max_unidades);


void liberaProduto(tProduto* p);


void exibirProduto(tProduto* p);


int ehSemelhante(tProduto* p1, tProduto* p2);


void reajuste(tProduto* p, float x);

// Gets e Sets
char* getIdentificacao(tProduto* p);
void setIdentificacao(tProduto* p, char* id);

char* getCodigoBarras(tProduto* p);
void setCodigoBarras(tProduto* p, char* codigo);

float getPrecoProduto(tProduto* p); 
void setPrecoProduto(tProduto* p, float preco);

int getQtUnidadesProduto(tProduto* p);
void setQtUnidadesProduto(tProduto* p, int qt); 


tUnidade* getUnidadeProduto(tProduto* p, int indice);
void setUnidadeProduto(tProduto* p, int indice, tUnidade* u);
int adicionaUnidade(tProduto* p, tUnidade* u);


char* getProdutoReq(tProduto* p);

int produtosIguais(tProduto* p1, tProduto* p2);

#endif
