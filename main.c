#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  Nodoff nodo;
  Fifoff fifo;
  inicalizar_nodo_ff(&nodo, 0);
  inicializar_fifo_ff(&fifo);
  push_ff(&fifo, &nodo);
  imprimir_nodo_ff(pop_ff(&fifo));
  return 0;
}
