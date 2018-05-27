#include <stdio.h>
#include <stdlib.h>

int parent(int i);

int left(int i);

int right(int i);

void minHeapify(int a[], int n, int i, double distancia[]);

void buildMinHeap(int a[], int n, double distancia[]);

int heapExtractMin(int a[], int* n, double distancia[]);

void heapIncreaseKey(int a[], int v, double distancia[], int nv);
