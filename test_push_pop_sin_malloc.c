#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  Nodo *m, n, v, x;
  Fifo f;


  inicalizar_nodo(&v);
  inicalizar_nodo(&x);
  inicalizar_nodo(&n);
  inicializar_fifo(&f);
  n.id = 1;
  x.id = 2;
  v.id= 3;
  push(&f, &n);
  push(&f, &x);
  push(&f, &v);
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
