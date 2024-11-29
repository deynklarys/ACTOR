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

typedef struct {
    int dataType;
    union {
        int intArray[ARRAY_MAX_LENGTH];
        char charArray[ARRAY_MAX_LENGTH];
        char *strArray[ARRAY_MAX_LENGTH];
    } data;
    int size;
} Array;

void traverseArray();
void searchArray();
void insertArray();
  void insertAtBeginning();
  void insertAtEnd();
  void insertAtMiddle();
void deleteArray();
  void deleteFromBeginning();
  void deleteFromEnd();
  void deleteFromMiddle();
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
  char *message[] = {"Arrays are a collection of elements of the same types of  data.\n", "Examples:\n", "\t1, 2, 3, 4, 5 is an array of numbers\n", "\ta, b, c, d, e is an array of letters\n", "\tapple, banana, mango, orange is an array of words\n","Each number, letter, or word in an array is called an element.\n"};
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

int main () {
  programHeader("Arrays");

  Array array;

  if (!initializeArray(&array)) {
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
        functionNotDone("Search");
        searchArray();
        break;
      case 3:
        functionNotDone("Insert");
        insertArray();
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
  return 0;
}

void traverseArray( Array *array) {
  printf("Array elements: ");
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

void searchArray() {
  // Implementation of search
}

void insertArray() {
  char *insertMenu[] = {"Insert at the beginning", "Insert at the middle", "Insert at the end", "Exit"};
  int insertMenuSize = sizeof(insertMenu) / sizeof(insertMenu[0]);
  int chosenOption;


  do {
    programHeader("Arrays");
    printMenu(insertMenu, insertMenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Insert at the beginning");
        insertAtBeginning();
        break;
      case 2:
        functionNotDone("Insert at the middle");
        insertAtMiddle();
        break;
      case 3:
        functionNotDone("Insert at the end");
        insertAtEnd();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }

    // if (chosenOption != 7) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != insertMenuSize);
}

void insertAtBeginning() {
    // Implementation of insertAtBeginning
}

void insertAtEnd() {
    // Implementation of insertAtEnd
}

void insertAtMiddle() {
    // Implementation of insertAtMiddle
}

void deleteArray() {
  char *deleteMenu[] = {"Delete at the beginning", "Delete at the middle", "Delete at the end", "Exit"};
  int deleteMenuSize = sizeof(deleteMenu) / sizeof(deleteMenu[0]);
  int chosenOption;


  do {
    programHeader("Arrays");
    printMenu(deleteMenu, deleteMenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Delete at the beginning");
        deleteFromBeginning();
        break;
      case 2:
        functionNotDone("Delete at the middle");
        deleteFromMiddle();
        break;
      case 3:
        functionNotDone("Delete at the end");
        deleteFromEnd();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }

    // if (chosenOption != 7) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != deleteMenuSize);}

void deleteFromBeginning() {
    // Implementation of deleteFromBeginning
}

void deleteFromEnd() {
    // Implementation of deleteFromEnd
}

void deleteFromMiddle() {
    // Implementation of deleteFromMiddle
}

void mergeArray() {
    // Implementation of merge
}

void sortArray() {
    // Implementation of sort
}