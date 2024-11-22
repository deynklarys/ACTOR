#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"


int main () {
  char *nonlinearDS_Menu[] = {"Linear Data Structures", "Nonlinear Data Structures", "Exit"};
  int nonlinearDS_MenuSize = sizeof(nonlinearDS_Menu) / sizeof(nonlinearDS_Menu[0]);
  int chosenOption;


  do {
    programHeader("Data Structures");
    printMenu(nonlinearDS_Menu, nonlinearDS_MenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Linear Data Structures");
        traverseList();
        break;
      case 2:
        functionNotDone("Nonlinear Data Structures");
        searchList();
        break;
      case 3:
        promptExit();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }

    // if (chosenOption != 7) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != nonlinearDS_MenuSize);

  return 0;
}
