#ifndef GRAFOS_H
#define GRAFOS_H


#define VECINOS_MAX 5
#define NODOS_MAX 5
#define STACK_MAX 5
#define FILAS 4
#define COLUMNAS 4

typedef struct Nodo Nodo;
typedef struct Fifo Fifo;


struct Nodo{
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];//vector de adyacencia
  struct Nodo *predecesor;
};


struct Fifo {//para registrar que nodos fueron visitados
  Nodo *q[STACK_MAX];
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
void leer_grafo(char *archivo, int matriz[][COLUMNAS]);
void leer_grafo2(char *archivo, Nodo grafo[]);
void inicializar_vector(int vector[], int n);
void vecinos_de(int nodo, int matriz[][COLUMNAS], int vecinos[]);
void imprimir_vector(int vector[], int n);
void bfs(Nodo grafo[]);
void bfs_con_vector_de_adyacencia(Nodo grafo[]);


#endif
