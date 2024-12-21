#include <stdio.h>
#include <windows.h>
#include <conio.h> // for _getch()
#include "../utility.h"

/*
Functions to implement:
push
pop 
peek
is full
is empty
*/

#define QUEUE_MAX_SIZE 50
#define STRING_MAX_LENGTH 50
int cursorXpos, cursorYpos;

typedef struct Node {
  void *data;
  struct Node *next;
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

void push(Queue *queue);
void pop(Queue *queue);
void peek(Queue *queue);
void isFull(Queue *queue);
void isEmpty(Queue *queue);

void printInt(void *data) {
  printf(" %d ", *(int *)data);
}
void printChar(void *data) {
  printf(" %c ", *(char *)data);
}
void printString(void *data) {
  printf(" %s ", (char *)data);
}

QueueResult initializeQueue();
void freeAll(Queue *queue);
void printQueue(Queue *queue);
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

int main () {
  programHeader("Queues");

  Queue queue;

  system("cls");
  while (1) {
    QueueResult queueResult = initializeQueue();
    queue = queueResult.queue;
    queue.queueDataType = queueResult.chosenDataType;
    if (queue.queueDataType == -1) {
      system("cls");
      return 0;
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
          freeAll(&queue);
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

  return 0;
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
      result.queue = (Queue) {NULL, NULL, sizeof(char *), printString, STRING, 0};
      break;
  }
  return result;
}


void freeAll(Queue *queue) {
  QueueNode *temp = queue->front;
  while (temp != NULL) {
    QueueNode *next = temp->next;
    free(temp->data);
    free(temp);
    temp = next;
  }
  queue->front = NULL;
  queue->rear = NULL;
  queue->queueSize = 0;
  printf("Queue freed.\n");
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