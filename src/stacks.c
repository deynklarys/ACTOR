#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

/*
Functions to implement:
push
pop 
peek
is full
is empty
*/

#define STACK_MAX_SIZE 50
#define STRING_MAX_LENGTH 50
int cursorXpos, cursorYpos;
void *data;
int *positionPtr;

typedef enum {
  INTEGER,
  CHARACTER,
  STRING
} DataType;

typedef struct Node {
  void *data;
  struct Node *next;
} StackNode;

typedef struct {
  StackNode *top;
  size_t dataSize;
  void (*printFunc)(void *);
  DataType stackDataType;
  int stackSize;
} Stack;

typedef struct {
  Stack list;
  int chosenDataType;
} StackResult;

void push();
void pop();
void peek();
void isFull();
void isEmpty();

void printInt(void *data) {
  printf("%d -> ", *(int *)data);
}
void printChar(void *data) {
  printf("%c -> ", *(char *)data);
}
void printString(void *data) {
  printf("%s -> ", (char *)data);
}

int chooseDataTypeStacks();
StackResult initializeStacks();
void *scanData(char prompt[], DataType dataType); // can be used for all data structures needing input
void freeAll(Stack *stack);

int main () {

  programHeader("Stacks");

  Stack stack;

  while (1) {
    StackResult stackResult = initializeStacks();
    stack = stackResult.list;
    stack.stackDataType = stackResult.chosenDataType;
    if (stack.stackDataType == -1) {
      system("cls");
      freeAll(&stack);
      return 0;
    }

    char *stacksMenu[] = {"Add an item", "Remove an item","Look for an item", "Check if the stack is full", "Check if the stack is empty", "Exit"};
    int stacksMenuSize = sizeof(stacksMenu) / sizeof(stacksMenu[0]);
    int chosenOption;


    do {
      programHeader("Stacks Operations");
      printMenu(stacksMenu, stacksMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &chosenOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 2);

      switch (chosenOption) {
        case 1:
          functionNotDone("Add an item");
          push();
          break;
        case 2:
          functionNotDone("Remove an item");
          pop();
          break;
        case 3:
          functionNotDone("Look for an item");
          peek();
          break;
        case 4:
          functionNotDone("Check if the stack is full");
          isFull();
          break;
        case 5:
          functionNotDone("Check if the stack is empty");
          isEmpty();
          break;
        case 6:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (chosenOption != stacksMenuSize);
    system("cls");
  }
  return 0;
}

int chooseDataTypeStacks () {
  int chosenOption;
  printf("\nChoose a data type for your stack:\n");
  char *dataTypeMenu[] = {"Integer", "Character", "String", "Exit"};
  int dataTypeMenuSize = sizeof(dataTypeMenu) / sizeof(dataTypeMenu[0]);

  int menuCursorXpos, menuCursorYpos;
  getCursorPos(&menuCursorXpos, &menuCursorYpos);
  do {
    printMenu(dataTypeMenu, dataTypeMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 1);
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      moveCursor(menuCursorXpos, menuCursorYpos);
      continue;
    }
    clearLines(cursorYpos + 1, cursorYpos + 1);
    moveCursor(0, cursorYpos + 2);
    switch (chosenOption) {
      case INTEGER:
        printf("You chose Integer\n");
        return INTEGER;
      case CHARACTER:
        printf("You chose Character\n");
        return CHARACTER;
      case STRING:
        printf("You chose String\n");
        return STRING;
      case 4:
        printf("Exiting...\n");
        return -1;
      default:
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    moveCursor(menuCursorXpos, menuCursorYpos);
  } while (chosenOption != dataTypeMenuSize);
}

StackResult initializeStacks() {
  char *message[] = {"Stacks are a type of data structure that follows the Last In First Out (LIFO) principle.", "This means that the last element added to the stack will be the first one to be removed.", "Like a stack of books!"};
  int messageSize = sizeof(message) / sizeof(message[0]);

  printWithinWidthCentered(message, messageSize, "Stacks");

  StackResult result;
  result.chosenDataType = chooseDataTypeStacks();
  if (result.chosenDataType == -1) {
    return result;
  }

  switch (result.chosenDataType) {
    case INTEGER:
      result.list = (Stack) {NULL, sizeof(int),printInt, INTEGER, 0};
      break;
    case CHARACTER:
      result.list = (Stack) {NULL, sizeof(char),printChar, CHARACTER, 0};
      break;
    case STRING:
      result.list = (Stack) {NULL, sizeof (char *),printString, STRING, 0};
      break;
  }
}

void *scanData (char prompt[], DataType dataType) {
  void *data = NULL;
  printf("%s", prompt);
  switch (dataType) {
    case INTEGER:
      int *intData = (int *)malloc(sizeof(int));
      if (scanf("%d", intData) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        free(intData);
        clearInputBuffer();
        return NULL;
      }
      data = intData;
      break;
    case CHARACTER:
      char *charData = (char *)malloc(sizeof(char));
      if (scanf(" %c", charData) != 1) {
        printf("Invalid input. Please enter a character.\n");
        free(charData);
        clearInputBuffer();
        return NULL;
      }
      data = charData;
      break;
    case STRING:
      clearInputBuffer(); // Clear any leftover input
      char buffer[STRING_MAX_LENGTH];
      if (fgets(buffer, STRING_MAX_LENGTH, stdin) == NULL) {
        printf("Invalid input. Please enter a string.\n");
        return NULL;
      }
      // Remove newline character if present
      if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
      }
      char *strData = (char *)malloc(strlen(buffer) + 1);
      strcpy(strData, buffer);
      data = strData;
      break;
  }
  return data;
}

void freeAll(Stack *stack) {
  if (stack->top == NULL) {
    printf("Nothing to free. The stack is already empty.\n");
    return;
  }

  printf("Freeing memory allocations...\n");
  StackNode *current = stack->top;
  StackNode *nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current->data);
    free(current);
    current = nextNode;
  }
  stack->top = NULL;
  stack->stackSize = 0;
  printf("Stack freed.\n");
}
