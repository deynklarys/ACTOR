// Analyze. Code. Test. Optimize. Repeat
#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()

#define MAX_LENGTH_SIZE 50
#define SUBSTRINGS_MAX_SUBSTRINGS 100 
#define SUBSTRINGS_MAX_LENGTH 500
#define true 1
#define false 0
#define SET_WIDTH 80
#define SET_HEIGHT 24

typedef enum {
  DATA_STRUCTURES_AND_ALGORITHMS,
  DATA_STRUCTURES,
  ALGORITHMS,
  ARRAYS,
  LINKED_LISTS,
  STACKS,
  QUEUES,
  STRINGS,
  TREES,
  SORTING_ALGORITHMS,
  SEARCHING_ALGORITHMS,
  LINEAR_SEARCH,
  BINARY_SEARCH,
} Topic;

typedef enum {
  SELECTION_SORT,
  BUBBLE_SORT,
  INSERTION_SORT,
  COUNT_SORT,
  RANDOM_SORT,
  MERGE_SORT,
  QUICK_SORT_L,
  QUICK_SORT_H,
  HEAP_SORT,
  RADIX_SORT,
} SortTopic;

typedef enum {
  INTEGER = 1,
  CHARACTER = 2,
  STRING = 3
} DataType;

int cursorXpos, cursorYpos;

