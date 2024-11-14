// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <windows.h>
#include "src/algorithms.h"

#define ARRAY_MAX_LENGTH 1000
int terminalWidth = 80;
int terminalHeight = 24;

void getTerminalSize() {
    /* Function to get the terminal size. */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminalHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  

  printf("terminalWidth: %d \nterminalHeight: %d \n", terminalWidth, terminalHeight);
}

/*
void array ( ) {
  int arrSize;
  int givenArray[ARRAY_MAX_LENGTH];
  printf("Enter array size: ");
  scanf("%d", &arrSize);
  printf("Enter your elements in the array:\n");
  for (int i = 0; i < arrSize; i++) {
    printf("\tarray[%d]: ", i);
    scanf("%d", &givenArray[i]);
  }

  sort (givenArray, arrSize, 1);

}
*/

void displayCenterText(char *message) {
  int length = strlen(message);

  int startIndex = (terminalWidth - length) / 2;
  printf("|");
  for (int i = 0; i < startIndex - 1; i++) {
    printf(" ");
  }
  printf("%s", message);
  startIndex = (length % 2 == 0) ? (startIndex - 1) : startIndex;
  for (int i = 0; i < startIndex; i++) {
    printf(" ");
  }
  printf("|");
}


void welcomeScreen () {
  system("cls");
  printf(" ");
  for (int i = 0; i < terminalWidth-2; i++) {
    printf("-");
  }
  printf("\n");

  for (int i = 1; i < terminalHeight - 1; i++) {
    if (i == terminalHeight / 4) {
      displayCenterText("WELCOME TO DATA STRUCTURES AND ALGORITHMS");
      printf("\n");
      continue;
    }
    if (i == 4 * (terminalHeight / 6)) {
      displayCenterText("Deanne Clarice C. Bea");
      printf("\n");
      continue;
    }
    if (i == 4 * (terminalHeight / 6) + 1) {
      displayCenterText("BS Computer Science 2A");
      printf("\n");
      continue;
    }
    if (i == terminalHeight - 4) {
      displayCenterText("Press Any Key To Continue");
      printf("\n");
      continue;
    }
    for (int j = 1 ; j <= terminalWidth; j++) {
      if (j == terminalWidth)
        printf("|");
      else {j == 1 ? printf("|") : printf(" ");}
      }
    printf("\n");
  }

  printf(" ");
  for (int i = 0; i < terminalWidth-2; i++) {
  printf("-");
  }
}


int main () {
  // getTerminalSize();
  welcomeScreen();


  return 0;
  
}