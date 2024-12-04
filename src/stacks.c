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
  int stackSize;
  DataType stackDataType;
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
