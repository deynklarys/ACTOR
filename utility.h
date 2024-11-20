#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()

#define ARRAY_MAX_LENGTH 50
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500
#define true 1
#define false 0
#define SET_WIDTH 80
#define SET_HEIGHT 24

int terminalWidth = 0;
int terminalHeight = 0;
char anyChar;
int chosenOption;
int cursorXpos, cursorYpos;

// Utility functions 
void getTerminalSize();
void displayCenterText(char *message);
void hideCursor();
void showCursor();
void getCursorPos(int *Xpos, int *Ypos);
void moveCursor(int Xpos, int Ypos);
void clearLines(int startLine, int endLine);
void clearWord(int Ypos, int startX, int endX);
void clearPrompts(char *header);
void promptExit();
void programHeader(char *header);
void printMenu(char *arrString[], int size);
void splitStrings (char *inputStr, char paragraphSubstrings[][SUBSTRINGS_MAX_LENGTH], int *paragraphSubstringsCount, int minCharWidth);
void printWithinWidth(char *message[], int messageSize, char *header);

#endif // UTILITY_H