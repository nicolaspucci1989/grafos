#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
  Nodo *g, *v, *u;
  Fifo *f;


  f = newFifo();
  g = malloc(NODOS_MAX * sizeof(Nodo));
  inicializar_fifo(f);
  inicializar_grafo(g);
  g[0].distancia = 0;
  g[0].id = 0;
  g[0].vecinos[0] = 1;
  g[0].vecinos[1] = 2;
  g[1].id = 1;
  g[1].vecinos[0] = 0;
  g[1].vecinos[1] = 3;
  imprimirFifo(f);
  push(f, &(g[0]));
  imprimirFifo(f);
  u = pop(f);
  imprimirFifo(f);
  v = &(g[u->vecinos[0]]);
  if(noFueVisitado(v)){
    v->distancia = u->distancia + 1;
    v->predecesor = u;
    push(f, v);
  }
  imprimirFifo(f);


  free(f);
  free(g);
  return 0;
}
