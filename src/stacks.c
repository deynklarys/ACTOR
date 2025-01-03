#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

// cd "c:\Academic-related_Programs\ACTOR\src\" ; if ($?) { gcc stacks.c -o stacks ..\utility.c} ; if ($?) { .\stacks }

#define STACK_MAX_SIZE 50
#define STRING_MAX_LENGTH 50
int cursorXpos, cursorYpos;

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
  Stack stack;
  int chosenDataType;
} StackResult;

void printStack(Stack *stack);
void pushStack(Stack *stack);
void popStack(Stack *stack);
void peekStack(Stack *stack);
void isFullStack(Stack *stack);
void isEmptyStack(Stack *stack);
StackResult initializeStacks();

void printInt(void *data) {
  printf(" %d ", *(int *)data);
}
void printChar(void *data) {
  printf(" %c ", *(char *)data);
}
void printString(void *data) {
  printf(" %s ", (char *)data);
}

void freeAll(Stack *stack);

int main() {
  programHeader("Stacks");

  Stack stack;

  system("cls");
  while (1) {
    StackResult stackResult = initializeStacks();
    stack = stackResult.stack;
    stack.stackDataType = stackResult.chosenDataType;
    if (stack.stackDataType == -1) {
      system("cls");
      freeAll(&stack);
      return 0;
    }

    char *stacksMenu[] = {"Add an item", "Remove an item", "Check the top item", "Check if the stack is full", "Check if the stack is empty", "Exit"};
    int stacksMenuSize = sizeof(stacksMenu) / sizeof(stacksMenu[0]);
    int chosenOption;

    system("cls");
    do {
      programHeader("Stacks Operations");
      printDataType("stack", stack.stackDataType);
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
      
      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      switch (chosenOption) {
        case 1:
          system("cls");
          programHeader("Add an item onto the stack"); 
          push(&stack);
          printStack(&stack);
          promptExit();
          system("cls");
          break;
        case 2:
          system("cls");
          programHeader("Remove an item from the stack");
          pop(&stack);
          printStack(&stack);
          promptExit();
          system("cls");
          break;
        case 3:
          peek(&stack);
          break;
        case 4:
          isFull(&stack);
          break;
        case 5:
          isEmpty(&stack);
          break;
        case 6:
          freeAll(&stack);
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

StackResult initializeStacks() {
  char *message[] = {"Stacks are a type of data structure that follows the Last In First Out (LIFO) or the First In Last Out (FILO) principle.", "This means that the last element added to the stack will be the first one to be removed. Like a stack of books!"};
  int messageSize = sizeof(message) / sizeof(message[0]);

  printWithinWidth(message, messageSize, "Stacks");

  StackResult result;
  result.chosenDataType = chooseDataType("stack");
  if (result.chosenDataType == -1) {
    return result;
  }

  switch (result.chosenDataType) {
    case INTEGER:
      result.stack = (Stack) {NULL, sizeof(int), printInt, INTEGER, 0};
      break;
    case CHARACTER:
      result.stack = (Stack) {NULL, sizeof(char), printChar, CHARACTER, 0};
      break;
    case STRING:
      result.stack = (Stack) {NULL, sizeof (char *),printString, STRING, 0};
      break;
  }
  return result;
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

void printStack(Stack *stack) {
  printf("\nYour stack: \n");
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return;
  }

  StackNode *temp = stack->top;
  while (temp != NULL) {
    stack->printFunc(temp->data);
    temp = temp->next;
    printf("\n");
  }
}
void pushStack(Stack *stack) {
  if (stack->stackSize == STACK_MAX_SIZE) {
    printf("Stack overflow\n");
    return;
  }

  void *data = scanData("Enter data to add: ", stack->stackDataType);
  if (data == NULL) {
    return;
  }

  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    free(data);
    return;
  }
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
  stack->stackSize++;
}
void popStack(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack underflow\n");
    return;
  }

  StackNode *temp = stack->top;
  stack->top = stack->top->next;

  stack->printFunc(temp->data);
  printf(" is removed from the stack.\n");

  free(temp->data);
  free(temp);
  stack->stackSize--;
}
void peekStack(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return;
  }

  printf("Top element: ");
  stack->printFunc(stack->top->data);
  printf("\n");
}
void isFullStack(Stack *stack) {
  char *message[] = {
    "\nNote:", "This program implements a stack data structure using linked lists. As a result, the stack will only be full when the system runs out of memory.",
    "However, for practical purposes, the stack is considered full when it reaches a predefined maximum size. In this implementation, the maximum stack size is set to 50."};
  if (stack->stackSize == STACK_MAX_SIZE) {
    printf("Stack is full\n");
  } else {
    printf("Stack is not full\n");
  }
  printWithinWidth(message, sizeof(message) / sizeof(message[0]), NULL);
}
void isEmptyStack(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
  } else {
    printf("Stack is not empty\n");
  }
}
