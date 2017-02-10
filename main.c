#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  nodo u, v;
  inicalizar_nodo(&u);
  inicalizar_nodo(&v);

  u.predecesor = &v;
  imprimir_nodo(&u);
  return 0;
}
