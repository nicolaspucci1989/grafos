#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main() {
  int matriz[FILAS][COLUMNAS];
  int i;
  Nodo grafo[NODOS_MAX];
  Nodo *u, *v;
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


  inicializar_fifo(&fifo);
  inicializar_grafo(grafo);
  inicializar_matriz(matriz);
  leer_grafo("grafo.txt", matriz);

  grafo[0].distancia = 0;
  push(&fifo, &(grafo[0]));

  while(!estaVacio(&fifo)){
    u = pop(&fifo);
    for(i=0; i<COLUMNAS; i++){
    // i = 0;
      if(matriz[u->id][i] != 0 && grafo[i].distancia == -1){
        v = &(grafo[i]);
        v->distancia = u->distancia + 1;
        push(&fifo, v);
      }
    }
  }


  // bfs(grafo);
  imprimir_grafo(grafo);

  return 0;
}
