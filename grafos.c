#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


void formatoDeArchivo(){
  printf("\nFormato de archivo de entrada:\n");
  printf("<cantidad de nodos> <fuente> <sumidero>\n");
  printf("<vertice 1> <vertice 2> <capacidad>\n");
  printf(".\n.\n.\n");
  printf("<vertice n> <vertice m> <capacidad>\n");
}


void inicializar_fifo(Fifo *f)
{
  f->cabeza = f->final = 0;
}


void imprimir_nodo(Nodo *n, int numeroDeNodos)
{
  int i;
  printf("Id %d predecesor %d Estado %d ",n->id, n->predecesor, n->estado);
  // imprimir capacidad
  printf("%s", "Capacidad: ");
  for(i=0; i<numeroDeNodos; i++){
    printf("%d  ", n->capacidad[i]);
  }
  // imprimir flujo
  printf("%s", "Flujo: ");
  for(i=0; i<numeroDeNodos; i++){
    printf("%d  ", n->flujo[i]);
  }
  putchar('\n');
}


void inicializar_nodo(Nodo *n, int id)
{
  int i;
  n->id = id;
  n->estado = NODO_INICIALIZADO;
  for(i=0; i<NODOS_MAX; i++)
    n->capacidad[i]=0;
}


void inicializar_flujo(Nodo *n)
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    n->flujo[i] = 0;
  }
}


void inicializar_flujo_grafo(Nodo grafo[], int numeroDeNodos)
{
  int i;

  for(i=0; i<numeroDeNodos; i++)
    inicializar_flujo(&(grafo[i]));
}


void inicializar_grafo(Nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++)
    inicializar_nodo(&(grafo[i]), i);
}


void imprimir_grafo(Nodo grafo[], int numeroDeNodos)
{
  int i;
  for(i=0; i<numeroDeNodos; i++)
    imprimir_nodo(&(grafo[i]), numeroDeNodos);
}


void push(Fifo *cola, Nodo *n)
{
  cola->q[cola->final] = n;
  cola->final += 1;
  n->estado = NODO_EN_COLA;
}


Nodo* pop(Fifo *cola)
{
  Nodo *ret;
  if(!estaVacio(cola)){
    ret = cola->q[cola->cabeza];
    ret->estado = NODO_ALCANZADO;
    cola->cabeza += 1;
  } else {
    ret = NULL;
  }
  return ret;
}


int estaVacio(Fifo *cola)
{
  return cola->cabeza == cola->final;
}


void leer_grafo(FILE* input, Nodo grafo[],
                  int *fuente, int *sumidero, int *cantidadDeNodos)
{
  int numeroDeVertices;
  int nodoU, nodoV, capacidad;
  int i;
  fscanf(input, "%d %d %d %d",cantidadDeNodos, &numeroDeVertices, fuente, sumidero);
  for(i=0; i<numeroDeVertices; i++){
    fscanf(input, "%d %d %d", &nodoU, &nodoV, &capacidad);
    grafo[nodoU].capacidad[nodoV] = capacidad;
  }
}


void inicializar_estado_nodos(Nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    grafo[i].estado = NODO_INICIALIZADO;
  }
}


int bfs(Nodo grafo[], int fuente, int sumidero, int numeroDeNodos)
{
  int i;
  Fifo fifo;
  Nodo *u;


  inicializar_estado_nodos(grafo);
  inicializar_fifo(&fifo);
  grafo[fuente].predecesor = -1;
  push(&fifo, &(grafo[fuente]));


  while(!estaVacio(&fifo)){
    u = pop(&fifo);
    for(i=0; i<numeroDeNodos; i++){
      if(grafo[i].estado == NODO_INICIALIZADO &&
        u->capacidad[i] - u->flujo[i] > 0){
        push(&fifo, &(grafo[i]));
        grafo[i].predecesor = u->id;
      }
    }
  }


  return grafo[sumidero].estado == NODO_ALCANZADO;
}


int minimo(int a, int b)
{
  return a < b ? a : b;
}


int ford_fulkerson(int fuente, int sumidero, Nodo grafo[], int numeroDeNodos)
{
  int flujoMaximo = 0;
  int incremento;
  Nodo *nodo;

  //Inicializar el flujo en 0
  inicializar_flujo_grafo(grafo, numeroDeNodos);


  while(bfs(grafo, fuente, sumidero, numeroDeNodos)){
    incremento = INFINITO;
    // desde el sumider hasta llegar a la fuente inclusive, siguiendo el
    // camino de aumento (predecesor)
    for(nodo=&(grafo[sumidero]); nodo->predecesor >= 0;
        nodo=&(grafo[nodo->predecesor])){
          incremento = minimo(incremento, grafo[nodo->predecesor].capacidad[nodo->id]
                      - grafo[nodo->predecesor].flujo[nodo->id]);
        }


    //ahora incrementar el flujo a lo largo del camino de aumento
    for(nodo=&(grafo[sumidero]); nodo->predecesor >= 0;
        nodo=&(grafo[nodo->predecesor])){
          grafo[nodo->predecesor].flujo[nodo->id] += incremento;
          grafo[nodo->id].flujo[nodo->predecesor] -= incremento;
        }


    flujoMaximo += incremento;
  }


  return flujoMaximo;
}
