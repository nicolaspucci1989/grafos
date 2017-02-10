#ifndef NODOS_H
#define NODOS_H


#define VECINOS_MAX 5
#define NODOS_MAX 5


typedef struct {
  int id;
  int distancia;
  int vecinos[VECINOS_MAX];
} nodo;


void inicalizar_nodo(nodo *n);
void inicializar_grafo(nodo g[]);
void imprimir_nodo(nodo *n);
void imprimir_grafo(nodo grafo[]);
void push(int stack[], int elemento, int *final);
int pop(int stack[], int *final);
void imprimirstack(int stack[], int final);



#endif
