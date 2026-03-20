#include "TAD_Peso.h"
#include "TAD_Altura.h"
typedef struct pessoaIMC PessoaIMC;

PessoaIMC *criaPessoaIMC(Peso *peso, Altura *altura);
void liberaPessoaIMC(PessoaIMC*p);
void exibePessoaIMC(PessoaIMC*p);
void acessaPessoaIMC(PessoaIMC*p, Peso **peso, Altura **altura);
void atribuiPessoaIMC(PessoaIMC*p, Peso *peso, Altura *altura);
int comparaPessoaIMC(PessoaIMC*p1, PessoaIMC*p2);
char *getPessoaIMC(PessoaIMC*p);
float calculaIMC(PessoaIMC*p);
int *classificaIMC(float imc);