void welcomeScreen ();
void dataStructures ();
  void linearDS();
    void arrays();
      #define INS 3
      #define DEL 4
      typedef struct {
        int dataType;
        union {
          int intArray[MAX_LENGTH_SIZE];
          char charArray[MAX_LENGTH_SIZE];
          char *strArray[MAX_LENGTH_SIZE];
        } data;
        int size;
      } Array;
      typedef struct {
        union {
          int intKey;
          char charKey;
          char strKey[MAX_LENGTH_SIZE];
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
      typedef struct TreeNode {
        void *data;
        struct TreeNode *left;
        struct TreeNode *right;
      } TreeNode;
      typedef struct {
        TreeNode *root;
        size_t dataSize;
        void (*printFunc)(void *);
        DataType treeDataType;
        int treeSize;
      } Tree;
      typedef struct {
        Tree tree;
        int chosenDataType;
      } TreeResult;
      TreeResult initializeTree();
      TreeNode *createTreeNode(size_t dataSize);
      TreeNode *insertNode(TreeNode *root, void *data, size_t dataSize);
      TreeNode *deleteNode(TreeNode *root, void *data, size_t dataSize);
      TreeNode *minValueNode(TreeNode *node);
      void inorderTraversal(TreeNode *root, void (*printFunc)(void *));
      void preorderTraversal(TreeNode *root, void (*printFunc)(void *));
      void postorderTraversal(TreeNode *root, void (*printFunc)(void *));
      void breadthFirstTraversal(TreeNode *root, void (*printFunc)(void *));
      void traverseTree(TreeNode *root, void (*printFunc)(void *));
  void strings();
    int position, length;
    char string[MAX_LENGTH_SIZE], stringToFind[MAX_LENGTH_SIZE], stringToInsert[MAX_LENGTH_SIZE], string2[MAX_LENGTH_SIZE],charToBeInserted;
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
void printWithinWidthCentered(char *message[], int messageSize, char *header);
void printWithinWidth(char *message[], int messageSize, char *header);
void functionNotDone(char *header);
void clearInputBuffer(); 
int chooseDataType(char dataStructure[]);
void *scanData(char prompt[], DataType dataType);
void printInt(void *data);
void printChar(void *data);
void printStr(void *data);
void printDataType(char dataStructure[], DataType dataType);
void displayTopicSummary(Topic topic);
void displaySortingTopicSummary(SortTopic sortTopic);

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
    displayTopicSummary(DATA_STRUCTURES_AND_ALGORITHMS);

    printf("What do you want to learn about?\n");
    printMenu(mainMenu, mainMenuSize);
    /* Get the current position of the cursor after the prompt. This coordinate will be used to bring back the cursor at this position when the user inputs an invalid option and the option that they typed is cleared. */
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &mainOption) != 1) {
      clearInputBuffer();
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
          clearInputBuffer();
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
  system("cls");
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
  programHeader("Trees");

  Tree tree;

  while (1) {
    system("cls");
    TreeResult treeResult = initializeTree();
    tree = treeResult.tree;
    tree.treeDataType = treeResult.chosenDataType;
    if (treeResult.chosenDataType == -1) {
      promptExit();
      system("cls");
      return;
    }

    char *treesMenu[] = {
      "Insert a node",
      "Delete a node",
      "Traverse tree",
      "Exit"
    };
    int treesMenuSize = sizeof(treesMenu) / sizeof(treesMenu[0]);
    
    int treeMenuOption;

    system("cls");
    do {
      programHeader("Trees Operations");
      printDataType("tree", tree.treeDataType);
      printMenu(treesMenu, treesMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &treeMenuOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, 23);
      moveCursor(0, cursorYpos + 2);

      switch (treeMenuOption) {
        case 1:
          data = scanData("Enter data to insert: ", tree.treeDataType);
          tree.root = insertNode(tree.root, data, tree.dataSize);
          tree.treeSize++;
          break;
        case 2:
          data = scanData("Enter data to delete: ", tree.treeDataType);
          tree.root = deleteNode(tree.root, data, tree.dataSize);
          tree.treeSize--;
          break;
        case 3:
          system("cls");
          traverseTree(tree.root, tree.printFunc);
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
    } while (treeMenuOption != treesMenuSize);
  }
}
  TreeResult initializeTree() {
    displayTopicSummary(TREES);

    TreeResult result;
    result.chosenDataType = chooseDataType("tree");
    if (result.chosenDataType == -1) {
      return result;
    }

    switch (result.chosenDataType) {
      case INTEGER:
        result.tree = (Tree){NULL, sizeof(int), printInt, INTEGER, 0};
        break;
      case CHARACTER:
        result.tree = (Tree){NULL, sizeof(char), printChar, CHARACTER, 0};
        break;
      case STRING:
        result.tree = (Tree){NULL, sizeof(char *), printStr, STRING, 0};
        break;
      default:
        result.tree = (Tree){NULL, 0, NULL, -1, 0};
        break;
    }
    return result;
  }
  TreeNode *createTreeNode(size_t dataSize) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
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
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  TreeNode *insertNode(TreeNode *root, void *data, size_t dataSize) {
    if (root == NULL) {
      TreeNode *newNode = createTreeNode(dataSize);
      memcpy(newNode->data, data, dataSize);
      return newNode;
    }
    if (data < root->data) {
      root->left = insertNode(root->left, data, dataSize);
    } else if (data > root->data) {
      root->right = insertNode(root->right, data, dataSize);
    }
    return root;
  }
  TreeNode *deleteNode (TreeNode *root, void *data, size_t dataSize) {
    if (root == NULL) {
      return root;
    }
    if (data < root->data) {
      root->left = deleteNode(root->left, data, dataSize);
    } else if (data > root->data) {
      root->right = deleteNode(root->right, data, dataSize);
    } else {
      if (root->left == NULL) {
        TreeNode *temp = root->right;
        free(root->data);
        free(root);
        return temp;
      } else if (root->right == NULL) {
        TreeNode *temp = root->left;
        free(root->data);
        free(root);
        return temp;
      }
      TreeNode *temp = minValueNode(root->right);
      memcpy(root->data, temp->data, dataSize);
      root->right = deleteNode(root->right, temp->data, dataSize);
    }
    return root;
  }
  TreeNode *minValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current && current->left != NULL) {
      current = current->left;
    }
    return current;
  }
  void inorderTraversal(TreeNode *root, void (*printFunc)(void *)) {
    if (root != NULL) {
      inorderTraversal(root->left, printFunc);
      printFunc(root->data);
      inorderTraversal(root->right, printFunc);
    }
  }
  void preorderTraversal(TreeNode *root, void (*printFunc)(void *)) {
    if (root != NULL) {
      printFunc(root->data);
      preorderTraversal(root->left, printFunc);
      preorderTraversal(root->right, printFunc);
    }
  }
  void postorderTraversal(TreeNode *root, void (*printFunc)(void *)) {
    if (root != NULL) {
      postorderTraversal(root->left, printFunc);
      postorderTraversal(root->right, printFunc);
      printFunc(root->data);
    }
  }
  void breadthFirstTraversal(TreeNode *root, void (*printFunc)(void *)) {
    if (root == NULL) {
      return;
    }

    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
      TreeNode *current = queue[front++];
      printFunc(current->data);

      if (current->left != NULL) {
        queue[rear++] = current->left;
      }
      if (current->right != NULL) {
        queue[rear++] = current->right;
      }
    }
  }
  void traverseTree(TreeNode *root, void (*printFunc)(void *)) {
    char *traverseMenu[] = {
      "Depth-first traversal: In-order traversal",
      "Depth-first traversal: Pre-order traversal",
      "Depth-first traversal: Post-order traversal",
      "Breadth-first traversal",
      "Exit"
    };
    int traverseMenuSize = sizeof(traverseMenu) / sizeof(traverseMenu[0]);

    int traverseMenuOption;

    do{
      programHeader("Tree Traversal");
      printMenu(traverseMenu, traverseMenuSize);
      
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &traverseMenuOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, 23);
      moveCursor(0, cursorYpos + 2);

      switch (traverseMenuOption) {
        case 1:
          printf("In-order (depth-first) Traversal:\n");
          inorderTraversal(root, printFunc);
          break;
        case 2:
          printf("Pre-order (depth-first) Traversal: \n");
          preorderTraversal(root, printFunc);
          break;
        case 3:
          printf("Post-order (depth-first) Traversal: \n");
          postorderTraversal(root, printFunc);
          break;
        case 4:
          printf("Breadth-first Traversal: \n");
          breadthFirstTraversal(root, printFunc);
          break;
        case 5:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
          break;
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (traverseMenuOption != traverseMenuSize);
  }
void nonLinearDS () {
  char *linearDS_Menu[] = {"Trees", "Exit"};
  int linearDS_MenuSize = sizeof(linearDS_Menu) / sizeof(linearDS_Menu[0]);
  int nonLinearDSOption;


  do {
    programHeader("Linear Data Structures");
    printMenu(linearDS_Menu, linearDS_MenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &nonLinearDSOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
    }

    switch (nonLinearDSOption) {
      case 1:
        system("cls");
        trees();
        system("cls");
        break;
      case 2:
        moveCursor(0, cursorYpos + 2);
        clearLines(cursorYpos + 2, cursorYpos + 2);
        promptExit();
        break;
      default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (nonLinearDSOption != linearDS_MenuSize);
}
void arrays () {
  programHeader("Arrays");

  Array array;
  Key key;

  system("cls");
  while (1) {

    if (!initializeArray(&array)) {
      promptExit();
      system("cls");
      return;
    }

    char *arraysMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two arrays", "Exit"};
    int arraysMenuSize = sizeof(arraysMenu) / sizeof(arraysMenu[0]);
    int chosenOption;

    system("cls");
    do {
      programHeader("Array Operations");
      printDataType("array", array.dataType);
      printMenu(arraysMenu, arraysMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &chosenOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer(); 
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
    if (position < 0 || position > array->size || array->size >= MAX_LENGTH_SIZE) {
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

    if (array1->size + array2->size > MAX_LENGTH_SIZE) {
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
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array2.size < MAX_LENGTH_SIZE);
        break;
      case CHARACTER:
        do {
          if (scanf(" %c", &ch) == 1) {
            array2.data.charArray[array2.size++] = ch;
          } else {
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array2.size < MAX_LENGTH_SIZE);
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
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array2.size < MAX_LENGTH_SIZE);
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
    displayTopicSummary(ARRAYS);

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
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array->size < MAX_LENGTH_SIZE);
        break;
      case CHARACTER:
        do {
          if (scanf(" %c", &ch) == 1) {
            array->data.charArray[array->size++] = ch;
          } else {
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array->size < MAX_LENGTH_SIZE);
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
            clearInputBuffer(); 
            break;
          }
        } while (getchar() != '\n' && array->size < MAX_LENGTH_SIZE);
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
      promptExit();
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
    displayTopicSummary(LINKED_LISTS);

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
      promptExit();
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
    displayTopicSummary(STACKS);

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
    if (stack->stackSize == MAX_LENGTH_SIZE) {
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
    if (stack->stackSize == MAX_LENGTH_SIZE) {
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
      promptExit();
      system("cls");
      return;
    }

    char *queuesMenu[] = {"Add an item", "Remove an item","Check the front item", "Check if the queue is full", "Check if the queue is empty", "Exit"};
    int queuesMenuSize = sizeof(queuesMenu) / sizeof(queuesMenu[0]);
    int queuesOption;

    system("cls");
    do {
      programHeader("Queues Operations");
      printDataType("queue", queue.queueDataType);
      printMenu(queuesMenu, queuesMenuSize);
      getCursorPos(&cursorXpos, &cursorYpos);
      if (scanf("%d", &queuesOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
      }

      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      switch (queuesOption) {
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
    } while (queuesOption != queuesMenuSize);
    system("cls");
  }
}
  QueueResult initializeQueue() {
    displayTopicSummary(QUEUES);

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
    if (queue->queueSize == MAX_LENGTH_SIZE) {
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
    if (queue->queueSize == MAX_LENGTH_SIZE) {
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

  displayTopicSummary(STRINGS);

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
      for (int i = 0; i < MAX_LENGTH_SIZE; i++) {
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
    if (fgets(string, MAX_LENGTH_SIZE, stdin) == NULL) {
      printf("Invalid input. Please enter a string.\n");
      return NULL;
    }
    
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
void linearDS () {
  char *linearDS_Menu[] = {"Arrays", "Linked Lists", "Stacks", "Queues", "Exit"};
  int linearDS_MenuSize = sizeof(linearDS_Menu) / sizeof(linearDS_Menu[0]);
  int linearDSOption;


  do {
    programHeader("Linear Data Structures");
    printMenu(linearDS_Menu, linearDS_MenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &linearDSOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
        continue;
    }

    switch (linearDSOption) {
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
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (linearDSOption != linearDS_MenuSize);
}
void dataStructures () {
  int dataStructuresOption;
  char *dataStructuresMenu[] = {"Linear Data Structures", "Nonlinear Data Structures", "Strings", "Exit"};
  int dataStructuresMenuSize = sizeof(dataStructuresMenu) / sizeof(dataStructuresMenu[0]);

  do {
    displayTopicSummary(DATA_STRUCTURES);

    printMenu(dataStructuresMenu, dataStructuresMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &dataStructuresOption) != 1) {
        clearLines(cursorYpos + 1, cursorYpos + 1);
        moveCursor(0, cursorYpos + 1);
        clearInputBuffer();
        printf("Invalid input. Please enter a number.\n");
        clearWord(cursorYpos, cursorXpos, SET_WIDTH);
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
        promptExit();
        break;
      default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (dataStructuresOption != dataStructuresMenuSize);
}

void sorting() {
  displayTopicSummary(SORTING_ALGORITHMS);

  int arrSize = 0;
  int givenArray[MAX_LENGTH_SIZE];
  int num;
  char ch;
  printf("Initialize your integer array for me to work on.\n\n");
  printf("Enter elements (space-separated, press Enter to finish):\n");

  while (1) {
      if (scanf("%d", &num) == 1) {
        givenArray[arrSize++] = num;
      } else {
        break;
      }

      ch = getchar();
      if (ch == '\n') {
        break;
      }
  }
  
  int beforeQueryPos, afterQueryPos;

  char *sortMenu[] = {"Selection Sort", "Bubble Sort", "Insertion Sort", "Count Sort", "Random Sort", "Merge Sort", "Quick Sort using Lomuto's Partition", "Quick Sort using Hoare's Partition", "Radix Sort", "Heap Sort", "Exit"};
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
  displayTopicSummary(SEARCHING_ALGORITHMS);
  
  int arrSize = 0;
  int givenArray[MAX_LENGTH_SIZE];
  int num;
  char ch;

  printf("Initialize your integer array for me to work on.\n\n");
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

  int algorithmsOption;

  do {
    displayTopicSummary(ALGORITHMS);

    printf("What do you want to learn about?\n");  
    printMenu(algorithmsMenu, algoMenuSize);
    getCursorPos(&cursorXpos, &cursorYpos);
    if (scanf("%d", &algorithmsOption) != 1) {
      clearLines(cursorYpos + 1, cursorYpos + 1);
      moveCursor(0, cursorYpos + 1);
      clearInputBuffer();
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      continue;
    }

    clearLines(cursorYpos + 1, 23);
    moveCursor(0, cursorYpos + 2);

    switch (algorithmsOption) {
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
        promptExit();
        break;
      default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
    }
    clearWord(cursorYpos, cursorXpos, SET_WIDTH);
  } while (algorithmsOption != algoMenuSize);
}

void about() {
  char *message[] = {
    "Analyze. Code. Test. Optimize. Repeat. To fully grasp the concepts of Data Structures and Algorithms. ACTOR serves to demonstrate the procedures included in the course. The project covers various data structures such as arrays, linked lists, stacks, queues, and trees, as well as algorithms for sorting and searching. It provides a hands-on approach to learning these fundamental concepts through interactive operations and visualizations.\n", 
    "ACTOR is a project in Data Structures and Algorithms during the Academic Year 2024-2025. This project is solely built by Deanne Clarice Bea, a second-year Computer Science student at the Bicol University.\n"
    };
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
  switch (sortType) {
    case 1:
      displaySortingTopicSummary(SELECTION_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Selection Sort:\n");
      selectionSort(array, size);
      break;
    case 2:
      displaySortingTopicSummary(BUBBLE_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Bubble Sort:\n");
      bubbleSort(array, size);
      break;
    case 3:
      displaySortingTopicSummary(INSERTION_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Insertion Sort:\n");
      insertionSort(array, size);
      break;
    case 4:
      displaySortingTopicSummary(COUNT_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Count Sort:\n");
      countSort(array, size);
      break;
    case 5:
      displaySortingTopicSummary(RANDOM_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Random Sort:\n");
      randomSort(array, size);
      break;
    case 6:
      displaySortingTopicSummary(MERGE_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Merge Sort:\n");
      mergeSort(array, 0, size - 1);
      break;
    case 7:
      displaySortingTopicSummary(QUICK_SORT_L);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Quick Sort (Lomuto):\n");
      quickSortLomuto(array, 0, size - 1);
      break;
    case 8:
      displaySortingTopicSummary(QUICK_SORT_H);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Quick Sort (Hoare):\n");
      quickSortHoare(array, 0, size - 1);
      break;
    case 9:
      displaySortingTopicSummary(RADIX_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Radix Sort:\n");
      radixSort(array, size);
      break;
    case 10:
      displaySortingTopicSummary(HEAP_SORT);
      printf("Your Array:\n");
      printArray(array, size);
      printf("Sorted array using Heap Sort:\n");
      heapSort(array, size);
      break;
    default:
      clearInputBuffer(); 
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

    if (key == array[mid])
      return mid;

    if (key > array[mid])
      return binarySearch(array, key, mid + 1, high);

    return binarySearch(array, key, low, mid - 1);
  }
  return -1;
}
int linearSearch(int array[], int n, int x) {
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}
void search(int array[], int size, int key, int searchType) {
  system("cls");
  if (searchType == 1) {
    programHeader("Linear Search");
    displayTopicSummary(LINEAR_SEARCH);
    printf("Your Array:\n");
    printArray(array, size);
    int linearResult = linearSearch(array, size, key);
    if (linearResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at index %d", linearResult + 1);
  } else if (searchType == 2) {
    programHeader("Binary Search");
    displayTopicSummary(BINARY_SEARCH);
    printf("Your Array:\n");
    printArray(array, size);
    sort(array, size, 9);
    int binaryResult = binarySearch(array, key, 0, size - 1);
    if (binaryResult == -1)
      printf("Element is not found in the array");
    else
      printf("Element is found at position %d", binaryResult + 1);
  }
}

// Utility functions 
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
      clearInputBuffer(); 
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
        clearInputBuffer();
        char buffer[MAX_LENGTH_SIZE];
        if (fgets(buffer, MAX_LENGTH_SIZE, stdin) == NULL) {
          clearLines(scanDataCursorYpos + 1, scanDataCursorYpos + 1);
          moveCursor(0, scanDataCursorYpos + 1);
          printf("Invalid input. Please enter a string.\n");
          clearWord(scanDataCursorYpos, scanDataCursorXpos, SET_WIDTH);
          moveCursor(0, scanDataCursorYpos);
          continue;
        }
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
void displayTopicSummary(Topic topic) {
  char *dataStructsAndAlgoText[] = {
    "Data Structures and Algorithms (DSA) are fundamental concepts in computer science that help in organizing and processing data efficiently.\n", 
    "Understanding it is like having a toolbox of different containers and recipes to solve problems efficiently.\n",
    "Data Structures are the different ways to store and organize data, while Algorithms are the step-by-step instructions to perform a specific task.\n"};
  int dataStructsAndAlgoTextSize = sizeof(dataStructsAndAlgoText) / sizeof(dataStructsAndAlgoText[0]);

  char *dataStructsText[] = {
    "Data Structures are the different ways to store and organize data.\n", 
    "It is like choosing the right container to store your food - a fridge for perishables, a pantry for dry goods, and a spice rack for seasonings!\n"};
  int dataStructsTextSize = sizeof(dataStructsText) / sizeof(dataStructsText[0]);

  char *algorithmsText[] = {
    "Algorithms are step-by-step instructions to perform a specific task.\n", 
    "It is like the special instructions that help you turn a bag of LEGO bricks into an amazing castle!\n"};
  int algorithmsTextSize = sizeof(algorithmsText) / sizeof(algorithmsText[0]);

  char *arraysText[] = {
    "An array is a collection of elements stored in contiguous memory locations.", 
    "Example:",
    "\t1, 2, 3, 4, 5 is an array of integers",
    "\tA, B, C, D, E is an array of characters",
    "\tapple, banana, cherry is an array of strings\n",

    "Imagine a long row of lockers, each with a number on it. You can put one toy in each locker and easily find it by its number!\n"};
  int arraysTextSize = sizeof(arraysText) / sizeof(arraysText[0]);

  char *linkedListsText[] = {
    "A linked list is a linear data structure where each element is a separate object called a node.\n",
    "Example:", 
    "\t1 -> 2 -> 3 -> 4 -> 5 is a linked list of integers", 
    "\tA -> B -> C -> D -> E is a linked list of characters", 
    "\tapple -> banana -> cherry is a linked list of strings\n",
    "Think of a treasure hunt where each clue leads you to the next clue. Each clue (node) knows where the next clue is!\n"};
  int linkedListsTextSize = sizeof(linkedListsText) / sizeof(linkedListsText[0]);

  char *stacksText[] = {
    "A stack is a linear data structure that follows the Last In First Out (LIFO) principle.\n", "Example:",
    "\tPush 1, 2, 3, 4, 5 onto the stack",
    "\tPop 5, 4, 3, 2, 1 from the stack\n", 
    "It is like a stack of plates where the last plate placed is the first to be washed!\n"};
  int stacksTextSize = sizeof(stacksText) / sizeof(stacksText[0]);

  char *queuesText[] = {
    "A queue is a linear data structure that follows the First In First Out (FIFO) principle.\n", "Example:",
    "\tEnqueue 1, 2, 3, 4, 5 into the queue",
    "\tDequeue 1, 2, 3, 4, 5 from the queue\n", 
    "It is like a queue of people waiting in line where the first person to arrive is the first to be served!\n"};
  int queuesTextSize = sizeof(queuesText) / sizeof(queuesText[0]);

  char *treesText[] = {
    "A tree is a non-linear data structure that consists of nodes connected by edges.\n",
    "Example:",
    "\t1 is the root node, 2 and 3 are its children, 4 and 5 are children of 2, and 6 and 7 are children of 3'n", 
    "Think of a family tree, where you start with your grandparents at the top and branch out to your parents, aunts, uncles, and then to you and your cousins.\n"};
  int treesTextSize = sizeof(treesText) / sizeof(treesText[0]);

  char *stringsText[] = {
    "A string is a sequence of characters terminated by a null character ('\\0'). Strings are typically represented as arrays of characters. The null character allows functions to determine the length of the string.\n",
    "Think of it like a necklace of beads, where each bead is a character and the clasp is the null character.\n",
    "Strings can be manipulated by finding, replacing, inserting, deleting characters, and more!\n"
  };
  int stringsTextSize = sizeof(stringsText) / sizeof(stringsText[0]);

  char *sortingAlgorithmsText[] = {
    "Sorting algorithms are used to arrange elements in a specific order.\n", 
    "It is like organizing a messy bookshelf so that you can easily find the book you are looking for!\n"};
  int sortingAlgorithmsTextSize = sizeof(sortingAlgorithmsText) / sizeof(sortingAlgorithmsText[0]);
  
  char *searchingAlgorithmsText[] = {
    "Searching algorithms are used to find the location of an element in a collection of elements.\n", 
    "It is like looking for a specific book in a library without knowing its exact location!\n"};
  int searchingAlgorithmsTextSize = sizeof(searchingAlgorithmsText) / sizeof(searchingAlgorithmsText[0]);

  char *linearSearchText[] = {
    "Linear Search is a simple search algorithm that sequentially checks each element in a collection until a match is found or the whole collection has been searched.\n"};
  int linearSearchTextSize = sizeof(linearSearchText) / sizeof(linearSearchText[0]);
  
  char *binarySearchText[] = {
    "Binary Search is a search algorithm that finds the position of a target value within a sorted array.\n", 
    "It compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half.\n"};
  int binarySearchTextSize = sizeof(binarySearchText) / sizeof(binarySearchText[0]);
  switch (topic) {
      case DATA_STRUCTURES_AND_ALGORITHMS:
          printWithinWidth(dataStructsAndAlgoText, dataStructsAndAlgoTextSize, "Data Structures and Algorithms");
          break;
      case DATA_STRUCTURES:
          printWithinWidth(dataStructsText, dataStructsTextSize, "Data Structures");
          break;
      case ALGORITHMS:
          printWithinWidth(algorithmsText, algorithmsTextSize, "Algorithms");
          break;
      case ARRAYS:
          printWithinWidth(arraysText, arraysTextSize, "Arrays");
          break;
      case LINKED_LISTS:
          printWithinWidth(linkedListsText, linkedListsTextSize, "Linked Lists");
          break;
      case STACKS:
          printWithinWidth(stacksText, stacksTextSize, "Stacks");
          break;
      case QUEUES:
          printWithinWidth(queuesText, queuesTextSize, "Queues");
          break;
      case STRINGS:
          printWithinWidth(stringsText, stringsTextSize, "Strings");
          break;
      case TREES:
          printWithinWidth(treesText, treesTextSize, "Trees");
          break;
      case SORTING_ALGORITHMS:
          printWithinWidth(sortingAlgorithmsText, sortingAlgorithmsTextSize, "Sorting Algorithms");
          break;
      case SEARCHING_ALGORITHMS:
          printWithinWidth(searchingAlgorithmsText, searchingAlgorithmsTextSize, "Searching Algorithms");
          break;
      case LINEAR_SEARCH:
          printWithinWidth(linearSearchText, linearSearchTextSize, "Linear Search");
          break;
      case BINARY_SEARCH:
          printWithinWidth(binarySearchText, binarySearchTextSize, "Binary Search");
          break;
      default:
          printf("Invalid topic.\n");
  }
}

void displaySortingTopicSummary(SortTopic sortTopic) {
  char *selectionSortText[] = {
    "Selection Sort: Imagine picking the smallest candy from a jar and placing it in a line until the jar is empty. That's Selection Sort!\n"
  };
  int selectionSortTextSize = sizeof(selectionSortText) / sizeof(selectionSortText[0]);

  char *bubbleSortText[] = {
    "Bubble Sort: Think of bubbles rising in soda. The largest bubbles (numbers) float to the top first. That's Bubble Sort!\n"
  };
  int bubbleSortTextSize = sizeof(bubbleSortText) / sizeof(bubbleSortText[0]);

  char *insertionSortText[] = {
    "Insertion Sort: Like sorting playing cards in your hand, one card at a time, to get them in order. That's Insertion Sort!\n"
  };
  int insertionSortTextSize = sizeof(insertionSortText) / sizeof(insertionSortText[0]);

  char *countSortText[] = {
    "Count Sort: Counting how many of each type of candy you have and then lining them up. That's Count Sort!\n"
  };
  int countSortTextSize = sizeof(countSortText) / sizeof(countSortText[0]);

  char *randomSortText[] = {
    "Random Sort: Imagine shuffling a deck of cards until they magically end up in order. That's Random Sort!\n"
  };
  int randomSortTextSize = sizeof(randomSortText) / sizeof(randomSortText[0]);

  char *mergeSortText[] = {
    "Merge Sort: Splitting a big puzzle into smaller pieces, solving each, and then putting them back together. That's Merge Sort!\n"
  };
  int mergeSortTextSize = sizeof(mergeSortText) / sizeof(mergeSortText[0]);

  char *quickSortLomutoText[] = {
    "Quick Sort (Lomuto Partition): Picking a pivot candy (usually the last one), sorting smaller and larger candies around it, and repeating. That's Quick Sort with Lomuto Partition!\n", "Lomuto's partition scheme is simple but less efficient for certain inputs.\n"
  };
  int quickSortLomutoTextSize = sizeof(quickSortLomutoText) / sizeof(quickSortLomutoText[0]);

  char *quickSortHoareText[] = {
    "Quick Sort (Hoare Partition): Picking a pivot candy (usually the first one), sorting smaller and larger candies around it, and repeating. That's Quick Sort with Hoare Partition!\n", "Hoare's partition scheme is more efficient, especially for larger arrays.\n"
  };
  int quickSortHoareTextSize = sizeof(quickSortHoareText) / sizeof(quickSortHoareText[0]);

  char *radixSortText[] = {
    "Radix Sort: Imagine sorting a stack of papers by looking at the last digit of the page number, then the second last, and so on. That's Radix Sort!\n"
  };
  int radixSortTextSize = sizeof(radixSortText) / sizeof(radixSortText[0]);

  char *heapSortText[] = {
    "Heap Sort: Imagine a heap of toys where the largest toy is always on top. You keep removing the largest toy until the heap is empty. That's Heap Sort!\n"
  };
  int heapSortTextSize = sizeof(heapSortText) / sizeof(heapSortText[0]);

  switch (sortTopic) {
    case SELECTION_SORT:
      printWithinWidth(selectionSortText, selectionSortTextSize, "Selection Sort");
      break;
    case BUBBLE_SORT:
      printWithinWidth(bubbleSortText, bubbleSortTextSize, "Bubble Sort");
      break;
    case INSERTION_SORT:
      printWithinWidth(insertionSortText, insertionSortTextSize, "Insertion Sort");
      break;
    case COUNT_SORT:
      printWithinWidth(countSortText, countSortTextSize, "Count Sort");
      break;
    case RANDOM_SORT:
      printWithinWidth(randomSortText, randomSortTextSize, "Random Sort");
      break;
    case MERGE_SORT:
      printWithinWidth(mergeSortText, mergeSortTextSize, "Merge Sort");
      break;
    case QUICK_SORT_L:
      printWithinWidth(quickSortLomutoText, quickSortLomutoTextSize, "Quick Sort");
      break;
    case QUICK_SORT_H:
      printWithinWidth(quickSortHoareText, quickSortHoareTextSize, "Quick Sort");
      break;
    case RADIX_SORT:
      printWithinWidth(radixSortText, radixSortTextSize, "Radix Sort");
      break;
    case HEAP_SORT:
      printWithinWidth(heapSortText, heapSortTextSize, "Heap Sort");
      break;
    default: 
      printf("Invalid topic.\n");
  }
}