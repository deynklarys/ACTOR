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

int main () {
  char *stacksMenu[] = {"Add an item", "Remove an item","Look for an item", "Check if the stack is full", "Check if the stack is empty", "Exit"};
  int stacksMenuSize = sizeof(stacksMenu) / sizeof(stacksMenu[0]);
  int chosenOption;


  do {
    programHeader("Linked List");
    printMenu(stacksMenu, stacksMenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

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
        printf("Invalid choice. Please choose a valid option.\n");
    }

    // if (chosenOption != stacksMenuSize) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != stacksMenuSize);

  return 0;
}
