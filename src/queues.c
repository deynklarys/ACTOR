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
  char *queuesMenu[] = {"Add an item", "Remove an item","Look for an item", "Check if the queue is full", "Check if the queue is empty", "Exit"};
  int queuesMenuSize = sizeof(queuesMenu) / sizeof(queuesMenu[0]);
  int chosenOption;


  do {
    programHeader("Linked List");
    printMenu(queuesMenu, queuesMenuSize);
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
        functionNotDone("Check if the queue is full");
        isFull();
        break;
      case 5:
        functionNotDone("Check if the queue is empty");
        isEmpty();
        break;
      case 6:
        promptExit();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }
  } while (chosenOption != queuesMenuSize);

  return 0;
}
