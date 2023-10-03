#include "buscas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool* visitados;
static int* anteriores;

void buscaLarguraMatriz(GrafoMatriz* grafo, int inicio) {
    visitados = (bool*) calloc(grafo->vertices, sizeof(bool));
    anteriores = (int*) malloc(grafo->vertices * sizeof(int));
    for (int i = 0; i < grafo->vertices; i++) anteriores[i] = -1;

    int* fila = (int*) malloc(grafo->vertices * sizeof(int));
    int inicioFila = 0, fimFila = 0;

    fila[fimFila++] = inicio;
    visitados[inicio] = true;

    while (inicioFila != fimFila) {
        int u = fila[inicioFila++];
        for (int v = 0; v < grafo->vertices; v++) {
            if (grafo->matriz[u][v] && !visitados[v]) {
                visitados[v] = true;
                anteriores[v] = u;
                fila[fimFila++] = v;
            }
        }
    }

    free(fila);
}

void imprimeCaminho(GrafoMatriz* grafo, int inicio, int fim) {
    buscaLarguraMatriz(grafo, inicio);
    if (!visitados[fim]) {
        printf("Não há caminho entre os vértices %d e %d\n", inicio, fim);
        return;
    }

    int* caminho = (int*) malloc(grafo->vertices * sizeof(int));
    int tamCaminho = 0;

    for (int v = fim; v != -1; v = anteriores[v]) {
        caminho[tamCaminho++] = v;
    }

    for (int i = tamCaminho - 1; i >= 0; i--) {
        printf("%d", caminho[i]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");

    free(caminho);
    free(visitados);
    free(anteriores);
}

#include <stdbool.h>

typedef struct Pilha {
    int* itens;
    int topo;
    int capacidade;
} Pilha;

Pilha* criaPilha(int capacidade) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->itens = (int*) malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

bool pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void empilha(Pilha* pilha, int item) {
    if (pilha->topo == pilha->capacidade - 1) return;
    pilha->itens[++(pilha->topo)] = item;
}

int desempilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) return -1;
    return pilha->itens[(pilha->topo)--];
}

void liberaPilha(Pilha* pilha) {
    free(pilha->itens);
    free(pilha);
}

void buscaProfundidadeMatriz(GrafoMatriz* grafo, int inicio) {
    bool* visitados = (bool*) calloc(grafo->vertices, sizeof(bool));
    Pilha* pilha = criaPilha(grafo->vertices);
    empilha(pilha, inicio);

    while (!pilhaVazia(pilha)) {
        int u = desempilha(pilha);
        if (!visitados[u]) {
            printf("%d ", u);
            visitados[u] = true;
            for (int v = 0; v < grafo->vertices; v++) {
                if (grafo->matriz[u][v] && !visitados[v]) {
                    empilha(pilha, v);
                }
            }
        }
    }
    printf("\n");

    liberaPilha(pilha);
    free(visitados);
}
