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

void traverse();
void search();
void insert();
  void insertAtBeginning();
  void insertAtEnd();
  void insertAtMiddle();
void delete();
  void deleteFromBeginning();
  void deleteFromEnd();
  void deleteFromMiddle();
void merge();
void sort();
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

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
        traverse();
        break;
      case 2:
        functionNotDone("Search");
        search();
        break;
      case 3:
        functionNotDone("Insert");
        insert();
        break;
      case 4:
        functionNotDone("Delete");
        delete();
        break;
      case 5:
        functionNotDone("Sort");
        sort();
        break;
      case 6:
        functionNotDone("Merge two arrays");
        merge();
        break;
      case 7:
        promptExit();
        break;
      default:
        printf("Invalid choice. Please choose a valid option.\n");
    }

    // if (chosenOption != 7) {
    //   printf("Press any key to continue...\n");
    //   getch(); // Wait for user input before continuing
    // }

  } while (chosenOption != arraysMenuSize);

  return 0;
}

void traverse() {
    // Implementation of traverse
}

void search() {
    // Implementation of search
}

void insert() {
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

void delete() {
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

void merge() {
    // Implementation of merge
}

void sort() {
    // Implementation of sort
}