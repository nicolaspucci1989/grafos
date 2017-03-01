#ifndef GRAFOS_H
#define GRAFOS_H


#define NODOS_MAX 10
#define STACK_MAX 10
#define NODO_INICIALIZADO 0
#define NODO_EN_COLA 1
#define NODO_ALCANZADO 2
#define INFINITO 10000

typedef struct Nodoff Nodoff;
typedef struct Fifoff Fifoff;


struct Nodoff{
  int id;
  int caminoDeAumento;
  int estado;
  int capacidad[NODOS_MAX]; //vector de adyacencia
  int flujo[NODOS_MAX];
};


struct Fifoff {//para registrar que nodos fueron visitados
  Nodoff *q[STACK_MAX];
  int final;
  int cabeza;
};



void formatoDeArchivo();


//Ford-Fulkerson
void imprimir_nodo_ff(Nodoff *n, int numeroDeNodos);
void imprimir_grafo_ff(Nodoff grafo[], int numeroDeNodos);
void inicalizar_nodo_ff(Nodoff *n, int id);
void inicializar_grafo_ff(Nodoff grafo[]);
void inicializar_flujo(Nodoff *n);
void inicializar_flujo_grafo(Nodoff grafo[], int numeroDeNodos);
void push_ff(Fifoff *cola, Nodoff *n);
Nodoff* pop_ff(Fifoff *cola);
void inicializar_fifo_ff(Fifoff *f);
int estaVacio_ff(Fifoff *cola);
void leer_grafo_ff(FILE* input, Nodoff grafo[],int *fuente,
                  int *sumidero, int *cantidadDeNodos);
int bfs_ff(Nodoff grafo[], int fuente, int sumidero, int numeroDeNodos);
void inicializar_estado_nodos(Nodoff grafo[]);
int ford_fulkerson(int fuente, int sumidero, Nodoff grafo[], int cantidadDeNodos);


#endif
