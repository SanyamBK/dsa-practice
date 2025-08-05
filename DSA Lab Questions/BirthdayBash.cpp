#include <stdio.h>
#include <stdlib.h> 

#define max(A, B) A > B ? A : B


int main () {
    char dummy; int i, j;
    int m, n;
    scanf("%d %d", &m, &n);


    char **CharMatrix = (char **) calloc(m, sizeof(char *));
    for (i = 0; i < m; i++) {
        CharMatrix[i] = (char *) calloc(n, sizeof(char));
            scanf("%s", CharMatrix[i]) != 1 ;

    }

    int row = m, col = n;
    int breadth = 1;
    int length = 0;
    for (int i = 0; i < row; i++) {
        int space = 0;
        int emptycell = 0;
        for (int j = 0; j < col; j++) {
            if (CharMatrix[i][j] == '.') {
                emptycell++;
            }
            if (emptycell > space) space = emptycell;

            if (CharMatrix[i][j] == 'X') emptycell = 0;

        }
        if (space >= length) {
            length = space;
        }
    }
    

    int ans1 = 2 * (length + breadth) - 1;
    

    row = n, col = m;
    breadth = 1;
    length = 0;
    for (int i = 0; i < row; i++) {
        int space = 0;
        int emptycell = 0;
        for (int j = 0; j < col; j++) {
            if (CharMatrix[j][i] == '.') {
                emptycell++;
            }
            if (emptycell > space) space = emptycell;

            if (CharMatrix[j][i] == 'X') emptycell = 0;

        }
        if (space >= length) {
            length = space;
        }
    }

    int ans2 = 2 * (length + breadth) - 1;

    printf("%d", max(ans1, ans2));

    for (i = 0; i < m; i++) {
        free(CharMatrix[i]);
    }
    free(CharMatrix);

    return 0;
}
