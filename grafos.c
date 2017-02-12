#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


Nodo* newNodo()
{
  return  malloc(sizeof(Nodo));
}


Fifo* newFifo()
{
  return  malloc(sizeof(Fifo));
}


void inicalizar_nodo(Nodo *n)
{
  int i;
  n->id = -1;
  n->distancia = -1;
  for(i=0; i<VECINOS_MAX; i++){
    n->vecinos[i] = -1;
  }
  n->predecesor = NULL;
}


void inicializar_grafo(Nodo g[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    inicalizar_nodo(&(g[i]));
  }
}


void inicializar_fifo(Fifo *f)
{
  f->cabeza = f->final = 0;
}


void imprimir_nodo(Nodo *n)
{
  int i;
  printf("Id %d Dist %d Vecinos: ",n->id, n->distancia);
  for(i=0; i<VECINOS_MAX; i++){
    printf("%d  ", n->vecinos[i]);
  }
  if(n->predecesor!= NULL){
    printf("Predecesor %d\n", n->predecesor->id);
  } else {
    printf("%s\n", "NULL");
  }
}


void imprimir_grafo(Nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    imprimir_nodo(&(grafo[i]));
  }
}


void push(Fifo *cola, Nodo *n)
{
  cola->q[cola->final] = n;
  cola->final += 1;
}


Nodo* pop(Fifo *cola)
{
  Nodo *ret;
  if(!estaVacio(cola)){
    ret = cola->q[cola->cabeza];
    cola->cabeza += 1;
  } else {
    ret = NULL;
  }
  return ret;
}


void imprimirFifo(Fifo *cola)
{
  int i;
  if(!estaVacio(cola)){
    for(i=cola->cabeza; i < cola->final; i++){
      imprimir_nodo(cola->q[i]);
    }
  } else {
    printf("cola vacia!\n");
  }
}


int estaVacio(Fifo *cola)
{
  return cola->cabeza == cola->final;
}


int noFueVisitado(Nodo *n)
{
  return n->distancia == -1;
}


// con matriz de adyacencia
void leer_grafo(char *archivo, int matriz[][COLUMNAS])
{
  int i, m, n, cantidadDeVertices;
  FILE* input = fopen(archivo,"r");
  fscanf(input, "%d", &cantidadDeVertices);
  for(i=0; i<cantidadDeVertices; i++){
    fscanf(input, "%d %d", &m, &n);
    matriz[m][n] = 1;
    matriz[n][m] = 1;
  }
  fclose(input);
}


void imprimir_matriz(int matriz[][COLUMNAS])
{
  int i, j;
  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      printf("%d ", matriz[i][j]);
    }
  putchar('\n');
  }
}


void inicializar_matriz(int matriz[][COLUMNAS])
{
  int i,j;
  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      matriz[i][j] = 0;
    }
  }
}


void inicializar_vector(int vector[], int n)
{
  int i;
  for(i=0; i<n; i++){
    vector[i] = -1;
  }
}


void vecinos_de(int nodo, int matriz[][COLUMNAS], int vecinos[])
{
  int i, j;

  inicializar_vector(vecinos, 5);
  for(i=0, j=0; i<COLUMNAS; i++ ){
    if(matriz[nodo][i]){
      vecinos[j] = i;
      j++;
    }
  }
}


void imprimir_vector(int vector[], int n)
{
  int i;
  for(i=0; i< n; i++){
    printf("%d ", vector[i]);
  }
  putchar('\n');
}

//
// void bfs(Nodo grafo[])
// {
// //   * inicializar las distancias a -1
// //   * empezar la busqueda en la fuente y asignarle
// //   una distancia de 0
// //   * visitar todos los vecinos de la fuente y
// //   asignarles una distancia de 1 y setear su
// //   predecesor a la fuente
// //   * visitar todos los vecinos de los vertices culla
// //   distancia es 1 y que todavia no fueron visitados, y
// //   asignarle a cada uno una distancia de 2 y su predecesor
// //   al nodo correspondiente
// //   * continuar hasta que todos los nodos fueron visitados
// //
//   int i;
//   Nodo *v, *u;
//   Fifo *cola;
//   cola = newFifo();
//
//   inicializar_grafo(g);
//   // pushear fuente
//   g[0].distancia = 0;
//   push(cola, &(g[0]));
//
//   while(!estaVacio(cola)){
//     // sacar un vertice u de la cola
//     u = pop(cola);
//
//     // por cada vecino v de u que no fue visitado:
//     //   setear la distancia de v a 1 mas que la de u
//     //   setear su predecesor a u
//     //   pushear v
//
//
//     vecinos_de(u->id, matrizDeAdyacencia, vecinos);
//     for(i=0; i<VECINOS_MAX; i++){
//       if(vecinos[i] != -1 &&
//         grafo[vecinos[i]].distancia != -1){
//           grafo[i].distancia = u->distancia + 1;
//           grafo[i].predecesor = u;
//           push(&grafo[i]);
//       }
//     }
//
//
//
//     for(i=0; u.vecinos[i] != -1 && i < VECINOS_MAX; i++){
//       v = &(grafo[u->vecinos[i]]);
//       if(noFueVisitado(v)){
//         v->distancia = u->distancia + 1;
//         v->predecesor = u
//         push(cola, v);
//       }
//     }
//   }
// }


void bfs(Nodo grafo[])
{
  Nodo *n, *m;
  Fifo fifo;
  int i;

  // inicializar_grafo(grafo);
  inicializar_fifo(&fifo);
  grafo[0].distancia = 0;
  push(&fifo, &(grafo[0]));

  while(!estaVacio(&fifo)){
    m = pop(&fifo);
    for(i=0; i<VECINOS_MAX; i++){
      if( m->vecinos[i] != -1 && grafo[m->vecinos[i]].distancia == -1){
        n = &(grafo[m->vecinos[i]]);
        n->distancia = m->distancia + 1;
        // n->predecesor = m;
        push(&fifo, n);
      }
    }
  }
}
