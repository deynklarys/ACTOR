#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

#define STRING_MAX_LENGTH 50

int cursorXpos, cursorYpos;
int indexPos, position, length;
char string[STRING_MAX_LENGTH], stringToFind[STRING_MAX_LENGTH], stringToInsert[STRING_MAX_LENGTH], string2[STRING_MAX_LENGTH],charToBeInserted;

// Declarations
void findChar ();
char *replaceChar ();
char *insertChar ();
char *deleteChar ();
int findStr ();
char *insertStr ();
void deleteStr ();
int strLength ();
char *concatenate ();
int compareStr ();

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
char *scanString(char *string) {
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
    getCursorPos(&cursorXpos, &cursorYpos);
    clearLines(cursorYpos, cursorYpos + 1);
    moveCursor(0, cursorYpos);   
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
        findChar();
        break;
      case 2:
        replaceChar();
        break;
      case 3:
        insertChar();
        break;
      case 4:
        deleteChar();
        break;
      case 5:
        findStr();
        break;
      case 6:
        insertStr();
        break;
      case 7:
        deleteStr();
        break;
      case 8:
        strLength();
        break;
      case 9:
        concatenate();
        break;
      case 10:
        compareStr();
        break;
      case 11:
        promptExit();
        system("cls");
        break;
      default:
        moveCursor(0, cursorYpos + 1);
        printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (chosenOption != stringsMenuSize);

  return 0;
}

void findChar () {
  while (1) {
    position = scanPosition();
    indexPos = position - 1;
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    printf("Character at position %d: %c\n", position, string[indexPos]);
    break;
  }
}
char *replaceChar () {
  while (1) {
    position = scanPosition();
    indexPos = position - 1;
    charToBeInserted = scanChar();
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    string[indexPos] = charToBeInserted;
    printf("Character at position %d replaced with %c\n", position, charToBeInserted);
    printString(string, "new");
    return string;
  }
}

char *insertChar () {
  while (1) {
    position = scanPosition();
    indexPos = position - 1;
    charToBeInserted = scanChar();
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = strlen(string); i >= indexPos; i--) {
      string[i + 1] = string[i];
    }
    string[indexPos] = charToBeInserted;
    printf("Character %c inserted at position %d\n", charToBeInserted, position);
    printString(string, "new");
    break;
  }
  return string;
}

char *deleteChar () {
  while (1) {
    position = scanPosition();
    indexPos = position - 1;
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    for (int i = indexPos; i < strlen(string) - 1; i++) {
      string[i] = string[i + 1];
    }
    printf("Character at position %d deleted\n", position);
    printString(string, "new");
    break;
  }
  return string;
}

int findStr () {
  while (1) {
    strcpy(stringToFind, scanString(stringToFind));
    if (stringToFind == NULL) {
      continue;
    }
    for (int i = 0; i < strlen(string); i++) {
      if (string[i] == stringToFind[0]) {
        int j;
        for (j = 1; j < strlen(stringToFind); j++) {
          if (string[i + j] != stringToFind[j]) {
            break;
          }
        }
        if (j == strlen(stringToFind)) {
          printf("Substring found starting at position %d\n", i + 1);
          return i + 1;
        }
      }
    }
    printf("Substring not found\n");
    break;
  }
  return -1;
}

char *insertStr () {
  while (1) {
    int position = scanPosition();
    indexPos = position - 1;
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    strcpy(stringToInsert, scanString(stringToInsert));
    for (int i = strlen(string); i >= indexPos; i--) {
      string[i + strlen(stringToInsert)] = string[i];
    }
    for (int i = 0; i < strlen(stringToInsert); i++) {
      string[indexPos + i] = stringToInsert[i];
    }
    printf("String inserted at position %d\n", position);
    printString(string, "new");
    break;
  }
  return string;
}
void deleteStr () {
  while (1) {
    int position = scanPosition();
    indexPos = position - 1;
    if (position == -1) {
      continue;
    }
    if (indexPos < 0 || indexPos >= strlen(string)) {
      printf("Invalid position. Please enter a valid position.\n");
      continue;
    }
    length = scanLength();
    for (int i = indexPos; i < strlen(string) - length; i++) {
      string[i] = string[i + length];
    }
    string[strlen(string) - length] = '\0';
    printf("Substring deleted\n");
    printString(string, "new");
    break;
  }
  return;
}
int strLength () {
  while (1) {
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
char *concatenate () {
  while (1) {
    strcpy(string2,scanString(string2));
    if (string2 == NULL) {
      continue;
    }
    int totalLength = strlen(string) + strlen(string2);
    char *concatenatedString = (char *)malloc(totalLength + 1);
    if (concatenatedString == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return NULL;
    }
    int i, j;
    for (i = 0; i < strlen(string); i++) {
      concatenatedString[i] = string[i];
    }
    for (j = 0; j < strlen(string2); j++) {
      concatenatedString[i + j] = string2[j];
    }
    concatenatedString[i + j] = '\0';
    printf("Concatenated string: %s\n", concatenatedString);
    return concatenatedString;
  }
}
int compareStr () {
  while (1) {
    strcpy(string2,scanString(string2));
    if (string2 == NULL) {
      continue;
    }
    for (int i = 0; i < strlen(string); i++) {
      if (string[i] < string2[i]) {
        printf("String 1 is less than string 2\n");
        return -1;
      } else if (string[i] > string2[i]) {
        printf("String 1 is greater than string 2\n");
        return 1;
      }
    }
    if (strlen(string) < strlen(string2)) {
      printf("String 1 is less than string 2\n");
      return -1;
    } else if (strlen(string) > strlen(string2)) {
      printf("String 1 is greater than string 2\n");
      return 1;
    } else {
      printf("String 1 is equal to string 2\n");
      return 0;
    }
  }
  return 0;
}

