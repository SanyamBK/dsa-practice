#include <stdio.h>

int m, n;
char pyramid[1000][1000];
int numMoves = 0;
char moves[100000];

int isEscapePossible(int x, int y, int mummies) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return 1; // Kone reached a boundary cell
    }

    if (pyramid[x][y] == 'M') {
        return 0; // Kone shares a cell with a mummy
    }

    if (pyramid[x][y] == '#') {
        return 0; // Kone reached a blocked cell
    }

    if (mummies == 0) {
        return 1; // All mummies have been avoided
    }

    pyramid[x][y] = '#'; // Mark the current cell as visited

    // Try moving in each direction (U, D, L, R)
    if (isEscapePossible(x - 1, y, mummies - 1)) {
        moves[numMoves++] = 'U';
        return 1;
    }

    if (isEscapePossible(x + 1, y, mummies - 1)) {
        moves[numMoves++] = 'D';
        return 1;
    }

    if (isEscapePossible(x, y - 1, mummies - 1)) {
        moves[numMoves++] = 'L';
        return 1;
    }

    if (isEscapePossible(x, y + 1, mummies - 1)) {
        moves[numMoves++] = 'R';
        return 1;
    }

    pyramid[x][y] = '.'; // Unmark the current cell

    return 0; // Kone cannot escape
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        scanf("%s", pyramid[i]);
    }

    int koneX, koneY;
    int mummyCount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pyramid[i][j] == 'A') {
                koneX = i;
                koneY = j;
            } else if (pyramid[i][j] == 'M') {
                mummyCount++;
            }
        }
    }

    if (isEscapePossible(koneX, koneY, mummyCount)) {
        printf("YES\n");
        printf("%d\n", numMoves);
        for (int i = 0; i < numMoves; i++) {
            printf("%c", moves[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
