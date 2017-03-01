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


void inicializar_fifo_ff(Fifoff *f)
{
  f->cabeza = f->final = 0;
}


void imprimir_nodo_ff(Nodoff *n, int numeroDeNodos)
{
  int i;
  printf("Id %d caminoDeAumento %d Estado %d ",n->id, n->caminoDeAumento, n->estado);
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


void inicializar_nodo_ff(Nodoff *n, int id)
{
  int i;
  n->id = id;
  n->caminoDeAumento = -1;
  n->estado = NODO_INICIALIZADO;
  for(i=0; i<NODOS_MAX; i++)
    n->capacidad[i]=0;
}


void inicializar_flujo(Nodoff *n)
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    n->flujo[i] = 0;
  }
}


void inicializar_flujo_grafo(Nodoff grafo[], int numeroDeNodos)
{
  int i;

  for(i=0; i<numeroDeNodos; i++)
    inicializar_flujo(&(grafo[i]));
}


void inicializar_grafo_ff(Nodoff grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++)
    inicializar_nodo_ff(&(grafo[i]), i);
}


void imprimir_grafo_ff(Nodoff grafo[], int numeroDeNodos)
{
  int i;
  for(i=0; i<numeroDeNodos; i++)
    imprimir_nodo_ff(&(grafo[i]), numeroDeNodos);
}


void push_ff(Fifoff *cola, Nodoff *n)
{
  cola->q[cola->final] = n;
  cola->final += 1;
  n->estado = NODO_EN_COLA;
}


Nodoff* pop_ff(Fifoff *cola)
{
  Nodoff *ret;
  if(!estaVacio_ff(cola)){
    ret = cola->q[cola->cabeza];
    ret->estado = NODO_ALCANZADO;
    cola->cabeza += 1;
  } else {
    ret = NULL;
  }
  return ret;
}


int estaVacio_ff(Fifoff *cola)
{
  return cola->cabeza == cola->final;
}


void leer_grafo_ff(FILE* input, Nodoff grafo[],
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


void inicializar_estado_nodos(Nodoff grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    grafo[i].estado = NODO_INICIALIZADO;
  }
}


int bfs_ff(Nodoff grafo[], int fuente, int sumidero, int numeroDeNodos)
{
  int i;
  Fifoff fifo;
  Nodoff *u;


  inicializar_estado_nodos(grafo);
  inicializar_fifo_ff(&fifo);
  push_ff(&fifo, &(grafo[fuente]));


  while(!estaVacio_ff(&fifo)){
    u = pop_ff(&fifo);
    for(i=0; i<numeroDeNodos; i++){
      if(grafo[i].estado == NODO_INICIALIZADO &&
        u->capacidad[i] - u->flujo[i] > 0){
        push_ff(&fifo, &(grafo[i]));
        u->caminoDeAumento = i;
        // break;
      }
    }
  }


  grafo[sumidero].caminoDeAumento = -1;
  return grafo[sumidero].estado == NODO_ALCANZADO;
}


int minimo(int a, int b)
{
  return a < b ? a : b;
}


int ford_fulkerson(int fuente, int sumidero, Nodoff grafo[], int numeroDeNodos)
{
  int flujoMaximo = 0;
  int incremento;
  Nodoff *nodo;

  //Inicializar el flujo en 0
  inicializar_flujo_grafo(grafo, numeroDeNodos);


    bfs_ff(grafo, fuente, sumidero, numeroDeNodos);
  // while(bfs_ff(grafo, fuente, sumidero, numeroDeNodos)){
    incremento = INFINITO;
    // desde la fuente hasta llegar al sumidero, siguiendo el
    // camino de aumento
    for(nodo=&(grafo[fuente]); grafo[nodo->id].caminoDeAumento > 0;
        nodo=&(grafo[nodo->caminoDeAumento])){
          incremento = minimo(incremento, nodo->capacidad[nodo->caminoDeAumento]
                      - nodo->flujo[nodo->caminoDeAumento]);
        }


    //ahora incrementar el flujo a lo largo del camino de aumento
    // for(nodo=&(grafo[fuente]); grafo[nodo->id].caminoDeAumento > 0;
    //     nodo=&(grafo[nodo->caminoDeAumento])){
    //       nodo->flujo[nodo->caminoDeAumento] += incremento;
    //       grafo[nodo->caminoDeAumento].flujo[nodo->id] -= incremento;
    //     }

    // for(nodo=numeroDeNodos - 1; grafo[nodo].caminoDeAumento>=0; nodo=grafo[nodo].caminoDeAumento){
    //   flujo[nodo][grafo[nodo].caminoDeAumento] += incremento;
    //   flujo[grafo[nodo].caminoDeAumento][nodo] -= incremento;
    // }


    flujoMaximo += incremento;
  // }


  return flujoMaximo;
  // return incremento;
}
