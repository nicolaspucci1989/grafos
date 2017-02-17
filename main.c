#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


void inicializarMatriz(int matriz[NODOS_MAX][NODOS_MAX])
{
  int i,j;
  for(i=0; i<NODOS_MAX; i++){
    for(j=0; j<NODOS_MAX; j++){
      matriz[i][j] = -1;
    }
  }
}


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
    int flujo[NODOS_MAX][NODOS_MAX];
    int resultado;

    inicializarMatriz(capacidad);
    inicializar_grafo_ff(grafo);


    leer_grafo_ff(archivo, grafo,
      capacidad, &fuente, &sumidero);
    fclose(archivo);
    resultado = bfs_ff(grafo, fuente, sumidero,
      capacidad, flujo);
    if(resultado)
      printf("%s\n", "nodo alcanzado!!");
    else
      printf("%s\n", "nodo no alcanzado!!");
  }

  
  return 0;
}
