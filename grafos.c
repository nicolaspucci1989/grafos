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


Nodo* newNodo()
{
  return  malloc(sizeof(Nodo));
}


Fifo* newFifo()
{
  return  malloc(sizeof(Fifo));
}


void inicalizar_nodo(Nodo *n, int id)
{
  int i;
  n->id = id;
  n->distancia = -1;
  for(i=0; i<VECINOS_MAX; i++){
    n->vecinos[i] = 0;
  }
}


void inicializar_grafo(Nodo g[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    inicalizar_nodo(&(g[i]), i);
  }
}


void inicializar_fifo(Fifo *f)
{
  f->cabeza = f->final = 0;
}

void inicializar_fifo_ff(Fifoff *f)
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
  putchar('\n');
}


void imprimir_nodo_ff(Nodoff *n)
{
  int i;
  printf("Id %d caminoDeAumento %d Estado %d Vecinos: ",n->id, n->caminoDeAumento, n->estado);
  for(i=0; i<VECINOS_MAX; i++){
    printf("%d  ", n->vecinos[i]);
  }
  putchar('\n');
}


void inicalizar_nodo_ff(Nodoff *n, int id)
{
  int i;
  n->id = id;
  // n->caminoDeAumento = -1;
  for(i=0; i<VECINOS_MAX; i++)
    n->vecinos[i] = 0;
}


void inicializar_grafo_ff(Nodoff grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++)
    inicalizar_nodo_ff(&(grafo[i]), i);
}


void imprimir_grafo_ff(Nodoff grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++)
    imprimir_nodo_ff(&(grafo[i]));
}


void imprimir_grafo(Nodo grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    if(grafo[i].distancia != -1){
      imprimir_nodo(&(grafo[i]));
    }
  }
}


void push(Fifo *cola, Nodo *n)
{
  cola->q[cola->final] = n;
  cola->final += 1;
}

void push_ff(Fifoff *cola, Nodoff *n)
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
    cola->cabeza += 1;
  } else {
    ret = NULL;
  }
  return ret;
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


int estaVacio_ff(Fifoff *cola)
{
  return cola->cabeza == cola->final;
}


int noFueVisitado(Nodo *n)
{
  return n->distancia == -1;
}


//con struct nodo
void leer_grafo(FILE* input , Nodo grafo[])
{
  int i, nodoU, nodoV, cantidadDeVertices;
  fscanf(input, "%d", &cantidadDeVertices);
  for(i=0; i<cantidadDeVertices; i++){
    fscanf(input, "%d %d", &nodoU, &nodoV);
    grafo[nodoU].vecinos[nodoV] = 1;
    grafo[nodoV].vecinos[nodoU] = 1;
  }
}


void leer_grafo_ff(FILE* input, Nodoff grafo[],
                  int matrizDeCapacidades[NODOS_MAX][NODOS_MAX],
                  int *fuente, int *sumidero)
{
  int nodoU, nodoV, cantidadDeNodos, capacidad;
  int i;
  fscanf(input, "%d %d %d",&cantidadDeNodos, fuente, sumidero);
  for(i=0; i<cantidadDeNodos; i++){
    fscanf(input, "%d %d %d", &nodoU, &nodoV, &capacidad);
    grafo[nodoU].vecinos[nodoV] = 1;
    grafo[nodoV].vecinos[nodoU] = 1;
    matrizDeCapacidades[nodoU][nodoV] = capacidad;
  }
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
        push(&fifo, n);
      }
    }
  }
}


void inicializar_fuente(Nodo *n){
  n->distancia = 0;
}


void bfs_con_vector_de_adyacencia(Nodo grafo[])
{
  int i;
  Fifo fifo;
  Nodo *u, *v;


  inicializar_fifo(&fifo);
  inicializar_fuente(&(grafo[0])); // a 0
  push(&fifo, &(grafo[0]));


  while(!estaVacio(&fifo)){
    u = pop(&fifo);
    for(i=0; i<VECINOS_MAX; i++){
      if(u->vecinos[i] != 0 && grafo[i].distancia == -1){
        v = &(grafo[i]);
        v->distancia = u->distancia + 1;
        push(&fifo, v);
      }
    }
  }
}

void inicializar_estado_nodos(Nodoff grafo[])
{
  int i;
  for(i=0; i<NODOS_MAX; i++){
    grafo[i].estado = NODO_INICIALIZADO;
  }
}


int bfs_ff(Nodoff grafo[], int fuente,
            int sumidero,
            int capacidad[NODOS_MAX][NODOS_MAX],
            int flujo[][NODOS_MAX])
{
  int i;
  Fifoff fifo;
  Nodoff *u;


  inicializar_estado_nodos(grafo);
  inicializar_fifo_ff(&fifo);
  // grafo[fuente].caminoDeAumento = -1;
  push_ff(&fifo, &(grafo[fuente]));


  while(!estaVacio_ff(&fifo)){
    u = pop_ff(&fifo);
    for(i=0; i<VECINOS_MAX; i++){
      if(u->vecinos[i] == 1){
        if(grafo[i].estado == NODO_INICIALIZADO &&
        capacidad[u->id][i] - flujo[u->id][i] > 0){
          push_ff(&fifo, &(grafo[i]));
          u->caminoDeAumento = i;
        }
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

int ford_fulkerson(int fuente, int sumidero,
                  Nodoff grafo[], int capacidad[NODOS_MAX][NODOS_MAX])
{
  int incremento;
  int i, j;
  int flujo[NODOS_MAX][NODOS_MAX];
  Nodoff *nodo;


  //Inicializar el flujo en 0
  for(i=0; i<NODOS_MAX; i++){
    for(j=0; j<NODOS_MAX; j++){
      flujo[i][j] = 0;
    }
  }

    bfs_ff(grafo, fuente, sumidero, capacidad, flujo);
  // while(bfs_ff(grafo, fuente, sumidero, capacidad, flujo)){
    incremento = INFINITO;
    // desde la fuente hasta llegar al sumidero, siguiendo el
    // camino de aumento
    for(nodo=&(grafo[fuente]); grafo[nodo->id].caminoDeAumento > 0;
        nodo=&(grafo[nodo->caminoDeAumento])){
          incremento = minimo(incremento, capacidad[nodo->id][nodo->caminoDeAumento]
                      - flujo[nodo->id][nodo->caminoDeAumento]);
          printf("Nodo %d caminoDeAumento %d capacidad %d\n",
                  nodo->id, nodo->caminoDeAumento, capacidad[nodo->id][nodo->caminoDeAumento]);
        }


    //ahora incrementar el flujo a lo largo del camino de aumento
    // for(nodo=&(grafo[fuente]); grafo[nodo->id].caminoDeAumento > 0;
    //     nodo=&(grafo[nodo->caminoDeAumento])){
    //       flujo[nodo][grafo[nodo].caminoDeAumento] += incremento;
    //       flujo[grafo[nodo].caminoDeAumento][nodo] -= incremento;
    //     }


    // for(nodo=numeroDeNodos - 1; grafo[nodo].caminoDeAumento>=0; nodo=grafo[nodo].caminoDeAumento){
    //   flujo[nodo][grafo[nodo].caminoDeAumento] += incremento;
    //   flujo[grafo[nodo].caminoDeAumento][nodo] -= incremento;
    // }


    // flujoMaximo += incremento;
  // }


  // return flujoMaximo;
  return incremento;
}
