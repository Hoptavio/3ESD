#ifndef UNIDADE_H
#define UNIDADE_H

#include "Data.h"

typedef struct unidade tUnidade;


tUnidade* criaUnidade(tData* dataFab, int lote);


void liberaUnidade(tUnidade* u);


void exibirUnidade(tUnidade* u);


tData* getDataFabricacao(tUnidade* u);


void setDataFabricacao(tUnidade* u, tData* dataFab);


int getLote(tUnidade* u);
void setLote(tUnidade* u, int lote);


int idadeUnidade(tUnidade* u, tData* dataAlvo);

int menorUnidade(tUnidade* u1, tUnidade* u2, tData* dataAtualRef);


char* getUnidadeReq(tUnidade* u);

#endif