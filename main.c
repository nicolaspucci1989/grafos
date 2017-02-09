#include "grafos.h"

int main(int argc, char const *argv[]) {
  nodo grafo[NODOS_MAX];
  inicializar_grafo(grafo);
  imprimir_grafo(grafo);
  return 0;
}
