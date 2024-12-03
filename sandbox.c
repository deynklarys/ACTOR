#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // for memory leak detection

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Enable memory leak detection

    // Deliberately introduce a memory leak
    int *leak = (int *)malloc(sizeof(int));
    *leak = 42;

    printf("Program is running...\n");

    // Normally, you would free the allocated memory
    // free(leak);

    return 0;
}