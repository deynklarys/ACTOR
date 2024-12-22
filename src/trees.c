#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h> 
#include "../utility.h"

int cursorXpos, cursorYpos;
void *data;

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
TreeNode *createNode(size_t dataSize);
TreeNode *insertNode(TreeNode *root, void *data, size_t dataSize);
TreeNode *deleteNode(TreeNode *root, void *data, size_t dataSize);
TreeNode *minValueNode(TreeNode *node);
void inorderTraversal(TreeNode *root, void (*printFunc)(void *));
void preorderTraversal(TreeNode *root, void (*printFunc)(void *));
void postorderTraversal(TreeNode *root, void (*printFunc)(void *));
void breadthFirstTraversal(TreeNode *root, void (*printFunc)(void *));
void traverseTree(TreeNode *root, void (*printFunc)(void *));

int main() {
  programHeader("Trees");

  Tree tree;

  while (1) {
    system("cls");
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

  return 0;
}

TreeResult initializeTree() {
  char *message[] = {
    "Trees are a type of non-linear data structure that consists of nodes connected by edges. Trees are used to represent hierarchical data, such as file systems, organization charts, and more.\n",
    "Imagine a tree in your backyard. It has a trunk, branches, and leaves. In computer science, a tree looks a bit like a real tree turned upside down. The root is its trunk, nodes are the branches and leaves where each node holds a data, and edges are the connection between nodes like branches.\n",
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
    default:
      result.tree = (Tree){NULL, 0, NULL, -1, 0};
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
