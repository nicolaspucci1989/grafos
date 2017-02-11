#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
  int matriz[FILAS][COLUMNAS];
  inicialiar_matriz(matriz);
  leer_grafo("grafo.txt", matriz);
  imprimir_matriz(matriz);
  return 0;
}
