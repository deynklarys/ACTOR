// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h> // for _getch()

#define ARRAY_MAX_LENGTH 1000
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500


int setWidth = 80;
int setHeight = 24;
int anyChar;

void printArray(int array[], int size);
void swap(int *a, int *b);

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);

bool isArraySorted(int array[], int size);
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

void initializeArray() {
  while (1) {
    int arrSize;
    int givenArray[ARRAY_MAX_LENGTH];
    char *arrayString[ARRAY_MAX_LENGTH];
    programHeader("Array Initialization");
    printf("Enter your elements in the array separated by a single space:\n\t");
    scanf("%s", &arrayString);
    int i = 0, j = 0;
    while (arrayString[i] != '\n') {
      if (arrayString[i] != ' ') {
        givenArray[j++] = (int *) arrayString[i++];
      } else {
        i++;
        continue;
      }

    }

    

  }
}

void sorting() {
  system("cls");
  programHeader("Sorting Algorithms");
  int arrSize;
  int givenArray[ARRAY_MAX_LENGTH];
  printf("Enter array size: ");
  scanf("%d", &arrSize);
  printf("Enter your elements in the array:\n");
  for (int i = 0; i < arrSize; i++) {
    printf("\tarray[%d]: ", i);
    scanf("%d", &givenArray[i]);
  }

  system("cls");

  printf("Given array: ");
  for (int i = 0; i < arrSize; i++) {
    printf("%d ", givenArray[i]);
  }
  printf("\n");

  char *sortMenu[] = {"Selection Sort", "Bubble Sort", "Insertion Sort", "Count Sort", "Random Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Heap Sort"};
  int sortMenuSize = sizeof(sortMenu)/sizeof(sortMenu[0]); 

  printf("What type of sorting algorithm do you want to do?\n");
  printMenu(sortMenu, sortMenuSize);
  int sortType;
  scanf("%d", &sortType);

  system("cls");
  sort (givenArray, arrSize, sortType);

  printf("\n\n");

  displayCenterText("Press Any Key To Exit");
  hideCursor();
  anyChar = _getch();
}

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
    int linearResult = linearSearch(array, size, key);
    if (linearResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at index %d", linearResult + 1);
  } else if (searchType == 2) {
    sort (array, size, 9);
    int binaryResult = binarySearch(array, key, 0, size - 1);
    if (binaryResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at position %d", binaryResult + 1);
  }
}
void searching() {
  system("cls");
  programHeader("Searching Algorithms");
  int arrSize;
  int givenArray[ARRAY_MAX_LENGTH];
  printf("Enter array size: ");
  scanf("%d", &arrSize);
  printf("Enter your elements in the array:\n");
  for (int i = 0; i < arrSize; i++) {
    printf("\tarray[%d]: ", i);
    scanf("%d", &givenArray[i]);
  }

  system("cls");

  printf("Given array: ");
  for (int i = 0; i < arrSize; i++) {
    printf("%d ", givenArray[i]);
  }
  printf("\n");

  printf("What element is to be find? ");
  int key;
  scanf("%d", &key);

  char *searchMenu[] = {"Linear Search", "Binary Search"};
  int searchMenuSize = sizeof(searchMenu)/sizeof(searchMenu[0]); 

  printf("What type of searching algorithm do you want to do?\n");
  printMenu(searchMenu, searchMenuSize);
  int searchType;
  scanf("%d", &searchType);

  system("cls");
  search(givenArray, arrSize, key, searchType);

  printf("\n\n");

  displayCenterText("Press Any Key To Exit");
  hideCursor();
  anyChar = _getch();
}


int main () {
  system("cls");
  char *algorithmsMenu[] = {"Searching", "Sorting", "Exit", "Quit"};
  int algoMenuSize = sizeof(algorithmsMenu) / sizeof(algorithmsMenu[0]);
  int chosenOption;

  do {
    system("cls");

    programHeader("Algorithms");
    printMenu(algorithmsMenu, algoMenuSize);

    int cursorXpos, cursorYpos;
    getCursorPos(&cursorXpos, &cursorYpos);
    scanf("%d", &chosenOption);

    if (chosenOption > 0 && chosenOption <= algoMenuSize) {
      switch (chosenOption) {
        case 1:
          /*system("cls");
          programHeader("Searching Algorithms");
          printf("\n\nFunction is not yet done...\n\n");
          displayCenterText("Press Any Key To Exit");
          anyChar = _getch();*/
          searching();
          break;
        case 2:
          /* system("cls");
          programHeader("Sorting Algorithms");
          printf("\n\nFunction is not yet done...\n\n");
          displayCenterText("Press Any Key To Exit");
          anyChar = _getch(); */
          sorting();
          break;
        case 3:
          system("cls");
          moveCursor(0, setHeight / 2 - 1);
          displayCenterText("Exiting Algorithms...");
          hideCursor();
          Sleep(1000);
          break;
        case 4: 
          system("cls");
          moveCursor(0, setHeight / 2 - 1);
          displayCenterText("Quitting Algorithms...");
          hideCursor();
          Sleep(1000);
          return 0;
          break;
        default:
          break; 
      }

    } else { 
      clearWord(cursorYpos, strlen("Choose a number: "), setWidth);

      moveCursor(0, cursorYpos + 2);

      displayCenterText("Invalid Choice");
      printf("\n");
      displayCenterText("Please pick a number from the given options only");
      printf("\n");
    }

    
  } while (chosenOption != algoMenuSize ); 





  return 0;
}
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
      temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }
}
void bubbleSort (int array[], int size) {
  int i, j, temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
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

bool isArraySorted (int array[], int size) {
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
    temp = array[i];
    array[i] = array[randomNumber];
    array[randomNumber] = temp;
  }
}
void randomSort(int array[], int size) {
  while (!isArraySorted(array, size)) {
    shuffle(array, size);
  }
}

// Merge sort has another algorithm that is probably more efficient, which uses only one temporary array and takes five parameters in the merge function. It as well requires a base case to stop the recursion. Other algorithm will be added in the future.
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
    int temp = array[0]; 
    array[0] = array[i];
    array[i] = temp;

    heapify(array, i, 0);
  }
}

void sort(int array[], int size, int sortType) {
  printf("Given Array:\n");
  printArray(array, size);

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