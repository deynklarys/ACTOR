#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"


int main () {
  char *linearDS_Menu[] = {"Arrays", "Linked Lists", "Stacks", "Queues", "Exit"};
  int linearDS_MenuSize = sizeof(linearDS_Menu) / sizeof(linearDS_Menu[0]);
  int chosenOption;


  do {
    programHeader("Linked List");
    printMenu(linearDS_Menu, linearDS_MenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Arrays");
        traverseList();
        break;
      case 2:
        functionNotDone("Linked Lists");
        searchList();
        break;
      case 3:
        functionNotDone("Stacks");
        insert();
        break;
      case 4:
        functionNotDone("Queues");
        delete();
        break;
      case 5:
        promptExit();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }
  } while (chosenOption != linearDS_MenuSize);

  return 0;
}
