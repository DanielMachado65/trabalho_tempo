#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
### Tabela Simbolo:
  * Para comparar duas chaves a e b.
  * put() e get().
*/

typedef struct horas{
  int horas;
  int minutos;
  int segundos;
} time_te;

/* contéudo da tabela */
typedef struct tabela{
  char *chave;
  time_te valor;
} timetable_t;

typedef struct pilha{
  int topo;
  int tam;
  timetable_t *vetor;
} Pilha;

Pilha * create_stack(int tam);
void push(Pilha *pilha, int e);
int full(Pilha *p);
// int pop(Pilha *p);
int empty(Pilha *p);
void free_stack(Pilha *p);
int time_cmp(time_t h1, time_t h2);
time_te * carregaVetor(int horas, int minutos, int segundos);

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "Portuguese");
  int tam = 3;
  Pilha *p = create_stack(tam+1);
  time_te *valor = carregaVetor(10,9,2);
  char *nome = (char *) malloc(sizeof(c));
  push(p, valor);

  // while (!empty(p)) {
  //   int e = pop(p);
  //   printf("%d\n",e);
  // }
  // free_stack(p);
  return 0;
}

time_te * carregaVetor(int horas, int minutos, int segundos){
  time_te *elemento = (time_te*) malloc(sizeof(time_te));
  elemento->horas = horas;
  elemento->minutos = minutos;
  elemento->segundos = segundos;
  return elemento;
}

/* Retorna:
 1  se h1 >  h2
 0  se h1 == h2
 -1 se h1 <  h2 */
int time_cmp(time_t h1, time_t h2){
  return 1;
}

/* Criando a pilha */
Pilha * create_stack(int tam){
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (timetable_t *) malloc(tam*sizeof(Pilha));
  return p;
}

int full(Pilha *p){
  return (p->topo == (p->tam-1));
}

void push(Pilha *pilha, time_te *key, char *value){
  if(full(pilha)){
    printf("%s\n","pilha cheia: capacidade ultrapassada");
    exit(1);
  }
  pilha->vetor[pilha->topo]->valor = key;
  pilha->vetor[pilha->topo]->chave = value;
  pilha->topo++;
}

// char * pop(Pilha *p){
//   if(empty(p)){
//     printf("%s\n","Lista está vazia");
//     exit(1);
//   }
//   p->topo--;
//   char *v = p->vetor[p->topo]->chave;
//   return v;
// }

int empty(Pilha *p){
  return (p->topo == 0);
}

void free_stack(Pilha *p){
  free(p->vetor);
  free(p);
}
