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

typedef struct Node {
  void *data;
  struct Node *next;
} Node;
Node *listHead = NULL;

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
void insertList();
  void insertAtBeginning();
  void insertAtEnd();
  void insertAtMiddle();
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
      scanf("%d", intData);
      data = intData;
      break;
    case CHARACTER: 
      char *charData = (char *)malloc(sizeof(char));
      scanf(" %c", charData);
      data = charData;
      break;
    case STRING: 
      char buffer[100];
      scanf("%s", buffer);
      char *strData = (char *)malloc(strlen(buffer) + 1);
      strcpy(strData, buffer);
      data = strData;
      break;
    default:
      printf("Invalid data type.\n");
      break;
  }
  return data;
}

int main () {
  programHeader("Linked Lists");

  List *list;
  
  while (1) {
    ListResult listResult = initializeLists();
    if (listResult.chosenDataType == -1) {
      system("cls");
      return 0;
    }

    char *listMenu[] = {"Traverse", "Search", "Insert", "Delete", "Sort", "Merge two lists", "Exit"};
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
          traverseList(list);
          break;
        case 2:
          functionNotDone("Search");
          searchList();
          break;
        case 3:
          system("cls");
          insertList();
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

  system("cls");
  return 0;
}

void traverseList(List *list) {
  Node *current = listHead;
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

void insertList() {
  char *insertMenu[] = {"Insert at the beginning", "Insert at the middle", "Insert at the end", "Exit"};
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

    void *data;
    if (chosenOption != insertMenuSize) {
      data = scanData("Enter data to insert: ", list->listDataType);
    }
    
    switch (chosenOption) {
      case 1:
        functionNotDone("Insert at the beginning");
        insertAtBeginning();
        break;
      case 2:
        functionNotDone("Insert at the middle");
        insertAtMiddle();
        break;
      case 3:
        functionNotDone("Insert at the end");
        insertAtEnd();
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

void insertAtBeginning() {
    // Implementation of insertAtBeginning
}

void insertAtEnd() {
    // Implementation of insertAtEnd
}

void insertAtMiddle() {
    // Implementation of insertAtMiddle
}

void deleteList() {
  char *deleteMenu[] = {"Delete at the beginning", "Delete at the middle", "Delete at the end", "Exit"};
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