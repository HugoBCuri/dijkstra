#include "grafo_listaadj.h"
#include "heap_binario.h"

#include <limits.h>
#include <float.h>
#include <string.h>

int main(int argc, char **argv)
{
    int vOrigem;
    TipoGrafo g1;
    createGrafo(&g1, &vOrigem, argv[1]);

    int nv = obtemNrVertices(&g1);
    int a[nv];
    int antecessor[nv];
    double distancia[nv];

    initializeSingleSource(nv, vOrigem, antecessor, distancia);

    for (int i = 0; i < nv; i++) {
        a[i] = i+1;
    }
    int n = nv-1;

    buildMinHeap(a, n, distancia);

    while (n >= 0) {
        int v = heapExtractMin(a, &n, distancia);
        TipoApontador aresta = primeiroListaAdj(v, &g1);
        while (aresta) {
            int vdest = verticeDestino(aresta, &g1);

            if (distancia[vdest] > distancia[v] + obtemPesoAresta(v, vdest, &g1)) {
                distancia[vdest] = distancia[v] + obtemPesoAresta(v, vdest, &g1);
                if (n > 1) {
                    heapIncreaseKey(a, vdest, distancia, nv);
                }
                antecessor[vdest] = v;
            }
            aresta = proxListaAdj(v, &g1, aresta);
        }
    }
    writeFile(nv, antecessor, distancia, argv[2]);
}

void initializeSingleSource(int nv, int v, int antecessor[], double distancia[])
{
    for (int i = 1; i <= nv; i++) {
        distancia[i] = DBL_MAX;
        antecessor[i] = -1;
    }
    distancia[v] = 0.0;
}

void writeFile(int nv, int antecessor[], double distancia[], char* fileName)
{
    FILE* fp = fopen(fileName, "w");

    for (int i = 1; i <= nv; i++) {
        if (distancia[i] == DBL_MAX)
            fprintf(fp, "%i %.2e %i\n", i, distancia[i], antecessor[i]);
        else
            fprintf(fp, "%i %lf %i\n", i, distancia[i], antecessor[i]);
    }
    fclose(fp);
}

void createGrafo(TipoGrafo* g, int* vOrigem, char* fileName)
{
    char c[1000];

    FILE *file;
    file = fopen(fileName, "r");

    // Leitura do vOrigem
    fgets(c, 1000, file);
    sscanf(c, "%i", vOrigem);

    // Leitura do nVertices e nArestas
    fgets(c, 1000, file);
    int nVertices, nArestas;
    sscanf(c, "%i %i", &nVertices, &nArestas);

    inicializaGrafo(g, nVertices);

    // Leitura das arestas
    int v1;
    TipoPeso auxPeso;
    int v2;

    while (fgets(c, 1000, file) != NULL) {
        sscanf(c, "%i %i %lf", &v1, &v2, &auxPeso);
        insereAresta(v1, v2, auxPeso, g);
    }
    fclose(file);
}
