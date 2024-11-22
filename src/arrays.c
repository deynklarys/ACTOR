#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

#define INTEGER 1
#define CHARACTER 2
#define STRING 3
#define ARRAY_MAX_LENGTH 50

typedef struct {
  int dataType;
  union {
    int intArray[ARRAY_MAX_LENGTH];
    char charArray[ARRAY_MAX_LENGTH];
    char *strArray[ARRAY_MAX_LENGTH];
  } data;
  int size;
} Array;

int chosenOption;

void traverseArray (int arr[], int size);
int searchArray (int arr[], int size, int key);
void insertArray (int arr[], int *n, int key, int position);
void deleteArray (int arr[], int *n, int position);
void mergeArray(int arr1[], int size1, int arr2[], int size2, int mergedArray[]);
void mergedArr(int arr[], int size);
int chooseDataType ();
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int chooseDataType () {
    printf("Choose a data type for your array:\n");
    char *dataTypeMenu[] = {"Integer", "Character", "String", "Exit"};
    int dataTypeMenuSize = sizeof(dataTypeMenu) / sizeof(dataTypeMenu[0]);

    do {
        printMenu(dataTypeMenu, dataTypeMenuSize);
        if (scanf("%d", &chosenOption) != 1) {
            clearInputBuffer(); // Clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (chosenOption > 0 && chosenOption <= dataTypeMenuSize) {
            switch(chosenOption) {
                case 1:
                    printf("You chose Integer\n");
                    return INTEGER;
                case 2:
                    printf("You chose Character\n");
                    return CHARACTER;
                case 3:
                    printf("You chose String\n");
                    return STRING;
                case 4:
                    printf("Exiting...\n");
                    return -1;
            }
        } else {
            printf("Invalid choice. Please choose a valid option.\n");
        }
    } while(chosenOption != 4);
    return -1; // Invalid choice
}

void traverseArray (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main () {
  // programHeader("Arrays");

  printf("Arrays are a collection of elements of the same types of data.\nExamples:\n\t1, 2, 3, 4, 5 is an array of numbers\n\ta, b, c, d, e is an array of letters\n\tapple, banana, mango, orange is an array of words\n");
  printf ("Each number, character, or word in an array is called an element.\n");

  Array array;
  array.dataType = chooseDataType();
  if (array.dataType == -1) {
    return 0; // Exit if the user chose to exit
  }
  array.size = ARRAY_MAX_LENGTH;

  printf("Initialize your array to work on.\n\n");
  printf("Enter elements (space-separated, press Enter twice to finish):\n");

  int num;
  char ch;
  char str[50];

  switch (array.dataType) {
    case INTEGER:
      while (1) {
        if (scanf("%d", &num) == 1) {
          array.data.intArray[array.size++] = num;
        } else {
          break; 
        }
        clearInputBuffer();
        if (getchar() == '\n') {
          break;
        }
      }
      break;
    case CHARACTER:
        while (1) {
          if (scanf(" %c", &ch) == 1) {
            array.data.charArray[array.size++] = ch;
          } else {
            break;
          }
          clearInputBuffer();
          if (getchar() == '\n') {
            break;
          }
        }
        break;
    case STRING:
      while (1) {
        if (scanf("%s", str) == 1) {
          array.data.strArray[array.size++] = strdup(str);
        } else {
          break;
        }
        clearInputBuffer();
        if (getchar() == '\n') {
          break;
        }
      }
      break;
  }

  printf("Array Operations\n");

  char* arrayMenu[] = {"Traverse", "Search", "Insert", "Delete", "Merge two arrays", "Exit"};
  int arrayMenuSize = sizeof(arrayMenu) / sizeof(arrayMenu[0]);

  do {
    printMenu(arrayMenu, arrayMenuSize);
    scanf("%d", &chosenOption);

    if (chosenOption > 0 && chosenOption < arrayMenuSize) {
      switch(chosenOption) {
        case 1:
          traverseArray(array.data.intArray, array.size);
          // functionNotDone("Traverse");
          break;
        case 2: {
          // int key;
          // printf("Enter the key to search: ");
          // scanf("%d", &key);
          // int index = searchArray(array.data.intArray, array.size, key);
          // if (index != -1) {
          //     printf("Element found at index %d\n", index);
          // } else {
          //     printf("Element not found\n");
          // }
          functionNotDone("Search");
          break;
        }
        case 3: {
          // int key, position;
          // printf("Enter the element to insert: ");
          // scanf("%d", &key);
          // printf("Enter the position to insert: ");
          // scanf("%d", &position);
          // insertArray(array.data.intArray, &array.size, key, position);
          functionNotDone("Insert");
          break;
        }
        case 4: {
          // int position;
          // printf("Enter the position to delete: ");
          // scanf("%d", &position);
          // deleteArray(array.data.intArray, &array.size, position);
          functionNotDone("Delete");
          break;
        }
        case 5:
          // mergedArr(array.data.intArray, array.size);
          functionNotDone("Merge Two Arrays");
          break;
      }
    } else {
      printf("Invalid choice\n");
    }
  } while(chosenOption != arrayMenuSize);

  return 0;
}
