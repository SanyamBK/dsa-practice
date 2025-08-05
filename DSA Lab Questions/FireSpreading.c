#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

Point make_point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int timeToBurn(int **matrix, int m, int n) {
    int time = 0;
    Point queue[m * n];
    int front = 0, rear = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                queue[rear++] = make_point(i, j);
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (front < rear) {
        Point cur = queue[front++];
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == 0) {
                matrix[nx][ny] = matrix[cur.x][cur.y] + 1;
                time = matrix[nx][ny] - 1;
                queue[rear++] = make_point(nx, ny);
            }
        }
    }

    return time;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
        matrix[i] = (int*)malloc(c * sizeof(int));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int t = timeToBurn(matrix, r, c);
    printf("%d", t);

    return 0;
}