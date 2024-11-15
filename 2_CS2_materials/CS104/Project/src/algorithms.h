#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdbool.h>

void printArray(int array[], int size);
void swap(int *a, int *b);

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);

bool isArraySorted(int array[], int size);
void shuffle(int array[], int size);
void randomSort(int array[], int size);

void merge(int array[], int leftIndex, int mid, int rightIndex);
void mergeSort(int array[], int leftIndex, int rightIndex);

int partitionLomuto(int array[], int first, int last);
int partitionHoare(int array[], int first, int last);
void quickSortLomuto(int array[], int first, int last);
void quickSortHoare(int array[], int first, int last);

void countRadixSort(int array[], int size, int placeValue);
void radixSort(int array[], int size);

void heapify(int array[], int size, int i);
void heapSort(int array[], int size);

void sort(int array[], int size, int sortType);



#endif /* ALGORITHMS_H */