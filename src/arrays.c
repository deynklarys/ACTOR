#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

void traverseArray (int arr[], int size);
int searchArray (int arr[], int size, int key);
void insertArray (int arr[], int *n, int key, int position);
void deleteArray (int arr[], int *n, int position);
void mergeArray(int arr1[], int size1, int arr2[], int size2, int mergedArray[]);
void mergedArr() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {6, 7, 8, 9, 10};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  int mergedSize = size1 + size2;
  int mergedArray[mergedSize];

  mergeArrays(arr1, size1, arr2, size2, mergedArray);

  printf("Merged array: ");
  for (int i = 0; i < mergedSize; i++) {
      printf("%d ", mergedArray[i]);
  }
  printf("\n");
}

int main () {

  return 0;
}

void traverseArray (int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int searchArray (int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

void insertArray (int arr[], int *n, int key, int position) {
  for (int i = *n - 1; i >= position; i--) {
    arr[i + 1] = arr[i];
  }
  arr[position] = key;
  (*n)++;
}

void deleteArray (int arr[], int *n, int position) {
  for (int i = position; i < *n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  (*n)--;
}

void mergeArray(int arr1[], int size1, int arr2[], int size2, int mergedArray[]) {
    int i, j;

    // Copy elements from the first array
    for (i = 0; i < size1; i++) {
        mergedArray[i] = arr1[i];
    }

    // Copy elements from the second array
    for (j = 0; j < size2; j++) {
        mergedArray[i + j] = arr2[j];
    }
}











