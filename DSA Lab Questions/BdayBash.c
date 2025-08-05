#include <stdio.h>

#define max(A, B) A > B ? A : B

int friendsTable(char input[][100], int row, int col) {
    int breadth = 1;
    int length = 0;
    for (int i = 0; i < row; i++) {
        int space = 0;
        int emptycell = 0;
        for (int j = 0; j < col; j++) {
            if (input[i][j] == '.') {
                emptycell++;
            }
            if (emptycell > space) space = emptycell;

            if (input[i][j] == 'X') emptycell = 0;

        }
        if (space >= length) {
            length = space;
        }
    }
    return 2 * (length + breadth) - 1;
}



int main () {
    char dummy; int i, j;
    int m, n;
    scanf("%d %d", &m, &n);

    char CharMatrix[100][100];
    for (i = 0; i < m; i++) {
        scanf("%s", CharMatrix[i]);
    }

    char TransCharMat[2500][2500];
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++) 
            TransCharMat[j][i] = CharMatrix[i][j];
    
    
    int ans1 = friendsTable(CharMatrix, m, n);
    int ans2 = friendsTable(TransCharMat, n, m);
    printf("%d", max(ans1, ans2));

    return 0;
}
