#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

#define STRING_MAX_LENGTH 50

int cursorXpos, cursorYpos;
int position, length;
char string[STRING_MAX_LENGTH], stringToFind[STRING_MAX_LENGTH], stringToInsert[STRING_MAX_LENGTH], string2[STRING_MAX_LENGTH],charToBeInserted;

// Declarations
void findChar (char string[]); // returns the nth character of the string
char *replaceChar (char string[]); // sets the nth character of the string to charToBeInserted
char *insertChar (char string[], int pos, char charToBeInserted); // inserts charToBeInserted into the string at position n
/*
char deleteChar (char string[], int pos); // deletes the nth character of the string
int findStr (char string[], char stringToFind[]); // returns the position of the first occurrence of stringToFind in string
char insertStr (char string[], char stringToInsert[], int position); // inserts stringToInsert into string at position
void deleteStr (char string[], int pos, int length); // deletes the substring of string starting at position and of length length
int strLength (char string[]); // returns the length of the string
char concatenate (char string[], char string2[]); // returns the concatenation of string1 and string2
int compareStr (char string[], char string2[]); // returns 0 if string1 and string2 are equal, -1 if string1 < string2, 1 if string1 > string2
*/
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
  if (string == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  printf("Enter the string: ");
  clearInputBuffer(); // Clear any leftover input
  if (fgets(string, STRING_MAX_LENGTH, stdin) == NULL) {
    printf("Invalid input. Please enter a string.\n");
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
void printString(char string[], char *status) {
  printf("Your %s string: ", status);
  printf("%s\n", string);
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

    strcpy(string, "Hello World!");
    position = 2;
    charToBeInserted = 'a';
    strcpy(stringToFind, "World");

  do {
    programHeader("Strings");

    printString(string, "");
    printf("\n");
    
    printMenu(stringsMenu, stringsMenuSize);
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
        findChar(string);
        break;
      case 2:
        strcpy(string, replaceChar(string));
        break;
      case 3:
        insertChar(string, position, charToBeInserted);
        break;
      case 4:
        // deleteChar(string, position);
        break;
      case 5:
        // findStr(string, stringToFind);
        break;
      case 6:
        // insertStr(string, stringToInsert, position);
        break;
      case 7:
        // deleteStr(string, position, length);
        break;
      case 8:
        // strLength(string);
        break;
      case 9:
        // strcpy(string2,"MY LOVE");
        // concatenate(string, string2);
        break;
      case 10:
        // compareStr(string, stringToFind);
        break;
      case 11:
        promptExit();
        system("cls");
        break;
      default:
        moveCursor(0, cursorYpos + 1);
        printf("Invalid choice. Please choose a valid option.\n");
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (chosenOption != stringsMenuSize);

  return 0;
}

void findChar (char string[]) {
  while (1) {
    position = scanPosition();
    if (position == -1) {
      continue;
    }
    if (position < 0 || position >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    printf("Character at position %d: %c\n", position, string[position]);
    break;
  }
}
char *replaceChar (char string[]) {
  while (1) {
    position = scanPosition();
    charToBeInserted = scanChar();
    if (position < 0 || position >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    string[position] = charToBeInserted;
    printf("Character at position %d replaced with %c\n", position, charToBeInserted);
    printString(string, "new");
    return string;
  }
}

char *insertChar (char string[], int pos, char charToBeInserted) {
  while (1) {
    position = scanPosition();
    charToBeInserted = scanChar();
    if (position == -1) {
      continue;
    }
    if (position < 0 || position >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = strlen(string); i >= position; i--) {
      string[i + 1] = string[i];
    }
    string[position] = charToBeInserted;
    printf("Character %c inserted at position %d\n", charToBeInserted, position);
    printString(string, "new");
    break;
  }
  return string;
}
/*
char deleteChar (char string[], int pos) {
  while (1) {
    int position = scanPosition();
    if (position == -1) {
      continue;
    }
    if (position < 0 || position >= strLength(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = position; i < strLength(string) - 1; i++) {
      string[i] = string[i + 1];
    }
    printf("Character at position %d deleted\n", position);
    printString(string, "new");
    break;
  }
  return string;
}
int findStr (char string[], char stringToFind[]) {
  while (1) {
    char stringToFind[] = scanString();
    if (stringToFind == NULL) {
      continue;
    }
    for (int i = 0; i < strLength(string); i++) {
      if (string[i] == stringToFind[0]) {
        int j;
        for (j = 1; j < strLength(stringToFind); j++) {
          if (string[i + j] != stringToFind[j]) {
            break;
          }
        }
        if (j == strLength(stringToFind)) {
          printf("Substring found at position %d\n", i);
          return i;
        }
      }
    }
    printf("Substring not found\n");
    break;
  }
  return -1;
}
char insertStr (char string[], char stringToInsert[], int position) {
  while (1) {
    int position = scanPosition();
    if (position == -1) {
      continue;
    }
    if (position < 0 || position >= strLength(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = 0; i < strLength(stringToInsert); i++) {
      string[position + i] = stringToInsert[i];
    }
    printf("String inserted at position %d\n", position);
    printString(string, "new");
    break;
  }
  return string;
}
void deleteStr (char string[], int pos, int length) {
  while (1) {
    int position = scanPosition();
    if (position == -1) {
      continue;
    }
    if (position < 0 || position >= strLength(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = position; i < strLength(string) - length; i++) {
      string[i] = string[i + length];
    }
    printf("Substring deleted\n");
    printString(string, "new");
    break;
  }
  return;
}
int strLength (char string[]) {
  while (1) {
    char string[] = scanString();
    if (string == NULL) {
      continue;
    }
    for (int i = 0; i < STRING_MAX_LENGTH; i++) {
      if (string[i] == '\0') {
        printf("Length of the string: %d\n", i);
        return i;
        break;
      }
    }
    break;
  }
}
char concatenate (char string[], char string2[]) {
  while (1) {
    char string[] = scanString();
    if (string == NULL) {
      continue;
    }
    char string2[] = scanString();
    if (string2 == NULL) {
      continue;
    }
    char concatenatedString[] = (char )malloc(strLength(string) + strLength(string2) + 1);
    if (concatenatedString == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return NULL;
    }
    int i, j;
    for (i = 0; i < strLength(string); i++) {
      concatenatedString[i] = string[i];
    }
    for (j = 0; j < strLength(string2); j++) {
      concatenatedString[i + j] = string2[j];
    }
    concatenatedString[i + j] = '\0';
    printf("Concatenated string: %s\n", concatenatedString);
    return concatenatedString;
  }
}
int compareStr (char string[], char string2[]) {
  while (1) {
    char string = scanString();
    if (string == NULL) {
      continue;
    }
    char string2 = scanString();
    if (string2 == NULL) {
      continue;
    }
    if (strLength(string) < strLength(string2)) {
      printf("String 1 is less than string 2\n");
      return -1;
    } else if (strLength(string) > strLength(string2)) {
      printf("String 1 is greater than string 2\n");
      return 1;
    } else {
      printf("String 1 is equal to string 2\n");
      return 0;
    }
  }
  return 0;
}
*/
