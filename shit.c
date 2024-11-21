#include <stdio.h>
#include <windows.h>

// Function to get the terminal size
void getTerminalSize(int *rows, int *cols) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rowss;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rowss = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    *cols = columns;
    *rows = rowss;
}

// Function to print the display centered
void printCenteredDisplay(char display[24][80]) {
    int termRows, termCols;
    getTerminalSize(&termRows, &termCols);

    int startRow = (termRows > 24) ? (termRows - 24) / 2 : 0;
    int startCol = (termCols > 80) ? (termCols - 80) / 2 : 0;

    for (int i = 0; i < 24; i++) {
        // Move the cursor to the starting position
        printf("\033[%d;%dH", startRow + i + 1, startCol + 1);
        printf("%s\n", display[i]);
    }
}

int main() {
    // Example display content
    char display[24][80] = {
        "This is a line of the display.",
        "This is another line of the display.",
        // Add more lines as needed
    };

    printCenteredDisplay(display);

    return 0;
}