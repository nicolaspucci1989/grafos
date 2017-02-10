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
  putchar('\n');
}


void imprimir_grafo(nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    imprimir_nodo(&(grafo[i]));
  }
}


void push(fifo *cola, int item)
{
  cola->stack[cola->final] = item;
  cola->final += 1;
}


int pop(fifo *cola)
{
  int ret;
  if(cola->final){
    ret = cola->stack[cola->cabeza];
    cola->cabeza += 1;
  } else {
    printf("stack vacio!\n");
    ret = -1;
  }
  return ret;
}


void imprimirstack(fifo *cola)
{
  int i;
  if(cola->cabeza < cola->final){
    for(i=cola->cabeza; i < cola->final; i++){
      printf("%d ", cola->stack[i]);
    }
  } else {
    printf("stack vacio!");
  }
  putchar('\n');
}


int estaVacio(fifo *cola)
{
  return cola->cabeza == cola->final;
}
