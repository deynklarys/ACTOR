#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h> // for getch()
#include "../utility.h"

/*
Functions to implement
traverseList
searchList
insert [beginning, end, middle]
delete [beginning, end, middle]
mergeLists
sortList
*/

#define INTEGER 1
#define CHARACTER 2
#define STRING 3
#define LIST_MAX_LENGTH 50
#define STRING_MAX_LENGTH 50
#define INS 3
#define DEL 4
int cursorXpos, cursorYpos;
void *data;
int *positionPtr;

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
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
void searchList();
void insertList(List *list);
  void insertAtBeginning(List *list);
  void insertAtEnd(List *list);
  void insertAtIndex(List *list, int index);
void deleteList();
  void deleteFromBeginning();
  void deleteFromEnd();
  void deleteFromMiddle();
void mergeLists();
void sortList();

void printInt(void *data) {
  printf("%d -> ", *(int *)data);
}

void printChar(void *data) {
  printf("%c -> ", *(char *)data);
}

void printFloat(void *data) {
  printf("%.2f -> ", *(float *)data);
}

void printString(void *data) {
  printf("%s -> ", (char *)data);
}

int chooseDataTypeLists () {
  int chosenOption;
  printf("\nChoose a data type for your list:\n");
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
      clearInputBuffer(); // Clear invalid input
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      moveCursor(menuCursorXpos, menuCursorYpos);
      continue;
    }
    clearLines(cursorYpos + 1, cursorYpos + 1);
    moveCursor(0, cursorYpos + 2);
    switch (chosenOption) {
      case INTEGER:
        printf("You chose Integer\n");
        return INTEGER;
      case CHARACTER:
        printf("You chose Character\n");
        return CHARACTER;
      case STRING:
        printf("You chose String\n");
        return STRING;
      case 4:
        printf("Exiting...\n");
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
  result.chosenDataType = chooseDataTypeLists();
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
      result.list = (List){NULL, sizeof(char *), printString, STRING, 0};
      break;
    default:
      result.list = (List){NULL, 0, NULL, -1, 0};
      break;
  }
  return result;

}

void *scanData(char promptMessage[], int dataType) {
  void *data = NULL;
  printf("%s", promptMessage);
  switch (dataType) {
    case INTEGER: 
      int *intData = (int *)malloc(sizeof(int));
      if (scanf("%d", intData) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        free(intData);
        clearInputBuffer(); // Clear invalid input
        return NULL;
      }
      data = intData;
      break;
    case CHARACTER: 
      char *charData = (char *)malloc(sizeof(char));
      if (scanf(" %c", charData) != 1) {
        printf("Invalid input. Please enter a character.\n");
        free(charData);
        clearInputBuffer(); // Clear invalid input
        return NULL;
      }
      data = charData;
      break;
    case STRING:
      clearInputBuffer(); // Clear any leftover input
      char buffer[STRING_MAX_LENGTH];
      if (fgets(buffer, STRING_MAX_LENGTH, stdin) == NULL) {
        printf("Invalid input. Please enter a string.\n");
        return NULL;
      }
      // Remove newline character if present
      buffer[strcspn(buffer, "\n")] = '\0';
      char *strData = (char *)malloc(strlen(buffer) + 1);
      if (strData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
      }
      strcpy(strData, buffer);
      data = strData;
      break;
    default:
      printf("Invalid data type.\n");
      break;
  }
  return data;
}

void freeAll(List *list) {
  Node *current = list->head;
  Node *nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current->data);
    free(current);
    current = nextNode;
  }
  list->head = NULL;
  list->listSize = 0;
  printf("List freed.\n");
  free(data);
  printf("Data freed.\n");
  free(positionPtr);
  printf("Position pointer freed.\n");
}

