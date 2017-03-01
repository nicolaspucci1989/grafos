#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


void inicializarMatriz(int matriz[NODOS_MAX][NODOS_MAX],
                      int valor)
{
  int i,j;
  for(i=0; i<NODOS_MAX; i++){
    for(j=0; j<NODOS_MAX; j++){
      matriz[i][j] = valor;
    }
  }
}


void imprimirMatriz(int matriz[][NODOS_MAX])
{
  int i, j;
  for(i=0; i<NODOS_MAX; i++){
    for(j=0; j<NODOS_MAX; j++){
      printf("%d ", matriz[i][j]);
    }
  putchar('\n');
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
    int resultado;
    int numeroDeNodos;


    inicializar_grafo_ff(grafo);
    leer_grafo_ff(archivo, grafo, &fuente, &sumidero, &numeroDeNodos);
    fclose(archivo);
    resultado = ford_fulkerson(fuente, sumidero, grafo, numeroDeNodos);
    printf("%s %d\n", "Flujo maximo:", resultado);
    // imprimir_grafo_ff(grafo, numeroDeNodos);
  }


  return 0;
}
