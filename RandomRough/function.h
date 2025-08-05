void printArray(int input[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", input[i]);
    }
}

void printMatrix(int input[][1000], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
}

void printCharcterMatrix (char input[][1000], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", input[i][j]);
        }
        printf("\n");
    }
}

void swap(int input[], int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}