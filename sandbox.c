#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <windows.h>

typedef enum {
    DATA_STRUCTURES_AND_ALGORITHMS,
    DATA_STRUCTURES,
    ALGORITHMS,
    ARRAYS,
    LINKED_LISTS,
    STACKS,
    QUEUES,
    TREES,
    SORTING_ALGORITHMS,
    SEARCHING_ALGORITHMS
} Topic;

void displayTopicSummary(Topic topic);

int main() {
    system("cls");
    displayTopicSummary(DATA_STRUCTURES_AND_ALGORITHMS);
    promptExit();
    system("cls");
    displayTopicSummary(ARRAYS);
    promptExit();
    system("cls");
    displayTopicSummary(LINKED_LISTS);
        promptExit();
    system("cls");
    displayTopicSummary(STACKS);    promptExit();
    system("cls");
    displayTopicSummary(QUEUES);    promptExit();
    system("cls");
    displayTopicSummary(TREES);    promptExit();
    system("cls");
    displayTopicSummary(SORTING_ALGORITHMS);    promptExit();
    system("cls");
    displayTopicSummary(SEARCHING_ALGORITHMS);    promptExit();
    system("cls");

    return 0;
}


void displayTopicSummary(Topic topic) {
    char *dataStructsAndAlgoText[] = {"Data Structures and Algorithms (DSA) are fundamental concepts in computer science that help in organizing and processing data efficiently.\n", "Understanding it is like having a toolbox of different containers and recipes to solve problems efficiently.\n","Data Structures are the different ways to store and organize data, while Algorithms are the step-by-step instructions to perform a specific task.\n"};
    int dataStructsAndAlgoTextSize = sizeof(dataStructsAndAlgoText) / sizeof(dataStructsAndAlgoText[0]);

    char *dataStructsText[] = {"Data Structures are the different ways to store and organize data.\n", "It is like choosing the right container to store your food - a fridge for perishables, a pantry for dry goods, and a spice rack for seasonings!\n"};
    int dataStructsTextSize = sizeof(dataStructsText) / sizeof(dataStructsText[0]);

    char *algorithmsText[] = {"Algorithms are step-by-step instructions to perform a specific task.\n", "It is like following a recipe to bake a cake - you need to follow the instructions in the right order to get the desired outcome!\n"};
    int algorithmsTextSize = sizeof(algorithmsText) / sizeof(algorithmsText[0]);

    char *arraysText[] = {
        "An array is a collection of elements stored in contiguous memory locations.\n", "Example:",
        "\t1, 2, 3, 4, 5 is an array of integers",
        "\tA, B, C, D, E is an array of characters",
        "\tapple, banana, cherry is an array of strings",
        "Imagine a long row of lockers, each with a number on it. You can put one toy in each locker and easily find it by its number!\n"};
    int arraysTextSize = sizeof(arraysText) / sizeof(arraysText[0]);

    char *linkedListsText[] = {
        "A linked list is a linear data structure where each element is a separate object called a node.\n",
        "Example:", 
        "\t1 -> 2 -> 3 -> 4 -> 5 is a linked list of integers", 
        "\tA -> B -> C -> D -> E is a linked list of characters", 
        "\tapple -> banana -> cherry is a linked list of strings",
        "Think of a treasure hunt where each clue leads you to the next clue. Each clue (node) knows where the next clue is!\n"};
    int linkedListsTextSize = sizeof(linkedListsText) / sizeof(linkedListsText[0]);

    char *stacksText[] = {
        "A stack is a linear data structure that follows the Last In First Out (LIFO) principle.\n", "Example:",
        "\tPush 1, 2, 3, 4, 5 onto the stack",
        "\tPop 5, 4, 3, 2, 1 from the stack", 
        "It is like a stack of plates where the last plate placed is the first to be washed!\n"};
    int stacksTextSize = sizeof(stacksText) / sizeof(stacksText[0]);

    char *queuesText[] = {"A queue is a linear data structure that follows the First In First Out (FIFO) principle.\n", "Example:",
    "\tEnqueue 1, 2, 3, 4, 5 into the queue",
    "\tDequeue 1, 2, 3, 4, 5 from the queue", 
    "It is like a queue of people waiting in line where the first person to arrive is the first to be served!\n"};
    int queuesTextSize = sizeof(queuesText) / sizeof(queuesText[0]);

    char *treesText[] = {"A tree is a non-linear data structure that consists of nodes connected by edges.\n",
    "Example:",
    "\t1 is the root node, 2 and 3 are its children, 4 and 5 are children of 2, and 6 and 7 are children of 3", 
    "Think of a family tree, where you start with your grandparents at the top and branch out to your parents, aunts, uncles, and then to you and your cousins.\n"};
    int treesTextSize = sizeof(treesText) / sizeof(treesText[0]);

    char *sortingAlgorithmsText[] = {"Sorting algorithms are used to arrange elements in a specific order.\n", "It is like organizing a messy bookshelf so that you can easily find the book you are looking for!\n"};
    int sortingAlgorithmsTextSize = sizeof(sortingAlgorithmsText) / sizeof(sortingAlgorithmsText[0]);

    char *searchingAlgorithmsText[] = {"Searching algorithms are used to find the location of an element in a collection of elements.\n", "It is like looking for a specific book in a library without knowing its exact location!\n"};
    int searchingAlgorithmsTextSize = sizeof(searchingAlgorithmsText) / sizeof(searchingAlgorithmsText[0]);
    
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
        case TREES:
            printWithinWidth(treesText, treesTextSize, "Trees");
            break;
        case SORTING_ALGORITHMS:
            printWithinWidth(sortingAlgorithmsText, sortingAlgorithmsTextSize, "Sorting Algorithms");
            break;
        case SEARCHING_ALGORITHMS:
            printWithinWidth(searchingAlgorithmsText, searchingAlgorithmsTextSize, "Searching Algorithms");
            break;
        default:
            printf("Invalid topic.\n");
    }
}
