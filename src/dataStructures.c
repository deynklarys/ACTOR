#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

#define ARRAY_MAX_LENGTH 1000
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500
#define true 1
#define false 0
#define SET_WIDTH 80
#define SET_HEIGHT 24

int main () {
  char *nonlinearDS_Menu[] = {"Linear Data Structures", "Nonlinear Data Structures", "Exit"};
  int nonlinearDS_MenuSize = sizeof(nonlinearDS_Menu) / sizeof(nonlinearDS_Menu[0]);
  int chosenOption;
  int cursorXpos, cursorYpos;


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
        clearInputBuffer(); // Clear invalid input
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break; 
    }

    // if (chosenOption != 7) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != nonlinearDS_MenuSize);

  return 0;
}
