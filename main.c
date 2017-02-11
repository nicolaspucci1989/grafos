#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
  // int id = 0, i;
  int matriz[FILAS][COLUMNAS];
  int vecinos[5];

  inicialiar_matriz(matriz);
  leer_grafo("grafo.txt", matriz);
  imprimir_matriz(matriz);

  //vecinos
  vecinos_de(0, matriz, vecinos);
  imprimir_vector(vecinos, 5);
  // for(i=0; i<COLUMNAS; i++){
  //   if(matriz[id][i]){
  //     printf("%d ", i);
  //   }
  // }
  return 0;
}
