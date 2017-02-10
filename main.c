#include "grafos.h"
// #define STACK_MAX 5
//
// typedef struct {
//   int stack[STACK_MAX];
//   int final;
// } fifo;


int main() {
  int stack[5];
  int  final = 0;
  // fifo cola;


  push(stack, 1, &final);
  imprimirstack(stack, final);
  push(stack, 2, &final);
  imprimirstack(stack, final);
  push(stack, 3, &final);
  imprimirstack(stack, final);
  pop(stack, &final);
  imprimirstack(stack, final);
  pop(stack, &final);
  imprimirstack(stack, final);
  pop(stack, &final);
  imprimirstack(stack, final);


  return 0;
}
