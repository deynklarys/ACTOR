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
#define STRING_MAX_LENGTH 50
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

void printInt(void *data) {
  printf("%d -> ", *(int *)data);
}
void printChar(void *data) {
  printf("%c -> ", *(char *)data);
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
        clearInputBuffer();
        return NULL;
      }
      data = intData;
      break;
    case CHARACTER: 
      char *charData = (char *)malloc(sizeof(char));
      if (scanf(" %c", charData) != 1) {
        printf("Invalid input. Please enter a character.\n");
        free(charData);
        clearInputBuffer();
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

void freeAll(List *list, void *data, int *positionPtr) {
  if (list->head == NULL) {
    printf("Nothing to free. The list is already empty.\n");
    return;
  }

  printf("Freeing memory allocations...\n");
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

  if (data != NULL) {
    free(data);
    printf("Data freed.\n");
  }

  if (positionPtr != NULL) {
    free(positionPtr);
    printf("Position pointer freed.\n");
  }
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
      freeAll(&list, NULL, NULL);
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
        clearInputBuffer();
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
          system("cls");
          programHeader("Search in a Linked List");
          searchList(&list);
          traverseList(&list);
          promptExit();
          system("cls");
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
    } while (chosenOption != listMenuSize);

    system("cls");
  }

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

  Node *tempNode = list->head;
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
  int chosenOption;

  do {
    programHeader("Insert in a Linked List");
    printMenu(insertMenu, insertMenuSize);
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

    if (chosenOption > 0 && chosenOption < insertMenuSize) {
      data = scanData("Enter data to insert: ", list->listDataType);
    }
    
    switch (chosenOption) {
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
  } while (chosenOption != insertMenuSize);

  freeAll(NULL, data, positionPtr);

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

void deleteList(List *list) {
  char *deleteMenu[] = {
    "Delete at the beginning", 
    "Delete at an index", 
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
      clearInputBuffer();
      printf("Invalid input. Please enter a number.\n");
      clearWord(cursorYpos, cursorXpos, SET_WIDTH);
      continue;
    }

    clearLines(cursorYpos + 1, cursorYpos + 1);
    moveCursor(0, cursorYpos + 2);

    switch (chosenOption) {
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
  } while (chosenOption != deleteMenuSize);

  freeAll(NULL, data, positionPtr);

  system("cls");
}

// All delete subfunctions can be implemented into only one function using delete from an index
void deleteFromBeginning(List *list) {
  if (list->head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *temp = list->head;
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
  Node *prevNode = NULL;
  Node *currNode = list->head;
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
    Node *prevNode = NULL;
    Node *currNode = list->head;
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
    Node *current = list1->head; 
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

  printf("Enter the second list.\n");
  while (nodes--) {
    data = scanData("Enter data: ", list2.listDataType);
    Node *newNode = createNode(list2.dataSize);
    if (list2.head == NULL) {
      list2.head = newNode;
    } else {
      Node *current = list2.head;
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

  freeAll(&list2, data, NULL);
}

void sortList(List *list) {
  if (list->head == NULL || list->head->next == NULL) {
    printf("List is empty or has only one element.\n");
    return;
  }

  Node *i, *j;
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