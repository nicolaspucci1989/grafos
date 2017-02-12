#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  // int vecinos[VECINOS_MAX];
  int i;
  Nodo *m = NULL, *n = NULL;
  Nodo grafo[NODOS_MAX];
  Fifo fifo;


  inicializar_fifo(&fifo);
  inicializar_grafo(grafo);

  grafo[0].id = 0;
  grafo[0].vecinos[0] = 1;
  grafo[0].vecinos[1] = 2;
  grafo[1].id = 1;
  grafo[1].vecinos[0] = 0;
  grafo[1].vecinos[1] = 3;
  grafo[2].id = 2;
  grafo[2].vecinos[0] = 0;
  grafo[2].vecinos[1] = 3;
  grafo[3].id = 3;
  grafo[3].vecinos[0] = 1;
  grafo[3].vecinos[1] = 2;

  //push fuente 0
  grafo[0].distancia = 0;
  push(&fifo, &(grafo[0]));

  while(!estaVacio(&fifo)){
    m = pop(&fifo);
    for(i=0; i<VECINOS_MAX; i++){
      if( m->vecinos[i] != -1 && grafo[m->vecinos[i]].distancia == -1){
        n = &(grafo[m->vecinos[i]]);
        n->distancia = m->distancia + 1;
        // n->predecesor = m;
        push(&fifo, n);
      }
    }
  }

  imprimir_grafo(grafo);


  // if(!estaVacio(&fifo)){
  //   m = pop(&fifo);
  //   n = &(grafo[m->vecinos[0]]);
  //   n->distancia = m->distancia + 1;
  //   n->predecesor = m;
  //   imprimir_nodo(n);
  // }
  //
  return 0;
}
