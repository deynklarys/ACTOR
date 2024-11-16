#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "src/algorithms.h"

int setWidth = 80;
int setHeight = 24;

// Utility function definitions
void getTerminalSize() {
    /* Function to get the terminal size. */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	setWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	setHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  

  printf("setWidth: %d \nsetHeight: %d \n", setWidth, setHeight);
}
// Prints without the border. It can be later modified to include borderlines if I'm already certain that the application has borderlines throughout. 
void displayCenterText(char *message) {
  int length = strlen(message);
  int startIndex = (setWidth - length) / 2;
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
  /* Function to show the cursor */
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = TRUE;
  SetConsoleCursorInfo(consoleHandle, &info);
}
void getCursorPos(int *Xpos, int *Ypos) {
    /* Function to get the current position of the cursor */
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    *Xpos = info.dwCursorPosition.X;
    *Ypos = info.dwCursorPosition.Y;
}
void moveCursor(int x, int y) {
  /* Function to move the cursor at a specified coordinate in the terminal */
  // First three lines are for program header
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hConsole, pos);
}
void clearLines(int startLine, int endLine) {
    /* Function to clear lines in the terminal given a starting and ending y-coordinate */
    hideCursor();
	for (int i = startLine; i <= endLine; i++) {
		moveCursor(0, i);
		for (int j = 0; j < setWidth; j++) {
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
void programHeader(char *header) {
  /* Move cursor at the top of the file */
  moveCursor(0,0);
  
  for (int i = 1; i <= setWidth; i++) {
    printf("-");
  }
  printf("\n");

  displayCenterText(header);
  printf("\n");

  for (int i = 1; i <= setWidth; i++) {
    printf("-");
  }
  printf("\n\n");
}

// Screen handlers function definitions
void welcomeScreen () {
  system("cls");
  for (int i = 1; i <= setWidth; i++) {
    i == 1 || i == setWidth ? printf(" ") : printf("-");
  }
  printf("\n");

  for (int i = 2; i < setHeight; i++) {
    if (i == setHeight / 3 || i == 4 * (setHeight / 6) || i == 4 * (setHeight / 6) + 1 || i == setHeight - 3) {
      printf("|");
      if (i == setHeight / 3)
        displayCenterText("WELCOME TO DATA STRUCTURES AND ALGORITHMS");
      if (i == 4 * (setHeight / 6))
        displayCenterText("Deanne Clarice C. Bea");
      if (i == 4 * (setHeight / 6) + 1)
        displayCenterText("BS Computer Science 2A");
      if (i == setHeight - 3)
        displayCenterText("Press Any Key To Continue");
      printf("|\n");
      continue;
    }
    for (int j = 1 ; j <= setWidth; j++) {
      j == 1 || j == setWidth ? printf("|") : printf(" ");
    }
    printf("\n");
  }

  for (int i = 1; i <= setWidth; i++) {
    i == 1 || i == setWidth ? printf(" ") : printf("-");
  }
    printf("\n");

  hideCursor();
}




// Screen 2
int main () {




  return 0;
}