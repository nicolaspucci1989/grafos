#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


int main(int argc, char *argv[]) {
  Nodo grafo[NODOS_MAX];
  FILE* archivo = NULL;


  if (argc <= 1) { // si no hay argumento, error
    printf("USO: bfs <nombre de archivo>\n");
    formatoDeArchivo();
    exit(1);
  } else if ((archivo = fopen(argv[1],"r")) == NULL){
    puts("Error al abrir archivo");
    exit(1);
  } else {
    inicializar_grafo(grafo);
    leer_grafo(archivo, grafo);
    bfs_con_vector_de_adyacencia(grafo);
    imprimir_grafo(grafo);
  }


  fclose(archivo);


  return 0;
}
