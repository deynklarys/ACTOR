// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "utility.h"

// cd "c:\Academic-related_Programs\ACTOR\" ; if ($?) { gcc ACTOR.c -o ACTOR utility.c } ; if ($?) { .\ACTOR}

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
      #define ARRAY_MAX_LENGTH 50
      #define INS 3
      #define DEL 4
      typedef struct {
        int dataType;
        union {
          int intArray[ARRAY_MAX_LENGTH];
          char charArray[ARRAY_MAX_LENGTH];
          char *strArray[ARRAY_MAX_LENGTH];
        } data;
        int size;
      } Array;
      typedef struct {
        union {
          int intKey;
          char charKey;
          char strKey[STRING_MAX_LENGTH];
        } dataKey;
      } Key;
      void traverseArray(Array *array);
      int linearSearchArray(Array array, Key *key);
      void searchArray(Array *array, Key *key);
      void insertArray(Array *array, Key *key);
      void deleteArray(Array *array);
      void mergeArray(Array *array1);
      void sortArray(Array *array);
      void insertArrayKey(Array *array, Key *key, int position);
      void deleteArrayKey(Array *array, int position);
      void mergeTwoArrays(Array *array1, Array *array2);
      void bubbleSortArray(Array *array);
      int initializeArray(Array *array);
      void printArrayPositions(Array *array, int operation);
    void linkedLists();
      void *data;
      int *positionPtr;
      typedef struct ListNode {
        void *data;
        struct ListNode *next;
      } ListNode;
      typedef struct {
        ListNode *head;
        size_t dataSize;
        void (*printFunc)(void *);
        int listDataType;
        int listSize;
      } List;
      typedef struct {
        List list;
        int chosenDataType;
      } ListResult;
      void traverseList(List *list);
      void searchList(List *list);
        int compareData(void *data1, void *data2, int dataType);
      void insertList(List *list);
        void insertAtBeginning(List *list);
        void insertAtIndex(List *list, int index);
        void insertAtEnd(List *list);
      void deleteList(List *list);
        void deleteFromBeginning(List *list);
        void deleteFromIndex(List *list, int index);
        void deleteFromEnd(List *list);
      void mergeLists(List *list);
        void mergeTwoLists(List *list1, List *list2);
      void sortList(List *list);
      ListResult initializeLists ();
    void stacks();
      #define STACK_MAX_SIZE 50
      typedef struct StackNode {
        void *data;
        struct StackNode *next;
      } StackNode;
      typedef struct {
        StackNode *top;
        size_t dataSize;
        void (*printFunc)(void *);
        DataType stackDataType;
        int stackSize;
      } Stack;
      typedef struct {
        Stack stack;
        int chosenDataType;
      } StackResult;
      void printStack(Stack *stack);
      void pushStack(Stack *stack);
      void popStack(Stack *stack);
      void peekStack(Stack *stack);
      void isFullStack(Stack *stack);
      void isEmptyStack(Stack *stack);
      StackResult initializeStacks();
    void queues();
      #define QUEUE_MAX_SIZE 50
      typedef struct QueueNode {
        void *data;
        struct QueueNode *next;
      } QueueNode;
      typedef struct {
        QueueNode *front;
        QueueNode *rear;
        size_t dataSize;
        void (*printFunc)(void *);
        DataType queueDataType;
        int queueSize;
      } Queue;
      typedef struct {
        Queue queue;
        int chosenDataType;
      } QueueResult;
      QueueResult initializeQueue();
      void printQueue(Queue *queue);
      void push(Queue *queue);
      void pop(Queue *queue);
      void peek(Queue *queue);
      void isFull(Queue *queue);
      void isEmpty(Queue *queue);
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

  int mainOption;
  do {
    programHeader("Data Structures and Algorithms");

    printf("What do you want to learn about?\n");
    printMenu(mainMenu, mainMenuSize);
    /* Get the current position of the cursor after the prompt. This coordinate will be used to bring back the cursor at this position when the user inputs an invalid option and the option that they typed is cleared. */
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &mainOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("\n");
      displayCenterText("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, strlen("Choose a number: "), SET_WIDTH);
      continue;
    }

      switch (mainOption) {
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

  } while (mainOption != mainMenuSize);             
                   
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
  programHeader("Arrays");

  Array array;
  Key key;

  system("cls");
  while (1) {

    if (!initializeArray(&array)) {
      system("cls");
      return;
    }

    char *arraysMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two arrays", "Exit"};
    int arraysMenuSize = sizeof(arraysMenu) / sizeof(arraysMenu[0]);
    int chosenOption;

    system("cls");
    do {
      programHeader("Array Operations");
      printMenu(arraysMenu, arraysMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &chosenOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer(); // Clear invalid input
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 2);
      
      switch (chosenOption) {
        case 1:
          traverseArray(&array);
          break;
        case 2:
          system("cls");
          searchArray(&array, &key);
          promptExit();
          system("cls");
          break;
        case 3:
          system("cls");
          insertArray(&array, &key);
          promptExit();
          system("cls");
          break;
        case 4:
          system("cls");
          deleteArray(&array);
          promptExit();
          system("cls");
          break;
        case 5:
          system("cls");
          sortArray(&array);
          promptExit();
          system("cls");
          break;
        case 6:
          system("cls");
          mergeArray(&array);
          promptExit();
          system("cls");
          break;
        case 7:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (chosenOption != arraysMenuSize);
    
    system("cls");
  }
}
  void traverseArray(Array *array) {
    printf("Your array elements:  ");
    for (int i = 0; i < array->size; i++) {
      switch (array->dataType) {
        case INTEGER:
          printf("%d ", array->data.intArray[i]);
          break;
        case CHARACTER:
          printf("%c ", array->data.charArray[i]);
          break;
        case STRING:
          printf("%s ", array->data.strArray[i]);
          break;
        default:
          printf("Unknown data type.\n");
          return;
      }
    }
    printf("\n");
  }
  int linearSearchArray(Array array, Key *key) {
    switch (array.dataType) {
      case INTEGER:
        for (int i = 0; i < array.size; i++) {
          if (array.data.intArray[i] == key->dataKey.intKey) {
            return i;
          }
        }
        return -1;
      case CHARACTER:
        for (int i = 0; i < array.size; i++) {
          if (array.data.charArray[i] == key->dataKey.charKey) {
            return i;
          }
        }
        return -1;
      case STRING:
        for (int i = 0; i < array.size; i++) {
          if (strcmp(array.data.strArray[i], key->dataKey.strKey) == 0) {
            return i;
          }
        }
        return -1;
      default:
        printf("Unknown data type.\n");
        return -1;
    }
  }
  void searchArray(Array *array, Key *key) {
    programHeader("Search in an Array");
    traverseArray(array);
    printf("\n\n");

    // do while loop to check if the user wants to search another element

    int result;
    switch (array->dataType) {
      case INTEGER:
        printf("Enter the number to search: ");
        scanf("%d", &key->dataKey.intKey);
        result = linearSearchArray(*array, key);
        break;
      case CHARACTER:
        printf("Enter the character to search: ");
        scanf(" %c", &key->dataKey.charKey);
        result = linearSearchArray(*array, key);
        break;
      case STRING:
        printf("Enter the string to search: ");
        scanf("%s", key->dataKey.strKey);
        result = linearSearchArray(*array, key);
        break;
      default:
        printf("Unknown data type.\n");
        return;
    }

    if (result == -1) {
      printf("Element not found.\n");
    } else {
      printf("Element found at position %d.\n", result + 1);
    }
  }
  void insertArrayKey(Array *array, Key *key, int position) {
    if (position < 0 || position > array->size || array->size >= ARRAY_MAX_LENGTH) {
      printf("Invalid position or array is full.\n");
      return;
    }

    switch (array->dataType) {
      case INTEGER:
        for (int i = array->size; i > position; i--) {
          array->data.intArray[i] = array->data.intArray[i - 1];
        }
        array->data.intArray[position] = key->dataKey.intKey;
        array->size++;
        break;
      case CHARACTER:
        for (int i = array->size; i > position; i--) {
          array->data.charArray[i] = array->data.charArray[i - 1];
        }
        array->data.charArray[position] = key->dataKey.charKey;
        array->size++;
        break;
      case STRING:
        for (int i = array->size; i > position; i--) {
          array->data.strArray[i] = array->data.strArray[i - 1];
        }
        array->data.strArray[position] = malloc(strlen(key->dataKey.strKey) + 1);
        if (array->data.strArray[position] != NULL) {
          strcpy(array->data.strArray[position], key->dataKey.strKey);
          array->size++;
        } else {
          printf("Memory allocation failed.\n");
        }
        break;
      default:
        printf("Unknown data type.\n");
        return;
    }
  }
  void insertArray(Array *array, Key *key) {
    programHeader("Insert in an Array");
    traverseArray(array);
    printArrayPositions(array, INS);

    // do while loop to check if the user wants to insert another element

    switch (array->dataType){
      int position;
      case INTEGER:
        printf("Enter the number to insert: ");
        scanf("%d", &key->dataKey.intKey);
        printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
        scanf("%d", &position);
        insertArrayKey(array, key, position - 1);
        break;
      case CHARACTER:
        printf("Enter the character to insert: ");
        scanf(" %c", &key->dataKey.charKey);
        printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
        scanf("%d", &position);
        insertArrayKey(array, key, position - 1);
        break;
      case STRING:
        printf("Enter the string to insert: ");
        scanf("%s", key->dataKey.strKey);
        printf("Enter the position of the element to insert from 1 to %d? ", array->size + 1);
        scanf("%d", &position);
        insertArrayKey(array, key, position - 1);
        break;
    }
    traverseArray(array);

  }
  void deleteArrayKey(Array *array, int position) {
    if (position < 0 || position >= array->size) {
      printf("Invalid position.\n");
      return;
    }

    switch (array->dataType) {
      case INTEGER:
        for (int i = position; i < array->size - 1; i++) {
          array->data.intArray[i] = array->data.intArray[i + 1];
        }
        array->size--;
        break;
      case CHARACTER:
        for (int i = position; i < array->size - 1; i++) {
          array->data.charArray[i] = array->data.charArray[i + 1];
        }
        array->size--;
        break;
      case STRING:
        free(array->data.strArray[position]);
        for (int i = position; i < array->size - 1; i++) {
            array->data.strArray[i] = array->data.strArray[i + 1];
        }
        array->size--;
        break;
      default:
        printf("Unknown data type.\n");
        return;
    }
  }
  void deleteArray(Array *array) {
    programHeader("Delete from an Array");
    traverseArray(array);
    printArrayPositions(array, DEL);

    int position;
    printf("Enter the position of the element to delete from 1 to %d: ", array->size);
    scanf("%d", &position);
    deleteArrayKey(array, position - 1);
    traverseArray(array);
  }
  void mergeTwoArrays(Array *array1, Array *array2) {
    if (array1->dataType != array2->dataType) {
      printf("Arrays have different data types and cannot be merged.\n");
      return;
    }

    if (array1->size + array2->size > ARRAY_MAX_LENGTH) {
      printf("Merged array exceeds maximum length.\n");
      return;
    }

    switch (array1->dataType) {
      case INTEGER:
        for (int i = 0; i < array2->size; i++) {
          array1->data.intArray[array1->size++] = array2->data.intArray[i];
        }
        break;
      case CHARACTER:
        for (int i = 0; i < array2->size; i++) {
          array1->data.charArray[array1->size++] = array2->data.charArray[i];
        }
        break;
      case STRING:
        for (int i = 0; i < array2->size; i++) {
          array1->data.strArray[array1->size] = malloc(strlen(array2->data.strArray[i]) + 1);
          if (array1->data.strArray[array1->size] != NULL) {
            strcpy(array1->data.strArray[array1->size], array2->data.strArray[i]);
            array1->size++;
          } else {
            printf("Memory allocation failed.\n");
            return;
          }
        }
        break;
      default:
        printf("Unknown data type.\n");
        return;
    }

    printf("\nArrays merged successfully\n");
    traverseArray(array1);
  }
  void mergeArray(Array *array1) {
    programHeader("Merge Two Arrays");
    traverseArray(array1);

    Array array2;
    array2.dataType = array1->dataType;
    array2.size = 0;

    printf("Initialize your second array to work on.\n\n");
    printf("Enter elements (space-separated, press Enter to finish):\n");

    int num;
    char ch;
    char str[50];

    switch (array2.dataType) {
      case INTEGER: 
        do {
          if (scanf("%d", &num) == 1) {
            array2.data.intArray[array2.size++] = num;
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
        break;
      case CHARACTER:
        do {
          if (scanf(" %c", &ch) == 1) {
            array2.data.charArray[array2.size++] = ch;
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
        break;
      case STRING:
        do {
          if (scanf("%s", str) == 1) {
            array2.data.strArray[array2.size] = malloc(strlen(str) + 1); // Allocate memory for the string
            if (array2.data.strArray[array2.size] != NULL) {
              strcpy(array2.data.strArray[array2.size], str); // Copy the string
              array2.size++;
            } else {
              printf("Memory allocation failed.\n");
              break;
            }
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array2.size < ARRAY_MAX_LENGTH);
        break;
    }  
    mergeTwoArrays(array1, &array2);
  }
  void bubbleSortArray (Array *array) {
    switch (array->dataType) {
    case INTEGER:
      for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
          if (array->data.intArray[j] > array->data.intArray[j + 1]) {
            int temp = array->data.intArray[j];
            array->data.intArray[j] = array->data.intArray[j + 1];
            array->data.intArray[j + 1] = temp;
          }
        }
      }
      break;
    case CHARACTER:
      for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
          if (array->data.charArray[j] > array->data.charArray[j + 1]) {
            char temp = array->data.charArray[j];
            array->data.charArray[j] = array->data.charArray[j + 1];
            array->data.charArray[j + 1] = temp;
          }
        }
      }
      break;
    case STRING:
      for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
          if (strcmp(array->data.strArray[j], array->data.strArray[j + 1]) > 0) {
            char *temp = array->data.strArray[j];
            array->data.strArray[j] = array->data.strArray[j + 1];
            array->data.strArray[j + 1] = temp;
          }
        }
      }
      break;
    default:
      printf("Unknown data type.\n");
      return;
    }
    printf("Array sorted successfully.\n");
    traverseArray(array);

  }
  void sortArray(Array *array) {
    char *message[] = {"Numbers will be sorted in ascending order. Letters and words will be sorted in alphabetical order. Bubble sorting algorithm will be used in this operation. To learn more about other sorting algorithms, go to Algorithms > Sorting." };
    int messageSize = sizeof(message)/sizeof(message[0]);
    printWithinWidth(message, messageSize, "Sort an Array");

    printf("\nArray before sorting:\n");
    traverseArray(array);
    printf("\n");
    bubbleSortArray(array);
  }
  int initializeArray (Array *array) {
    char *message[] = {"Arrays are a collection of elements of the same types of  data.", "Examples:",
    "\t1, 2, 3, 4, 5 is an array of integers or numbers",
    "\ta, b, c, d, e is an array of characters or letters",
    "\tapple, banana, mango, orange is an array of strings or words",
    "Each number, letter, or word in an array is called an element."};
    int messageSize = sizeof(message)/sizeof(message[0]);

    printWithinWidth(message, messageSize, "Arrays");

    array->dataType = chooseDataType("array");
    if (array->dataType == -1) {
      return 0; 
    }
    array->size = 0;

    printf("Initialize your array to work on.\n\n");
    printf("Enter elements (space-separated, press Enter to finish):\n");

    int num;
    char ch;
    char str[50];

    switch (array->dataType) {
      case INTEGER: 
        do {
          if (scanf("%d", &num) == 1) {
            array->data.intArray[array->size++] = num;
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
        break;
      case CHARACTER:
        do {
          if (scanf(" %c", &ch) == 1) {
            array->data.charArray[array->size++] = ch;
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
        break;
      case STRING:
        do {
          if (scanf("%s", str) == 1) {
            array->data.strArray[array->size] = malloc(strlen(str) + 1); // Allocate memory for the string
            if (array->data.strArray[array->size] != NULL) {
              strcpy(array->data.strArray[array->size], str); // Copy the string
              array->size++;
            } else {
              printf("Memory allocation failed.\n");
              break;
            }
          } else {
            clearInputBuffer(); // Clear invalid input
            break;
          }
        } while (getchar() != '\n' && array->size < ARRAY_MAX_LENGTH);
        break;
    }
  }
  void printArrayPositions(Array *array, int operation) {
    printf("Position of elements: ");
    switch (operation) {
      case INS:
        switch (array->dataType) {
          case INTEGER:
            for (int i = 0; i < array->size + 1; i++) {
              char intStr[10];
              int intLength = 0;
              if (i == array->size) {
                intLength = 3;
              } else {
                sprintf(intStr, "%d", array->data.intArray[i] + 1);
                intLength = strlen(intStr);
              }
              int mid = intLength / 2;
              mid = intLength % 2 == 0 ? mid : mid + 1;
              for (int j = 1; j <= intLength; j++) {
                j == mid ? printf("%d", i + 1) : printf(" ");
              }
              printf(" ");
            }
            break;
          case CHARACTER:
            for (int i = 0; i < array->size + 1; i++) {
              printf("%d ", i + 1);
            }
            break;
          case STRING:
            for (int i = 0; i < array->size + 1; i++) {
              int strLength = strlen(array->data.strArray[i]);
              if (i == array->size) {
                strLength = 5;
              }
              int mid = strLength / 2;
              mid = strLength % 2 == 0 ? mid : mid + 1;
              for (int j = 1; j <= strLength; j++) {
                j == mid ? printf("%d", i + 1) : printf(" ");
              }
              printf(" ");
            }
            break;
          default:
            printf("Unknown data type.\n");
        }
        break;
      case DEL:
        switch (array->dataType) {
          case INTEGER:
            for (int i = 0; i < array->size; i++) {
              char intStr[10];
              sprintf(intStr, "%d", array->data.intArray[i] + 1);
              int intLength = strlen(intStr);
              int mid = intLength / 2;
              mid = intLength % 2 == 0 ? mid : mid + 1;
              for (int j = 1; j <= intLength; j++) {
                j == mid ? printf("%d", i + 1) : printf(" ");
              }
              printf(" ");
            }
            break;
          case CHARACTER:
            for (int i = 0; i < array->size; i++) {
              printf("%d ", i + 1);
            }
            break;
          case STRING:
            for (int i = 0; i < array->size; i++) {
              int strLength = strlen(array->data.strArray[i]);
              int mid = strLength / 2;
              mid = strLength % 2 == 0 ? mid : mid + 1;
              for (int j = 1; j <= strLength; j++) {
                j == mid ? printf("%d", i + 1) : printf(" ");
              }
              printf(" ");
            }
            break;
          default:
            printf("Unknown data type.\n");
        }
        break;
    }
    printf("\n\n");
  }
void linkedLists () {
  programHeader("Linked Lists");

  List list;
  
  system("cls");
  while (1) {
    ListResult listResult = initializeLists();
    list = listResult.list;
    list.listDataType = listResult.chosenDataType;
    if (listResult.chosenDataType == -1) {
      system("cls");
      return;
    }

    char *listMenu[] = {
      "Traverse", 
      "Search", 
      "Insert", 
      "Delete", 
      "Sort", 
      "Merge two lists", 
      "Exit"};
    int listMenuSize = sizeof(listMenu) / sizeof(listMenu[0]);

    system("cls");
    int listMenuOption;
    do {
      programHeader("Linked List Operations");
      printDataType("list", list.listDataType);
      printMenu(listMenu, listMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &listMenuOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      switch (listMenuOption) {
        case 1:
          traverseList(&list);
          break;
        case 2:
          searchList(&list); 
          break;
        case 3:
          system("cls");
          insertList(&list);
          system("cls");
          break;
        case 4:
          system("cls");
          deleteList(&list);
          system("cls");
          break;
        case 5:
          system("cls");
          programHeader("Sort");
          printf("Original list: ");
          traverseList(&list);
          sortList(&list);
          printf("Sorted list: ");
          traverseList(&list);
          promptExit();
          system("cls");
          break;
        case 6:
          system("cls");
          programHeader("Merge Two Lists");
          mergeLists(&list);
          promptExit();
          system("cls");
          break;
        case 7:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (listMenuOption != listMenuSize);

    system("cls");
  }
}
  void traverseList(List *list) {
    ListNode *current = list->head;

    if (current == NULL) {
      printf("List is empty.\n");
      return;
    }

    printf("\nHEAD -> ");
    while (current != NULL) {
      list->printFunc(current->data);
      current = current->next;
      printf("->");
    }
    printf("NULL\n");
  }
  int compareData(void *data1, void *data2, int dataType) {
    switch (dataType) {
      case INTEGER:
        return (*(int *)data1 == *(int *)data2);
      case CHARACTER:
        return (*(char *)data1 == *(char *)data2);
      case STRING:
        return (strcmp((char *)data1, (char *)data2) == 0);
      default:
        return 0;
    }
  }
  void searchList(List *list) {
    if (list->head == NULL) {
      printf("List is empty.\n");
      return;
    }

    data = scanData("Enter data to search: ", list->listDataType);
    if (data == NULL) {
      return;
    }

    ListNode *tempNode = list->head;
    int currIndex = 0;

    while (tempNode != NULL) {
      if (compareData(tempNode->data, data, list->listDataType)) {
        printf("Data found at position %d\n", currIndex + 1);

        return;
      } 
      
      tempNode = tempNode->next;
      currIndex++;
    }
    printf("Data not found.\n");
    free(data);
  }
  void insertList(List *list) {
    char *insertMenu[] = {
      "Insert at the beginning",
      "Insert at a position",
      "Insert at the end",
      "Exit"};
    int insertMenuSize = sizeof(insertMenu) / sizeof(insertMenu[0]);
    int insertOption;

    do {
      programHeader("Insert in a Linked List");
      printMenu(insertMenu, insertMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &insertOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      if (insertOption > 0 && insertOption < insertMenuSize) {
        data = scanData("Enter data to insert: ", list->listDataType);
      }
      
      switch (insertOption) {
        case 1:
          system("cls");
          programHeader("Insert at the Beginning");
          insertAtBeginning(list);
          traverseList(list);
          promptExit();
          system("cls");
          break;
        case 2:
          positionPtr = (int *)scanData("Enter the position to insert: ", INTEGER);
          int position = *positionPtr;
          system("cls");
          programHeader("Insert at an Index");
          insertAtIndex(list, position - 1);
          traverseList(list);
          promptExit();
          system("cls");
          break;
        case 3:
          system("cls");
          programHeader("Insert at the end");
          insertAtEnd(list);
          traverseList(list);
          promptExit();
          system("cls");
          break;
        case 4:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
          break;
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (insertOption != insertMenuSize);
    system("cls");
  }
  ListNode* createNode(size_t dataSize) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    if (dataSize == sizeof(char *)) {
      newNode->data = malloc(strlen((char *)data) + 1);
      strcpy((char *)newNode->data, (char *)data);
    } else {
      newNode->data = malloc(dataSize);
      if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(newNode);
        exit(EXIT_FAILURE);
      }
      memcpy(newNode->data, data, dataSize);
    }
    newNode->next = NULL;
    return newNode;
  }
  void insertAtBeginning(List *list) {
    ListNode *newNode = createNode(list->dataSize);
    newNode->next = list->head;
    list->head = newNode;
    list->listSize++;
  }
  void insertAtIndex(List *list, int index) {
    if (index > list->listSize) {
      printf("Index out of bounds.\n");
      return;
    }

    if (index == 0) {
      insertAtBeginning(list);
      return;
    }

    ListNode *prevNode = NULL;
    ListNode *currNode = list->head;
    int currIndex = 0;

    while (currIndex < index) {
      prevNode = currNode;
      currNode = currNode->next;
      currIndex++;
    }

    ListNode *newNode = createNode(list->dataSize);
    newNode->next = currNode;
    prevNode->next = newNode;

    list->listSize++;
  }
  void insertAtEnd(List *list) {
    ListNode *newNode = createNode(list->dataSize);
    if (list->head == NULL) {
      list->head = newNode;
    } else {
      ListNode *current = list->head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = newNode;
    }
    list->listSize++;
  }
  void deleteList(List *list) {
    char *deleteMenu[] = {
      "Delete at the beginning", 
      "Delete at an index", 
      "Delete at the end", 
      "Exit"};
    int deleteMenuSize = sizeof(deleteMenu) / sizeof(deleteMenu[0]);
    int deleteOption;


    do {
      programHeader("Delete From a Linked List");
      printMenu(deleteMenu, deleteMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &deleteOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 2);

      switch (deleteOption) {
        case 1:
          system("cls");
          programHeader("Delete at the Beginning");
          printf("Previous list: ");
          traverseList(list);
          deleteFromBeginning(list);
          printf("New list: ");
          traverseList(list);
          promptExit();
          system("cls");
          break;
        case 2:
          positionPtr = (int *)scanData("Enter the position to delete: ", INTEGER);
          int position = *positionPtr;
          system("cls");
          programHeader("Delete at an Index");
          printf("Previous list: ");
          traverseList(list);
          deleteFromIndex(list, position - 1);
          printf("New list: ");
          traverseList(list);
          promptExit();
          system("cls");
          break; 
        case 3:
          system("cls");
          programHeader("Delete at the End");
          printf("Previous list: ");
          traverseList(list);
          deleteFromEnd(list);
          printf("New list: ");
          traverseList(list);
          promptExit();
          system("cls");
          break;
        case 4:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
          break;
        }
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (deleteOption != deleteMenuSize);
    system("cls");
  }
  // All delete subfunctions can be implemented into only one function using delete from an index
  void deleteFromBeginning(List *list) {
    if (list->head == NULL) {
      printf("List is empty.\n");
      return;
    }
    ListNode *temp = list->head;
    list->head = list->head->next;
    free(temp->data);
    free(temp);
    list->listSize--;
  }
  void deleteFromIndex(List *list, int index) {
    if (index >= list->listSize || index < 0) {
      printf("Index out of bounds.\n");
      return;
    }
    if (index == 0) {
      deleteFromBeginning(list);
      return;
    }
    ListNode *prevNode = NULL;
    ListNode *currNode = list->head;
    int currIndex = 0;
    while (currIndex < index) {
      prevNode = currNode;
      currNode = currNode->next;
      currIndex++;
    }
    prevNode->next = currNode->next;
    free(currNode->data);
    free(currNode);
    list->listSize--;
  }
  void deleteFromEnd(List *list) {
    if (list->head == NULL) {
      printf("List is empty.\n");
      return;
    }
    if (list->head->next == NULL) {
      free(list->head->data);
      free(list->head);
      list->head = NULL;
    } else {
      ListNode *prevNode = NULL;
      ListNode *currNode = list->head;
      while (currNode->next != NULL) {
        prevNode = currNode;
        currNode = currNode->next;
      }
      prevNode->next = NULL;
      free(currNode->data);
      free(currNode);
    }
    list->listSize--;
  }
  void mergeTwoLists(List *list1, List *list2) {
    if (list1->head == NULL) {
      list1->head = list2->head; 
    } else { 
      ListNode *current = list1->head; 
      while (current->next != NULL) {
        current = current->next; 
      }
      current->next = list2->head;
      }
    list1->listSize += list2->listSize;
  }
  void mergeLists(List *list1) {
    List list2;
    list2.head = NULL;
    list2.listDataType = list1->listDataType;
    list2.dataSize = list1->dataSize;
    list2.printFunc = list1->printFunc;
    list2.listSize = 0;

    int nodes;
    printf("Enter the number of nodes in the second list: ");
    scanf("%d", &nodes);

    printf("Enter the second list. Press Enter after every data.\n"); 
    while (nodes--) {
      data = scanData("Enter a data: ", list2.listDataType);
      ListNode *newNode = createNode(list2.dataSize);
      if (list2.head == NULL) {
        list2.head = newNode;
      } else {
        ListNode *current = list2.head;
        while (current->next != NULL) {
          current = current->next;
        }
        current->next = newNode;
      }
      list2.listSize++;
    }
    mergeTwoLists(list1, &list2);

    printf("Merged list: ");
    traverseList(list1);
  }
  void sortList(List *list) {
    if (list->head == NULL || list->head->next == NULL) {
      printf("List is empty or has only one element.\n");
      return;
    }

    ListNode *i, *j;
    void *tempData = malloc(list->dataSize);
    if (tempData == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return;
    }

    for (i = list->head; i != NULL; i = i->next) {
      for (j = i->next; j != NULL; j = j->next) {
        int comparison;
        switch (list->listDataType) {
          case INTEGER:
            comparison = (*(int *)i->data > *(int *)j->data);
            break;
          case CHARACTER:
            comparison = (*(char *)i->data > *(char *)j->data);
            break;
          case STRING:
            comparison = (strcmp((char *)i->data, (char *)j->data) > 0);
            break;
          default:
            comparison = 0;
            break;
        }
        if (comparison) {
          memcpy(tempData, i->data, list->dataSize);
          memcpy(i->data, j->data, list->dataSize);
          memcpy(j->data, tempData, list->dataSize);
        }
      }
    }

    free(tempData);
    printf("\nList sorted.\n\n");
  }
  ListResult initializeLists () {
    char *message[] = {"Lists are a collection of elements of the same types of  data.", "Examples:",
      "\t1, 2, 3, 4, 5 is a list of numbers or integers",
      "\ta, b, c, d, e is a list of characters",
      "\t\"apple\", \"banana\", \"cherry\" is a list of strings",
      "If you have encountered arrays, you would realize that arrays and lists are basically the same. The difference is how they are stored in the memory.",
      "Each element in a list is called a node."};
    int messageSize = sizeof(message)/sizeof(message[0]);

    printWithinWidth(message, messageSize, "Lists");

    ListResult result;
    result.chosenDataType = chooseDataType("list");
    if (result.chosenDataType == -1) {
      return result; 
    }  
    switch (result.chosenDataType) {
      case INTEGER:
        result.list = (List){NULL, sizeof(int), printInt, INTEGER, 0};
        break;
      case CHARACTER:
        result.list = (List){NULL, sizeof(char), printChar, CHARACTER, 0};
        break;
      case STRING:
        result.list = (List){NULL, sizeof(char *), printStr, STRING, 0};
        break;
      default:
        result.list = (List){NULL, 0, NULL, -1, 0};
        break;
    }
    return result;

  }
void stacks () {
  programHeader("Stacks");

  Stack stack;

  system("cls");
  while (1) {
    StackResult stackResult = initializeStacks();
    stack = stackResult.stack;
    stack.stackDataType = stackResult.chosenDataType;
    if (stack.stackDataType == -1) {
      system("cls");
      return;
    }

    char *stacksMenu[] = {"Add an item", "Remove an item", "Check the top item", "Check if the stack is full", "Check if the stack is empty", "Exit"};
    int stacksMenuSize = sizeof(stacksMenu) / sizeof(stacksMenu[0]);
    int stackOption;

    system("cls");
    do {
      programHeader("Stacks Operations");
      printDataType("stack", stack.stackDataType);
      printMenu(stacksMenu, stacksMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &stackOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }
      
      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      switch (stackOption) {
        case 1:
          system("cls");
          programHeader("Add an item onto the stack"); 
          pushStack(&stack);
          printStack(&stack);
          promptExit();
          system("cls");
          break;
        case 2:
          system("cls");
          programHeader("Remove an item from the stack");
          popStack(&stack);
          printStack(&stack);
          promptExit();
          system("cls");
          break;
        case 3:
          peekStack(&stack);
          break;
        case 4:
          isFullStack(&stack);
          break;
        case 5:
          isEmptyStack(&stack);
          break;
        case 6:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (stackOption != stacksMenuSize);
    system("cls");
  }
}
  StackResult initializeStacks() {
    char *message[] = {"Stacks are a type of data structure that follows the Last In First Out (LIFO) or the First In Last Out (FILO) principle.", "This means that the last element added to the stack will be the first one to be removed. Like a stack of books!"};
    int messageSize = sizeof(message) / sizeof(message[0]);

    printWithinWidth(message, messageSize, "Stacks");

    StackResult result;
    result.chosenDataType = chooseDataType("stack");
    if (result.chosenDataType == -1) {
      return result;
    }

    switch (result.chosenDataType) {
      case INTEGER:
        result.stack = (Stack) {NULL, sizeof(int), printInt, INTEGER, 0};
        break;
      case CHARACTER:
        result.stack = (Stack) {NULL, sizeof(char), printChar, CHARACTER, 0};
        break;
      case STRING:
        result.stack = (Stack) {NULL, sizeof (char *),printStr, STRING, 0};
        break;
    }
    return result;
  }
  void printStack(Stack *stack) {
    printf("\nYour stack: \n");
    if (stack->top == NULL) {
      printf("Stack is empty\n");
      return;
    }

    StackNode *temp = stack->top;
    while (temp != NULL) {
      stack->printFunc(temp->data);
      temp = temp->next;
      printf("\n");
    }
  }
  void pushStack(Stack *stack) {
    if (stack->stackSize == STACK_MAX_SIZE) {
      printf("Stack overflow\n");
      return;
    }

    void *data = scanData("Enter data to add: ", stack->stackDataType);
    if (data == NULL) {
      return;
    }

    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      free(data);
      return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->stackSize++;
  }
  void popStack(Stack *stack) {
    if (stack->top == NULL) {
      printf("Stack underflow\n");
      return;
    }

    StackNode *temp = stack->top;
    stack->top = stack->top->next;

    stack->printFunc(temp->data);
    printf(" is removed from the stack.\n");

    free(temp->data);
    free(temp);
    stack->stackSize--;
  }
  void peekStack(Stack *stack) {
    if (stack->top == NULL) {
      printf("Stack is empty\n");
      return;
    }

    printf("Top element: ");
    stack->printFunc(stack->top->data);
    printf("\n");
  }
  void isFullStack(Stack *stack) {
    char *message[] = {
      "\nNote:", "This program implements a stack data structure using linked lists. As a result, the stack will only be full when the system runs out of memory.",
      "However, for practical purposes, the stack is considered full when it reaches a predefined maximum size. In this implementation, the maximum stack size is set to 50."};
    if (stack->stackSize == STACK_MAX_SIZE) {
      printf("Stack is full\n");
    } else {
      printf("Stack is not full\n");
    }
    printWithinWidth(message, sizeof(message) / sizeof(message[0]), NULL);
  }
  void isEmptyStack(Stack *stack) {
    if (stack->top == NULL) {
      printf("Stack is empty\n");
    } else {
      printf("Stack is not empty\n");
    }
  }
void queues () {
  programHeader("Queues");

  Queue queue;

  system("cls");
  while (1) {
    QueueResult queueResult = initializeQueue();
    queue = queueResult.queue;
    queue.queueDataType = queueResult.chosenDataType;
    if (queue.queueDataType == -1) {
      system("cls");
      return;
    }

    char *queuesMenu[] = {"Add an item", "Remove an item","Check the front item", "Check if the queue is full", "Check if the queue is empty", "Exit"};
    int queuesMenuSize = sizeof(queuesMenu) / sizeof(queuesMenu[0]);
    int chosenOption;

    system("cls");
    do {
      programHeader("Queues Operations");
      printDataType("queue", queue.queueDataType);
      printMenu(queuesMenu, queuesMenuSize);
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
          system("cls");
          programHeader("Add an item");
          push(&queue);
          printQueue(&queue);
          promptExit();
          system("cls");
          break;
        case 2:
          system("cls");
          programHeader("Remove an item");
          pop(&queue);
          printQueue(&queue);
          promptExit();
          system("cls");
          break;
        case 3:
          peek(&queue);
          break;
        case 4:
          isFull(&queue);
          break;
        case 5:
          isEmpty(&queue);
          break;
        case 6:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (chosenOption != queuesMenuSize);
    system("cls");
  }
}
  QueueResult initializeQueue() {
    char *message[] = {"Queues are a type of data structure that follows the First In First Out (FIFO) principle.", "This means that the first element added to the queue will be the first one to be removed. Like a queue of people!\n"};
    int messageSize = sizeof(message) / sizeof(message[0]);

    printWithinWidth(message, messageSize, "Queues");

    QueueResult result;
    result.chosenDataType = chooseDataType("queue");
    if (result.chosenDataType == -1) {
      return result;
    }

    switch (result.chosenDataType) {
      case INTEGER:
        result.queue = (Queue) {NULL, NULL, sizeof(int), printInt, INTEGER, 0};
        break;
      case CHARACTER:
        result.queue = (Queue) {NULL, NULL, sizeof(char), printChar, CHARACTER, 0};
        break;
      case STRING:
        result.queue = (Queue) {NULL, NULL, sizeof(char *), printStr, STRING, 0};
        break;
    }
    return result;
  }
  void printQueue(Queue *queue) {
    printf("\nYour queue: \n");
    if (queue->front == NULL) {
      printf("Queue is empty\n");
      return;
    }

    QueueNode *temp = queue->front;
    printf("Front -> ");
    while (temp != NULL) {
      queue->printFunc(temp->data);
      temp = temp->next;
      if (temp != NULL) {
        printf(" -> ");
      }
    }
    printf(" <- Rear\n");
  }
  void push(Queue *queue) {
    if (queue->queueSize == QUEUE_MAX_SIZE) {
      printf("Queue overflow\n");
      return;
    }

    void *data = scanData("Enter data to add: ", queue->queueDataType);
    if (data == NULL) {
      return;
    }

    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      free(data);
      return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
      queue->front = newNode;
    } else {
      queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->queueSize++;
  }
  void pop(Queue *queue) {
    if (queue->front == NULL) {
      printf("Queue underflow\n");
      return;
    }

    QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    queue->printFunc(temp->data);
    printf(" is removed from the queue.\n");

    free(temp->data);
    free(temp);
    queue->queueSize--;
  }
  void peek(Queue *queue) {
    if (queue->front == NULL) {
      printf("Queue is empty\n");
      return;
    }

    printf("The front of the queue is: ");
    queue->printFunc(queue->front->data);
    printf("\n");
  }
  void isFull(Queue *queue) {
    if (queue->queueSize == QUEUE_MAX_SIZE) {
      printf("Queue is full\n");
    } else {
      printf("Queue is not full\n");
    }
  }
  void isEmpty(Queue *queue) {
    if (queue->front == NULL) {
      printf("Queue is empty\n");
    } else {
      printf("Queue is not empty\n");
    }
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
  int stringsOption;

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
    if (scanf("%d", &stringsOption) != 1) {
      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 1);
      clearInputBuffer();
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      continue;
    }
    clearLines(cursorYpos + 1, 24);
    moveCursor(0, cursorYpos + 2);

    switch (stringsOption) {
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
  } while (stringsOption != stringsMenuSize);
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
  int dataStructuresOption;
  char *dataStructuresMenu[] = {"Linear Data Structures", "Nonlinear Data Structures", "Strings", "Exit"};
  int dataStructuresMenuSize = sizeof(dataStructuresMenu) / sizeof(dataStructuresMenu[0]);

  do {
    programHeader("Data Structures");
    printMenu(dataStructuresMenu, dataStructuresMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &dataStructuresOption) != 1) {
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      continue;
    }

    switch (dataStructuresOption) {
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
  } while (dataStructuresOption != dataStructuresMenuSize);
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
  char *message[] = {"Analyze. Code. Test. Optimize. Repeat. To fully grasp the concepts of Data Structures and Algorithms, ACTOR serves to demonstrate the procedures included in the course. ACTOR is a project in Data Structures and Algorithms during the Academic Year 2024-2025.\n"};
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

















































