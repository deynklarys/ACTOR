// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

#define ARRAY_MAX_LENGTH 1000
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500
#define STRING_MAX_LENGTH 50
#define true 1
#define false 0
#define SET_WIDTH 80
#define SET_HEIGHT 24

int chosenOption;
int cursorXpos, cursorYpos;

// Screen handlers
void welcomeScreen ();
void dataStructures ();
  void linearDS();
    void arrays();
    void linkedLists();
    void stacks();
    void queues();
  void nonLinearDS();
    void trees();
  void strings();
    int position, length;
    char string[STRING_MAX_LENGTH], stringToFind[STRING_MAX_LENGTH], stringToInsert[STRING_MAX_LENGTH], string2[STRING_MAX_LENGTH],charToBeInserted;
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
    int scanPosition(char *prompt);
    char scanChar(char *prompt);
    char *scanString(char *string);
    int scanLength(char *prompt);
    void printString(char string[], char *status);
    void introduceStrings();
void algorithms();
  void searching();
  void sorting();
    void partitionScheme(); // for quick sort
    void digitOrder(); // for radix sort
void about();

// Arrays Function Declarations
  void printArray(int array[], int size);
  void swap(int *a, int *b);
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
  int isArraySorted(int array[], int size);
  void shuffle(int array[], int size);
void randomSort(int array[], int size);
  void merge(int array[], int leftIndex, int mid, int rightIndex);
void mergeSort(int array[], int leftIndex, int rightIndex);
  int partitionLomuto(int array[], int first, int last);
  int partitionHoare(int array[], int first, int last);
void quickSortLomuto(int array[], int first, int last);
void quickSortHoare(int array[], int first, int last);
  void countRadixSort(int array[], int size, int placeValue);
void radixSort(int array[], int size);
  void heapify(int array[], int size, int i);
void heapSort(int array[], int size);
void sort(int array[], int size, int sortType);

// Search functions
int binarySearch(int array[], int key, int low, int high);
int linearSearch(int array[], int n, int x);
void search(int array[], int size, int key, int searchType);

int main () {
  /*
    If the terminal screen is not 80 by 24 size, it will recommend to adjust the window size for better experience
    int terminalWidth = 0;
    int terminalHeight = 0;

    getTerminalSize();

    if (terminalWidth != SET_WIDTH && terminalHeight != SET_HEIGHT) {
      print("The terminal size is not suitable for this program. It must be 80 characters  width and 24 lines height. Please resize the program and rerun the program. Thank you!");
      return 0;
    }
  
  */
  welcomeScreen();

  getch(); // Use _getch() to read a single character without echoing

  system("cls");
  showCursor();

  char *mainMenu[] = {"Data Structures", "Algorithms", "About", "Quit"};
  int mainMenuSize = sizeof(mainMenu)/sizeof(mainMenu[0]);


  do {
    programHeader("Data Structures and Algorithms");

    printf("What do you want to learn about?\n");
    printMenu(mainMenu, mainMenuSize);
    /* Get the current position of the cursor after the prompt. This coordinate will be used to bring back the cursor at this position when the user inputs an invalid option and the option that they typed is cleared. */
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("\n");
      displayCenterText("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
      continue;
    }

      switch (chosenOption) {
        case 1:
          system("cls");
          dataStructures();
          system("cls");
          break;
        case 2:
          system("cls");
          algorithms();
          system("cls");
          break;
        case 3:
          system("cls");
          about();
          system("cls");
          showCursor();
          break;
        case 4: 
          system("cls");
          moveCursor(0, SET_HEIGHT / 2 - 1);
          displayCenterText("Quitting ACTOR...");
          hideCursor();
          Sleep(1000);
          break;
        default:
          clearInputBuffer(); // Clear invalid input
          printf("\n");
          displayCenterText("Invalid input. Please enter a number.\n");
          clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
          break; 
      }

  } while (chosenOption != mainMenuSize);             
                   
  return 0;
}

