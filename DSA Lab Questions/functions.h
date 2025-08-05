#include <stdio.h>

int i, j;

void printArray(int input[], int n) {
    for (i = 0; i < n; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
}

void printMatrix(int input[][1000], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
}


void printDynamicCharcterMatrix (char input[], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%c", input[i*row+j]);
        printf("\n");
    }
}

void printCharcterMatrix (char input[][1000], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%c", input[i][j]);
        printf("\n");
    }
}


void swap(int input[], int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

void ConsumeToEOL(void) {
  int ch;
  do {
    ch = getchar();
  } while (ch != '\n' && ch != EOF);
}

void print(int input) {
    printf("%d\n", input);
}