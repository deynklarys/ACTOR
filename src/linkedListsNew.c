#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    size_t dataSize;
    void (*printFunc)(void *);
} List;

Node* createNode(void *data, size_t dataSize) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (dataSize == sizeof(char *)) {
        newNode->data = malloc(strlen((char *)data) + 1);
        strcpy((char *)newNode->data, (char *)data);
    } else {
        newNode->data = malloc(dataSize);
        memcpy(newNode->data, data, dataSize);
    }
    newNode->next = NULL;
    return newNode;
}

void addNode(List *list, void *data) {
    Node *newNode = createNode(data, list->dataSize);
    newNode->next = list->head;
    list->head = newNode;
}

void printList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        list->printFunc(current->data);
        current = current->next;
    }
    printf("\n");
}

void printInt(void *data) {
    printf("%d ", *(int *)data);
}

void printChar(void *data) {
    printf("%c ", *(char *)data);
}

void printFloat(void *data) {
    printf("%.2f ", *(float *)data);
}

void printString(void *data) {
    printf("%s ", (char *)data);
}

int main() {
    List intList = {NULL, sizeof(int), printInt};
    int a = 10, b = 20, c = 30;
    addNode(&intList, &a);
    addNode(&intList, &b);
    addNode(&intList, &c);
    printList(&intList);

    List charList = {NULL, sizeof(char), printChar};
    char x = 'a', y = 'b', z = 'c';
    addNode(&charList, &x);
    addNode(&charList, &y);
    addNode(&charList, &z);
    printList(&charList);

    List floatList = {NULL, sizeof(float), printFloat};
    float p = 1.1, q = 2.2, r = 3.3;
    addNode(&floatList, &p);
    addNode(&floatList, &q);
    addNode(&floatList, &r);
    printList(&floatList);

    List stringList = {NULL, sizeof(char *), printString};
    char str1[] = "apple", str2[] = "deanneclarice", str3[] = "cherry";
    addNode(&stringList, str1);
    addNode(&stringList, str2);
    addNode(&stringList, str3);
    printList(&stringList);

    return 0;
}