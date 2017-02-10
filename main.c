#include "grafos.h"


int main() {
  // int stack[5];
  // int  final = 0;
  fifo cola;


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
  pop(&cola);


  return 0;
}
