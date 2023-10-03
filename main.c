#include "grafo.h"
#include "buscas.h"
#include <stdio.h>

int main() {
    GrafoMatriz* grafo = carregaGrafoMatriz("dados.txt");
    
    printf("Busca em Largura a partir do vértice 0:\n");
    buscaLarguraMatriz(grafo, 0);

    printf("\nCaminho entre 0 e 3:\n");
    imprimeCaminho(grafo, 0, 3);

    printf("\nBusca em Profundidade a partir do vértice 0:\n");
    buscaProfundidadeMatriz(grafo, 0);

    liberaGrafoMatriz(grafo);
    return 0;
}
