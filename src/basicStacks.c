#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
} Stack;

void initialize(Stack *s) {
  s->top = NULL;
}

int isEmpty(Stack *s) {
  return s->top == NULL;
}

void push(Stack *s, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = value;
  newNode->next = s->top;
  s->top = newNode;
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    return -1;
  }
  Node *temp = s->top;
  int poppedValue = temp->data;
  s->top = s->top->next;
  free(temp);
  return poppedValue;
}

int peek(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return -1;
  }
  return s->top->data;
}

void freeStack(Stack *s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

int main() {
  Stack s;
  initialize(&s);

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("Top element is %d\n", peek(&s));
  printf("Popped element is %d\n", pop(&s));
  printf("Popped element is %d\n", pop(&s));
  printf("Popped element is %d\n", pop(&s));
  printf("Popped element is %d\n", pop(&s));

  freeStack(&s); // Free any remaining nodes

  return 0;
}