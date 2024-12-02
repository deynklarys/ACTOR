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
#define INS 3
#define DEL 4
int cursorXpos, cursorYpos;

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
  char *message[] = {"Arrays are a collection of elements of the same types of  data.", "Examples:",
  "\t1, 2, 3, 4, 5 is an array of numbers or integers",
  "\ta, b, c, d, e is an array of letters or characters",
  "\tapple, banana, mango, orange is an array of words or strings",
  "Each number, letter, or word in an array is called an element."};
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
    case INS:
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
            if (i == array->size + 1) {
              strLength = 5;
            }
            int mid = strLength / 2;
            mid = strLength % 2 == 0 ? mid : mid + 1;
            for (int j = 1; j <= strLength; j++) {
              j == mid ? printf("%d", i + 1) : printf(".");
            }
            printf(" ");
          }
          break;
        default:
          printf("Unknown data type.\n");
          return;
      }
      break;
    case DEL:
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
      getCursorPos(&cursorXpos, &cursorYpos);
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
          system("cls");
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
          system("cls");
          deleteArray(&array);
          promptExit();
          system("cls");
          break;
        case 5:
          system("cls");
          sortArray(&array);
          promptExit();
          system("cls");
          break;
        case 6:
          system("cls");
          mergeArray(&array);
          promptExit();
          system("cls");
          break;
        case 7:
          promptExit();
          break;
        default:
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
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
  printArrayPositions(array, INS);

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

void deleteArrayKey(Array *array, int position) {
  if (position < 0 || position >= array->size) {
    printf("Invalid position.\n");
    return;
  }

  switch (array->dataType) {
    case INTEGER:
      for (int i = position; i < array->size - 1; i++) {
        array->data.intArray[i] = array->data.intArray[i + 1];
      }
      array->size--;
      break;
    case CHARACTER:
      for (int i = position; i < array->size - 1; i++) {
        array->data.charArray[i] = array->data.charArray[i + 1];
      }
      array->size--;
      break;
    case STRING:
      free(array->data.strArray[position]);
      for (int i = position; i < array->size - 1; i++) {
          array->data.strArray[i] = array->data.strArray[i + 1];
      }
      array->size--;
      break;
    default:
      printf("Unknown data type.\n");
      return;
  }
}
void deleteArray(Array *array) {
  programHeader("Delete from an Array");
  traverseArray(array);
  printArrayPositions(array, DEL);

  int position;
  printf("Enter the position of the element to delete from 1 to %d: ", array->size);
  scanf("%d", &position);
  deleteArrayKey(array, position - 1);
  traverseArray(array);
}

void mergeTwoArrays(Array *array1, Array *array2) {
  if (array1->dataType != array2->dataType) {
    printf("Arrays have different data types and cannot be merged.\n");
    return;
  }

  if (array1->size + array2->size > ARRAY_MAX_LENGTH) {
    printf("Merged array exceeds maximum length.\n");
    return;
  }

  switch (array1->dataType) {
    case INTEGER:
      for (int i = 0; i < array2->size; i++) {
        array1->data.intArray[array1->size++] = array2->data.intArray[i];
      }
      break;
    case CHARACTER:
      for (int i = 0; i < array2->size; i++) {
        array1->data.charArray[array1->size++] = array2->data.charArray[i];
      }
      break;
    case STRING:
      for (int i = 0; i < array2->size; i++) {
        array1->data.strArray[array1->size] = malloc(strlen(array2->data.strArray[i]) + 1);
        if (array1->data.strArray[array1->size] != NULL) {
          strcpy(array1->data.strArray[array1->size], array2->data.strArray[i]);
          array1->size++;
        } else {
          printf("Memory allocation failed.\n");
          return;
        }
      }
      break;
    default:
      printf("Unknown data type.\n");
      return;
  }

  printf("\nArrays merged successfully\n");
  traverseArray(array1);
}
void mergeArray(Array *array1) {
  programHeader("Merge Two Arrays");
  traverseArray(array1);

  Array array2;
  array2.dataType = array1->dataType;
  array2.size = 0;

  printf("Initialize your second array to work on.\n\n");
  printf("Enter elements (space-separated, press Enter to finish):\n");

  int num;
  char ch;
  char str[50];

  switch (array2.dataType) {
    case INTEGER: 
      do {
        if (scanf("%d", &num) == 1) {
          array2.data.intArray[array2.size++] = num;
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
      break;
    case CHARACTER:
      do {
        if (scanf(" %c", &ch) == 1) {
          array2.data.charArray[array2.size++] = ch;
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
      break;
    case STRING:
      do {
        if (scanf("%s", str) == 1) {
          array2.data.strArray[array2.size] = malloc(strlen(str) + 1); // Allocate memory for the string
          if (array2.data.strArray[array2.size] != NULL) {
            strcpy(array2.data.strArray[array2.size], str); // Copy the string
            array2.size++;
          } else {
            printf("Memory allocation failed.\n");
            break;
          }
        } else {
          clearInputBuffer(); // Clear invalid input
          break;
        }
      } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
      break;
  }  
  mergeTwoArrays(array1, &array2);
}

void bubbleSortArray (Array *array) {
  switch (array->dataType) {
  case INTEGER:
    for (int i = 0; i < array->size - 1; i++) {
      for (int j = 0; j < array->size - i - 1; j++) {
        if (array->data.intArray[j] > array->data.intArray[j + 1]) {
          int temp = array->data.intArray[j];
          array->data.intArray[j] = array->data.intArray[j + 1];
          array->data.intArray[j + 1] = temp;
        }
      }
    }
    break;
  case CHARACTER:
    for (int i = 0; i < array->size - 1; i++) {
      for (int j = 0; j < array->size - i - 1; j++) {
        if (array->data.charArray[j] > array->data.charArray[j + 1]) {
          char temp = array->data.charArray[j];
          array->data.charArray[j] = array->data.charArray[j + 1];
          array->data.charArray[j + 1] = temp;
        }
      }
    }
    break;
  case STRING:
    for (int i = 0; i < array->size - 1; i++) {
      for (int j = 0; j < array->size - i - 1; j++) {
        if (strcmp(array->data.strArray[j], array->data.strArray[j + 1]) > 0) {
          char *temp = array->data.strArray[j];
          array->data.strArray[j] = array->data.strArray[j + 1];
          array->data.strArray[j + 1] = temp;
        }
      }
    }
    break;
  default:
    printf("Unknown data type.\n");
    return;
  }
  printf("Array sorted successfully.\n");
  traverseArray(array);

}
void sortArray(Array *array) {
  char *message[] = {"Numbers will be sorted in ascending order. Letters and words will be sorted in alphabetical order.Bubble sorting algorithm will be used in this operation. To learn more about other sorting algorithms, go to Algorithms > Sorting." };
  int messageSize = sizeof(message)/sizeof(message[0]);
  printWithinWidth(message, messageSize, "Sort an Array");

  printf("\nArray before sorting:\n");
  traverseArray(array);
  printf("\n");
  bubbleSortArray(array);
}