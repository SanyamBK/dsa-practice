#include <stdio.h>
#include <stdlib.h> 

#define max(A, B) A > B ? A : B

int friendsTable(char **input, int row, int col) {
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
    char **CharMatrix = (char **) calloc(m, sizeof(char *));
    for (i = 0; i < m; i++) {
        CharMatrix[i] = (char *) calloc(n, sizeof(char));
        scanf("%s", CharMatrix[i]);
    }

    char **TransCharMat = (char **) realloc(*CharMatrix, n * sizeof(char *));
    for (i = 0; i < n; i++) {
        TransCharMat[i] = (char *) calloc(m, sizeof(char));
        for (j = 0; j < m; j++) {
            TransCharMat[i][j] = CharMatrix[j][i];
        }
    }

    int ans1 = friendsTable(CharMatrix, m, n);
    int ans2 = friendsTable(TransCharMat, n, m);
    printf("%d", max(ans1, ans2));

    for (i = 0; i < m; i++) {
        free(CharMatrix[i]);
    }
    free(CharMatrix);

    for (i = 0; i < n; i++) {
        free(TransCharMat[i]);
    }
    free(TransCharMat);

    return 0;
}
