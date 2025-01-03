#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

#define ARRAY_MAX_LENGTH 50
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500
#define STRING_MAX_LENGTH 50
#define true 1
#define false 0
#define SET_WIDTH 80
#define SET_HEIGHT 24

// Utility function definitions

// Prints without the border. It can be later modified to include borderlines if I'm already certain that the application has borderlines throughout. 
void displayCenterText(char *message) {
  int length = strlen(message);
  int startIndex = (SET_WIDTH - length) / 2;
  for (int i = 0; i < startIndex - 1; i++) {
    printf(" ");
  }
  printf("%s", message);
  startIndex = (length % 2 == 0) ? (startIndex - 1) : startIndex;
  for (int i = 0; i < startIndex; i++) {
    printf(" ");
  }
}
void hideCursor() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}
void showCursor() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = TRUE;
  SetConsoleCursorInfo(consoleHandle, &info);
}
void getCursorPos(int *Xpos, int *Ypos) {
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  *Xpos = info.dwCursorPosition.X;
  *Ypos = info.dwCursorPosition.Y;
}
void moveCursor(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hConsole, pos);
}
void clearLines(int startLine, int endLine) {
  /* Function to clear lines in the terminal given a starting and ending y-coordinate */
  hideCursor();
	for (int i = startLine; i <= endLine; i++) {
		moveCursor(0, i);
		for (int j = 0; j < SET_WIDTH; j++) {
			printf(" ");
		}
	}
  showCursor();
}
void clearWord(int y, int startCol, int endCol) {
  /* Function to clear a specific portion of a line in the terminal */
  moveCursor(startCol, y);
  for (int i = 0; i < endCol - startCol; i++) {
  printf(" ");
  }
}
void clearPrompts(char *header) {
  /* Function to clear the prompts of the program. It will essentially clear everything below the program header. */
  system("cls");
  programHeader(header);
}
void promptExit(){
  int exitXpos, exitYpos, anyChar;
    getCursorPos(&exitXpos, &exitYpos);
  do {
    moveCursor(0, exitYpos + 3);
    displayCenterText("Press Enter To Exit");
    hideCursor();
    anyChar = _getch();
    /*On Windows systems, pressing Enter generates a carriage return ('\r'), which is why the comparison is made with '\r'.*/
    showCursor();
  } while (anyChar != '\r');
}
void programHeader(char *header) {
  /* Move cursor at the top of the file */
  moveCursor(0,0);
  
  for (int i = 1; i <= SET_WIDTH; i++) {
    printf("-");
  }
  printf("\n");

  displayCenterText(header);
  printf("\n");

  for (int i = 1; i <= SET_WIDTH; i++) {
    printf("-");
  }
  printf("\n\n");
}
void printMenu(char *arrString[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d) %s\n", i+1, arrString[i]);
  }
  printf("Choose a number: ");
}
void splitStrings(char *message, char substrings[][SUBSTRINGS_MAX_LENGTH], int *count, int lineWidth) {
  int messageLength = strlen(message);
  int start = 0;

  while (start < messageLength) {
    int end = start + lineWidth;
    if (end > messageLength) {
      end = messageLength;
    }

    // Find the last space within the line width to avoid breaking words
    while (end > start && message[end] != ' ' && message[end] != '\0') {
      end--;
    }

    // If no space was found, break at the line width
    if (end == start) {
      end = start + lineWidth;
    }

    strncpy(substrings[*count], message + start, end - start);
    substrings[*count][end - start] = '\0'; // Null-terminate the substring
    (*count)++;

    start = end + 1; // Move to the next part of the message
  }
}
void printWithinWidthCentered(char *message[], int messageSize, char *header) {
  char paragraphSubstrings[SUBSTRINGS_MAX_SUBSTRINGS][SUBSTRINGS_MAX_LENGTH];
  int paragraphSubstringsCount = 0;

  int lineWidth = SET_WIDTH * 0.8; 

  for (int i = 0; i < messageSize; i++) {
    splitStrings(message[i], paragraphSubstrings, &paragraphSubstringsCount, lineWidth);
  }

  programHeader(header);

  for (int i = 0; i < paragraphSubstringsCount; i++) {
    displayCenterText(paragraphSubstrings[i]);
    printf("\n");
  }
}
void printWithinWidth(char *message[], int messageSize, char *header) {
  char paragraphSubstrings[SUBSTRINGS_MAX_SUBSTRINGS][SUBSTRINGS_MAX_LENGTH];
  int paragraphSubstringsCount = 0;

  int lineWidth = SET_WIDTH * 0.9;

  for (int i = 0; i < messageSize; i++) {
    splitStrings(message[i], paragraphSubstrings, &paragraphSubstringsCount, lineWidth);
  }

  if (header != NULL) {
    programHeader(header);
  }

  for (int i = 0; i < paragraphSubstringsCount; i++) {
    printf("  %s\n", paragraphSubstrings[i]);
  }
}
void functionNotDone(char *header) {
  system("cls");
  programHeader(header);
  printf("\n\nFunction is not yet done...");
  promptExit();
  system("cls");
}
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int chooseDataType(char dataStructure[]) {
  int cursorXpos, cursorYpos;
  int chosenOption;
  printf("Choose data type for your %s: \n", dataStructure);
  char *dataTypeMenu[] = {"Integer", "Character", "String", "Exit"};
  int dataTypeMenuSize = sizeof(dataTypeMenu) / sizeof(dataTypeMenu[0]);

  int menuCursorXpos, menuCursorYpos;
  getCursorPos(&menuCursorXpos, &menuCursorYpos);
  do {
    printMenu(dataTypeMenu, dataTypeMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 1);
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      moveCursor(menuCursorXpos, menuCursorYpos);
      continue;
    }
    clearLines(cursorYpos + 1, cursorYpos + 1);
    moveCursor(0, cursorYpos + 2);
    switch (chosenOption) {
      case INTEGER:
        return INTEGER;
      case CHARACTER:
        return CHARACTER;
      case STRING:
        return STRING;
      case 4:
        return -1;
      default:
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    moveCursor(menuCursorXpos, menuCursorYpos);
  } while (chosenOption != dataTypeMenuSize);
}
void *scanData(char prompt[], DataType dataType) {
  void *data = NULL;
  int scanDataCursorXpos, scanDataCursorYpos;
  while (data == NULL) {
    printf("%s", prompt);
    getCursorPos(&scanDataCursorXpos, &scanDataCursorYpos);
    switch (dataType) {
      case INTEGER: {
        int *intData = (int *)malloc(sizeof(int));
        if (scanf("%d", intData) != 1) {
          clearLines(scanDataCursorYpos + 1, scanDataCursorYpos + 1);
          moveCursor(0, scanDataCursorYpos + 1);
          clearInputBuffer();
          printf("Invalid input. Please enter an integer.\n");
          free(intData);
          clearWord(scanDataCursorYpos, scanDataCursorXpos, SET_WIDTH);
          moveCursor(0, scanDataCursorYpos);
          continue;
        }
        data = intData;
        break;
      }
      case CHARACTER: {
        char *charData = (char *)malloc(sizeof(char));
        if (scanf(" %c", charData) != 1) {
          clearLines(scanDataCursorYpos + 1, scanDataCursorYpos + 1);
          moveCursor(0, scanDataCursorYpos + 1);
          clearInputBuffer();
          printf("Invalid input. Please enter a character.\n");
          free(charData);
          clearWord(scanDataCursorYpos, scanDataCursorXpos, SET_WIDTH);
          moveCursor(0, scanDataCursorYpos);
          continue;
        }
        data = charData;
        break;
      }
      case STRING: {
        clearInputBuffer(); // Clear any leftover input
        char buffer[STRING_MAX_LENGTH];
        if (fgets(buffer, STRING_MAX_LENGTH, stdin) == NULL) {
          clearLines(scanDataCursorYpos + 1, scanDataCursorYpos + 1);
          moveCursor(0, scanDataCursorYpos + 1);
          printf("Invalid input. Please enter a string.\n");
          clearWord(scanDataCursorYpos, scanDataCursorXpos, SET_WIDTH);
          moveCursor(0, scanDataCursorYpos);
          continue;
        }
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
        char *strData = (char *)malloc(strlen(buffer) + 1);
        if (strData == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          continue;
        }
        strcpy(strData, buffer);
        data = strData;
        break;
      }
    }
    clearWord(scanDataCursorYpos, scanDataCursorXpos, SET_WIDTH);
    moveCursor(0, scanDataCursorYpos);
  }
  return data;
}
void printInt(void *data) {
  printf(" %d ", *(int *)data);
}
void printChar(void *data) {
  printf(" %c ", *(char *)data);
}
void printStr(void *data) {
  printf(" %s ", (char *)data);
}
void printDataType(char dataStructure[], DataType dataType) {
  printf("Your %s data type: ", dataStructure);
  switch (dataType) {
    case INTEGER:
      printf("Integer\n");
      break;
    case CHARACTER:
      printf("Character\n");
      break;
    case STRING:
      printf("String\n");
      break;
  }
}

int scanInt(char *prompt) {
  int scanIntegerPosX, scanIntegerPosY;
  int integer;
  printf("%s", prompt);
  getCursorPos(&scanIntegerPosX, &scanIntegerPosY);
  if (scanf("%d", integer) != 1) {
    clearLines(scanIntegerPosY + 1, scanIntegerPosY + 1);
    moveCursor(0, scanIntegerPosY + 1);
    printf("Invalid input. Please enter a number.\n");
    clearInputBuffer();
    clearWord(scanIntegerPosY, scanIntegerPosX, SET_WIDTH);
    moveCursor(0, scanIntegerPosY);
    return -1;
  }

  clearLines(scanIntegerPosY + 1, scanIntegerPosY + 1);
  moveCursor(0, scanIntegerPosY + 1);
  return integer;
  }