int main () {
  programHeader("Linked Lists");

  List list;
  
  while (1) {
    ListResult listResult = initializeLists();
    list = listResult.list;
    list.listDataType = listResult.chosenDataType;
    if (listResult.chosenDataType == -1) {
      system("cls");
      return 0;
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
    int chosenOption;

    system("cls");
    do {
      programHeader("Linked List Operations");
      printMenu(listMenu, listMenuSize);
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
          traverseList(&list);
          break;
        case 2:
          functionNotDone("Search");
          searchList();
          break;
        case 3:
          system("cls");
          insertList(&list);
          system("cls");
          break;
        case 4:
          system("cls");
          deleteList();
          system("cls");
          break;
        case 5:
          functionNotDone("Sort");
          sortList();
          break;
        case 6:
          functionNotDone("Merge Two Lists");
          mergeLists();
          break;
        case 7:
          promptExit();
          break;
        default:
          moveCursor(0, cursorYpos + 1);
          printf("Invalid choice. Please choose a valid option.\n");
      }
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
    } while (chosenOption != listMenuSize);

    system("cls");
  }

  freeAll(&list);
  system("cls");
  return 0;
}

void traverseList(List *list) {
  Node *current = list->head;
  printf("\nHEAD -> ");
  while (current != NULL) {
    list->printFunc(current->data);
    current = current->next;
  }
  printf("NULL\n");
}
void searchListKey() {
    // Implementation of searchListKey
}
void searchList() {
    // Implementation of searchList
}

void insertList(List *list) {
  char *insertMenu[] = {
    "Insert at the beginning",
    "Insert at a position",
    "Insert at the end",
    "Exit"};
  int insertMenuSize = sizeof(insertMenu) / sizeof(insertMenu[0]);
  int chosenOption;

  do {
    programHeader("Insert in a Linked List");
    printMenu(insertMenu, insertMenuSize);
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

    if (chosenOption != insertMenuSize) {
      data = scanData("Enter data to insert: ", list->listDataType);
    }
    
    switch (chosenOption) {
      case 1:
        system("cls");
        programHeader("Insert at the beginning");
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
  } while (chosenOption != insertMenuSize);

  system("cls");
}

Node* createNode(size_t dataSize) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  if (dataSize == sizeof(char *)) {
    newNode->data = malloc(strlen((char *)data) + 1);
    strcpy((char *)newNode->data, (char *)data);
  } else {
  newNode->data = malloc(dataSize);
  newNode->data = malloc(dataSize);
  if (newNode->data == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    free(newNode);
    exit(EXIT_FAILURE);
  }
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
  Node *newNode = createNode(list->dataSize);
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

  Node *prevNode = NULL;
  Node *currNode = list->head;
  int currIndex = 0;

  while (currIndex < index) {
    prevNode = currNode;
    currNode = currNode->next;
    currIndex++;
  }

  Node *newNode = createNode(list->dataSize);
  newNode->next = currNode;
  prevNode->next = newNode;

  list->listSize++;
}

void insertAtEnd(List *list) {
  Node *newNode = createNode(list->dataSize);
  if (list->head == NULL) {
    list->head = newNode;
  } else {
    Node *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  list->listSize++;
}

void deleteList() {
  char *deleteMenu[] = {
    "Delete at the beginning", 
    "Delete at the middle", 
    "Delete at the end", 
    "Exit"};
  int deleteMenuSize = sizeof(deleteMenu) / sizeof(deleteMenu[0]);
  int chosenOption;


  do {
    programHeader("Delete From a Linked List");
    printMenu(deleteMenu, deleteMenuSize);
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
        functionNotDone("Delete at the beginning");
        deleteFromBeginning();
        break;
      case 2:
        positionPtr = (int *)scanData("Enter the position to insert: ", INTEGER);
        int position = *positionPtr;
        functionNotDone("Delete at the middle");
        deleteFromMiddle();
        break;
      case 3:
        functionNotDone("Delete at the end");
        deleteFromEnd();
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
  } while (chosenOption != deleteMenuSize);

    system("cls");
}

void deleteFromBeginning() {
    // Implementation of deleteFromBeginning
}

void deleteFromEnd() {
    // Implementation of deleteFromEnd
}

void deleteFromMiddle() {
    // Implementation of deleteFromMiddle
}

void mergeTwoLists() {
    // Implementation of mergeTwoLists
}
void mergeLists() {
    // Implementation of mergeLists
}

void sortTheList() {
    // Implementation of sortTheList
}
void sortList() {
    // Implementation of sortList
}