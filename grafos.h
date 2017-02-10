#ifndef GRAFOS_H
#define GRAFOS_H


#define VECINOS_MAX 5
#define NODOS_MAX 5
#define STACK_MAX 5

typedef struct nodo nodo;


struct nodo{
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];
  struct nodo *predecesor;
};


typedef struct {//para registrar que nodos fueron visitados
  nodo *q[STACK_MAX];
  int final;
  int cabeza;
} fifo;


void inicalizar_nodo(nodo *n);
void inicializar_grafo(nodo g[]);
void imprimir_nodo(nodo *n);
void imprimir_grafo(nodo grafo[]);
void push(fifo *cola, nodo *n);
nodo* pop(fifo *cola);
void imprimirStack(fifo *cola);
int estaVacio(fifo *cola);

#endif
