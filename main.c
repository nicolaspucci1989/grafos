#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main(int argc, char const *argv[]) {
  FILE* archivo = NULL;
  if (argc <= 1){
    formatoDeArchivo();
    exit(1);
  } else if((archivo = fopen(argv[1], "r")) == NULL){
    puts("Erro al abrir archivo.");
    exit(1);
  } else {
    Nodoff grafo[NODOS_MAX];
    int fuente, sumidero;
    int matrizDeCapacidades[NODOS_MAX][NODOS_MAX];


    inicializar_grafo_ff(grafo);
    leer_grafo_ff(archivo, grafo, matrizDeCapacidades, &fuente, &sumidero);
    imprimir_grafo_ff(grafo);
    fclose(archivo);
  }
  return 0;
}
