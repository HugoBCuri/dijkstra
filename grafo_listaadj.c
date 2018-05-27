#include "grafo_listaadj.h"
#include <stdlib.h>
#include <stdio.h>

bool inicializaGrafo(TipoGrafo *grafo, int nv)
{
    grafo->listaAdj = (TipoApontador*) calloc(nv+1, sizeof(TipoApontador));
    grafo->numArestas = 0;
    grafo->numVertices = nv;
    return true;
}

bool existeAresta(int v1, int v2, TipoGrafo *grafo)
{
    TipoAresta *p = grafo->listaAdj[v1];
    while (p) {
        if (p->vdest == v2)
            return true;
        p = p->prox;
    }
    return false;
}

void imprimeGrafo(TipoGrafo *grafo)
{
    for (int i=1; i <= grafo->numVertices; i++) {
        TipoAresta *p = grafo->listaAdj[i];
        printf("v%d:", i);
        while (p) {
            printf("(%d, %lf); ", p->vdest, p->peso);
            p = p->prox;
        }
        printf("\n");
    }
}

void liberaGrafo(TipoGrafo *grafo)
{
    TipoApontador p = NULL;
    TipoApontador x = NULL;

    for (int i = 0; i <= grafo->numVertices; i++) {
        p = grafo->listaAdj[i];
        while (p) {
            printf("%i\n", p->vdest);
            x = p;
            p = p->prox;
            free(x);
        }
    }
    grafo->numArestas = 0;
    grafo->numVertices = 0;
}

void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo)
{
    TipoAresta *p = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = (TipoAresta*) malloc(sizeof(TipoAresta));
    grafo->listaAdj[v1]->vdest = v2;
    grafo->listaAdj[v1]->prox = p;
    grafo->listaAdj[v1]->peso = peso;
    grafo->numArestas++;
}

bool removeAresta(int v1, int v2, TipoGrafo *grafo)
{
    TipoAresta* p = grafo->listaAdj[v1];
    TipoAresta* ant;
    while (p) {
        if (p->vdest == v2)
            break;
        ant = p;
        p = p->prox;
    }

    if (ant && p) {
        ant->prox = p->prox;
        free(p);
        return true;
    }
    if (p) {
        grafo->listaAdj[v1] = VERTICE_INVALIDO;
        free(p);
        return true;
    }
    return false;
}

int obtemNrVertices(TipoGrafo* grafo)
{
    return grafo->numVertices;
}

int obtemNrArestas(TipoGrafo* grafo)
{
    return grafo->numArestas;
}

bool verificaValidadeVertice(int v, TipoGrafo *grafo)
{
    return v < grafo->numVertices && v > 0;
}

TipoPeso obtemPesoAresta(int v1, int v2, TipoGrafo *grafo)
{
    TipoAresta* aresta = grafo->listaAdj[v1];
    while (aresta) {
        if (aresta->vdest == v2) {
            return aresta->peso;
        }
        aresta = aresta->prox;
    }
    return AN;
}

bool removeArestaObtendoPeso(int v1, int v2, TipoPeso* peso, TipoGrafo *grafo)
{
    TipoAresta* aresta = grafo->listaAdj[v1];
    TipoAresta* ant = NULL;
    while (aresta) {
        if (aresta->vdest == v2) {
            break;
        }
        ant = aresta;
        aresta = aresta->prox;
    }
    if (ant && aresta) {
        ant = aresta->prox;
        *peso = aresta->peso;
        free(aresta);
        return true;
    }
    if (aresta) {
        grafo->listaAdj[v1] = NULL;
        *peso = aresta->peso;
        free(aresta);
        return true;
    }
    return false;
}

bool listaAdjVazia(int v, TipoGrafo* grafo)
{
    return grafo->listaAdj[v] ? true : false;
}

TipoApontador primeiroListaAdj(int v, TipoGrafo* grafo)
{
    return grafo->listaAdj[v];
}

TipoApontador proxListaAdj(int v, TipoGrafo* grafo, TipoApontador atual)
{
    return atual->prox;
}

int verticeDestino(TipoApontador p, TipoGrafo* grafo)
{
    return p->vdest;
}
