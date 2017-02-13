#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  Nodo *m;
  Nodo grafo[NODOS_MAX];
  Fifo f;


  inicializar_grafo(grafo);
  grafo[0].id = 0;
  grafo[1].id = 1;
  grafo[2].id= 2;
  push(&f, &grafo[0]);
  push(&f, &grafo[1]);
  push(&f, &grafo[2]);
  imprimirFifo(&f);


  puts("==================");


  // imprimirFifo(f);
  m = pop(&f);
  imprimir_nodo(m);
  m = pop(&f);
  imprimir_nodo(m);
  m = pop(&f);
  imprimir_nodo(m);


  return 0;
}
