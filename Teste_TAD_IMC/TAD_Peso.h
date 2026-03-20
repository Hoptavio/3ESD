//Cria a struct peso
typedef struct peso Peso;
//Função para criar peso aloca Kilogramas e gramas
Peso *criaPeso(float kg, float g);
//Função para liberar peso alocado
void liberaPeso(Peso*p);
//Função para exibir peso na tela
void exibePeso(Peso*p);
//Função para acessar peso e retornar os valores de kg e g
void acessaPeso(Peso*p, float*kg, float*g);
//Função para atribuir novos valores de peso
void atribuiPeso(Peso*p, float kg, float g);
//Função para comparar pesos
int comparaPeso(Peso*p1, Peso*p2);
//Função para somar peso em gramas
Peso *somaPeso(Peso*p, float g);
//Função para copiar peso
Peso *copiaPeso(Peso*p);
//Função para retornar uma string com os valores de peso no formato kg,g
char *getPeso(Peso*p);