// Screen handlers function definitions
void welcomeScreen () {
  // system("cls");
  for (int i = 1; i <= SET_WIDTH; i++) {
    i == 1 || i == SET_WIDTH ? printf(" ") : printf("-");
  }
  printf("\n");

  for (int i = 2; i < SET_HEIGHT; i++) {
    if (i == SET_HEIGHT / 3 || i == 4 * (SET_HEIGHT / 6) || i == 4 * (SET_HEIGHT / 6) + 1 || i == SET_HEIGHT - 3) {
      printf("|");
      if (i == SET_HEIGHT / 3)
        displayCenterText("WELCOME TO DATA STRUCTURES AND ALGORITHMS");
      if (i == 4 * (SET_HEIGHT / 6))
        displayCenterText("Deanne Clarice C. Bea");
      if (i == 4 * (SET_HEIGHT / 6) + 1)
        displayCenterText("BS Computer Science 2A");
      if (i == SET_HEIGHT - 3)
        displayCenterText("Press Any Key To Continue");
      printf("|\n");
      continue;
    }
    for (int j = 1 ; j <= SET_WIDTH; j++) {
      j == 1 || j == SET_WIDTH ? printf("|") : printf(" ");
    }
    printf("\n");
  }

  for (int i = 1; i <= SET_WIDTH; i++) {
    i == 1 || i == SET_WIDTH ? printf(" ") : printf("-");
  }
    printf("\n");

  hideCursor();
}

void trees () {
  functionNotDone("Trees");
}
void nonLinearDS () {
  functionNotDone("Non-Linear Data Structures");
}
void arrays () {
  char *arraysMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two arrays", "Exit"};
  int arraysMenuSize = sizeof(arraysMenu) / sizeof(arraysMenu[0]);
  int chosenOption;

  do {
    programHeader("Arrays");
    printMenu(arraysMenu, arraysMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Traverse");
        // traverse();
        break;
      case 2:
        functionNotDone("Search");
        // search();
        break;
      case 3:
        functionNotDone("Insert");
        // insert();
        break;
      case 4:
        functionNotDone("Delete");
        // delete();
        break;
      case 5:
        functionNotDone("Sort");
        // sort();
        break;
      case 6:
        functionNotDone("Merge two arrays");
        // merge();
        break;
      case 7:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break;
    }
  } while (chosenOption != arraysMenuSize);
}
void linkedLists () {
  char *linkedListMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two lists", "Exit"};
  int linkedListMenuSize = sizeof(linkedListMenu) / sizeof(linkedListMenu[0]);
  int chosenOption;

  do {
    programHeader("Linked List");
    printMenu(linkedListMenu, linkedListMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        functionNotDone("Traverse");
        // traverseList();
        break;
      case 2:
        functionNotDone("Search");
        // searchList();
        break;
      case 3:
        functionNotDone("Insert");
        // insert();
        break;
      case 4:
        functionNotDone("Delete");
        // delete();
        break;
      case 5:
        functionNotDone("Sort");
        // sortList();
        break;
      case 6:
        functionNotDone("Merge Two Lists");
        // mergeLists();
        break;
      case 7:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break;
    }
  } while (chosenOption != linkedListMenuSize);

}
void stacks () {
  char *stacksMenu[] = {"Add an item", "Remove an item","Look for an item", "Check if the stack is full", "Check if the stack is empty", "Exit"};
  int stacksMenuSize = sizeof(stacksMenu) / sizeof(stacksMenu[0]);
  int chosenOption;

  do {
    programHeader("Linked List");
    printMenu(stacksMenu, stacksMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }
    switch (chosenOption) {
      case 1:
        functionNotDone("Add an item");
        // push();
        break;
      case 2:
        functionNotDone("Remove an item");
        // pop();
        break;
      case 3:
        functionNotDone("Look for an item");
        // peek();
        break;
      case 4:
        functionNotDone("Check if the stack is full");
        // isFull();
        break;
      case 5:
        functionNotDone("Check if the stack is empty");
        // isEmpty();
        break;
      case 6:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break; 
    }
  } while (chosenOption != stacksMenuSize);
}
void queues () {
  char *queuesMenu[] = {"Add an item", "Remove an item","Look for an item", "Check if the queue is full", "Check if the queue is empty", "Exit"};
  int queuesMenuSize = sizeof(queuesMenu) / sizeof(queuesMenu[0]);
  int chosenOption;

  do {
    programHeader("Linked List");
    printMenu(queuesMenu, queuesMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }
    switch (chosenOption) {
      case 1:
        functionNotDone("Add an item");
        // push();
        break;
      case 2:
        functionNotDone("Remove an item");
        // pop();
        break;
      case 3:
        functionNotDone("Look for an item");
        // peek();
        break;
      case 4:
        functionNotDone("Check if the queue is full");
        // isFull();
        break;
      case 5:
        functionNotDone("Check if the queue is empty");
        // isEmpty();
        break;
      case 6:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break; 
    }
  } while (chosenOption != queuesMenuSize);
}

