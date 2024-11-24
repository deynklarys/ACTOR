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

int main () {
  char *arraysMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two arrays", "Exit"};
  int arraysMenuSize = sizeof(arraysMenu) / sizeof(arraysMenu[0]);
  int chosenOption;


  do {
    programHeader("Arrays");
    printMenu(arraysMenu, arraysMenuSize);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Traverse");
        traverseArray();
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
        functionNotDone("Merge twArrayo arrays");
        mergeArray();
        break;
      case 7:
        promptExit();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }
  } while (chosenOption != arraysMenuSize);

  return 0;
}

void traverseArray() {
    // Implementation of traverse
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