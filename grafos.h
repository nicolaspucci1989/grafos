#ifndef NODOS_H
#define NODOS_H


#define VECINOS_MAX 5
#define NODOS_MAX 5
#define STACK_MAX 5


typedef struct {
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];
} nodo;


typedef struct {
  int stack[STACK_MAX];
  int final;
} fifo;


void inicalizar_nodo(nodo *n);
void inicializar_grafo(nodo g[]);
void imprimir_nodo(nodo *n);
void imprimir_grafo(nodo grafo[]);
void push(fifo *cola, int item);
int pop(fifo *cola);
void imprimirstack(fifo *cola);



#endif
