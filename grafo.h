#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

typedef struct GrafoMatriz {
    int vertices;
    int** matriz;
} GrafoMatriz;

typedef struct GrafoLista {
    int vertices;
    int** lista;
    int* tam_lista;
} GrafoLista;

GrafoMatriz* inicializaGrafoMatriz(int vertices);
GrafoLista* inicializaGrafoLista(int vertices);
void adicionaArestaMatriz(GrafoMatriz* grafo, int u, int v);
void adicionaArestaLista(GrafoLista* grafo, int u, int v);
void liberaGrafoMatriz(GrafoMatriz* grafo);
void liberaGrafoLista(GrafoLista* grafo);

