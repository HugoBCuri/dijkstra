#include "heap_binario.h"

int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return (2*i) + 1;
}

void minHeapify(int a[], int n, int i, double distancia[])
{
    if (n <= 1) {
       return;
    }

    int l = left(i);
    int r = right(i);
    int smallest;
    if (l <= n && distancia[a[l]] < distancia[a[i]]) {
        smallest = l;
    } else {
        smallest = i;
    }

    if (r <= n && distancia[a[r]] < distancia[a[smallest]]) {
        smallest = r;
    }

    if (smallest != i) {
        int aux = a[i];
        a[i] = a[smallest];
        a[smallest] = aux;
        minHeapify(a, n, i, distancia);
    }
}

void buildMinHeap(int a[], int n, double distancia[])
{
    for (int i = n/2; i >= 0; i--) {
        minHeapify(a, n, i, distancia);
    }
}

int heapExtractMin(int a[], int* n, double distancia[])
{

    int min = a[0];
    a[0] = a[*n];
    *n = (*n) -1;
    minHeapify(a, *n, 0, distancia);
    return min;
}

void heapIncreaseKey(int a[], int v, double distancia[], int nv)
{
    int i;
    for (i = 0; i < nv; i++) {
        if (a[i] == v)
            break;
    }
    while (i > 0 && distancia[a[parent(i)]] > distancia[a[i]]) {
        int parentI = parent(i);
        int aux = a[i];
        a[i] = a[parentI];
        a[parentI] = aux;
        i = parentI;
    }
}
