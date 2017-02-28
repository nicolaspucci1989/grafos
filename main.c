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
    int capacidad[NODOS_MAX][NODOS_MAX];
    int resultado;


    inicializar_grafo_ff(grafo);


    leer_grafo_ff(archivo, grafo,
      capacidad, &fuente, &sumidero);
    fclose(archivo);
    resultado = ford_fulkerson(fuente, sumidero, grafo, capacidad);
    printf("%d\n", resultado);
  }

  return 0;
}
