#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "../utils.h"

void copyArr(int* src, int* dest, int n);

int main() {

  // Setup test data
  const int N = 10000;
  int* in = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    in[i] = rand() % N;
  }

  // Clone test data
  int* clone = (int*)malloc(N * sizeof(int));

  clock_t tic, toc;
  double t1, t2, t3, t4, t5;

  printf("Size of array: %d\n", N);

  // Run benchmarks
  copyArr(in, clone, N);
  tic = clock();
  insertionSort(clone, N);
  toc = clock();
  t1 = (((double)(toc - tic)) / CLOCKS_PER_SEC) * 1000;

  copyArr(in, clone, N);
  tic = clock();
  mergeSort(clone, N);
  toc = clock();
  t2 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  copyArr(in, clone, N);
  tic = clock();
  quickSort(clone, N);
  toc = clock();
  t3 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  copyArr(in, clone, N);
  tic = clock();
  bubbleSort(clone, N);
  toc = clock();
  t4 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  copyArr(in, clone, N);
  tic = clock();
  selectionSort(clone, N);
  toc = clock();
  t5 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  // Print output
  printf("Insertion sort: %lfms\n", t1);
  printf("Merge sort: %lfms\n", t2);
  printf("Quick sort: %lfms\n", t3);
  printf("Bubble sort: %lfms\n", t4);
  printf("Selection sort: %lfms\n", t5);

  free(in);
  free(clone);

  return 0;
}

void copyArr(int* src, int* dest, int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}