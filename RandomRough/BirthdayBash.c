#include <stdio.h>
#include <limits.h>
#include "function.h"
#include <string.h>


#define max(A, B) A > B ? A : B

int count_cells(char strmat[][100], int row, int col) {
    int breadth = 1;
    int length = INT_MIN;
    for (int i = 0; i < row; i++) {
        int space = 0;
        int j;
        int emptycell = 0;
        for (j = 0; j < col; j++) {
            if (strmat[i][j] == '.') {
                emptycell++;
            }

            // if (emptycell > space) space = emptycell;

//            if (strmat[i][j] == 'X') emptycell = 0;
            
        }
        printf("%d empty cell\n", emptycell);
        // if (space >= length) {
        //     length = space;
        //     if (space == length && strmat[i][j] == strmat[i-1][j] == '.') breadth++;
        // }
    } 
    return length;
}

int main () {
    int m, n;
    scanf("%d %d", &m, &n);
    char strmat[m][n];

    for (int i = 0; i < m; i++) {
        scanf("%s", strmat[i]);
    }
    
    int binmatrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (strmat[i][j] == 46 ) binmatrix[i][j] = 1;
            if (strmat[i][j] == 88) binmatrix[i][j] = 0;
        }
    }
    printMatrix(binmatrix, m, n);

    int ans1 = count_cells(strmat, m, n);
    

    char transtrmat[n][m]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transtrmat[j][i] = strmat[i][j];
        }
    }


    int ans2 = count_cells(transtrmat, n, m);

    printf("%d", ans2);

    return 0;
}