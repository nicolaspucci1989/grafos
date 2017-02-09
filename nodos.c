#include <stdio.h>
#include <stdlib.h>
#define VECINOS_MAX 5
#define NODOS_MAX 5


typedef struct {
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];
} nodo;


void inicalizar_nodo(nodo *n){
  int i;
  n->id = -1;
  n->distancia = -1;
  for(i=0; i<VECINOS_MAX; i++){
    n->vecinos[i] = -1;
  }
}


void inicializar_grafo(nodo g[]){
  int i;
  for(i=0; i<NODOS_MAX; i++){
    inicalizar_nodo(&(g[i]));
  }
}


void imprimir_nodo(nodo *n){
  int i;
  printf("%d %d: ",n->id, n->distancia);
  for(i=0; i<VECINOS_MAX; i++){
    printf("%d  ", n->vecinos[i]);
  }
  putchar('\n');
}


void imprimir_grafo(nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    imprimir_nodo(&(grafo[i]));
  }
}


int main(int argc, char const *argv[]) {
  nodo grafo[NODOS_MAX];
  inicializar_grafo(grafo);
  imprimir_grafo(grafo);
  return 0;
}
