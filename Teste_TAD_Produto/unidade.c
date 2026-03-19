#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unidade.h"
#include "Data.h"

struct unidade {
    tData* dataFab;
    int lote;
};

tUnidade* criaUnidade(tData* dataFab, int lote) {
    tUnidade* u = (tUnidade*)malloc(sizeof(tUnidade));
    if (dataFab == NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        u->dataFab = dta_cria(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    } else {
        u->dataFab = dataFab;
    }
    u->lote = lote;
    return u;
}

void liberaUnidade(tUnidade* u) {
    if (u != NULL) {
        if (u->dataFab != NULL) {
            dta_libera(u->dataFab);
        }
        free(u);
    }
}

void exibirUnidade(tUnidade* u) {
    if (u == NULL) return;
    printf("Lote: %d | Data Fab: ", u->lote);
    dta_exibe(u->dataFab);
}

tData* getDataFabricacao(tUnidade* u) {
    return u->dataFab;
}

void setDataFabricacao(tUnidade* u, tData* d) {
    u->dataFab = d;
}

int getLote(tUnidade* u) {
    return u->lote;
}

void setLote(tUnidade* u, int l) {
    u->lote = l;
}

int idadeUnidade(tUnidade* u, tData* dataAlvo) {
    int dif = dta_diferenca(u->dataFab, dataAlvo) - 1;
    return dif >= 0 ? dif : -dif; 
}

int menorUnidade(tUnidade* u1, tUnidade* u2, tData* dataAtualRef) {
    int idade1 = idadeUnidade(u1, dataAtualRef);
    int idade2 = idadeUnidade(u2, dataAtualRef);
    if (idade1 < idade2) return 1;
    if (idade1 == idade2) {
        if (u1->lote < u2->lote) return 1;
    }
    return 0;
}

char* getUnidadeReq(tUnidade* u) {
    char* strData = dta_getData(u->dataFab);
    char* str = (char*)malloc(100);
    sprintf(str, "Lote: %d, Fabricado em: %s", u->lote, strData);
    free(strData);
    return str;
}