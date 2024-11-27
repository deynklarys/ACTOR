#include <stdio.h>
#include <windows.h>
#include <conio.h> // for getch()
#include "utility.h"

void printWithinWidth(char *message[], int messageSize, char *header) {

  char paragraphSubstrings[SUBSTRINGS_MAX_SUBSTRINGS][SUBSTRINGS_MAX_LENGTH];
  int paragraphSubstringsCount = 0;

  int lineWidth = SET_WIDTH * 0.7; 
  int phraseToCopy = lineWidth;

  for (int i = 0; i < messageSize; i++) {
    splitStrings(message[i], paragraphSubstrings, &paragraphSubstringsCount, lineWidth);
  }

  programHeader(header);

  for (int i = 0; i < paragraphSubstringsCount; i++) {
    printf("%s", paragraphSubstrings[i]);
  }
}

int main () {

  char *message[] = {"Arrays are a collection of elements of the same types of  data.\n", "Examples:\n", "\t1, 2, 3, 4, 5 is an array of numbers\n", "\ta, b, c, d, e is an array of letters\n", "\tapple, banana, mango, orange is an array of words\n","Each number, letter, or word in an array is called an element.\n"};
  int messageSize = sizeof(message)/sizeof(message[0]);

  printWithinWidth(message, messageSize, "Arrays");

  return 0;
}