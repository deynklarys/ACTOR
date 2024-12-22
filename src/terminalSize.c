#include <stdio.h>
#include <windows.h>

int terminalWidth = 0;
int terminalHeight = 0;
void getTerminalSize() {
  /* Function to get the terminal size. */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminalHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  

  printf("terminalWidth: %d \nterminalHeight: %d \n", terminalWidth, terminalHeight);
}

int main() {
  getTerminalSize();
  return 0;
}