#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


void inicalizar_nodo(nodo *n)
{
  int i;
  n->id = -1;
  n->distancia = -1;
  for(i=0; i<VECINOS_MAX; i++){
    n->vecinos[i] = -1;
  }
  n->predecesor = NULL;
}


void inicializar_grafo(nodo g[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    inicalizar_nodo(&(g[i]));
  }
}


void imprimir_nodo(nodo *n)
{
  int i;
  printf("%d %d: ",n->id, n->distancia);
  for(i=0; i<VECINOS_MAX; i++){
    printf("%d  ", n->vecinos[i]);
  }
  if(n->predecesor!= NULL){
    printf("Predecesor %d\n", n->predecesor->id);
  } else {
    printf("%s\n", "NULL");
  }
}


void imprimir_grafo(nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    imprimir_nodo(&(grafo[i]));
  }
}


void push(fifo *cola, nodo *n)
{
  cola->q[cola->final] = n;
  cola->final += 1;
}


nodo* pop(fifo *cola)
{
  nodo *ret;
  if(!estaVacio(cola)){
    ret = cola->q[cola->cabeza];
    cola->cabeza += 1;
  } else {
    ret = NULL;
  }
  return ret;
}


void imprimirStack(fifo *cola)
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


int estaVacio(fifo *cola)
{
  return cola->cabeza == cola->final;
}


int noFueVisitado(nodo *n)
{
  return n->distancia == -1;
}


// bfs()
// {
//   * inicializar las distancias a -1
//   * empezar la busqueda en la fuente y asignarle
//   una distancia de 0
//   * visitar todos los vecinos de la fuente y
//   asignarles una distancia de 1 y setear su
//   predecesor a la fuente
//   * visitar todos los vecinos de los vertices culla
//   distancia es 1 y que todavia no fueron visitados, y
//   asignarle a cada uno una distancia de 2 y su predecesor
//   al nodo correspondiente
//   * continuar hasta que todos los nodos fueron visitados
//
  // int i;
  // nodo* v, u;
  //
  // inicializar_grafo(g);
  // // pushear fuente
  // g[0].distancia = 0;
  // g[0].id = 0;
  // push(&(g[0]));
  //
  // while(!estaVacio(cola)){
  //   // sacar un vertice u de la cola
  //   u = pop(cola);
  //
  //   // por cada vecino v de u que no fue visitado:
  //   //   setear la distancia de v a 1 mas que la de u
  //   //   setear su predecesor a u
  //   //   pushear v

  //   for(i=0; i!= -1; i++){
  //     v = u->vecinos[i];
  //     if(noFueVisitado(v)){
  //       v->distancia = u->distancia + 1;
  //       v->predecesor = u
  //       push(cola, v);
  //     }
  //   }
  // }
// }
