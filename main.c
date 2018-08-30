#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
TODO: https://gitlab.tadsufpr.net.br/ds141-alexkutzke/material/blob/master/aula_04.md
HACK: Tabela Simbolo:
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

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "Portuguese");
  int tam = 3;
  Pilha *p = create_stack(tam+1);
  time_te *valor = carregaVetor(10,9,2);
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

/*
Função: comparar os tempos fornecidos.
Retorna:
 1  se h1 >  h2
 0  se h1 == h2
 -1 se h1 <  h2 */
int time_cmp(time_t h1, time_t h2){
  return 1;
}

void push(Pilha *pilha, time_te *key, char *value){
  int i;
  // procura pela proxima posição livre
  while(pilha[i++]){
    if (pilha[i] == 0) {
      pilha[i]->valor = key;
      pilha[i]->chave = value;
    }
  }
}

char * pop(Pilha *p){
  if(empty(p)){
    printf("%s\n","Lista está vazia");
    exit(1);
  }
  p->topo--;
  char *v = p->vetor[p->topo]->chave;
  return v;
}

int empty(Pilha *p){
  for (int i=0;i < count; i++) {

  }
}
