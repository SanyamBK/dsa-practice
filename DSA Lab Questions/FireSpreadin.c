#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int i, j;

int BurnTime(int **input, int m, int n) {

    int coords[m*n][2];
    int c = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (input[i][j] == 1) {
                coords[c][0] = i;
                coords[c][1] = j;
                c++;
            }
        }
    }


    int time = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (input[i][j] == 0) {
                int mintime = fmax(m, n);
                    for (int k = 0; k < c; k++) {
                        int maxdist = fmax(abs((i-coords[k][0])), abs((j-coords[k][1])));
                        if (maxdist < mintime) 
                            mintime = maxdist;
                    }
                    
                if (time < mintime) 
                    time = mintime;
            }
        }
    }
    return time;
}

int main () {
    int m, n;
    scanf("%d %d", &m, &n);

    int** houses = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        houses[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &houses[i][j]);
        }
    }

    printf("%d", BurnTime(houses, m, n));

}