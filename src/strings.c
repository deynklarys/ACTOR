#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

#define STRING_MAX_LENGTH 50

int cursorXpos, cursorYpos;

// Declarations
int findChar (char *string[], int pos); // returns the nth character of the string
void replaceChar (char *string[], int pos, char charToBeInserted); // sets the nth character of the string to charToBeInserted
char *insertChar (char *string[], int pos, char charToBeInserted); // inserts charToBeInserted into the string at position n
char *deleteChar (char *string[], int pos); // deletes the nth character of the string
int findStr (char *string[], char *stringToFind[]); // returns the position of the first occurrence of stringToFind in string
char *insertStr (char *string[], char *stringToInsert[], int position); // inserts stringToInsert into string at position
void deleteStr (char *string[], int pos, int length); // deletes the substring of string starting at position and of length length
int strLength (char *string[]); // returns the length of the string
char *concatenate (char *string1[], char *string2[]); // returns the concatenation of string1 and string2
int compareStr (char *string1[], char *string2[]); // returns 0 if string1 and string2 are equal, -1 if string1 < string2, 1 if string1 > string2

int scanPosition() {
  int position;
  printf("Enter the position: ");
  if (scanf("%d", &position) != 1) {
    printf("Invalid input. Please enter a number.\n");
    clearInputBuffer();
    return -1;
  }
  return position;
}
char scanChar() {
  char character;
  printf("Enter the character: ");
  if (scanf(" %c", &character) != 1) {
    printf("Invalid input. Please enter a character.\n");
    clearInputBuffer();
    return '\0';
  }
  return character;
}
char *scanString() {
  char *string = (char *)malloc(STRING_MAX_LENGTH);
  if (string == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  printf("Enter the string: ");
  clearInputBuffer(); // Clear any leftover input
  if (fgets(string, STRING_MAX_LENGTH, stdin) == NULL) {
    printf("Invalid input. Please enter a string.\n");
    free(string);
    return NULL;
  }
  // Remove newline character if present
  string[strcspn(string, "\n")] = '\0';
  return string;
}
int scanLength() {
  int length;
  printf("Enter the length: ");
  if (scanf("%d", &length) != 1) {
    printf("Invalid input. Please enter a number.\n");
    clearInputBuffer();
    return -1;
  }
  return length;
}

int main () {
  char *stringsMenu[] = {
    "Find a character", 
    "Replace a character", 
    "Insert a character", 
    "Delete a character",
    "Find the position of a substring",
    "Insert a string",
    "Delete a string", 
    "Find the length of a string",    
    "Concatenate two strings",
    "Compare two strings",
    "Exit" };
  int stringsMenuSize = sizeof(stringsMenu) / sizeof(stringsMenu[0]);
  int chosenOption;


  do {
    programHeader("Strings");
    printMenu(stringsMenu, stringsMenuSize);
    if (scanf("%d", &chosenOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Find a character");
        break;
      case 2:
        functionNotDone("Replace a character");
        break;
      case 3:
        functionNotDone("Insert a character");
        break;
      case 4:
        functionNotDone("Delete a character");
        break;
      case 5:
        functionNotDone("Find a substring");
        break;
      case 6:
        functionNotDone("Insert a string");
        break;
      case 7:
        functionNotDone("Delete a string");
        break;
      case 8:
        functionNotDone("Find the position of a substring");
        break;
      case 9:
        functionNotDone("Find the length of a string");
        break;
      case 10:
        functionNotDone("Concatenate two strings");
        break;
      case 11:
        functionNotDone("Compare two strings");
        break;
      case 12:
        promptExit();
        break;
      default:
        moveCursor(0, cursorYpos + 1);
        printf("Invalid choice. Please choose a valid option.\n");
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (chosenOption != stringsMenuSize);

  return 0;
}

int findChar (char *string[], int pos) {
  return 0;
}
void replaceChar (char *string[], int pos, char charToBeInserted) {
  return;
}
char *insertChar (char *string[], int pos, char charToBeInserted) {
  return string;
}
char *deleteChar (char *string[], int pos) {
  return string;
}
int findStr (char *string[], char *stringToFind[]) {
  return 0;
}
char *insertStr (char *string[], char *stringToInsert[], int position) {
  return string;
}
void deleteStr (char *string[], int pos, int length) {
  return;
}
int strLength (char *string[]) {
  return 0;
}
char *concatenate (char *string1[], char *string2[]) {
  return string1;
}
int compareStr (char *string1[], char *string2[]) {
  return 0;
}
