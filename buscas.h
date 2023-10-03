#ifndef BUSCAS_H
#define BUSCAS_H

#include "grafo.h"

void buscaLarguraMatriz(GrafoMatriz* grafo, int inicio);
void imprimeCaminho(GrafoMatriz* grafo, int inicio, int fim);

void buscaProfundidadeMatriz(GrafoMatriz* grafo, int inicio);

