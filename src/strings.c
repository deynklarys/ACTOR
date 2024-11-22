#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

// Declarations
int getChar (char *string[], int n); // returns the nth character of the string
void putChar (char *string[], int n, char charToBeInserted); // sets the nth character of the string to charToBeInserted
int strLength (char *string[]); // returns the length of the string
int position (char *string[], char *stringToFind[]); // returns the position of the first occurrence of stringToFind in string
char *concatenate (char *string1[], char *string2[]); // returns the concatenation of string1 and string2
char *substring (char *string[], int position, int length); // returns the substring of string starting at position and of length length
void deleteStr (char *string[], int position, int length); // deletes the substring of string starting at position and of length length
char *insertStr (char *string[], char *stringToInsert[], int position); // inserts stringToInsert into string at position
int compareStr (char *string1[], char *string2[]); // returns 0 if string1 and string2 are equal, -1 if string1 < string2, 1 if string1 > string2

int main () {
  char *stringsMenu[] = {"Find a letter", "Replace a letter", "Insert a letter", "Delete a letter", "Exit"};
  int stringsMenuSize = sizeof(stringsMenu) / sizeof(stringsMenu[0]);
  int chosenOption;


  do {
    programHeader("Linked List");
    printMenu(stringsMenu, stringsMenuSize);
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
  } while (chosenOption != stringsMenuSize);

  return 0;
}

//Definitions

int getChar (char *string[], int n) {
  // Function definition
  return 0;
}

void putChar (char *string[], int n, char charToBeInserted) {
  // Function definition
}

int strLength (char *string[]) {
  // Function definition
  return 0;
}

int position (char *string[], char *stringToFind[]) {
  // Function definition
  return 0;
}

char *concatenate (char *string1[], char *string2[]) {
  // Function definition
  return NULL;
}

char *substring (char *string[], int position, int length) {
  // Function definition
  return NULL;
}

void deleteStr (char *string[], int position, int length) {
  // Function definition
}

char *insertStr (char *string[], char *stringToInsert[], int position) {
  // Function definition
  return NULL;
}

int compareStr (char *string1[], char *string2[]) {
  // Function definition
  return 0;
}