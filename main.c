#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  int matriz[FILAS][COLUMNAS];
  Nodo grafo[NODOS_MAX];
  Fifo fifo;


  // grafo[0].id = 0;
  // grafo[0].vecinos[0] = 1;
  // grafo[0].vecinos[1] = 2;
  // grafo[1].id = 1;
  // grafo[1].vecinos[0] = 0;
  // grafo[1].vecinos[1] = 3;
  // grafo[2].id = 2;
  // grafo[2].vecinos[0] = 0;
  // grafo[2].vecinos[1] = 3;
  // grafo[3].id = 3;
  // grafo[3].vecinos[0] = 1;
  // grafo[3].vecinos[1] = 2;


  inicializar_matriz(matriz);
  leer_grafo("grafo.txt", matriz);


  // bfs(grafo);
  // imprimir_grafo(grafo);

  return 0;
}
