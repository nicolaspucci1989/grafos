#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
  // nodo g[NODOS_MAX];
  // nodo *v;
  // nodo *u;
  nodo n;
  fifo cola;

  // inicializar_grafo(g);
  // g[0].id=0;
  // g[0].vecinos[0] = 1;
  // g[0].distancia = 0;
  //
  // g[1].id=1;
  // g[1].vecinos[0] = 2;
  // g[1].distancia = 1;
  inicalizar_nodo(&n);
  push(&cola, &n);
  imprimir_nodo(&n);
  // imprimir_nodo(&g[1]);
  // v = &g[0];
  // u = &g[1];
  // u = pop(&cola);
  // imprimir_nodo(u);
  // printf("%d\n", u->vecinos[0]);
  // imprimir_nodo(&g[u->vecinos[0]]);
  // v = &g[u->vecinos[0]];
  // v = u;
  // imprimir_nodo(v);
  return 0;
}
