#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
  fifo cola;
  cola.cabeza = cola.final = 0;

  
  push(&cola, 1);
  imprimirstack(&cola);
  push(&cola, 2);
  imprimirstack(&cola);
  push(&cola, 3);
  imprimirstack(&cola);
  pop(&cola);
  imprimirstack(&cola);
  pop(&cola);
  imprimirstack(&cola);
  pop(&cola);
  imprimirstack(&cola);


  return 0;
}
