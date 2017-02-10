#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  fifo cola;
  nodo n;
  cola.cabeza = cola.final = 0;


  inicalizar_nodo(&n);
  push(&cola, &n);
  imprimir_nodo(cola.q[0]);
  imprimir_nodo(pop(&cola));
  if (pop(&cola) == NULL) {
    printf("%s\n", "NULL");
  } else {
    printf("%s\n", "No NULL");
  }

  return 0;
}
