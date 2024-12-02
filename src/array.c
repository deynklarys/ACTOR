#include <stdio.h>
#include <windows.h>
#include <conio.h> // for getch()
#include "../utility.h"

/*
Functions to implement
traverse
search
insert [beginning, end, middle]
delete [beginning, end, middle]
merge
sort
*/

#define INTEGER 1
#define CHARACTER 2
#define STRING 3
#define ARRAY_MAX_LENGTH 50
#define STRING_MAX_LENGTH 50
#define INSERT 3
#define DELETE 4

typedef struct {
  int dataType;
  union {
    int intArray[ARRAY_MAX_LENGTH];
    char charArray[ARRAY_MAX_LENGTH];
    char *strArray[ARRAY_MAX_LENGTH];
  } data;
  int size;
} Array;

typedef struct {
  union {
    int intKey;
    char charKey;
    char strKey[STRING_MAX_LENGTH];
  } dataKey;
} Key;

void traverseArray();
void searchArray();
void insertArray();
void deleteArray();
void mergeArray();
void sortArray();

int chooseDataType () {
  int chosenOption;
  printf("\nChoose a data type for your array:\n");
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

int initializeArray (Array *array) {
  char *message[] = {"Arrays are a collection of elements of the same types of  data.\n", "Examples:\n", "\t1, 2, 3, 4, 5 is an array of numbers or integers\n", "\ta, b, c, d, e is an array of letters or characters\n", "\tapple, banana, mango, orange is an array of words or strings\n","Each number, letter, or word in an array is called an element.\n"};
  int messageSize = sizeof(message)/sizeof(message[0]);

  printWithinWidth(message, messageSize, "Arrays");

  array->dataType = chooseDataType();
  if (array->dataType == -1) {
    return 0; 
  }
  array->size = 0;

  printf("Initialize your array to work on.\n\n");
  printf("Enter elements (space-separated, press Enter to finish):\n");

  int num;
  char ch;
  char str[50];

  switch (array->dataType) {
    case INTEGER: 
      do {
        if (scanf("%d", &num) == 1) {
          array->data.intArray[array->size++] = num;
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
      break;
    case CHARACTER:
      do {
        if (scanf(" %c", &ch) == 1) {
          array->data.charArray[array->size++] = ch;
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
      break;
    case STRING:
      do {
        if (scanf("%s", str) == 1) {
          array->data.strArray[array->size] = malloc(strlen(str) + 1); // Allocate memory for the string
          if (array->data.strArray[array->size] != NULL) {
            strcpy(array->data.strArray[array->size], str); // Copy the string
            array->size++;
          } else {
            printf("Memory allocation failed.\n");
            break;
          }
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
      break;
  }
}

void printArrayPositions (Array *array, int operation) {
  switch (operation) {
    case INSERT:
      switch (array->dataType) {
        case INTEGER:
        case CHARACTER:
          printf("Position of elements: ");
          for (int i = 0; i < array->size + 1; i++) {
            printf("%d ", i + 1);
          }
          break;
        case STRING:
          printf("Position of elements: ");
          for (int i = 0; i < array->size + 1; i++) {
            int strLength = strlen(array->data.strArray[i]);
            int mid = strLength / 2;
            mid = strLength % 2 == 0 ? mid : mid + 1;
            for (int j = 1; j <= strLength; j++) {
              if (j == mid) {
                printf("%d", i + 1);
              } else {
                printf(".");
              }
            }
            printf(" ");
          }
          break;
        default:
          printf("Unknown data type.\n");
          return;
      }
      break;
    case DELETE:
      switch (array->dataType) {
        case INTEGER:
        case CHARACTER:
          printf("Position of elements: ");
          for (int i = 0; i < array->size; i++) {
            printf("%d ", i + 1);
          }
          break;
        case STRING:
          printf("Position of elements: ");
          for (int i = 0; i < array->size; i++) {
            int strLength = strlen(array->data.strArray[i]);
            int mid = strLength / 2;
            mid = strLength % 2 == 0 ? mid : mid + 1;
            for (int j = 1; j <= strLength; j++) {
              if (j == mid) {
                printf("%d", i + 1);
              } else {
                printf(".");
              }
            }
            printf(" ");
          }
          break;
        default:
          printf("Unknown data type.\n");
          return;
      }
      break;
  }
  printf("\n\n");
}

int main () {
  programHeader("Arrays");

  Array array;
  Key key;

  while (1) {

    if (!initializeArray(&array)) {
      system("cls");
      return 0;
    }

    char *arraysMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two arrays", "Exit"};
    int arraysMenuSize = sizeof(arraysMenu) / sizeof(arraysMenu[0]);
    int chosenOption;

    system("cls");
      do {
      programHeader("Array Operations");
      printMenu(arraysMenu, arraysMenuSize);
      if (scanf("%d", &chosenOption) != 1) {
        clearInputBuffer(); // Clear invalid input
        printf("Invalid input. Please enter a number.\n");
        continue;
      }

      switch (chosenOption) {
        case 1:
          traverseArray(&array);
          break;
        case 2:
          searchArray(&array, &key);
          promptExit();
          system("cls");
          break;
        case 3:
          system("cls");
          insertArray(&array, &key);
          promptExit();
          system("cls");
          break;
        case 4:
          functionNotDone("Delete");
          deleteArray();
          break;
        case 5:
          functionNotDone("Sort");
          sortArray();
          break;
        case 6:
          functionNotDone("Merge two arrays");
          mergeArray();
          break;
        case 7:
          promptExit();
          break;
        default:
          printf("Invalid choice. Please choose a valid option.\n");
      }
    } while (chosenOption != arraysMenuSize);
    
    system("cls");
  }

  system("cls");
  return 0;
}

void traverseArray(Array *array) {
  printf("Your array elements:  ");
  for (int i = 0; i < array->size; i++) {
    switch (array->dataType) {
      case INTEGER:
        printf("%d ", array->data.intArray[i]);
        break;
      case CHARACTER:
        printf("%c ", array->data.charArray[i]);
        break;
      case STRING:
        printf("%s ", array->data.strArray[i]);
        break;
      default:
        printf("Unknown data type.\n");
        return;
    }
  }
  printf("\n");
}

int linearSearch(Array array, Key *key) {
  switch (array.dataType) {
    case INTEGER:
      for (int i = 0; i < array.size; i++) {
        if (array.data.intArray[i] == key->dataKey.intKey) {
          return i;
        }
      }
      return -1;
    case CHARACTER:
      for (int i = 0; i < array.size; i++) {
        if (array.data.charArray[i] == key->dataKey.charKey) {
          return i;
        }
      }
      return -1;
    case STRING:
      for (int i = 0; i < array.size; i++) {
        if (strcmp(array.data.strArray[i], key->dataKey.strKey) == 0) {
          return i;
        }
      }
      return -1;
    default:
      printf("Unknown data type.\n");
      return -1;
  }
}
void searchArray(Array *array, Key *key) {
  programHeader("Search in an Array");
  traverseArray(array);
  printf("\n\n");

  // do while loop to check if the user wants to search another element

  int result;
  switch (array->dataType) {
    case INTEGER:
      printf("Enter the number to search: ");
      scanf("%d", &key->dataKey.intKey);
      result = linearSearch(*array, key);
      break;
    case CHARACTER:
      printf("Enter the character to search: ");
      scanf(" %c", &key->dataKey.charKey);
      result = linearSearch(*array, key);
      break;
    case STRING:
      printf("Enter the string to search: ");
      scanf("%s", key->dataKey.strKey);
      result = linearSearch(*array, key);
      break;
    default:
      printf("Unknown data type.\n");
      return;
  }

  if (result == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at position %d.\n", result + 1);
  }
}

void insertArrayKey(Array *array, Key *key, int position) {
  if (position < 0 || position > array->size || array->size >= ARRAY_MAX_LENGTH) {
    printf("Invalid position or array is full.\n");
    return;
  }

  switch (array->dataType) {
    case INTEGER:
      for (int i = array->size; i > position; i--) {
        array->data.intArray[i] = array->data.intArray[i - 1];
      }
      array->data.intArray[position] = key->dataKey.intKey;
      array->size++;
      break;
    case CHARACTER:
      for (int i = array->size; i > position; i--) {
        array->data.charArray[i] = array->data.charArray[i - 1];
      }
      array->data.charArray[position] = key->dataKey.charKey;
      array->size++;
      break;
    case STRING:
      for (int i = array->size; i > position; i--) {
        array->data.strArray[i] = array->data.strArray[i - 1];
      }
      array->data.strArray[position] = malloc(strlen(key->dataKey.strKey) + 1);
      if (array->data.strArray[position] != NULL) {
        strcpy(array->data.strArray[position], key->dataKey.strKey);
        array->size++;
      } else {
        printf("Memory allocation failed.\n");
      }
      break;
    default:
      printf("Unknown data type.\n");
      return;
  }
}
void insertArray(Array *array, Key *key) {
  programHeader("Insert in an Array");
  traverseArray(array);
  printArrayPositions(array, INSERT);

  // do while loop to check if the user wants to insert another element

  switch (array->dataType){
    int position;
    case INTEGER:
      printf("Enter the number to insert: ");
      scanf("%d", &key->dataKey.intKey);
      printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
      scanf("%d", &position);
      insertArrayKey(array, key, position - 1);
      break;
    case CHARACTER:
      printf("Enter the character to insert: ");
      scanf(" %c", &key->dataKey.charKey);
      printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
      scanf("%d", &position);
      insertArrayKey(array, key, position - 1);
      break;
    case STRING:
      printf("Enter the string to insert: ");
      scanf("%s", key->dataKey.strKey);
      printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
      scanf("%d", &position);
      insertArrayKey(array, key, position - 1);
      break;
  }
  traverseArray(array);

}


void deleteArray() {
  // Implementation of delete
}

void mergeArray() {
  // Implementation of merge
}

void sortArray() {
  // Implementation of sort
}