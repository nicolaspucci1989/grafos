#ifndef GRAFOS_H
#define GRAFOS_H


#define NODOS_MAX 10
#define STACK_MAX 10
#define NODO_INICIALIZADO 0
#define NODO_EN_COLA 1
#define NODO_ALCANZADO 2
#define INFINITO 10000

typedef struct Nodo Nodo;
typedef struct Fifo Fifo;


struct Nodo{
  int id;
  int predecesor;
  int estado;
  int capacidad[NODOS_MAX]; //vector de adyacencia
  int flujo[NODOS_MAX];
};


struct Fifo {//para registrar que nodos fueron visitados
  Nodo *q[STACK_MAX];
  int final;
  int cabeza;
};



void formatoDeArchivo();


//Ford-Fulkerson
void imprimir_nodo(Nodo *n, int numeroDeNodos);
void imprimir_grafo(Nodo grafo[], int numeroDeNodos);
void inicalizar_nodo(Nodo *n, int id);
void inicializar_grafo(Nodo grafo[]);
void inicializar_flujo(Nodo *n);
void inicializar_flujo_grafo(Nodo grafo[], int numeroDeNodos);
void push(Fifo *cola, Nodo *n);
Nodo* pop(Fifo *cola);
void inicializar_fifo(Fifo *f);
int estaVacio(Fifo *cola);
void leer_grafo(FILE* input, Nodo grafo[],int *fuente,
                  int *sumidero, int *cantidadDeNodos);
int bfs(Nodo grafo[], int fuente, int sumidero, int numeroDeNodos);
void inicializar_estado_nodos(Nodo grafo[]);
int ford_fulkerson(int fuente, int sumidero, Nodo grafo[], int cantidadDeNodos);


#endif
