#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

GrafoMatriz* inicializaGrafoMatriz(int vertices) {
    GrafoMatriz* grafo = (GrafoMatriz*) malloc(sizeof(GrafoMatriz));
    grafo->vertices = vertices;
    grafo->matriz = (int**) malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        grafo->matriz[i] = (int*) calloc(vertices, sizeof(int));
    }
    return grafo;
}

GrafoLista* inicializaGrafoLista(int vertices) {
    GrafoLista* grafo = (GrafoLista*) malloc(sizeof(GrafoLista));
    grafo->vertices = vertices;
    grafo->lista = (int**) malloc(vertices * sizeof(int*));
    grafo->tam_lista = (int*) calloc(vertices, sizeof(int));
    for (int i = 0; i < vertices; i++) {
        grafo->lista[i] = (int*) malloc(vertices * sizeof(int));
    }
    return grafo;
}

void adicionaArestaMatriz(GrafoMatriz* grafo, int u, int v) {
    grafo->matriz[u][v] = 1;
    grafo->matriz[v][u] = 1;
}

void adicionaArestaLista(GrafoLista* grafo, int u, int v) {
    grafo->lista[u][grafo->tam_lista[u]++] = v;
    grafo->lista[v][grafo->tam_lista[v]++] = u;
}

void liberaGrafoMatriz(GrafoMatriz* grafo) {
    for (int i = 0; i < grafo->vertices; i++) {
        free(grafo->matriz[i]);
    }
    free(grafo->matriz);
    free(grafo);
}

void liberaGrafoLista(GrafoLista* grafo) {
    for (int i = 0; i < grafo->vertices; i++) {
        free(grafo->lista[i]);
    }
    free(grafo->lista);
    free(grafo->tam_lista);
    free(grafo);
}

GrafoMatriz* carregaGrafoMatriz(const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    int vertices;
    fscanf(fp, "%d", &vertices);

    GrafoMatriz* grafo = inicializaGrafoMatriz(vertices);

    int u, v;
    while (fscanf(fp, "%d %d", &u, &v) == 2) {
        adicionaArestaMatriz(grafo, u, v);
    }

    fclose(fp);
    return grafo;
}

GrafoLista* carregaGrafoLista(const char* arquivo) {
    FILE* fp = fopen(arquivo, "r");
    int vertices;
    fscanf(fp, "%d", &vertices);

    GrafoLista* grafo = inicializaGrafoLista(vertices);

    int u, v;
    while (fscanf(fp, "%d %d", &u, &v) == 2) {
        adicionaArestaLista(grafo, u, v);
    }

    fclose(fp);
    return grafo;
}
