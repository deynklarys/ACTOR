#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
  if (root == NULL) {
    return createNode(data);
  }
  if (data < root->data) {
    root->left = insertNode(root->left, data);
  } else if (data > root->data) {
    root->right = insertNode(root->right, data);
  }
  return root;
}

// Function to perform in-order traversal of the tree
void inorderTraversal(struct Node* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void breadthFirstTraversal(struct Node* root) {
  if (root == NULL) {
    return;
  }

  struct Node* queue[100];
  int front = 0, rear = 0;
  queue[rear++] = root;

  while (front < rear) {
    struct Node* current = queue[front++];
    printf("%d ", current->data);

    if (current->left != NULL) {
      queue[rear++] = current->left;
    }
    if (current->right != NULL) {
      queue[rear++] = current->right;
    }
  }
}

int main() {
  struct Node* root = NULL;
  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  printf("In-order traversal of the binary tree: ");
  inorderTraversal(root);

  printf("\nBreadth first traversal of the binary tree: ");
  breadthFirstTraversal(root);

  return 0;
}