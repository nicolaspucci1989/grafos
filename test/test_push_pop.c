#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
  Nodo *n, *m, *v, *x;
  Fifo *f = NULL;

  f = newFifo(f);
  f->final = f->cabeza = 0;
  n = newNodo();
  v = newNodo();
  x = newNodo();
  inicalizar_nodo(v);
  inicalizar_nodo(x);
  inicalizar_nodo(n);
  n->id = 1;
  x->id = 2;
  v->id = 3;
  push(f, n);
  push(f, x);
  push(f, v);
  imprimirFifo(f);
  puts("==================");

  // imprimirFifo(f);
  m = pop(f);
  imprimir_nodo(m);
  m = pop(f);
  imprimir_nodo(m);
  m = pop(f);
  imprimir_nodo(m);


  free(n);
  free(x);
  free(v);
  free(f);

  return 0;
}