void strings () {
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

  system("cls");

  introduceStrings();

  strcpy(string, scanString(string));
  promptExit();

  system("cls");
  do {
    programHeader("Strings");
    getCursorPos(&cursorXpos, &cursorYpos);
    clearLines(cursorYpos, cursorYpos + 1);
    moveCursor(0, cursorYpos);   
    printString(string, "");
    printf("\n");
    
    printMenu(stringsMenu, stringsMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    moveCursor(cursorXpos, cursorYpos);
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
}
  void findChar () {
    while (1) {
      position = scanPosition("to find");
      if (position == -1) {
        continue;
      }
      printf("Character at position %d: %c\n", position, string[position - 1]);
      break;
    }
  }
  char *replaceChar () {
    while (1) {
      position = scanPosition("to replace");
      if (position == -1) {
        continue;
      }
      charToBeInserted = scanChar("to replace with");
      string[position - 1] = charToBeInserted;
      printf("Character at position %d replaced with %c\n", position, charToBeInserted);
      printString(string, "new");
      return string;
    }
  }
  char *insertChar () {
    while (1) {
      position = scanPosition("to insert");
      if (position == -1) {
        continue;
      }
      charToBeInserted = scanChar("to insert");

      for (int i = strlen(string); i >= position - 1; i--) {
        string[i + 1] = string[i];
      }
      string[position - 1] = charToBeInserted;
      printf("Character %c inserted at position %d\n", charToBeInserted, position);
      printString(string, "new");
      break;
    }
    return string;
  }
  char *deleteChar () {
    while (1) {
      position = scanPosition("to delete");
      if (position == -1) {
        continue;
      }
      for (int i = position - 1; i < strlen(string) - 1; i++) {
        string[i] = string[i + 1];
      }
      string[strlen(string) - 1] = '\0';
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
      int position = scanPosition("to insert");
      if (position == -1) {
        continue;
      }
      strcpy(stringToInsert, scanString(stringToInsert));
      for (int i = strlen(string); i >= position - 1; i--) {
        string[i + strlen(stringToInsert)] = string[i];
      }
      for (int i = 0; i < strlen(stringToInsert); i++) {
        string[position - 1 + i] = stringToInsert[i];
      }
      printf("String inserted at position %d\n", position);
      printString(string, "new");
      break;
    }
    return string;
  }
  void deleteStr () {
    while (1) {
      int position = scanPosition("to delete");
      if (position == -1) {
        continue;
      }
      length = scanLength("to delete");
      for (int i = position - 1; i < strlen(string) - length; i++) {
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
  int scanPosition(char *prompt) {
    int scanPositionPosX, scanPositionPosY;
    int position;
    printf("Enter the position %s: ", prompt);
    getCursorPos(&scanPositionPosX, &scanPositionPosY);
    if (scanf("%d", &position) != 1) {
      clearLines(scanPositionPosY + 1, scanPositionPosY + 1);
      moveCursor(0, scanPositionPosY + 1);
      printf("Invalid input. Please enter a number.\n");
      clearInputBuffer();
      clearWord(scanPositionPosY, scanPositionPosX, SET_WIDTH);
      moveCursor(0, scanPositionPosY);
      return -1;
    }
    if (position < 1 || position > strlen(string) + 1) {
      clearLines(scanPositionPosY + 1, scanPositionPosY + 1);
      moveCursor(0, scanPositionPosY + 1);
      clearInputBuffer();
      printf("Invalid position. Please enter a valid position.\n");
      clearWord(scanPositionPosY, scanPositionPosX, SET_WIDTH);
      moveCursor(0, scanPositionPosY);
      return -1;
    }
    clearLines(scanPositionPosY + 1, scanPositionPosY + 1);
    moveCursor(0, scanPositionPosY + 1);
    return position;
  }
  char scanChar(char *prompt) {
    int scanCharPosX, scanCharPosY;
    char character;
    getCursorPos(&scanCharPosX, &scanCharPosY);
    printf("Enter the character %s: ", prompt);
    if (scanf(" %c", &character) != 1) {
      clearLines(scanCharPosY + 1, scanCharPosY + 1);
      moveCursor(0, scanCharPosY + 1);
      printf("Invalid input. Please enter a character.\n");
      clearInputBuffer();
      clearWord(scanCharPosY, scanCharPosX, SET_WIDTH);
      moveCursor(0, scanCharPosY);
      return '\0';
    }
    clearLines(scanCharPosY + 1, scanCharPosY + 1);
    moveCursor(0, scanCharPosY + 1);
    return character;
  }
  char *scanString(char *string) {
    if (string == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return NULL;
    }
    printf("Enter the string: ");
    clearInputBuffer();
    if (fgets(string, STRING_MAX_LENGTH, stdin) == NULL) {
      printf("Invalid input. Please enter a string.\n");
      return NULL;
    }
    // Remove newline character if present
    string[strcspn(string, "\n")] = '\0';
    return string;
  }
  int scanLength(char *prompt) {
    int scanLengthPosX, scanLengthPosY;
    int length;
    printf("Enter the length  %s: ", prompt);
    getCursorPos(&scanLengthPosX, &scanLengthPosY);
    if (scanf("%d", &length) != 1) {
      clearLines(scanLengthPosY + 1, scanLengthPosY + 1);
      moveCursor(0, scanLengthPosY + 1);
      printf("Invalid input. Please enter a number.\n");
      clearInputBuffer();
      clearWord(scanLengthPosY, scanLengthPosX, SET_WIDTH);
      moveCursor(0, scanLengthPosY);
      return -1;
    }
    if (length < 1 || length > strlen(string)) {
      clearLines(scanLengthPosY + 1, scanLengthPosY + 1);
      moveCursor(0, scanLengthPosY + 1);
      printf("Invalid length. Please enter a valid length.\n");
      clearWord(scanLengthPosY, scanLengthPosX, SET_WIDTH);
      moveCursor(0, scanLengthPosY);
      return -1;
    }
    clearLines(scanLengthPosY + 1, scanLengthPosY + 1);
    moveCursor(0, scanLengthPosY + 1);
    return length;
  }
  void printString(char string[], char *status) {
    printf("Your %s string: ", status);
    printf("%s\n", string);
  }
  void introduceStrings() {
    char *introduction[] = {
      "A string is a sequence of characters terminated by a null character ('\\0'). Strings are typically represented as arrays of characters. The null character indicates the end of the string, allowing functions to determine the length of the string.",
      "Think of it like a necklace of beads, where each bead is a character and the clasp is the null character.",
      "Strings can be manipulated by finding, replacing, inserting, deleting characters, and more!\n"
    };
    int introductionSize = sizeof(introduction) / sizeof(introduction[0]);

    printWithinWidth(introduction, introductionSize, "Strings");
  }
void linearDS () {
  char *linearDS_Menu[] = {"Arrays", "Linked Lists", "Stacks", "Queues", "Exit"};
  int linearDS_MenuSize = sizeof(linearDS_Menu) / sizeof(linearDS_Menu[0]);
  int chosenOption;


  do {
    programHeader("Linear Data Structures");
    printMenu(linearDS_Menu, linearDS_MenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        system("cls");
        arrays();
        system("cls");
        break;
      case 2:
        system("cls");
        linkedLists();
        system("cls");
        break;
      case 3:
        system("cls");
        stacks();
        system("cls");
        break;
      case 4:
        system("cls");
        queues();
        system("cls");
        break;
      case 5:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break;
    }
  } while (chosenOption != linearDS_MenuSize);
}
void dataStructures () {
  char *dataStructuresMenu[] = {"Linear Data Structures", "Nonlinear Data Structures", "Strings", "Exit"};
  int dataStructuresMenuSize = sizeof(dataStructuresMenu) / sizeof(dataStructuresMenu[0]);

  do {
    programHeader("Data Structures");
    printMenu(dataStructuresMenu, dataStructuresMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (chosenOption) {
      case 1:
        system("cls");
        linearDS();
        system("cls");
        break;
      case 2:
        system("cls");
        nonLinearDS();
        system("cls");
        break;
      case 3:
        system("cls");
        strings();
        system("cls");
        break;
      case 4:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
        clearInputBuffer(); // Clear invalid input
        printf("\n");
        displayCenterText("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
        break; 
    }

  } while (chosenOption != dataStructuresMenuSize);
}

void sorting() {
  programHeader("Sorting Algorithms");

  int arrSize = 0;
  int givenArray[ARRAY_MAX_LENGTH];
  int num;
  char ch;
  printf("Initialize your array for me to work on.\n\n");
  printf("Enter elements (space-separated, press Enter to finish):\n");

  while (1) {
      // Read an integer
      if (scanf("%d", &num) == 1) {
          givenArray[arrSize++] = num;
      } else {
          break;
      }

      // Read the next character
      ch = getchar();
      if (ch == '\n') {
          break;
      }
  }
  
  int beforeQueryPos, afterQueryPos;

  char *sortMenu[] = {"Selection Sort", "Bubble Sort", "Insertion Sort", "Count Sort", "Random Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Heap Sort", "Exit"};
  int sortMenuSize = sizeof(sortMenu)/sizeof(sortMenu[0]); 
  int sortType;

  do {
    getCursorPos(&cursorXpos, &cursorYpos);
    beforeQueryPos = cursorYpos;
    printf("\nWhat type of sorting algorithm do you want to do?\n");
    printMenu(sortMenu, sortMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    afterQueryPos = cursorYpos;
    scanf("%d", &sortType);

    if (sortType == sortMenuSize) {
      moveCursor(0, cursorYpos - 1);
      promptExit();
      break;
    }

    if (sortType > 0 && sortType < sortMenuSize) {
      system("cls");
      programHeader("Sorting Algorithms");
      printf("Your Array:\n");
      printArray(givenArray, arrSize);
      sort(givenArray, arrSize, sortType);

      char tryOthers;
      do {
        printf("Do you want to try other sorting algorithms? [Y/N] ");
        getCursorPos(&cursorXpos, &cursorYpos);
        /* The space before %c in the format string is used to skip any leading whitespace characters, including newlines, which ensures that scanf waits for a non-whitespace character. */
        scanf(" %c", &tryOthers);
    
        if (tryOthers != 'n' && tryOthers != 'N' && tryOthers != 'y' && tryOthers != 'Y') {
          clearWord(cursorYpos, strlen("Do you want to try other sorting algorithms? [Y/N] "), SET_WIDTH);
          moveCursor(0, cursorYpos + 3);
          displayCenterText("Invalid answer");
          moveCursor(0, cursorYpos);
        }
      } while (tryOthers != 'n' && tryOthers != 'N' && tryOthers != 'y' && tryOthers != 'Y');
      
      if (tryOthers == 'y' || tryOthers == 'Y') {
        clearLines(cursorYpos + 3, cursorYpos + 3);
        moveCursor(0, cursorYpos);
        continue;
      }
      
      // If the user chose 'n' or 'N', exit the loop
      promptExit();
      break;
    }  else { 
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);

      moveCursor(0, afterQueryPos + 2);
      displayCenterText("Invalid input. Please enter a number.\n");
      moveCursor(0, beforeQueryPos);
    }
  } while (sortType != sortMenuSize);
}
void searching() {
  programHeader("Searching Algorithms");
  int arrSize = 0;
  int givenArray[ARRAY_MAX_LENGTH];
  int num;
  char ch;

  printf("Initialize your array for me to work on.\n\n");
  printf("Enter elements (space-separated, press Enter to finish):\n");

  while (1) {
      // Read an integer
      if (scanf("%d", &num) == 1) {
        givenArray[arrSize++] = num;
      } else {
        break;
      }

      // Read the next character
      ch = getchar();
      if (ch == '\n') {
        break;
      }
  }

  char *searchMenu[] = {"Linear Search", "Binary Search", "Exit"};
  int searchMenuSize = sizeof(searchMenu)/sizeof(searchMenu[0]);
  int searchType;

  printf("\nWhat element is to be find? ");
  int key;
  scanf("%d", &key);

  int beforeQueryPos;

  do {
    getCursorPos(&cursorXpos, &cursorYpos);
    beforeQueryPos = cursorYpos;
    printf("What type of searching algorithm do you want to do?\n");
    printMenu(searchMenu, searchMenuSize);

    getCursorPos(&cursorXpos, &cursorYpos);
    int notePos = cursorYpos + 2;
    moveCursor(0, notePos);
    printf("Note: Binary search will sort the array first and will return a\nposition based from the sorted array.");

    moveCursor(cursorXpos, cursorYpos);
    scanf("%d", &searchType);

    if (searchType == searchMenuSize) {
      moveCursor(0, cursorYpos + 3);
      promptExit();
      break;
    }

    if (searchType > 0 && searchType < searchMenuSize) {
      search(givenArray, arrSize, key, searchType);
      char tryOthers;
      do {
        printf("\n\nDo you want to try the other searching algorithms? [Y/N] ");
        getCursorPos(&cursorXpos, &cursorYpos);
        /* The space before %c in the format string is used to skip any leading whitespace characters, including newlines, which ensures that scanf waits for a non-whitespace character. */
        scanf(" %c", &tryOthers);
    
        if (tryOthers != 'n' && tryOthers != 'N' && tryOthers != 'y' && tryOthers != 'Y') {
          clearWord(cursorYpos, strlen("Do you want to try other sorting algorithms? [Y/N] "), SET_WIDTH);
          moveCursor(0, cursorYpos + 3);
          displayCenterText("Invalid answer");
          moveCursor(0, cursorYpos);
        }
      } while (tryOthers != 'n' && tryOthers != 'N' && tryOthers != 'y' && tryOthers != 'Y');
      
      if (tryOthers == 'y' || tryOthers == 'Y') {

        clearLines(cursorYpos, cursorYpos + 3);
        moveCursor(0, cursorYpos);
        continue;
      }
      
      // If the user chose 'n' or 'N', exit the loop
      promptExit();
      break;
    }  else { 
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);

      moveCursor(0, cursorYpos + 6);
      displayCenterText("Invalid input. Please enter a number.\n");
      moveCursor(0, beforeQueryPos);
    }

  } while (searchType != searchMenuSize);
}
void algorithms() {
  char *algorithmsMenu[] = {"Searching", "Sorting", "Exit"};
  int algoMenuSize = sizeof(algorithmsMenu) / sizeof(algorithmsMenu[0]);

  do {
    programHeader("Algorithms");

    printf("What do you want to learn about?\n");  
    printMenu(algorithmsMenu, algoMenuSize);

    getCursorPos(&cursorXpos, &cursorYpos);
    
    // Moves so that the output is below the input statement
    moveCursor(0, cursorYpos + 2);
    printf("Did you know?\n");
    // Must make a function that prints within the set width
    printf("Algorithms are like the special instructions that help you\nturn a bag of LEGO bricks into an amazing castle!\n");

    // moves the cursor back to the input statement
    moveCursor(cursorXpos, cursorYpos);
    if (scanf("%d", &chosenOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    if (chosenOption == algoMenuSize) {
      moveCursor(0, cursorYpos + 3);
      promptExit();
      break;
    }

      switch (chosenOption) {
        case 1:
          system("cls");
          searching();
          system("cls");
          break;
        case 2:
          system("cls");
          sorting();
          system("cls");
          break;
        case 3:
          system("cls");
          moveCursor(0, SET_HEIGHT / 2 - 1);
          displayCenterText("Exiting Algorithms...");
          hideCursor();
          Sleep(1000);
          break;
        default:
          moveCursor(0, cursorYpos + 6);
          clearInputBuffer(); // Clear invalid input
          displayCenterText("Invalid input. Please enter a number.\n");
          clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
          break; 
      }

  } while (chosenOption != algoMenuSize);
}

void about() {
  char *message[] = {"Analyze. Code. Test. Optimize. Repeat. To fully grasp the concepts of Data Structures and Algorithms, ACTOR serves to demonstrate the procedures included in the course. ACTOR/ACTO Algo is a project in Data Structures and Algorithms during the Academic Year 2024-2025.\n", "Pens and papers is one way of learning; practical implementation is understanding of it\n"};
  int messageSize = sizeof(message)/sizeof(message[0]);

  printWithinWidthCentered(message, messageSize, "About ACTOR");
  
  promptExit();
}



// Array Functions
// Utility functions
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n\n");
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Sort functions
void selectionSort(int array[],  int size) {
  int i, j, min, temp;
  for (i = 0; i < size - 1; i++) {
    min = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&array[i], &array[min]);
    }
  }
}
void bubbleSort (int array[], int size) {
  int i, j, temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}
void insertionSort(int array[], int size) {
  int i,j, temp;
  for (i = 1; i < size; i++) {
    temp = array[i];
    j = i - 1;
    for (j=i-1; j >= 0 && array[j] > temp; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = temp;
  }
}
void countSort(int array[], int size) {
  int max = 0;

  for (int i = 0; i < size; i++)
    if (array[i] > max)
      max = array[i];

  int countArraySize = max + 1; 

  int *countArray = (int *)malloc((countArraySize) * sizeof(int));
  for (int i = 0; i < countArraySize; i++)
    countArray[i] = 0;

  for (int i = 0; i < size; i++)
    countArray[array[i]]++;
  
  for (int i = 1; i < countArraySize; i++)
    countArray[i] += countArray[i - 1];

  int *outputArray = (int *)malloc((size) * sizeof(int));
  for (int i = 0; i < size; i++)
    outputArray[i] = 0;

  for (int i = size - 1; i >= 0; i--) {
    outputArray[countArray[array[i]] - 1] = array[i];
    countArray[array[i]]--;
  }
  
  for (int i = 0; i < size; i++)
    array[i] = outputArray[i];
}
int isArraySorted (int array[], int size) {
  for (int i = 1; i < size; i++) {
    if (array[i] < array [i - 1]){
      return false;
    }
  }
  return true;
}
void shuffle (int array[], int size) {
  int i, randomNumber, temp;
  for (i = 0; i < size; i++) {
    randomNumber = rand() % size;
    swap(&array[i], &array[randomNumber]);
  }
}
void randomSort(int array[], int size) {
  while (!isArraySorted(array, size)) {
    shuffle(array, size);
  }
}
void merge(int array[], int leftIndex, int mid, int rightIndex) {
  int i, j, k;
  int leftArrSize = mid - leftIndex + 1;
  int rightArrSize = rightIndex - mid;

  int *leftArray = (int *)malloc((leftArrSize) * sizeof(int));
  for (i = 0; i < leftArrSize; i++) 
    leftArray[i] = 0;

  int *rightArray = (int *)malloc((rightArrSize) * sizeof(int));
  for (i = 0; i < rightArrSize; i++)
    rightArray[i] = 0;

  for (i = 0; i < leftArrSize; i++)
    leftArray[i] = array[leftIndex + i];
  for (j = 0; j < rightArrSize; j++)
    rightArray[j] = array[mid + 1 + j];

  i = 0;
  j = 0;
  k = leftIndex;

  while (i < leftArrSize && j < rightArrSize) {
    if (leftArray[i] <= rightArray[j])
      array[k] = leftArray[i++];
    else
      array[k] = rightArray[j++];
    k++;
  }

  while (i < leftArrSize) 
    array[k++] = leftArray[i++];

  while (j < rightArrSize)
    array[k++] = rightArray[j++];
}
void mergeSort (int array[], int leftIndex, int rightIndex) {
  if (leftIndex < rightIndex) {
    int mid = (leftIndex + rightIndex) / 2;
    
    mergeSort(array, leftIndex, mid);
    mergeSort(array, mid + 1, rightIndex);

    merge(array, leftIndex, mid, rightIndex);
  }
}
int partitionLomuto(int array[], int first, int last) {
    int pivot = array[last];
    int i = first - 1;
    for (int j = first; j <= last - 1; j++) {
      if (array[j] < pivot) {
        i++;
        swap(&array[i], &array[j]);
      }
    }
    i++;
    swap(&array[i], &array[last]);
    return i;
}
int partitionHoare(int array[], int first, int last) {
    int pivot = array[first];
    int i = first - 1;
    int j = last + 1;
    while (true) {
      do {
        i++;
      } while (array[i] < pivot);
      do {
        j--;
      } while (array[j] > pivot);
      if (i >= j) {
        return j;
      }
      swap(&array[i], &array[j]);
    }
}
void quickSortLomuto(int array[], int first, int last) {
  if (first < last) {
    int partitionIndex = partitionLomuto(array, first, last);
    quickSortLomuto(array, first, partitionIndex - 1);
    quickSortLomuto(array, partitionIndex + 1, last);
  }
}
void quickSortHoare(int array[], int first, int last) {
  if (first < last) {
    int partitionIndex = partitionHoare(array, first, last);
    quickSortHoare(array, first, partitionIndex);
    quickSortHoare(array, partitionIndex + 1, last);
  }
}
void countRadixSort (int array[], int size, int placeValue) {
  int *outputArray = (int *)malloc((size) * sizeof(int));
  for (int i = 0; i < size; i++)
    outputArray[i] = 0;

  int countArray[10] = {0};

  for (int i = 0 ; i < size; i++) 
    countArray[array[i] / placeValue % 10]++;

  for (int i = 1; i < 10; i++)
    countArray[i] += countArray[i - 1];

  for (int i = size - 1; i >= 0; i--)
    outputArray[--countArray[array[i] / placeValue % 10]] = array[i];

  for (int i = 0; i < size; i++)
    array[i] = outputArray[i];
}
void radixSort(int array[], int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  for (int placeValue = 1; max / placeValue > 0; placeValue *= 10)
    countRadixSort(array, size, placeValue);
}
void heapify(int array[], int size, int i) {
  int largest = i; 
  int leftIndex = 2 * i + 1; 
  int rightIndex = 2 * i + 2;

  if (leftIndex < size && array[leftIndex] > array[largest]) 
    largest = leftIndex;

  if (rightIndex < size && array[rightIndex] > array[largest])
    largest = rightIndex;

  if (largest != i) {
    swap(&array[i], &array[largest]);

    heapify(array, size, largest);
  }
}
void heapSort(int array[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(array, size, i);

  for (int i = size - 1; i > 0; i--) {
    swap(&array[0], &array[i]);

    heapify(array, i, 0);
  }
}
void sort(int array[], int size, int sortType) {
  printf("Sorted array using ");

  switch (sortType) {
    case 1:
      printf("Selection Sort:\n");
      selectionSort(array, size);
      break;
    case 2:
      printf("Bubble Sort:\n");
      bubbleSort(array, size);
      break;
    case 3:
      printf("Insertion Sort:\n");
      insertionSort(array, size);
      break;
    case 4:
      printf("Count Sort:\n");
      countSort(array, size);
      break;
    case 5:
      printf("Random Sort:\n");
      randomSort(array, size);
      break;
    case 6:
      printf("Merge Sort:\n");
      mergeSort(array, 0, size - 1);
      break;
    case 7:
      printf("Quick Sort (Lomuto):\n");
      quickSortLomuto(array, 0, size - 1);
      break;
    case 8:
      printf("Radix Sort:\n");
      radixSort(array, size);
      break;
    case 9:
      printf("Heap Sort:\n");
      heapSort(array, size);
      break;
    default:
      clearInputBuffer(); // Clear invalid input
      printf("\n");
      displayCenterText("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
      break;
  }
  printArray(array, size);
}

// Search functions
int binarySearch(int array[], int key, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (key == array[mid])
      return mid;

    // Search the right half
    if (key > array[mid])
      return binarySearch(array, key, mid + 1, high);

    // Search the left half
    return binarySearch(array, key, low, mid - 1);
  }
  return -1;
}
int linearSearch(int array[], int n, int x) {
  
  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}
void search(int array[], int size, int key, int searchType) {
  system("cls");
  if (searchType == 1) {
    programHeader("Linear Search");
    printf("Your Array:\n");
    printArray(array, size);
    int linearResult = linearSearch(array, size, key);
    if (linearResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at index %d", linearResult + 1);
  } else if (searchType == 2) {
    programHeader("Binary Search");
    printf("Your Array:\n");
    printArray(array, size);
    sort (array, size, 9);
    int binaryResult = binarySearch(array, key, 0, size - 1);
    if (binaryResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at position %d", binaryResult + 1);
  }
}

















































