// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()

#define ARRAY_MAX_LENGTH 1000
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
    void graphs();
  void strings();
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
  algorithms();
  
  return 0;
}

// Utility function definitions
void getTerminalSize() {
    /* Function to get the terminal size. */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	terminalWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminalHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  

  printf("terminalWidth: %d \nterminalHeight: %d \n", terminalWidth, terminalHeight);
}
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
  do {
  getCursorPos(&cursorXpos, &cursorYpos);
  moveCursor(0, cursorYpos + 3);
  displayCenterText("Press Enter To Exit");
  hideCursor();
  anyChar = _getch();
  /*On Windows systems, pressing Enter generates a carriage return ('\r'), which is why the comparison is made with '\r'.*/
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
void splitStrings (char *inputStr, char paragraphSubstrings[][SUBSTRINGS_MAX_LENGTH], int *paragraphSubstringsCount, int minCharWidth) {
  int startIndexOffset = 0;

  int phraseToCopy = minCharWidth;

  int numOfCharsLeftBeforeASpace = 0;
  int j = 0, k = 0;

  for (int i = 0; i < strlen(inputStr); i+= minCharWidth) {
    while(startIndexOffset < strlen(inputStr)) {
      while (startIndexOffset + phraseToCopy + j < strlen(inputStr) && inputStr[startIndexOffset + phraseToCopy + j] != ' ') {
        numOfCharsLeftBeforeASpace++;
        j++;
      }
      phraseToCopy += numOfCharsLeftBeforeASpace;

      if (inputStr[startIndexOffset + k ] == '\t' && startIndexOffset != 0)
        phraseToCopy -= 8;
      if (inputStr[startIndexOffset] == ' ' && startIndexOffset != 0)
        k++;

      strncpy(paragraphSubstrings[*paragraphSubstringsCount], inputStr + startIndexOffset + k, phraseToCopy);

      paragraphSubstrings[*paragraphSubstringsCount][phraseToCopy + numOfCharsLeftBeforeASpace] = '\0';

      startIndexOffset += phraseToCopy;
      
      (*paragraphSubstringsCount)++;

      phraseToCopy = minCharWidth;
      j = 0, k = 0;
      numOfCharsLeftBeforeASpace = 0;

    }
  }
}
void printWithinWidth(char *message[], int messageSize, char *header) {
  char paragraphSubstrings[SUBSTRINGS_MAX_SUBSTRINGS][SUBSTRINGS_MAX_LENGTH];
  int paragraphSubstringsCount = 0;

  int lineWidth = SET_WIDTH * 0.7; 
  int phraseToCopy = lineWidth;

  for (int i = 0; i < messageSize; i++) {
    splitStrings(message[i], paragraphSubstrings, &paragraphSubstringsCount, lineWidth);
  }

  programHeader(header);
  printf("\n");

  for (int i = 0; i < paragraphSubstringsCount; i++) {
    displayCenterText(paragraphSubstrings[i]);
    printf("\n");
  }
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

void sorting() {
  system("cls");
  programHeader("Sorting Algorithms");

  int arrSize = 0;
  int givenArray[ARRAY_MAX_LENGTH];
  int num;
  char ch;

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

  char *sortMenu[] = {"Selection Sort", "Bubble Sort", "Insertion Sort", "Count Sort", "Random Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Heap Sort"};
  int sortMenuSize = sizeof(sortMenu)/sizeof(sortMenu[0]); 

  printf("\nWhat type of sorting algorithm do you want to do?\n");
  printMenu(sortMenu, sortMenuSize);
  int sortType;
  scanf("%d", &sortType);

  system("cls");
  programHeader("Sorting Algorithms");
  printf("Your Array:\n");
  printArray(givenArray, arrSize);
  sort (givenArray, arrSize, sortType);

  printf("\n\n");

  displayCenterText("Press Any Key To Exit");
  hideCursor();
  anyChar = _getch();
}
void searching() {
  system("cls");
  programHeader("Searching Algorithms");
  int arrSize = 0;
  int givenArray[ARRAY_MAX_LENGTH];
  int num;
  char ch;

  // Prompt the user to enter elements
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

  printf("\nWhat element is to be find? ");
  int key;
  scanf("%d", &key);

  char *searchMenu[] = {"Linear Search", "Binary Search"};
  int searchMenuSize = sizeof(searchMenu)/sizeof(searchMenu[0]);

  printf("What type of searching algorithm do you want to do?\n");
  printMenu(searchMenu, searchMenuSize);

  int cursorXpos, cursorYpos;
  getCursorPos(&cursorXpos, &cursorYpos);
  int searchType;

  moveCursor(0, cursorYpos + 2);
  printf("Note: Binary search will sort the array first and will return a\nposition based from the sorted array.");
  
  moveCursor(cursorXpos,cursorYpos);
  scanf("%d", &searchType);
  system("cls");

  search(givenArray, arrSize, key, searchType);

  printf("\n\n");

  displayCenterText("Press Any Key To Exit");
  hideCursor();
  anyChar = _getch();
}
void algorithms() {
  system("cls");
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
    printf("Algorithms are like the special instructions that help you turn a bag of LEGO bricks into an amazing castle!\n");

    // moves the cursor back to the input statement
    moveCursor(cursorXpos, cursorYpos);
    scanf("%d", &chosenOption);

    if (chosenOption > 0 && chosenOption <= algoMenuSize) {
      switch (chosenOption) {
        case 1:
          searching();
          break;
        case 2:
          sorting();
          break;
        case 3:
          system("cls");
          moveCursor(0, SET_HEIGHT / 2 - 1);
          displayCenterText("Exiting Algorithms...");
          hideCursor();
          Sleep(1000);
          break;
        default:
          break; 
      }

    } else { 
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);

      // Move from +2 to +5 to accommodate the trivia
      moveCursor(0, cursorYpos + 5);

      displayCenterText("Invalid Choice");
      printf("\n");
      displayCenterText("Please pick a number from the given options only");
      printf("\n");
    }

  } while (chosenOption != algoMenuSize);

  system("cls");
}

void about() {
  system("cls");
  char *message[] = {"Analyze. Code. Test. Optimize. Repeat. To fully grasp the concepts of Data Structures and Algorithms, ACTOR serves to demonstrate the procedures included in the course. ACTOR/ACTO Algo is a project in Data Structures and Algorithms during the Academic Year 2024-2025.\n", "Pens and papers is one way of learning; practical implementation is understanding of it\n"};
  int messageSize = sizeof(message)/sizeof(message[0]);

  printWithinWidth(message, messageSize, "About ACTOR");
  
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
      printf("Invalid choice\n");
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

















































