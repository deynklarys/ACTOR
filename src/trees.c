#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h> 
#include "../utility.h"

int cursorXpos, cursorYpos;

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

TreeResult initializeTree() {
  char *message[] = {
    "Trees are a type of non-linear data structure that consists of nodes connected by edges. The topmost node of the tree is called the root, and the nodes below it are called child nodes. Trees are used to represent hierarchical data, such as file systems, organization charts, and more.",
    "There are different types of trees, such as binary trees, binary search trees, AVL trees, and more. Each type of tree has its own set of rules and properties.",
    "Imagine a tree in your backyard. It has a trunk, branches, and leaves. In computer science, a tree is a way to organize information that looks a bit like a real tree turned upside down. The root is its trunk, nodes are the branches and leaves where each node holds a data, and edges are the connection between nodes like branches.",
    "In this program, you can create a binary tree and perform various operations on it.\n",
  };
  int messageSize = sizeof(message) / sizeof(message[0]);

  printWithinWidth(message, messageSize, "Trees");

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
  }
  return result;
}

TreeNode *createNode(size_t dataSize) {
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = malloc(dataSize);
  if (newNode->data == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    free(newNode);
    exit(EXIT_FAILURE);
  }
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

TreeNode *insertNode(TreeNode *root, void *data, size_t dataSize) {
  if (root == NULL) {
    TreeNode *newNode = createNode(dataSize);
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
  programHeader("Tree Traversal");
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

    clearLines(cursorYpos + 1, 24);
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
  } while (traverseMenuOption != traverseMenuSize);
  
}

int main() {
  programHeader("Trees");

  Tree tree;

  system("cls");
  while (1) {
    TreeResult treeResult = initializeTree();
    tree = treeResult.tree;
    tree.treeDataType = treeResult.chosenDataType;
    if (treeResult.chosenDataType == -1) {
      system("cls");
      return 0;
    }

    char *treesMenu[] = {
      "Insert a node",
      "Delete a node",
      "Traverse tree",
      "Exit"
    };
    int treesMenuSize = sizeof(treesMenu) / sizeof(treesMenu[0]);
    
    int treeMenuOption;

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

      clearLines(cursorYpos + 1, 24);
      moveCursor(0, cursorYpos + 2);

      switch (treeMenuOption) {
        case 1:
          void *data = scanData("Enter data to insert: ", tree.dataSize);
          tree.root = insertNode(tree.root, data, tree.dataSize);
          tree.treeSize++;
          break;
        case 2:
          void *data = scanData("Enter data to delete: ", tree.dataSize);
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

  return 0;
}