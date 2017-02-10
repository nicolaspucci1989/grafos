#include "grafos.h"


int main() {
  fifo cola;
  nodo n;
  cola.cabeza = cola.final = 0;


  inicalizar_nodo(&n);
  push(&cola, &n);
  imprimir_nodo(cola.q[0]);


  return 0;
}
