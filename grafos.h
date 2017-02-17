#ifndef GRAFOS_H
#define GRAFOS_H


#define VECINOS_MAX 10
#define NODOS_MAX 10
#define STACK_MAX 10
#define FILAS 4
#define COLUMNAS 4
#define NODO_INICIALIZADO 0
#define NODO_EN_COLA 1
#define NODO_ALCANZADO 2

typedef struct Nodo Nodo;
typedef struct Nodoff Nodoff;
typedef struct Fifo Fifo;
typedef struct Fifoff Fifoff;


struct Nodo{
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];//vector de adyacencia
};


struct Nodoff{
  int id;
  int caminoDeAumento;
  int estado;
  int vecinos[VECINOS_MAX];//vector de adyacencia
};


struct Fifo {//para registrar que nodos fueron visitados
  Nodo *q[STACK_MAX];
  int final;
  int cabeza;
};


struct Fifoff {//para registrar que nodos fueron visitados
  Nodoff *q[STACK_MAX];
  int final;
  int cabeza;
};

void inicalizar_nodo(Nodo *n, int id);
void inicializar_grafo(Nodo g[]);
void inicializar_fifo(Fifo *f);
void imprimir_nodo(Nodo *n);
void imprimir_grafo(Nodo grafo[]);
void push(Fifo *cola, Nodo *n);
Nodo* pop(Fifo *cola);
void imprimirFifo(Fifo *cola);
int estaVacio(Fifo *cola);
int noFueVisitado(Nodo *n);
Nodo* newNodo();
Fifo* newFifo();
void inicializar_matriz(int matriz[FILAS][COLUMNAS]);
void imprimir_matriz(int matriz[FILAS][COLUMNAS]);
void leer_grafo(FILE* input, Nodo grafo[]);
void inicializar_vector(int vector[], int n);
void vecinos_de(int nodo, int matriz[][COLUMNAS], int vecinos[]);
void imprimir_vector(int vector[], int n);
void bfs(Nodo grafo[]);
void bfs_con_vector_de_adyacencia(Nodo grafo[]);
void formatoDeArchivo();


//Ford-Fulkerson
void imprimir_nodo_ff(Nodoff *n);
void inicalizar_nodo_ff(Nodoff *n, int id);
void inicializar_grafo_ff(Nodoff grafo[]);
void imprimir_grafo_ff(Nodoff grafo[]);
void push_ff(Fifoff *cola, Nodoff *n);
Nodoff* pop_ff(Fifoff *cola);
void inicializar_fifo_ff(Fifoff *f);
int estaVacio_ff(Fifoff *cola);
void leer_grafo_ff(FILE* input, Nodoff grafo[],
                  int matrizDeCapacidades[NODOS_MAX][NODOS_MAX],
                  int *fuente, int *sumidero);

#endif
