#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  fifo cola;
  nodo n;
  cola.cabeza = cola.final = 0;


  inicalizar_nodo(&n);
  push(&cola, &n);
  imprimirStack(&cola);


  return 0;
}
