void swapColumn(int input[][5], int n1, int n2) {
    for (int i = 0; i < 3; ++i) {
    int temp = input[i][n1];
        input[i][n1] = input[i][n2];
        input[i][n2] = temp;
    }
}

void swapRow(int input[][5], int n1, int n2) {
  for (int i = 0; i < 5; ++i) {
    int temp = input[n1][i];
        input[n1][i] = input[n2][i];
        input[n2][i] = temp;
    }
}